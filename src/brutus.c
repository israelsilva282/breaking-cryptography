#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE                                        \
    "Script based encryption and decryption tool.\n" \
    "The result is printed to standard output.\n\n"  \
    "%s <file>\n"                                    \
    "  <file> - File to decrypt.\n"

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        char *file = argv[1];
        char command[100];
        for (int i = 0; i < 257; i++)
        {
            sprintf(command, "./caesar -%d %s > out.out", i, file);
            system(command);
            sprintf(command, "echo 'key: %d' && file out.out", i);
            system(command);
        }
    }
    else
    {
        printf(USAGE, argv[0]);
    }
    return 0;
}