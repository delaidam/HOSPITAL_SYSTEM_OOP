cmake_minimum_required(VERSION 3.23)
project(HOSPITAL_MANAGEMENT_OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(HOSPITAL_MANAGEMENT_OOP main.cpp
        Login.cpp Login.h
        Hospital.cpp Hospital.h
        Apoteka.cpp Apoteka.h
        Soba.cpp Soba.h
        Osoba.cpp Osoba.cpp)
