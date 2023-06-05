cmake_minimum_required(VERSION 3.25)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(program1
        1.Cpp_basics/main.cpp)

add_executable(program2
        2.Software_flow_control/main.cpp)

add_executable(program3
        3.Functions/main.cpp)

add_executable(program4
        4.VariablesAndLifetimes/main.cpp)

add_executable(program5
        5.ParametersAndOverloading/main.cpp)

add_executable(program6
        6.Arrays/main.cpp)

add_executable(program7
        7.Strings/main.cpp)

add_executable(program8
        8.Structures/main.cpp)

add_executable(program9
        9.Classes/main.cpp)

add_executable(program10
        10.ClassesWithEncapsulation/main.cpp)

add_executable(program11
        11.ClassesWithFriend/main.cpp)

add_executable(program12
        12.CodeWithMultipleFiles/main.cpp 12.CodeWithMultipleFiles/Country.cpp 12.CodeWithMultipleFiles/Country.h)

add_executable(program13
        13.ConstructorsAndDestructor/main.cpp 13.ConstructorsAndDestructor/Country_.cpp)

add_executable(program14
        14.Pointers/main.cpp)

add_executable(program15
        15.Inheritance/main.cpp 15.Inheritance/Pikachu.cpp 15.Inheritance/Pokemon.cpp 15.Inheritance/Charmander.cpp)

add_executable(program16
        16.Inheritence2/main.cpp 16.Inheritence2/Engine.cpp 16.Inheritence2/Car.cpp 16.Inheritence2/Car.h 16.Inheritence2/RaceCar.cpp 16.Inheritence2/RaceCar.h 16.Inheritence2/Computer.cpp 16.Inheritence2/Computer.h)

add_executable(program99
        99.StaticAndNonStatic/main.cpp)

add_executable(program98
        98.Vectors/main.cpp)