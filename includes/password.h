#pragma once

#include <stdlib.h>

typedef enum {
    TYPE_LOWER = 1<<1,
    TYPE_UPPER = 1<<2,
    TYPE_NUMBS = 1<<3,
    TYPE_SYMBS = 1<<4
} type_t;

typedef struct {
    char *buff;
    size_t length;
    type_t type;
} Password;

int get_input(Password *password);

int generate_password(Password *password);

void destroy_password(Password *password);