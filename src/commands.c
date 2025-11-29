#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
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

/**
 * @brief Changes the current working directory.
 * @param path Directory to switch into.
 */
int handleCdCommand(const char *path) {
    if (!path || chdir(path) != 0) {
        printError("cd: failed to change directory\n");
        return -1;
    }
    return 0;
}

/**
 * @brief Creates a directory with default permissions.
 * @param dirname Name of directory to create.
 */
int handleMkdirCommand(const char *dirname) {
    if (!dirname) {
        printError("mkdir: missing directory name\n");
        return -1;
    }

    if (mkdir(dirname, 0755) != 0) {
        printError("mkdir: failed to create directory\n");
        return -1;
    }

    printSuccess("Directory created successfully\n");
    return 0;
}

/**
 * @brief Lists files in given directory (or current directory).
 * @param path Directory path or NULL for current directory.
 */
int handleLsCommand(const char *path) {
    const char *dirPath = (path ? path : ".");

    DIR *dir = opendir(dirPath);
    if (!dir) {
        printError("ls: cannot open directory\n");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printString(entry->d_name);
        printString("  ");
    }
    printString("\n");

    closedir(dir);
    return 0;
}

/**
 * @brief Prints text to output.
 * @param text Text after "echo".
 */
int handleEchoCommand(const char *text) {
    if (!text) {
        printString("\n");
        return 0;
    }

    printString(text);
    printString("\n");
    return 0;
}