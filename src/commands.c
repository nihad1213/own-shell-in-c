#include <unistd.h>
#include "include/custom_io.h"
#include "include/commands.h"

/**
 * @brief Implements the 'exit' command behavior.
 *
 * Prints a message indicating that the program is exiting.
 * Called from main when the user types 'exit'.
 *
 * @return int - Always returns 1 to indicate the shell should exit.
 */
int handleExitCommand(void) {
    printSuccess("Exiting program...\n");
    return 1;
}
