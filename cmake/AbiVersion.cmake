include(AbiCMakeVars)
set(GERMINA_ABI_VERSION_IN "${CMAKE_CURRENT_SOURCE_DIR}/cmake/template/version.h.in")
set(GERMINA_ABI_VERSION_OUT "${GERMINA_ABI_GENERATED_DIR}/include/germina/abi/version.h")

if(NOT EXISTS "${GERMINA_ABI_VERSION_IN}")
    message(FATAL_ERROR "Germina Abi: Version template missing at ${GERMINA_ABI_VERSION_IN}")
endif()

execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE GIT_RESULT
    OUTPUT_VARIABLE GERMINA_ABI_GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

if(NOT GIT_RESULT EQUAL 0)
    set(GERMINA_ABI_GIT_HASH "0")
endif()

configure_file("${GERMINA_ABI_VERSION_IN}" "${GERMINA_ABI_VERSION_OUT}" @ONLY)

message(STATUS "Germina Abi: version ${PROJECT_VERSION}+${GERMINA_ABI_GIT_HASH}")

