# Play with C idioms and tools

## Building

```sh
mkdir build
cd build
cmake ..
make
```

## Formatting code

```sh
find src -name '*.c' -o -name '*.h' -exec clang-format -i {} \;
```