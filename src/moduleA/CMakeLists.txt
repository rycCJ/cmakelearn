# --- 创建静态库 ---
# 创建一个名为 strutils 的静态库 (STATIC)
# 源文件是当前目录下的 strutils.cpp
add_library(strutils STATIC 
    strutils.cpp
)

# --- 指定头文件目录 ---
# 告诉编译器去项目的 include 目录寻找头文件
# PUBLIC 意味着链接到此库的其他目标也会自动获得此路径
target_include_directories(strutils PUBLIC 
    "${CMAKE_SOURCE_DIR}/include"
)

# --- [新增] 安装规则 for strutils 库和头文件 ---
# 安装库文件
# ARCHIVE DESTINATION lib: 将静态库文件 (ARCHIVE) 安装到 CMAKE_INSTALL_PREFIX 下的 "lib" 目录中。
install(TARGETS strutils ARCHIVE DESTINATION lib)

# 安装公共头文件
# FILES: 指定要安装的文件。
# DESTINATION include/strutils: 将这些文件安装到 CMAKE_INSTALL_PREFIX 下的 "include/strutils" 目录中。
install(FILES "${CMAKE_SOURCE_DIR}/include/my_pro_project/strutils.hpp"
        DESTINATION include/strutils
)