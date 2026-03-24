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
        src/WindowApp/Shaders/Shaders.cpp
    PUBLIC
        FILE_SET HEADERS

        BASE_DIRS
            src/WindowApp
        FILES 
            src/WindowApp/Shaders/Shaders.hpp
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

add_library(ColorWrapper)
target_sources(ColorWrapper
    PRIVATE 
        src/Button/IDrawableFactory/Buttons/ButtonColors/ColorValueWrapper/ColorValueWrapper.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            src/Button
        FILES
            src/Button/IDrawableFactory/Buttons/ButtonColors/ColorValueWrapper/ColorValueWrapper.hpp
)


add_library(Colors)

target_sources(Colors
    PRIVATE
        src/Button/IDrawableFactory/Buttons/ButtonColors/ButtonColors.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            src/Button
        FILES
            src/Button/IDrawableFactory/Buttons/ButtonColors/ButtonColors.hpp
)
target_link_libraries(Colors PRIVATE ColorWrapper)

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

target_link_libraries(Buttons PRIVATE Colors)

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



target_link_libraries(Buttons PRIVATE GPUMemoryManager Vect2DUtils ShaderManager)

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

add_library(Inputs)

target_sources(Inputs
    PRIVATE
        src/WindowApp/Inputs/Inputs.cpp
    PUBLIC
        FILE_SET HEADERS
    BASE_DIRS
        src/WindowApp
    FILES
        src/WindowApp/Inputs/Inputs.hpp
)

target_link_libraries(DrawablesProvider PRIVATE IDrawableManager)

target_link_libraries(WindowApp PRIVATE WindowManager DrawablesProvider ShaderManager Inputs)

target_link_libraries(VisualDiffTool PRIVATE WindowApp)
