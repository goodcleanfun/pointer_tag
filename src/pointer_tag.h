#ifndef POINTER_TAG_H
#define POINTER_TAG_H

#include <stdint.h>

void *pointer_tag(void *value, uintptr_t tag) {
    return (void *)((uintptr_t)(value) | (tag));
}

bool pointer_is_tagged(void *value, uintptr_t tag) {
    return ((uintptr_t)(value) & (tag)) != 0;
}

void *pointer_untag(void *value, uintptr_t tag) {
    return (void *)((uintptr_t)(value) & ~tag);
}

#endif