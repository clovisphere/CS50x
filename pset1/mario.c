#include <stdio.h>
#include<cs50.h>

// define LOWER and UPPER LIMIT constants
#define LOWER_LIMIT 1
#define UPPER LIMIT 8

/**
 * builds the pyramid with given height.
 *
 * @height: the height of the pyramid
 */
void build_pyramid(int height) {
    int i, j;
    int space = height - 1;

    for (i = 0; i < height; i++) { // outer loop
        if (space > 0) printf("%*c", space, ' ');
        // inner loop that prints the bricks
        for (j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
        space -= 1;
    } // end outer loop
}

// starts program execution
int main() {
    puts("Let's build a pyramid..\n");
    
    int height;
    
    do {
        height = get_int("Height (value should be between 1 and 8): ");
    } while (height < 1 || height > 8); 
    // the magic starts here:-)
    build_pyramid(height);
    return 0;
}
