#include<stdio.h>
#include<cs50.h>

// starts program execution
int main() {
    string name = get_string("What is your name?: "); // get user's name
    printf("Hello, %s\n", name);

    return 0;
}
