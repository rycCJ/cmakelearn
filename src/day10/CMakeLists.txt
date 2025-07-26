# 定义一个名为 GuessNumApp 的可执行文件
# 源文件是当前目录下的 01_guess_num.cpp
add_executable(GuessNumApp 01_guess_num.cpp)
# --- 指定头文件目录 ---
# 告诉编译器去项目的 include 目录寻找头文件
# PUBLIC 意味着链接到此库的其他目标也会自动获得此路径
target_include_directories(GuessNumApp PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
)

# （可选）如果 guess_num.cpp 需要用到 strutils 库，
# 你可以在这里添加链接：
# target_link_libraries(GuessNumApp strutils)

install(TARGETS GuessNumApp RUNTIME DESTINATION bin)


add_executable(CalculatorAPP 02_calculator.cpp)

target_include_directories(CalculatorAPP PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
)
install(TARGETS CalculatorAPP RUNTIME DESTINATION bin)



add_executable(ToDolistApp 03_todolist.cpp)

target_include_directories(ToDolistApp PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
)
install(TARGETS ToDolistApp RUNTIME DESTINATION bin)

add_executable(arrApp arrgroup.cpp)

target_include_directories(arrApp PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
)
install(TARGETS arrApp RUNTIME DESTINATION bin)
