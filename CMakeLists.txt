cmake_minimum_required(VERSION 3.26)
project(Fapper)

set(CMAKE_CXX_STANDARD 17)

add_executable(fapconfig main.cpp
        Iberia/IberiaIO.cpp
        Iberia/Iberia.cpp
        Iberia/IberiaDataStore.cpp
        Iberia/IberiaMisc.cpp
        Iberia/settings.cpp)
