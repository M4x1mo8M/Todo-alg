
#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t length = 0u;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

char *string_filter(const char *str, char c) {
    size_t length = string_length(str);
    char *filtered = malloc((length + 1) * sizeof(char));
    if (filtered == NULL) {
        fprintf(stderr, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    
    size_t j = 0u;
    for (size_t i = 0u; i < length; ++i) {
        if (str[i] != c) {
            filtered[j++] = str[i];
        }
    }
    filtered[j] = '\0'; // Null-terminate the filtered string
    return filtered;
}

bool string_is_symmetric(const char *str) {
    size_t length = string_length(str);
    for (size_t i = 0u; i < length / 2; ++i) {
        if (str[i] != str[length - 1 - i]) {
            return false;
        }
    }
    return true;
}