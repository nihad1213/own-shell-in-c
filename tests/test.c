#include "custom_io.h"

int main(void) {

    int result = cmpString("test", "test");
    printf("%d\n", result);
    printSingleCharacter('A');
    // printSingleCharacter('');
    printString("\nHello World!\n");
    printError("This is error message");
    printWarning("This is warning message");
    printSuccess("This is success message");
    // printString("");
    return 0;
}