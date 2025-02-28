cmake_minimum_required(VERSION 3.20)
project(hello_window VERSION 1.0.0)

# Encontrar OpenGL
find_package(OpenGL REQUIRED)

# Agregar archivos fuente (🔥 Incluye glad.c)
add_executable(hello_window src/main.cpp src/glad.c)

# 📌 Especificar rutas de inclusión (Para que encuentre glfw3.h y glad.h)
target_include_directories(hello_window PRIVATE dependencies /ucrt64/include)

# 📌 Especificar rutas de librerías (Para que encuentre libglfw3.a)
target_link_directories(hello_window PRIVATE /ucrt64/lib)

# 📌 Enlazar correctamente las librerías
target_link_libraries(hello_window PRIVATE glfw3 OpenGL::GL)
