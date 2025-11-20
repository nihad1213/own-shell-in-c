#include "include/custom_io.h"

int main() {
    char input[BUFSIZE];

    while (1) {
        printSingleCharacter('$');
        int len = getLine(input, BUFSIZE);

        if (len == -1) {
            printError("EOF received. Exiting...\n");
            break;
        }

        if (len == 0) continue;

        // Commands will start in here

    }
    

    return 0;
}