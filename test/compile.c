#include <germina/abi/version.h>
#include <germina/version.h>

#include <stdint.h>

int main(void) {
    GVersion version = {
        .major = GERMINA_ABI_VERSION_MAJOR, .minor = GERMINA_ABI_VERSION_MINOR, .patch = GERMINA_ABI_VERSION_PATCH, .revision = GERMINA_ABI_VERSION_REVISION};

    if (version.major != GERMINA_ABI_VERSION_MAJOR)
        return 1;

    if (version.minor != GERMINA_ABI_VERSION_MINOR)
        return 1;

    if (version.patch != GERMINA_ABI_VERSION_PATCH)
        return 1;

    if (version.revision != GERMINA_ABI_VERSION_REVISION)
        return 1;

    return 0;
}