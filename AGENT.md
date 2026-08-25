# Germina ABI — Agent Instructions

## Purpose

Germina ABI defines the stable C-compatible contracts shared by the
Germina Compiler, Core and Runtime.

The ABI is a contract, not an implementation.

## Repository structure

    germina-abi/
    ├── include/
    │   └── germina/
    │       └── abi/
    ├── docs/
    ├── tests/
    └── CMakeLists.txt

## Public headers

All public ABI headers live under:

    include/germina/abi/

Headers must be valid C.

They must be usable by:

- C
- C++
- other languages capable of consuming a C ABI

## ABI design rules

1. Use C-compatible types.
2. Do not use C++ classes.
3. Do not use templates.
4. Do not use exceptions.
5. Do not expose STL types.
6. Do not expose implementation-owned structures unless their layout is
   intentionally part of the ABI.
7. Prefer opaque handles for implementation-owned objects.
8. Avoid compiler-specific types.
9. Avoid implementation-specific memory layouts unless explicitly required.
10. Keep calling conventions explicit.
11. Keep ownership rules explicit.
12. Keep alignment requirements explicit.
13. Keep lifetime requirements explicit.

## Implementation independence

ABI headers must not include:

- Host implementation headers
- Runtime implementation headers
- Compiler headers
- MLIR headers
- LLVM headers

The ABI must be usable independently from the compiler.

## Header-only model

The ABI is an interface/header-only library.

CMake exposes:

    germina::abi

No compiled ABI library is required unless a future ABI requirement explicitly
justifies one.

Do not add implementation code merely to make the ABI "complete".

## Documentation

Every public ABI concept must have corresponding documentation under:

    docs/

Documentation must explain:

- purpose
- ownership
- lifetime
- thread-safety
- error behavior
- versioning
- compatibility requirements

If a declaration changes, review the corresponding documentation.

## Compatibility

ABI compatibility is a first-class concern.

Before changing an existing public type or function:

1. Determine whether the change is ABI-breaking.
2. Check versioning requirements.
3. Check all known consumers.
4. Update documentation.
5. Add or update compatibility tests.

Prefer additive changes over destructive changes.

## Testing

The ABI must be tested independently.

At minimum, verify that public headers compile as C.

Where relevant, test:

- sizeof
- alignment
- field offsets
- opaque handles
- calling conventions
- version information
- compatibility assumptions

Tests must not require the full Germina Runtime or Compiler.

## Dependency direction

The ABI depends on nothing from Germina.

Consumers depend on the ABI:

    Compiler ──┐
    Host ──────┼──> ABI
    Runtime ───┘

Never introduce the reverse dependency.

Architectural dependencies must follow the ownership rules defined by the
root Germina `AGENTS.md`. Do not introduce dependencies for implementation
convenience.