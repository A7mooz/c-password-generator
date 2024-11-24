#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <openssl/rand.h>

int random_range(int min, int max) {
    uint32_t random_value;
    int range = max - min + 1;

    if (range <= 0) return -1; // Invalid range

    // Loop to avoid modulo bias
    do {
        if (RAND_bytes((unsigned char *)&random_value, sizeof(random_value)) != 1) {
            fprintf(stderr, "RAND_bytes failed\n");
            return -1; // Error occurred
        }
    } while (random_value >= (UINT32_MAX / range) * range);

    return min + (random_value % range);
}