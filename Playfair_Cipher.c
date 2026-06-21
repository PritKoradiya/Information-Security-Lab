#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keyMatrix[5][5];

void generateKeyMatrix(char key[]) {
    int used[26] = {0};
    int k = 0;

    for (int i = 0; key[i]; i++) {
        if (key[i] == 'J') key[i] = 'I';
        if (!used[key[i] - 'A']) {
            keyMatrix[k / 5][k % 5] = key[i];
            used[key[i] - 'A'] = 1;
            k++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (i == ('J' - 'A')) continue;
        if (!used[i]) {
            keyMatrix[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

void findPosition(char ch, int *r, int *c) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (keyMatrix[i][j] == ch) {
                *r = i;
                *c = j;
                return;
            }
}

void preprocessPlaintext(char input[], char output[]) {
    int i = 0, k = 0;

    while (input[i]) {
        char a = input[i];
        char b = input[i + 1];

        if (a == 'J') a = 'I';

        if (!b) {
            output[k++] = a;
            output[k++] = 'X';
            break;
        }

        if (b == 'J') b = 'I';

        if (a == b) {
            output[k++] = a;
            output[k++] = 'X';
            i++;
        } else {
            output[k++] = a;
            output[k++] = b;
            i += 2;
        }
    }
    output[k] = '\0';
}

void playfair(char text[], int encrypt) {
    char result[200];
    int r1, c1, r2, c2;

    for (int i = 0; text[i]; i += 2) {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            result[i]     = keyMatrix[r1][(c1 + encrypt + 5) % 5];
            result[i + 1] = keyMatrix[r2][(c2 + encrypt + 5) % 5];
        }
        else if (c1 == c2) {
            result[i]     = keyMatrix[(r1 + encrypt + 5) % 5][c1];
            result[i + 1] = keyMatrix[(r2 + encrypt + 5) % 5][c2];
        }
        else {
            result[i]     = keyMatrix[r1][c2];
            result[i + 1] = keyMatrix[r2][c1];
        }
    }
    result[strlen(text)] = '\0';
    printf("Result: %s\n", result);
}

int main() {
    char key[50], text[100], processed[200];
    int choice;

    printf("Enter Key: ");
    scanf("%s", key);

    for (int i = 0; key[i]; i++)
        key[i] = toupper(key[i]);

    generateKeyMatrix(key);

    printf("\nKey Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", keyMatrix[i][j]);
        printf("\n");
    }

    printf("\n1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Plaintext: ");
        scanf("%s", text);

        for (int i = 0; text[i]; i++)
            text[i] = toupper(text[i]);

        preprocessPlaintext(text, processed);
        playfair(processed, 1);
    }
    else {
        printf("Enter Ciphertext: ");
        scanf("%s", text);

        for (int i = 0; text[i]; i++)
            text[i] = toupper(text[i]);

        playfair(text, -1);
    }

    return 0;
}