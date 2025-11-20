/**
 * @file custom_io.h
 * @brief This header file provides IO functions
 */
#ifndef CUSTOM_IO_H
#define CUSTOM_IO_H

#define ERROR  -1;
#define SUCCESS 0;
#define BUFSIZE 1024;

// Function definitions
int printSingleCharacter(char chr);
int printString(const char *str);
int printError(const char *str);
int printWarning(const char *str);
int printSuccess(const char *str);

#endif