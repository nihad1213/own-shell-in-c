#include "include/custom_io.h"
#include "include/commands.h"

int main() {
    char input[BUFSIZE];

    while (1) {
        printString("$ ");
        int len = getLine(input, BUFSIZE);

        if (len == -1) {
            printError("EOF received. Exiting...\n");
            break;
        }

        if (len == 0) continue;

        if (cmpString(input, "exit") == 0) {
            if (handle_exit_command())
                break;
        }

    }
    

    return 0;
}