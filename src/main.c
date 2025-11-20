#include "include/custom_io.h"

int main() {
    char input[BUFSIZE];

    while (1) {
        printString('$ ');
        int len = getLine(input, BUFSIZE);

        if (len == -1) {
            printError("EOF received. Exiting...\n");
            break;
        }

        if (len == 0) continue;

        if (cmpString(input, "exit") == 0) {
            printSuccess("Exiting program...\n");
            break;
        }

    }
    

    return 0;
}