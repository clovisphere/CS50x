#include<stdio.h>
#include<cs50.h>
#include<math.h>

// starts program execution
int main() {
    int allowed_change[] = {25, 10, 5, 1}; // holds allowed $ changes
    float input;
    int cents, coins = 0;
    
    do {
        input = get_float("Change owed: "); // user input
        cents = round(input * 100);
    } while (cents < 0); // show prompt if input is negative
    
    for (int i = 0; i < 4; i++) {
        while (cents >= allowed_change[i]) { 
            coins++;
            cents -= allowed_change[i];
        }
    }
    printf("%d\n", coins);
}
