#include <stdio.h>

int main() {
    char choice;
    char text[100];
    char key[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter choice (E = Encrypt, D = Decrypt): ");
    scanf(" %c", &choice);   
    getchar();               

    printf("Enter text: ");
    gets(text);

    /*  ENCRYPTION  */
    if (choice == 'E' || choice == 'e') {

        for (i = 0; text[i] != '\0'; i++) {

            if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] = key[text[i] - 'A'];
            }
            else if (text[i] >= 'a' && text[i] <= 'z') {
                text[i] = key[text[i] - 'a'] + 32;
            }
        }

        printf("Encrypted text: %s", text);
    }

    /*  DECRYPTION */
    else if (choice == 'D' || choice == 'd') {

        for (i = 0; text[i] != '\0'; i++) {

            switch (text[i]) {

                case 'Q': text[i] = 'A'; break;
                case 'W': text[i] = 'B'; break;
                case 'E': text[i] = 'C'; break;
                case 'R': text[i] = 'D'; break;
                case 'T': text[i] = 'E'; break;
                case 'Y': text[i] = 'F'; break;
                case 'U': text[i] = 'G'; break;
                case 'I': text[i] = 'H'; break;
                case 'O': text[i] = 'I'; break;
                case 'P': text[i] = 'J'; break;
                case 'A': text[i] = 'K'; break;
                case 'S': text[i] = 'L'; break;
                case 'D': text[i] = 'M'; break;
                case 'F': text[i] = 'N'; break;
                case 'G': text[i] = 'O'; break;
                case 'H': text[i] = 'P'; break;
                case 'J': text[i] = 'Q'; break;
                case 'K': text[i] = 'R'; break;
                case 'L': text[i] = 'S'; break;
                case 'Z': text[i] = 'T'; break;
                case 'X': text[i] = 'U'; break;
                case 'C': text[i] = 'V'; break;
                case 'V': text[i] = 'W'; break;
                case 'B': text[i] = 'X'; break;
                case 'N': text[i] = 'Y'; break;
                case 'M': text[i] = 'Z'; break;

                case 'q': text[i] = 'a'; break;
                case 'w': text[i] = 'b'; break;
                case 'e': text[i] = 'c'; break;
                case 'r': text[i] = 'd'; break;
                case 't': text[i] = 'e'; break;
                case 'y': text[i] = 'f'; break;
                case 'u': text[i] = 'g'; break;
                case 'i': text[i] = 'h'; break;
                case 'o': text[i] = 'i'; break;
                case 'p': text[i] = 'j'; break;
                case 'a': text[i] = 'k'; break;
                case 's': text[i] = 'l'; break;
                case 'd': text[i] = 'm'; break;
                case 'f': text[i] = 'n'; break;
                case 'g': text[i] = 'o'; break;
                case 'h': text[i] = 'p'; break;
                case 'j': text[i] = 'q'; break;
                case 'k': text[i] = 'r'; break;
                case 'l': text[i] = 's'; break;
                case 'z': text[i] = 't'; break;
                case 'x': text[i] = 'u'; break;
                case 'c': text[i] = 'v'; break;
                case 'v': text[i] = 'w'; break;
                case 'b': text[i] = 'x'; break;
                case 'n': text[i] = 'y'; break;
                case 'm': text[i] = 'z'; break;

                default: break;  
            }
        }

        printf("Decrypted text: %s", text);
    }

    else {
        printf("Invalid choice");
    }

    return 0;
}