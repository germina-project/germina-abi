# Germina ABI

Germina ABI defines the stable C-level contracts shared between
Germina components.

It does not implement memory management, scheduling, execution,
or compiler functionality.

## Consumers

- Germina Compiler
- Germina Core
- Germina Runtime

## Design goals

- C-compatible
- stable
- implementation-independent
- platform-aware where required
- usable without the compiler
- usable without the runtime
- usable without the core