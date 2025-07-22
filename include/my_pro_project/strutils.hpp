#pragma once // 这是一个防止头文件被重复包含的常用指令

#include <string> // 我们需要用到 std::string

namespace strutils {

/**
 * @brief 将字符串转换为全大写
 * @param str 输入的字符串
 * @return 全大写的字符串
 */
std::string toUpperCase(const std::string& str);

/**
 * @brief 将字符串转换为全小写
 * @param str 输入的字符串
 * @return 全小写的字符串
 */
std::string toLowerCase(const std::string& str);

} // namespace strutils
