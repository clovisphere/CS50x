#
# This is a sample Makefile.
#

# compiler to use
CC= clang
# C flags
CFLAGS=-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
# additional libs
LDLIBS=-lcs50 -lm
# dependencied if any..
DEPS=
# replace the below with your file name (without the extension i.e hello instead of hello.c)
TARGET=hello
# Object file(s)
OBJ=$(TARGET:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDLIBS))

# default
$(TARGET): $(TARGET).c
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

.PHONY: clean
	
clean:
	rm -rf core $(TARGET) *.o *.dSYM


