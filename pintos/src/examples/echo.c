#include <stdio.h>
#include<syscall.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Loop through each argument (skip argv[0], the program name)
    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];

        for (int j = 0; arg[j] != '\0'; j++) {
            if (arg[j] == '\\') {
                // Handle escape sequences
                j++;
                switch (arg[j]) {
                    case 'n': putchar('\n'); break;
                    case 't': putchar('\t'); break;
                    case 'r': putchar('\r'); break;
                    case '\\': putchar('\\'); break;
                    case '"': putchar('"'); break;
                    case '\0': putchar('\\'); j--; break; // trailing backslash
                    default: putchar('\\'); putchar(arg[j]); break; // unknown escape
                }
            } else {
                putchar(arg[j]);
            }
        }

        if (i < argc - 1) putchar(' '); // space between arguments
    }

    putchar('\n'); // final newline
    return 0; // EXIT_SUCCESS may not be defined in Pintos
}
