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

add_library(ShaderManager)

target_sources(ShaderManager
    PRIVATE 
        src/WindowManager/Shaders/Shaders.cpp
    PUBLIC
        FILE_SET HEADERS

        BASE_DIRS
            src/WindowManager
        FILES 
            src/WindowManager/Shaders/Shaders.hpp
)

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
        ShaderManager            
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
        src/Button/IDrawableFactory/Buttons/EBO/EBO.cpp
        src/Button/IDrawableFactory/Buttons/VBO/VBO.cpp
        src/Button/IDrawableFactory/Buttons/VAO/VAO.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS  
            src/Button
        FILES
            src/Button/IDrawableFactory/Buttons/EBO/EBO.hpp
            src/Button/IDrawableFactory/Buttons/VBO/VBO.hpp
            src/Button/IDrawableFactory/Buttons/VAO/VAO.hpp
)

add_library(Vect2DUtils)

target_sources(Vect2DUtils
    PRIVATE
        src/Button/Vect2D/Vect2D.cpp
    PUBLIC
        FILE_SET HEADERS

        BASE_DIRS
            src/Button
        FILES 
            src/Button/Vect2D/Vect2D.hpp
)

add_library(Buttons)

target_sources(Buttons
        PRIVATE
            src/Button/IDrawableFactory/Buttons/Button.cpp
        PUBLIC
            FILE_SET HEADERS
            BASE_DIRS
                src/Button
            FILES
                src/Button/IDrawableFactory/Buttons/Button.hpp
)

add_library(IDrawableManager)

target_sources(IDrawableManager
            PRIVATE
                src/Button/IDrawableFactory/IDrawableFactory.cpp
            PUBLIC 
                FILE_SET HEADERS
                BASE_DIRS
                    src/Button
                FILES
                    src/Button/IDrawableFactory/IDrawableFactory.hpp
)



target_link_libraries(Buttons PRIVATE GPUMemoryManager Vect2DUtils)

target_link_libraries(IDrawableManager PRIVATE Buttons)

add_library(DrawablesProvider)

target_sources(DrawablesProvider
                PRIVATE
                    src/Button/IDrawableManager.cpp
                PUBLIC
                    FILE_SET HEADERS
                    BASE_DIRS
                        src/Button
                    FILES
                        src/Button/IDrawableManager.hpp
)

target_link_libraries(DrawablesProvider PRIVATE IDrawableManager)

target_link_libraries(WindowApp PRIVATE WindowManager DrawablesProvider)

target_link_libraries(VisualDiffTool PRIVATE WindowApp)
