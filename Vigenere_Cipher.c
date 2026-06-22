#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char key[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; i < textLen; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyChar = toupper(key[keyIndex % keyLen]) - 'A';

            text[i] = (ch - base + keyChar) % 26 + base;
            keyIndex++;
        }
    }
}

void decrypt(char text[], char key[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; i < textLen; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyChar = toupper(key[keyIndex % keyLen]) - 'A';

            text[i] = (ch - base - keyChar + 26) % 26 + base;
            keyIndex++;
        }
    }
}

int main() {
    char text[1000], key[100];
    int choice;

    printf("===== Vigenere Cipher =====\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    getchar();

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    printf("Enter the key: ");
    scanf("%s", key);

    if (choice == 1) {
        encrypt(text, key);
        printf("Encrypted Text: %s\n", text);
    } 
    else if (choice == 2) {
        decrypt(text, key);
        printf("Decrypted Text: %s\n", text);
    } 
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}