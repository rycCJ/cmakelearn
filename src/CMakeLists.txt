# ====================================================================
# src 目录下的主 CMakeLists.txt
# 它的职责是包含所有库模块，并定义主应用程序。
# ====================================================================

# --- 1. 包含子目录模块 ---
# 添加 moduleA 子目录，CMake 会去处理 src/moduleA/CMakeLists.txt
# 这会定义 "strutils" 这个库目标。
add_subdirectory(moduleA)


# --- 2. 定义主应用程序 ---
# add_executable 命令用于创建一个可执行程序。
# StrUtilsApp 是我们给程序起的名字。
# main.cpp 是编译这个程序所需的源文件，它就在当前目录下。
add_executable(StrUtilsApp 
    main.cpp
)

# --- 3. 链接库 ---
# target_link_libraries 命令将库链接到可执行文件上。
# 这句话的意思是：“在编译 StrUtilsApp 时，请把 strutils 库链接进来。”
target_link_libraries(StrUtilsApp 
    strutils
)

# --- [新增] 安装规则 for StrUtilsApp ---
# install 命令告诉 CMake 在执行 "install" 步骤时要做什么。
# TARGETS StrUtilsApp: 指定要安装的目标。
# RUNTIME DESTINATION bin: 将可执行文件 (RUNTIME) 安装到 CMAKE_INSTALL_PREFIX 下的 "bin" 目录中。
install(TARGETS StrUtilsApp RUNTIME DESTINATION bin)