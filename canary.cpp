#include "canary.h"

#include "assert.h"

canary_t left_canary(const void *ptr)
{
    assert(ptr != NULL);

    return *(canary_t *)(((char *) ptr) - CANARY_SIZE);
}

canary_t right_canary(const void *ptr, size_t size)
{
    assert(ptr != NULL);

    return *(canary_t *)(((char *) ptr) + size);
}