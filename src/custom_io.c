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
    if (!str) {
        return ERROR;
    }

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

}