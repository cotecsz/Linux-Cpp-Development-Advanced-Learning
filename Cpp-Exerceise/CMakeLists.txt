cmake_minimum_required(VERSION 3.14)
project(Cpp_Exerceise)

set(CMAKE_CXX_STANDARD 11)


add_executable(01-1_struct chap01-封装与继承/01-1_struct.cpp)

add_executable(02-1_structClass chap02-类的形态/02-1_structClass.cpp)
add_executable(02-2_operatorMain chap02-类的形态/02-2_operator.cpp chap02-类的形态/02-2_operatorMain.cpp)

add_executable(03-1_initialize chap03-构造函数/03-1_initialize.cpp)
add_executable(03-2_constructor chap03-构造函数/03-2_constructor.cpp)
add_executable(03-3_constructorWithPara chap03-构造函数/03-3_constructorWithPara.cpp)
add_executable(03-4_intArrayMain chap03-构造函数/03-4_intArray.cpp chap03-构造函数/03-4_intArrayMain.cpp)
add_executable(03-5_defaultConstructor chap03-构造函数/03-5_defaultConstructor.cpp)
add_executable(03-6_deepCopyVSCopy "chap03-构造函数/03-6_deepCopyVSCopy.cpp")
