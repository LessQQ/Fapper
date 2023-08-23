cmake_minimum_required(VERSION 3.26)
project(Fapper)

set(CMAKE_CXX_STANDARD 17)

add_executable(fapper main.cpp
        IberiaIO.cpp
        Iberia.cpp
        IberiaDataStore.cpp
        IberiaMisc.cpp
        settings.cpp)
