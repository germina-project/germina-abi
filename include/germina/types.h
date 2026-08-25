#ifndef GERMINA_ABI_TYPES_H
#define GERMINA_ABI_TYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// GHandle layout:
// 63..16: payload (48 bits stable)
// 15..6: context (10 bits versioned)
// 5..0: owner runtime ID (6 bits versioned)
typedef struct GHandle {
    uint64_t handle;
} GHandle;

_Static_assert(sizeof(GHandle) == sizeof(uint64_t), "GHandle must be 64 bits");

#define GHANDLE_PAYLOAD_BITS 48u
#define GHANDLE_PAYLOAD_SHIFT 16u
#define GHANDLE_PAYLOAD_VALUE_MASK ((UINT64_C(1) << GHANDLE_PAYLOAD_BITS) - UINT64_C(1))
#define GHANDLE_PAYLOAD_MASK (GHANDLE_PAYLOAD_VALUE_MASK << GHANDLE_PAYLOAD_SHIFT)

#define GHANDLE_SERVICE_BITS 16u
#define GHANDLE_SERVICE_SHIFT 0u
#define GHANDLE_SERVICE_MASK ((UINT64_C(1) << GHANDLE_SERVICE_BITS) - UINT64_C(1))

_Static_assert(GHANDLE_PAYLOAD_BITS + GHANDLE_SERVICE_BITS == UINT64_C(sizeof(GHandle) * 8), "Payload + Service bit layout must equal GHandle bits");

typedef uint8_t GRuntimeIndex;

#define GRUNTIME_INDEX_BITS 6u
#define GRUNTIME_INDEX_SHIFT 0u
#define GRUNTIME_INDEX_VALUE_MASK ((UINT64_C(1) << GRUNTIME_INDEX_BITS) - UINT64_C(1))
#define GRUNTIME_INDEX_MASK (GRUNTIME_INDEX_VALUE_MASK << GRUNTIME_INDEX_SHIFT)
#define GRUNTIME_INDEX_MAX GRUNTIME_INDEX_VALUE_MASK
#define GRUNTIME_INDEX_INVALID UINT8_MAX

#define GRUNTIME_CONTEXT_BITS 10u
#define GRUNTIME_CONTEXT_SHIFT 6u
#define GRUNTIME_CONTEXT_VALUE_MASK ((UINT64_C(1) << GRUNTIME_CONTEXT_BITS) - UINT64_C(1))
#define GRUNTIME_CONTEXT_MASK (GRUNTIME_CONTEXT_VALUE_MASK << GRUNTIME_CONTEXT_SHIFT)

_Static_assert(GRUNTIME_INDEX_BITS + GRUNTIME_CONTEXT_BITS == GHANDLE_SERVICE_BITS, "GHandle service layout not valid");

#define GHANDLE_GET_RUNTIME_INDEX(handle) ((GRuntimeIndex)(((handle).handle & GRUNTIME_INDEX_MASK) >> GRUNTIME_INDEX_SHIFT))
#define GHANDLE_GET_RUNTIME_CONTEXT(handle) ((uint16_t)(((handle).handle & GRUNTIME_CONTEXT_MASK) >> GRUNTIME_CONTEXT_SHIFT))
#define GHANDLE_GET_PAYLOAD(handle) (((handle).handle & GHANDLE_PAYLOAD_MASK) >> GHANDLE_PAYLOAD_SHIFT)
#define GHANDLE_MAKE(runtime_id, context, payload)                                                           \
    ((GHandle){.handle = ((((uint64_t)(payload)) & GHANDLE_PAYLOAD_VALUE_MASK) << GHANDLE_PAYLOAD_SHIFT) |   \
                         ((((uint64_t)(context)) & GRUNTIME_CONTEXT_VALUE_MASK) << GRUNTIME_CONTEXT_SHIFT) | \
                         ((((uint64_t)(runtime_id)) & GRUNTIME_INDEX_VALUE_MASK) << GRUNTIME_INDEX_SHIFT)})

#ifdef __cplusplus
}
#endif

#endif