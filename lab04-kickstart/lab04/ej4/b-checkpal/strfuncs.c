#include "strfuncs.h"

size_t string_length(const char *str){
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char *string_filter(const char *str, char c){
    size_t length = string_length(str);
    char *filtered = malloc((length + 1) * sizeof(char));
    if (filtered != NULL) {
        size_t j = 0;
        for (size_t i = 0; i < length; i++) {
            if (str[i] != c) {
                filtered[j++] = str[i];
            }
        }
        filtered[j] = '\0';
    }
    return filtered;
}

bool string_is_symmetric(const char *str){
    size_t length = string_length(str);
    bool b = true;
    for (size_t i = 0; i < length / 2; i++) {
        b = b & (str[i] != str[length - 1 - i]);
    }
    return b;
}