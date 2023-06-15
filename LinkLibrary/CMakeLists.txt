# 递归获取目录下所有的 cpp 文件
file(GLOB_RECURSE LINKLIBRARY_SRC_FILES ./*.cpp)

# 递归获取目录下所有的h文件
file(GLOB_RECURSE LINKLIBRARY_HEADER_FILES ./*.h)

set(LIBRARY_debug ${PROJECT_BINARY_DIR}/bin/Debug/add)
set(LIBRARY_release ${PROJECT_BINARY_DIR}/bin/Release/add)

include_directories(${PROJECT_SOURCE_DIR}/Library)

add_executable(LinkLibrary LINKLIBRARY_SRC_FILES)

target_link_libraries(LinkLibrary PRIVATE
			debug ${LIBRARY_debug}
			optimized ${LIBRARY_release})

#安装动态库和静态库
INSTALL(TARGETS Library_shared 
    LIBRARY DESTINATION ./lib)

#安装头文件
INSTALL(FILES ${LIBRARY_HEADER_FILES}  DESTINATION ./include)

INSTALL(TARGETS LinkLibrary
    RUNTIME DESTINATION ./bin)