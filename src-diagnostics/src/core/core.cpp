/**
 *  @Copyright Alexander Williams-Letondre 2024-12-28
 */

#include <stdio.h>
#include "core.hpp"

Example::Example() {
    printf("This is a basic example getting started up\n");
}

void Example::print() {
    printf("Printing something simple...\n");
}

int Example::returnNumber() {
    return 1;
}
