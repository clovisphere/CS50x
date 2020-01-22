# CS50x

This repo contains my solution to pset from the popular Harvard's [CS50 course](https://online-learning.harvard.edu/course/cs50-introduction-computer-science).

##### Prerequisite

I will be using [libcs50](https://github.com/cs50/libcs50/releases) locally, follow this [guide](https://cs50.readthedocs.io/library/c/) to install it. Another alternative would be to use the [CS50's sandbox](https://cs50.readthedocs.io/sandbox/).

##### How to run code

There's a sample [Makefile](./Makefile) that you can use (if you want).

```console
$ make TARGET
$ ./TARGET
```

or you be old school and write commands to compile and run the program.

```console
$ clang -std=c11 -Wall -lcs50 -o TARGET TARGET.c
$ ./TARGET
```

(where **TARGET** is the name of your C file i.e if you have a file named *hello.c*, **TARGET** is *hello*)
