# CMake 最低版本要求。这是每个 CMakeLists.txt 的标准开头。
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和版本。
project(cmakelearn)

# --- 全局配置 ---
# 设置 C++ 标准为 C++17。
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- [新增] 安装路径配置 ---
# 定义安装的根目录。这里我们设置为项目根目录下的 "install" 文件夹。
# ${CMAKE_SOURCE_DIR} 指向项目的根目录 (StrUtils/)。
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install")

# --- 输出目录配置 ---
# 将最终生成的可执行文件 (.exe) 统一输出到 build/bin 目录。
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# 将最终生成的库文件 (.a, .lib) 统一输出到 build/lib 目录。
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# --- 单元测试配置 ---
# 包含 CTest 模块以支持测试。
enable_testing()

# 将第三方库目录添加到 CMake 的搜索路径中。
# 这让 CMake 知道可以去 vendor/googletest 里找 gtest 的 CMakeLists.txt。
add_subdirectory(third_party/googletest)

# --- 子目录处理 ---
# 告诉 CMake 去处理 src 和 tests 目录下的 CMakeLists.txt 文件。
# CMake 会先进入 src 目录，执行那里的指令，然后再进入 tests 目录。
# --- 这是我们添加的诊断信息 ---
message(STATUS "==> 准备进入 src 目录...")
add_subdirectory(src)

message(STATUS "==> 准备进入 tests 目录...")
add_subdirectory(tests)