#include <unistd.h>
#include "include/custom_io.h"

/**
 * printSingleCharacter - Print character
 * @chr: character
 * Return: Only one character
 */
int printSingleCharacter(char chr) {
    return write(1, &chr, 1);
}

/**
 * printString - Print string
 * @str: string
 * Return: string
 */
int printString(const char *str) {
    if (!str) return ERROR;

    for (int length = 0; str[length] != '\0'; length++) {
        printSingleCharacter(str[length]);
    }

    return SUCCESS;
}

/**
 * printError - Print error message
 * @str: string
 * Return: string
 */
int printError(const char *str) {
    if (!str) return ERROR;

    printString("\033[1;31m");
    printString(str);
    printString("\033[0m\n");

    return SUCCESS;
}

/**
 * printWarning - Print warning message
 * @str: string
 * Return: string
 */
int printWarning(const char *str) {
    if (!str) return ERROR;
    
    printString("\033[1;33m");
    printString(str);
    printString("\033[0m\n");

    return SUCCESS;
}

/**
 * printWarning - Print success message
 * @str: string
 * Return: string
 */
int printSuccess(const char *str) {
    if (!str) return ERROR;

    printString("\033[1;32m");
    printString(str);
    printString("\033[0m\n");

    return SUCCESS;
}

/**
 * getLine - Get inputs from buffer
 * @line: pointer to buffer pointer
 * @n: pointer to buffer size
 * @stream: input stream
 * return: number of characters read or -1 on failure/EOF
 */
int getLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) == NULL) return ERROR;

    int len = 0;

    while (buffer[len] != '\0') {
        if (buffer[len] == '\n') {
            buffer[len] = '\0';
            break;
        }

        len++;
    }

    return len;
}

/**
 * cmpString - Compare 2 string
 * @str1: first string
 * @str2: second string
 * return: 0 if both string equal,
 *         negative value if str1 < str2,
 *         positive value if str1 > str2
 */
int cmpString(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return (unsigned char)*str1 - (unsigned char)*str2;
}


