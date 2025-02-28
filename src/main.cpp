#include "config.h"  // 🔥 Asegúrate de que config.h contiene solo los includes necesarios
#include <iostream>   // Para usar std::cout
#include <glad/glad.h>  // GLAD debe incluirse antes de GLFW
#include <GLFW/glfw3.h> // Incluye la librería GLFW

int main() {
    GLFWwindow* window;  // Puntero a la ventana de GLFW

    // 🔥 1️⃣ Inicializar GLFW
    if (!glfwInit()) {
        std::cout << "GLFW couldn't start" << std::endl;
        return -1;  // 🚨 Si GLFW no se inicializa, se termina el programa con código de error -1
    }

    // 🔥 2️⃣ Crear una ventana con GLFW
    window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);
    if (!window) {  // 🚨 Verifica si la ventana se creó correctamente
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();  // ⚠️ Libera los recursos antes de salir
        return -1;
    }

    // 🔥 3️⃣ Hacer que la ventana recién creada sea el contexto actual de OpenGL
    glfwMakeContextCurrent(window);

    // 🔥 4️⃣ Inicializar GLAD (debe hacerse después de crear la ventana)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();  // ⚠️ Libera los recursos antes de salir
        return -1;
    }

    // 🔥 5️⃣ Establecer el color de fondo de la ventana (RGBA: Azul claro)
    glClearColor(0.45f, 0.5f, 0.75f, 1.0f);

    // 🔄 6️⃣ Bucle principal de renderizado
    while (!glfwWindowShouldClose(window)) {  // 🚀 Mantiene la ventana abierta hasta que el usuario la cierre

        glfwPollEvents();  // 🔄 Procesa eventos de entrada (teclado, ratón, etc.)

        glClear(GL_COLOR_BUFFER_BIT);  // 🖌 Limpia la pantalla con el color definido en glClearColor

        glfwSwapBuffers(window);  // 🔄 Intercambia los buffers para actualizar la ventana con la nueva imagen
    }

    // 🔥 7️⃣ Liberar recursos antes de salir
    glfwTerminate();

    return 0;  // ✅ Salida exitosa del programa
}
