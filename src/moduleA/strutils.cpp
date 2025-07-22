#include "my_pro_project/strutils.hpp" // 包含我们自己的头文件
#include <algorithm>
#include <cctype>

namespace strutils {

std::string toUpperCase(const std::string& str) {
    std::string upper_str = str;
    std::transform(upper_str.begin(), upper_str.end(), upper_str.begin(), ::toupper);
    return upper_str;
}

std::string toLowerCase(const std::string& str) {
    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

} // namespace strutils
