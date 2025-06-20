#include <stdio.h>

#include "pair.h"

pair_t pair_new(int x, int y) {
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;
    return p;
}

int pair_first(pair_t p) {
    return p.values[0];
}

int pair_second(pair_t p) {
    return p.values[1];
}

pair_t pair_swapped(pair_t p) {
    pair_t swapped;
    swapped.values[0] = p.values[1];
    swapped.values[1] = p.values[0];
    return swapped;
}

void pair_destroy(pair_t p) {
    return p;
    // In this case, no dynamic memory allocation is used,
    // so there's nothing to free. This function is a placeholder
    // for future extensions where dynamic memory might be involved.
}