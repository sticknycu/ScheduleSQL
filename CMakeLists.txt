cmake_minimum_required(VERSION 3.19)
project(ScheduleSQL C)

set(CMAKE_C_STANDARD 99)
set(json-c/json.h)

add_executable(ScheduleSQL src/uso/main.c src/uso/main.h src/uso/instructions/create.c src/uso/instructions/create.h src/uso/instructions/delete.c src/uso/instructions/delete.h src/uso/instructions/modify.c src/uso/instructions/modify.h src/uso/instructions/add/addEntry.c src/uso/instructions/add/addEntry.h src/uso/instructions/add/addData.c src/uso/instructions/add/addData.h src/uso/instructions/modify/modifyDataSimple.c src/uso/instructions/modify/modifyDataSimple.h src/uso/instructions/modify/modifyDataArgument.c src/uso/instructions/modify/modifyDataArgument.h src/uso/instructions/delete/deleteDataSimple.c src/uso/instructions/delete/deleteDataSimple.h src/uso/instructions/delete/deleteDataArgument.c src/uso/instructions/delete/deleteDataArgument.h src/uso/instructions/delete/deleteEntry.c src/uso/instructions/delete/deleteEntry.h)