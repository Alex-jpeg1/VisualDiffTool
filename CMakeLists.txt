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

add_library(WindowApp)

target_sources(WindowApp
    PRIVATE 
        src/WindowApp/WindowApp.cpp
    PUBLIC 
        FILE_SET HEADERS
        BASE_DIRS
            src/WindowApp
        FILES
            src/WindowApp/WindowApp.hpp
    )

add_library(GPUMemoryManager)

target_sources(GPUMemoryManager
    PRIVATE
        src/Button/EBO/EBO.cpp
        src/Button/VBO/VBO.cpp
        src/Button/VAO/VAO.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS  
            src/Button
        FILES
            src/Button/EBO/EBO.hpp
            src/Button/VBO/VBO.hpp
            src/Button/VAO/VAO.hpp
)

add_library(Buttons)

target_sources(Buttons
        PRIVATE
            src/Button/Button.cpp
        PUBLIC
            FILE_SET HEADERS
            BASE_DIRS
                src/Button
            FILES
                src/Button/Button.hpp
)

target_link_libraries(Buttons PRIVATE GPUMemoryManager)

target_link_libraries(WindowApp PRIVATE WindowManager Buttons)

target_link_libraries(VisualDiffTool PRIVATE WindowApp)
