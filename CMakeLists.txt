project(HELLO_CMAKE)

set(CMAKE_INSTALL_PREFIX ./install)
set(HEADER_LIBRARY_INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/./Library/)
# 递归获取目录下所有的h文件
file(GLOB_RECURSE LINKLIBRARY_HEADER_FILES ${HEADER_LIBRARY_INCLUDE_DIRECTORY}*.h)

add_subdirectory(HELLO_CMAKE bin)

add_subdirectory(Library bin)

add_subdirectory(LinkLibrary bin)

#添加依赖, 定义编译顺序
add_dependencies(LinkLibrary Library)

#安装动态库和静态库
INSTALL(TARGETS Library_shared 
    LIBRARY DESTINATION ./lib)

#安装头文件
#获取 Library 的头文件路径, 并将其解析为同源的相对路径
#   例如 : ${PROJECT_SOURCE_DIR}/Library /lib/a.h               
#        - ${PROJECT_BINARY_DIR}/install/include /lib/a.h
#       ${PROJECT_SOURCE_DIR}/Library   与  {PROJECT_BINARY_DIR}/install/include 同源
foreach(header ${LINKLIBRARY_HEADER_FILES})
    string(REPLACE ${HEADER_LIBRARY_INCLUDE_DIRECTORY} "" relativeHeader ${header})
    string(REGEX REPLACE "[^\\/]*\\.[^\\/\\.]*$" "" relativeHeader ${relativeHeader})
    install(FILES ${header} DESTINATION ./include/${relativeHeader})
endforeach()

#安装 LinkLibrary 作为 Example
INSTALL(TARGETS LinkLibrary
    RUNTIME DESTINATION ./bin)