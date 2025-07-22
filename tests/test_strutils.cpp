#include <gtest/gtest.h> // 包含 Google Test 的主头文件
#include "my_pro_project/strutils.hpp" // 包含我们要测试的库的头文件

// TEST 是一个宏，用于定义一个测试用例。
// 第一个参数是测试套件的名称 (TestSuiteName)。
// 第二个参数是测试用例的名称 (TestName)。
TEST(StrUtilsTest, ToUpperCase) {
    // EXPECT_EQ 是一个断言，它检查两个值是否相等。
    // 如果不相等，测试将失败，但程序会继续执行。
    EXPECT_EQ(strutils::toUpperCase("hello"), "HELLO");
    EXPECT_EQ(strutils::toUpperCase("World"), "WORLD");
    EXPECT_EQ(strutils::toUpperCase("C++"), "C++");
}

TEST(StrUtilsTest, ToLowerCase) {
    EXPECT_EQ(strutils::toLowerCase("HELLO"), "hello");
    EXPECT_EQ(strutils::toLowerCase("World"), "world");
    EXPECT_EQ(strutils::toLowerCase("C++"), "c++");
}

// 当你运行这个 "tests" 可执行文件时，gtest 会自动找到并执行
// 所有用 TEST 宏定义的测试用例，并报告结果。
