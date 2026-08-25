#ifndef GERMINA_ABI_RUNTIME_H
#define GERMINA_ABI_RUNTIME_H

#include <stddef.h>
#include <germina/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GRuntimeHandle {
    GRuntimeIndex index;
    uint8_t sign[7];
} GRuntimeHandle;

GRuntimeHandle germina_runtime_create();
void germina_runtime_destroy(GRuntimeHandle runtime);

GHandle germina_alloc(GRuntimeHandle runtime, size_t size, size_t alignment);
void germina_free(GRuntimeHandle runtime, GHandle handle);

#ifdef __cplusplus
}
#endif

#endif