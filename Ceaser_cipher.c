#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int shift, i, choice;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    printf("\n1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            if (choice == 1)
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            else if (choice == 2)
                text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            if (choice == 1)
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            else if (choice == 2)
                text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }

    if (choice == 1)
        printf("\nEncrypted text: %s", text);
    else if (choice == 2)
        printf("\nDecrypted text: %s", text);
    else
        printf("\nInvalid choice!");

    return 0;
}
