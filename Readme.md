To install the dependencies, follow the instructions to use vckpkg to install raylib

To build, use these commands:

```cmake
mkdir build # Create a build directory
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=E:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build . # Build the project
```