cmake_minimum_required(VERSION 3.30)
project(Museum)

set(CMAKE_CXX_STANDARD 20)

add_executable(Museum src/main.cpp
        src/Name.cpp
        include/Name.h
        src/Date.cpp
        include/Date.h
        src/Dimensions.cpp
        include/Dimensions.h
        src/Artwork.cpp
        include/Artwork.h
        src/Painting.cpp
        include/Painting.h
        src/Sculpture.cpp
        include/Sculpture.h
        src/WrittenWord.cpp
        include/WrittenWord.h
        include/Utility.h
)
