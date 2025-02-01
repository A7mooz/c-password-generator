#include <stdlib.h>
#include <stdio.h>

#include "password.h"
#include "random.h"
#include "characters.h"

int get_input(Password *password) {
    int len;
    printf("Enter the length of the password: ");
    scanf("%d", &len);
    puts("");

    if (len < 0 || len > __INT_MAX__) {
        fprintf(stderr, "Invalid length");
        return -1;
    }

    int parsed;
    printf("Enter the type of the password:\n"
           "Lowercase letters: %i\n"
           "Uppercase letters: %i\n"
           "Numbers: %i\n"
           "Symbols: %i\n"
           "Note: add them together if you want multiple types (exp. Lower and Upper = %i)\n"
           "Input: "
          , TYPE_LOWER, TYPE_UPPER, TYPE_NUMBS, TYPE_SYMBS, TYPE_LOWER + TYPE_UPPER);
    scanf("%i", &parsed);
    
    if (parsed < TYPE_LOWER) {
        fprintf(stderr, "Number is too small.");
        return -1;
    }

    if (parsed > (TYPE_LOWER | TYPE_UPPER | TYPE_NUMBS | TYPE_SYMBS)) {
        fprintf(stderr, "Number is too big.");
        return -1;
    }

    type_t t = (type_t)parsed;

    password->length = len;
    password->type = t;

    return 1;
}

struct Arr
{
    void const *arr;
    size_t len;
};


char generate_char(type_t type) {
    struct Arr arr[4];
    int len = 0;

    int r;

    if (type & TYPE_LOWER) {
        arr[len++] = (struct Arr){LOWERCASE, sizeof(LOWERCASE)};
    }

    if (type & TYPE_UPPER) {
        arr[len++] = (struct Arr){UPPERCASE, sizeof(UPPERCASE)};
    }

    if (type & TYPE_NUMBS) {
        arr[len++] = (struct Arr){NUMBERS, sizeof(NUMBERS)};
    }

    if (type & TYPE_SYMBS) {
        arr[len++] = (struct Arr){SYMBOLS, sizeof(SYMBOLS)};
    }

    r = random_range(0, len-1);

    if (r == -1) return -1;

    int i = r;

    struct Arr e = arr[i];

    r = random_range(0, e.len-1);

    if (r == -1) return -1;

    char ch = ((char*)e.arr)[r];

    return ch;
}

int generate_password(Password *password) {
    char *buff = (char*)malloc(password->length + 1);
    if (buff == NULL) {
        fprintf(stderr, "Failed to allocate memory.");
        return -1;
    }

    size_t i = 0;
    for (; i < password->length; ++i) {
        buff[i] = generate_char(password->type);
    }

    buff[i] = '\0';

    password->buff = buff;

    return 1;
}

void destroy_password(Password *password) {
    free(password->buff);
    password->buff = NULL;
    password->length = 0;
    password->type = 0;
}
