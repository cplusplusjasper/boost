# Boost Example

Example of program options using Boost libraries installed with Conan C/C++ package manager.

Mostly used to run the conan.io getting started: https://docs.conan.io/en/latest/getting_started.html

## Compiling steps

1. Configure the CMake project (Using MSVC 16 in this example):

    ```
    $ cmake .. -G "Visual Studio 16"
    ```

2. Build it:

    ```
    $ cmake --build . --config Release
    ```

3. Run the application:

    ```
    $ .\bin\bst.exe
    ```
