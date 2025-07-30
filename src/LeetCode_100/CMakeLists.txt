# 定义一个名为 GuessNumApp 的可执行文件
# 源文件是当前目录下的 01_guess_num.cpp
add_executable(TwoSumApp 01_twosum.cpp)

# --- 指定头文件目录 ---
# 告诉编译器去项目的 include 目录寻找头文件
# PUBLIC 意味着链接到此库的其他目标也会自动获得此路径
target_include_directories(TwoSumApp PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

# （可选）如果 guess_num.cpp 需要用到 strutils 库，
# 你可以在这里添加链接：
# target_link_libraries(GuessNumApp strutils)
install(TARGETS TwoSumApp RUNTIME DESTINATION bin)

add_executable(GroupAnagApp 02_groupAnag.cpp)
target_include_directories(GroupAnagApp PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)
install(TARGETS GroupAnagApp RUNTIME DESTINATION bin)

add_executable(IntersectingApp 160_Intersecting_Linked_Lists.cpp)
target_include_directories(IntersectingApp PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)
install(TARGETS IntersectingApp RUNTIME DESTINATION bin)

add_executable(ReverseListApp 206_reverse_Linked_List.cpp)
target_include_directories(ReverseListApp PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)
install(TARGETS ReverseListApp RUNTIME DESTINATION bin)

add_executable(CycleListApp 141_cycle_Linked_List.cpp)
target_include_directories(CycleListApp PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)
install(TARGETS CycleListApp RUNTIME DESTINATION bin)

add_executable(PalinListApp 234_Palindrome_Linked_List.cpp)
target_include_directories(PalinListApp PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)
install(TARGETS PalinListApp RUNTIME DESTINATION bin)