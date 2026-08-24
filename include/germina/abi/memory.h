#ifndef GERMINA_ABI_MEMORY_H
#define GERMINA_ABI_MEMORY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (*germina_allocate_fn)(
    void* user_data,
    size_t size,
    size_t alignment
);

typedef void (*germina_deallocate_fn)(
    void* user_data,
    void* ptr,
    size_t size,
    size_t alignment
);

typedef struct germina_allocator {
    void* user_data;

    germina_allocate_fn allocate;
    germina_deallocate_fn deallocate;
} germina_allocator;

#ifdef __cplusplus
}
#endif

#endif