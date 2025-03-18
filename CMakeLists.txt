cmake_minimum_required(VERSION 3.24)
project(Projet_Agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_Agenda main.c
        src/cell.c
        include/cell.h
        src/list.c
        include/list.h src/timer.c include/timer.h src/contact.c include/contact.h)
