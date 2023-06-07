project(HELLO_CMAKE)

message(status "This is BINARY dir " ${HELLO_CMAKE_BINARY_DIR})

message(status "This is SOURCE dir "${HELLO_CMAKE_SOURCE_DIR})

add_executable(hello HELLO_CMAKE/HELLO_CMAKE.cpp)