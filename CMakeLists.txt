cmake_minimum_required(VERSION 3.19)
project(ScheduleSQL C)

set(CMAKE_C_STANDARD 99)

add_executable(ScheduleSQL src/uso/main.c src/uso/main.h src/uso/instructions/create.c src/uso/instructions/create.h src/uso/instructions/delete.c src/uso/instructions/delete.h src/uso/instructions/modify.c src/uso/instructions/modify.h)