#ifndef GERMINA_ABI_TYPES_H
#define GERMINA_ABI_TYPES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t germina_type_id;
typedef uint32_t germina_flags;
typedef uint64_t germina_size;
typedef uint64_t germina_handle;

typedef struct germina_status {
    int32_t code;
} germina_status;

#ifdef __cplusplus
}
#endif

#endif