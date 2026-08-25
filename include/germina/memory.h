#ifndef GERMINA_ABI_MEMORY_H
#define GERMINA_ABI_MEMORY_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*GerminaAllocate)(void *user_data, size_t size, size_t alignment);

typedef void (*GerminaDeallocate)(void *user_data, void *ptr, size_t size, size_t alignment);

typedef struct GerminaAllocator {
    void *user_data;

    GerminaAllocate allocate;
    GerminaDeallocate deallocate;
} GerminaAllocator;

void *germina_allocate(size_t size, size_t alignment);
void germina_deallocate(void *ptr, size_t size, size_t alignment);

#ifdef __cplusplus
}
#endif

#endif