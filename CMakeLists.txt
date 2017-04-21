cmake_minimum_required(VERSION 3.6)
project(TexttureCubeTwo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Main.cpp Camera.cpp Camera.h Default.frag
        Default.vert InputFile.cpp InputFile.h Mesh.cpp Mesh.h Shader.cpp
        Shader.h ShaderProgram.cpp ShaderProgram.h Transform.cpp Transform.h DefaultTextured.frag
        DefaultTextured.vert PhongShading.frag PhongShading.vert DefaultTransform.vert Texture2D.cpp
        Texture2D.h smiley.jpeg crate.png floor.jpg pyramid.png)
add_executable(TexttureCubeTwo ${SOURCE_FILES})
target_link_libraries(TexttureCubeTwo -lglut -lGL -lGLU -lGLEW -lIL)