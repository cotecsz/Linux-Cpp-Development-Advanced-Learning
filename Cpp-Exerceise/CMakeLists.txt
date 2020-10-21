cmake_minimum_required(VERSION 3.14)
project(Cpp_Exerceise)

set(CMAKE_CXX_STANDARD 11)

#chapter 00 经典问题
add_executable(00-1_constObject chap00-经典问题/00-1_constObject.cpp)
add_executable(00-2_thisMember chap00-经典问题/00-2_thisMember.cpp)
add_executable(00-3_assignmengCopyConstructor chap00-经典问题/00-3_assignmengCopyConstructor.cpp)


add_executable(01-1_struct chap01-封装与继承/01-1_struct.cpp)

add_executable(02-1_structClass chap02-类的形态/02-1_structClass.cpp)
add_executable(02-2_operatorMain chap02-类的形态/02-2_operator.cpp chap02-类的形态/02-2_operatorMain.cpp)

add_executable(03-1_initialize chap03-构造函数/03-1_initialize.cpp)
add_executable(03-2_constructor chap03-构造函数/03-2_constructor.cpp)
add_executable(03-3_constructorWithPara chap03-构造函数/03-3_constructorWithPara.cpp)
add_executable(03-4_intArrayMain chap03-构造函数/03-4_intArray.cpp chap03-构造函数/03-4_intArrayMain.cpp)
add_executable(03-5_defaultConstructor chap03-构造函数/03-5_defaultConstructor.cpp)
add_executable(03-6_deepCopyVSCopy "chap03-构造函数/03-6_deepCopyVSCopy.cpp")

# chapter 04 初始化列表
add_executable(04-1_constMember chap04-初始化列表/04-1_constMember.cpp)
add_executable(04-2_InitializeList chap04-初始化列表/04-2_InitializeList.cpp)
add_executable(04-3_constMemory chap04-初始化列表/04-3_constMemory.cpp)

# chapter 05 对象构造顺序
add_executable(05-1_LocalVariable chap05-对象构造顺序/05-1_LocalVariable.cpp)
add_executable(05-2_HeapVariable chap05-对象构造顺序/05-2_HeapVariable.cpp)
add_executable(05-3_GlobalVariable chap05-对象构造顺序/05-3_GlobalVariable.cpp
                chap05-对象构造顺序/05-3_Global_2.cpp
                chap05-对象构造顺序/05-3_Global_1.cpp
                chap05-对象构造顺序/05-3_Global_3.cpp)

# chapter 06 析构函数
add_executable(06-1_intArrayMain chap06-析构函数/06-1_intArrayMain.cpp
                chap06-析构函数/06-1_intArray.cpp)
add_executable(06-2_deconstructor chap06-析构函数/06-2_deconstructor.cpp)
add_executable(06-3_deconstructorOrder chap06-析构函数/06-3_deconstructorOrder.cpp)

# chapter 07 临时对象
add_executable(07-1_tempVariable chap07-临时对象/07-1_tempVariable.cpp)
add_executable(07-2_initVariable chap07-临时对象/07-2_initVariable.cpp)
add_executable(07-3_tempVariableLiftTime chap07-临时对象/07-3_tempVariableLiftTime.cpp)

# chapter 08 静态成员变量
add_executable(08-1_countObjectNumber chap08-静态成员变量/08-1_countObjectNumber.cpp)
add_executable(08-2_staticFunction chap08-静态成员变量/08-2_staticFunction.cpp)
add_executable(08-3_countObjectNumSafe chap08-静态成员变量/08-3_countObjectNumSafe.cpp)

# chapter 09 二阶构造模式
add_executable(09-1_constructorReturn chap09-二阶构造模式/09-1_constructorReturn.cpp)
add_executable(09-2_intArrayMain chap09-二阶构造模式/09-2_intArrayMain.cpp
        chap09-二阶构造模式/09-2_intArray.cpp)
add_executable(09-3_TwoPhaseCons chap09-二阶构造模式/09-3_TwoPhaseCons.cpp)

# chapter 10 友元
add_executable(10-1_friendFunction chap10-友元/10-1_friendFunction.cpp)
add_executable(10-2_friendClass chap10-友元/10-2_friendClass.cpp)

# chapter 11 函数重载
add_executable(11-1_overLoading chap11-函数重载/11-1_overLoading.cpp)
add_executable(11-2_extendSystemFunction chap11-函数重载/11-2_extendSystemFunction.cpp)

# chapter 12 操作符重载
add_executable(12-1_ComplexAdd chap12-操作符重载/12-1_ComplexAdd.cpp)
add_executable(12-2_operator chap12-操作符重载/12-2_operator.cpp)
add_executable(12-3_ClassOperator chap12-操作符重载/12-3_ClassOperator.cpp)
add_executable(12-4_ComplexMain chap12-操作符重载/12-4_Complex.cpp
                chap12-操作符重载/12-4_ComplexMain.cpp)
add_executable(12-5_intArrayMain chap12-操作符重载/12-5_intArray.cpp
                chap12-操作符重载/12-5_intArrayMain.cpp)


# chapter 13 智能指针
add_executable(13-1_MemoryLeak chap13-智能指针/13-1_MemoryLeak.cpp)
add_executable(13-2_autoPointer chap13-智能指针/13-2_autoPointer.cpp)

# chapter 15 类型转换
add_executable(15-1_CTypeTrans chap15-类型转换/15-1_CTypeTrans.cpp)
add_executable(15-2_CppClassTypeTrans chap15-类型转换/15-2_CppClassTypeTrans.cpp)
add_executable(15-3_ClassTypeToBuildType chap15-类型转换/15-3_ClassTypeToBuildType.cpp)
add_executable(15-4_TransConstrClassTypeToClassType chap15-类型转换/15-4_TransConstrClassTypeToClassType.cpp)
