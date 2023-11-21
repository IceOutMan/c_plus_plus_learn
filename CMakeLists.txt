cmake_minimum_required(VERSION 3.26)
project(c_plus_plus_learn)

set(CMAKE_CXX_STANDARD 14)

add_executable(class_inherit first_project/class_inherit/main.cpp)

add_executable(template_use first_project/template_use/main.cpp
        first_project/template_use/template_function_recursion.h
        first_project/template_use/template_class.h)

add_executable(collection_use_map_use first_project/collection_use/map_use/main.cpp)

add_executable(test_use first_project/test_use/main.cpp first_project/test_use/main.h)
