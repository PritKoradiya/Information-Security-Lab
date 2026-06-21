#include <stdio.h>
#include <string.h>

void encrypt(char text[], int key) {
    int len = strlen(text);
    char rail[key][len];
    int i, j;

    for (i = 0; i < key; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';

    int dir = 0, row = 0;
    for (j = 0; j < len; j++) {
        rail[row][j] = text[j];

        if (row == 0 || row == key - 1)
            dir = !dir;

        row += dir ? 1 : -1;
    }

    for (i = 0; i < key; i++)
        for (j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);

    printf("\n");
}

void decrypt(char cipher[], int key) {
    int len = strlen(cipher);
    char rail[key][len];
    int i, j;

    for (i = 0; i < key; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';

    int dir = 0, row = 0;
    for (j = 0; j < len; j++) {
        rail[row][j] = '*';

        if (row == 0 || row == key - 1)
            dir = !dir;

        row += dir ? 1 : -1;
    }

    int idx = 0;
    for (i = 0; i < key; i++)
        for (j = 0; j < len; j++)
            if (rail[i][j] == '*' && idx < len)
                rail[i][j] = cipher[idx++];

    dir = 0;
    row = 0;
    for (j = 0; j < len; j++) {
        printf("%c", rail[row][j]);

        if (row == 0 || row == key - 1)
            dir = !dir;

        row += dir ? 1 : -1;
    }

    printf("\n");
}

int main() {
    int choice, key;
    char text[100];

    printf("1. Encryption\n2. Decryption\n");
    scanf("%d", &choice);

    printf("Enter text: ");
    scanf(" %[^\n]", text);

    printf("Enter number of rails: ");
    scanf("%d", &key);

    if (choice == 1)
        encrypt(text, key);
    else if (choice == 2)
        decrypt(text, key);
    else
        printf("Invalid choice\n");

    return 0;
}