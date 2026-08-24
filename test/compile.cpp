#include <germina/abi/version.h>
#include <germina/version.h>

int main() {
    GVersion version{GERMINA_ABI_VERSION_MAJOR, GERMINA_ABI_VERSION_MINOR, GERMINA_ABI_VERSION_PATCH, GERMINA_ABI_VERSION_REVISION};

    return version.major == GERMINA_ABI_VERSION_MAJOR ? 0 : 1;
}