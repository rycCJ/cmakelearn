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
# 这是一个关键字，用来指定我们要安装这个目标的哪一种产物类型。
# ARCHIVE 特指静态库文件（在 Windows 上是 .lib 文件，在 Linux/macOS 上是 .a 文件）。
# 对应的还有 RUNTIME（用于可执行文件 .exe 或动态库 .dll）和 LIBRARY（用于共享库 .so）。


# 安装公共头文件
# FILES: 指定要安装的文件。
# DESTINATION include/strutils: 将这些文件安装到 CMAKE_INSTALL_PREFIX 下的 "include/strutils" 目录中。
install(FILES "${CMAKE_SOURCE_DIR}/include/my_pro_project/strutils.hpp"
        DESTINATION include/myproject
)

# --- 2. [新增] 定义该模块的可执行程序 ---
# 用当前目录下的 main.cpp 创建一个名为 ModuleA_App 的可执行文件
add_executable(StrUtilsaApp main.cpp)

# 告诉 CMake，ModuleA_App 需要链接 strutils 库才能运行
target_link_libraries(StrUtilsaApp strutils)

# 为这个新的可执行文件也设置安装规则
install(TARGETS StrUtilsaApp RUNTIME DESTINATION bin)