#include <unistd.h>
#include "include/custom_io.h"

/**
 * printSingleCharacter - Print character
 * @chr: character
 * Return: 
 */
int printSingleCharacter(char chr) {
    return write(1, &chr, 1);
}

