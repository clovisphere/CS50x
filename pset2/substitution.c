#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

static const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";

void usage() {
    printf("\nUsage: ./substitution KEY\n");
}

bool has_invalid_or_duplicate_char(string key) {
    char c, arr[30];

    for (int i = 0; i < strlen(key); i++) {
        c = key[i];
        if (!isalpha(c)) {
            return true;
        } else {
            arr[i] = tolower(c);
        }

    }
    // check for duplicate
    for (int i = 0; i < strlen(arr); i++) {
        for (int j = i + 1; j < strlen(arr); j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

void encrypt(string key, string text) {
    char c, e, *pt_c, temp[2] = {0};
    int index; 
    
    printf("ciphertext: "); // ugly.. but meeeh..

    for(int i = 0; i < strlen(text); i++) {
        c = text[i];
        if(isalpha(c)) {
            // we need to retrieve the character index from alphabet
            // NOTE: see explanation on -
            // https://stackoverflow.com/questions/3217629/how-do-i-find-the-index-of-a-character-within-a-string-in-c
            e = tolower(c);
            pt_c = strchr(ALPHABET, e);
            index = (int) (pt_c - ALPHABET);

            if(islower(c)) {
                temp[0] = tolower(key[index]);
                printf("%s", temp);
            } else {
                temp[0] = toupper(key[index]);
                printf("%s", temp);
            }
        } else {
            temp[0] = c;
            printf("%s", temp);
        }
    }
    printf("\n");
}

// starts program execution
int main(int argc, char **argv) {
    if (argc != 2) {
        usage();
    } else if (strlen(argv[1]) != 26 || has_invalid_or_duplicate_char(argv[1])) {
        printf("\nKEY must contain 26 charaters, duplicate character not allowed in KEY.\n");
    } else {
        string input = get_string("plaintext: ");
        encrypt(argv[1], input);
    }
    return 0;
}
