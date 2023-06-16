# 递归获取目录下所有的 cpp 文件
file(GLOB_RECURSE LINKLIBRARY_SRC_FILES ./*.cpp)

set(LIBRARY_debug ${PROJECT_BINARY_DIR}/bin/Debug/Library)
set(LIBRARY_release ${PROJECT_BINARY_DIR}/bin/Release/Library)

include_directories(${PROJECT_SOURCE_DIR}/Library)

add_executable(LinkLibrary ${LINKLIBRARY_SRC_FILES})

target_link_libraries(LinkLibrary PRIVATE
			debug ${LIBRARY_debug}
			optimized ${LIBRARY_release})
