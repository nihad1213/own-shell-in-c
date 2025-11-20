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
ssize_t getLine(char **line, size_t *n, FILE *stream) {
    if (!line || !n || !stream) return ERROR;

    if (*line == NULL || *n == 0) {
        *n = BUFSIZE;
        *line = malloc(*n);
        if (!*line) 
            return ERROR;
        
    }

    if (fgets(*line, *n, stream) == NULL)
        return ERROR;
    
    return strlen(*line);
}


