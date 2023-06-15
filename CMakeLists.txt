project(HELLO_CMAKE)

set(CMAKE_INSTALL_PREFIX ./install)

add_subdirectory(HELLO_CMAKE bin)

add_subdirectory(Library bin)

add_subdirectory(LinkLibrary bin)
