# 创建一个名为 "tests" 的可执行文件，用于运行我们的单元测试。
add_executable(tests 
    test_strutils.cpp
)

# 将我们的 strutils 库和 gtest 的库链接到测试程序上。
# gtest_main 包含了运行测试所需的 main 函数。
target_link_libraries(tests 
    strutils 
    GTest::gtest_main
)

# include(GoogleTest) 是一个 CMake 脚本，它提供了 gtest_discover_tests 命令。
include(GoogleTest)
# 这个命令会自动发现 tests 可执行文件中的所有 Google Test 测试用例，
# 并将它们注册到 CTest 中，这样我们就可以用 "ctest" 命令来运行它们。
gtest_discover_tests(tests)

# --- [新增] 安装规则 for tests ---
# 我们也可以选择将测试程序安装到 bin 目录中。
install(TARGETS tests RUNTIME DESTINATION bin)
