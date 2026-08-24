cmake_minimum_required(VERSION 4.2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(germina-abi 
    VERSION 0.1.0
    LANGUAGES C
)

include(CTest)

add_library(germina-abi INTERFACE)
include(AbiVersion)

target_include_directories(germina-abi
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${GERMINA_ABI_GENERATED_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

add_library(germina::abi ALIAS germina-abi)

if(BUILD_TESTING)
    add_executable(germina-abi-compile-test
        test/compile.c
    )
    target_link_libraries(germina-abi-compile-test
        PRIVATE
            germina::abi
    )
    add_test(
        NAME germina.abi.compile.c
        COMMAND germina-abi-compile-test
    )

    add_executable(germina-abi-compile-cxx-test
        test/compile.cpp
    )
    target_link_libraries(germina-abi-compile-cxx-test
        PRIVATE
            germina::abi
    )
    add_test(
        NAME germina.abi.compile.cpp
        COMMAND germina-abi-compile-cxx-test
    )
endif()