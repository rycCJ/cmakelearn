StrUtils/
├── .gitignore
├── CMakeLists.txt          <-- 顶级 CMake 配置文件
├── build/                  <-- 编译中间文件的存放位置
├── install/                <-- [新增] 最终产品的安装位置
│   ├── bin/                <--   存放可执行文件
│   ├── lib/                <--   存放库文件
│   └── include/            <--   存放公共头文件
├── include/
│   └── my_pro_projet/
│       └── strutils.hpp
├── src/
│   ├── CMakeLists.txt
│   ├── main.cpp
│   └── moduleA/
│       ├── CMakeLists.txt
│       └── strutils.cpp
├── tests/
│   ├── CMakeLists.txt
│   └── test_strutils.cpp
└── third_party/
    └── googletest/ 
    
