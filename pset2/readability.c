#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>


/**
 * calculates the Coleman-Liau index
 *
 * @l_letter: total number of letters
 * @t_word: total number of words
 * @t_sentence: total number of sentences
 *
 * @return: void
 */
void coleman_liau_index(int t_letter, int t_word, int t_sentence) {
    int avg_letters_per_100_words = (100.0 * t_letter) / t_word;
    int avg_sentences_per_100_words = (100.0 * t_sentence) / t_word;

    // FORMULA: index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words, and 
    // S is the average number of sentences per 100 words
    int index = round((0.0588 * avg_letters_per_100_words) - (0.296 * avg_sentences_per_100_words) - 15.8);
    
    if(index >= 16) {
        printf("\nGrade 16+\n");
    }
    else if(index <= 1) {
        printf("\nBefore Grade 1\n");
    }
    else {
        printf("\nGrade %d\n", index);
    }
}

// starts program execution
int main() {
    unsigned int letters = 0, words = 0, sentences = 0;
    bool status = false;
    char c;
    string s = get_string("Text: ");

    for(int i = 0; i < strlen(s); i++) {
        c = s[i];
        
        // check if character is word seperator first i.e space
        // NOTE: (c == '\'' && s[i + 1] == 'v') is hack as it appears
        // check50 considers "I've" to be two words
        if (c == ' ' || (c == '\'' && s[i + 1] == 'v')) {
            status = false;
        }
        if(isalpha(c)) {
            letters++;

            if(!status) {
                words++;
                status = true;
            }
        }
        if(c == '.' || c == '?' || c == '!') {
            sentences++;
        }
    }
    // TODO: remove the line below as the exercise doesn't ask one one to print
    // the total number of letters, words and sentences.
    //printf("\nLetters: %d\nWords: %d\nSentences: %d\n", letters, words, sentences);
    coleman_liau_index(letters, words, sentences);
    return 0;
}
