#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

pair_t pair_new(int x, int y) {
    pair_t p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p) {
    return p->fst;
}

int pair_second(pair_t p) {
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    pair_t swapped = malloc(sizeof(struct s_pair_t));
    swapped->fst = p->snd;
    swapped->snd = p->fst;
    return swapped;
}

void pair_destroy(pair_t p) {
    free (p);
    // In this case, no dynamic memory allocation is used,
    // so there's nothing to free. This function is a placeholder
    // for future extensions where dynamic memory might be involved.
}