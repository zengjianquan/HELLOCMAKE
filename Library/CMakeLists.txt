#set(LIBRARY_SRC Library.cpp)

# 递归获取目录下所有的 cpp 文件
file(GLOB_RECURSE LIBRARY_SRC_FILES ./*.cpp)

# 递归获取目录下所有的h文件
file(GLOB_RECURSE LIBRARY_HEADER_FILES ./*.h)

#生成动态库和静态库
add_library(Library_shared SHARED ${LIBRARY_SRC_FILES})
#add_library(Library_static STATIC ${LIBRARY_SRC_FILES})

#将动态库和静态库的名字设置为 Library
set_target_properties(Library_shared PROPERTIES OUTPUT_NAME "Library")
# #set_target_properties(Library_static PROPERTIES OUTPUT_NAME "Library")

#设置动态库版本
set_target_properties(Library_shared PROPERTIES VERSION 1.0 SOVERSION 1)