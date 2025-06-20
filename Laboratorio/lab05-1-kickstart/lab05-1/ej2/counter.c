#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    if (c != NULL) {
        c->count = 0;
    }
    return c;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    return c->count == 0;
}

void counter_dec(counter c) {
    c->count--;
}

counter counter_copy(counter c) {
    counter new_counter = malloc(sizeof(struct _counter));
    new_counter->count = c->count;
    return new_counter;
}

void counter_destroy(counter c) {
    free(c);
    // No additional memory to free, as we only allocated memory for the counter struct.
}
