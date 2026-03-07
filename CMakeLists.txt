cmake_minimum_required(VERSION 3.23)

project(VisualDiffTool)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(VisualDiffTool)

target_sources(VisualDiffTool 
                PRIVATE
                src/main.cpp 
                )


add_library(Glad)

target_sources(Glad
        PRIVATE
            extern/gladsrc/glad.c
        PUBLIC 
            FILE_SET HEADERS 
            BASE_DIRS
                extern
            FILES 
                extern/glad/glad.h   
)       
target_link_libraries(Glad PRIVATE OpenGL::GL)

add_library(WindowManager)

target_sources(WindowManager
    PRIVATE
        src/WindowManager/WindowManager.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            src/WindowManager
        FILES 
            src/WindowManager/WindowManager.hpp
    )

target_link_libraries(WindowManager
    PRIVATE
        Glad
        glfw
        OpenGL::GL            
    )

target_link_libraries(VisualDiffTool PRIVATE WindowManager)
