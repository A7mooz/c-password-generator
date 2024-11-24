#include <stdio.h>
#include <stdlib.h>

#include "password.h"

int main() {
    Password pass;

    if (get_input(&pass) == -1) {
        return EXIT_FAILURE;
    }
    
    if (generate_password(&pass) == -1) {
        return EXIT_FAILURE;
    }

    printf("\nPassword: %s\n", pass.buff);

    destroy_password(&pass);
    
    return EXIT_SUCCESS;
}