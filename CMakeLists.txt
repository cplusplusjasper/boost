cmake_minimum_required(VERSION 2.8.12)
project(BOOSTMAIN)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
   		"${CMAKE_BINARY_DIR}/conan.cmake"
		TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)


conan_cmake_run(CONANFILE conanfile.py
	BASIC_SETUP CMAKE_TARGETS
	BUILD missing)

add_executable(bst main.cpp)
target_link_libraries(bst PUBLIC CONAN_PKG::boost)
