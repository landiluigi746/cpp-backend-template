# cpp-backend-template

This is a small C++ backend template that uses CMake as build system, vcpkg as dependency manager, Crow as web framework and features Docker and Docker compose support.
It also provides already defined Microsoft-like formatting options with clang-format.

## Dependencies

To use this template you need:

- a C++ compiler (C++23 is used by default, edit [CMake config](CMakeLists.txt) if you want to use a different standard)
- CMake (3.14.0 >=)
- vcpkg
- Docker and Docker compose
- clang-format (optional, used to format code)

## Getting started

To get started with this template, either clone it or generate a new repo from this one.
Then, create a ```.env``` file with env variables (see an example configuration [here](.env.sample)).

To prepare the local environment, run the following command:
```bash
make devenv
```

Then, to start all containers with docker compose:
```bash
make up
```

To stop all containers with docker compose:
```bash
make down
```

To see logs from the container:
```bash
make logs
```
