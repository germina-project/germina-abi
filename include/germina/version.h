#ifndef GERMINA_ABI_VERSION_H
#define GERMINA_ABI_VERSION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GVersion {
    uint32_t major;
    uint32_t minor;
    uint32_t patch;
    uint32_t revision;
} GVersion;

GVersion germina_abi_version();
GVersion germina_core_version();
GVersion germina_runtime_version();

#ifdef __cplusplus
}
#endif

#endif