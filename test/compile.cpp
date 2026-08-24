#include <germina/abi/version.h>
#include <germina/abi/types.h>
#include <germina/abi/memory.h>

int main()
{
    GAbiVersion version{
        GERMINA_ABI_VERSION_MAJOR,
        GERMINA_ABI_VERSION_MINOR,
        GERMINA_ABI_VERSION_PATCH,
        GERMINA_ABI_VERSION_REVISION
    };

    return version.major == GERMINA_ABI_VERSION_MAJOR ? 0 : 1;
}