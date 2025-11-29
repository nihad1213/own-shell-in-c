#include "include/custom_io.h"
#include "include/commands.h"
#include <string.h>

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    char input[BUFSIZE];
    char cmd[BUFSIZE];
    char arg[BUFSIZE];

    while (1) {
        printString("$ ");
        int len = getLine(input, BUFSIZE);

        if (len == -1) {
            printError("EOF received. Exiting...\n");
            break;
        }

        if (len == 0) continue;

        // reset buffers
        cmd[0] = '\0';
        arg[0] = '\0';

        sscanf(input, "%s %s", cmd, arg);

        if (cmpString(cmd, "exit") == 0) {
            if (handleExitCommand())
                break;
        }
        else if (cmpString(cmd, "cd") == 0) {
            handleCdCommand(arg);
        }
        else if (cmpString(cmd, "mkdir") == 0) {
            handleMkdirCommand(arg);
        }
        else if (cmpString(cmd, "ls") == 0) {
            handleLsCommand(arg[0] ? arg : NULL);
        }
        else if (cmpString(cmd, "echo") == 0) {
            handleEchoCommand(arg[0] ? arg : NULL);
        }
        else {
            printError("Unknown command\n");
        }
    }

    return 0;
}
