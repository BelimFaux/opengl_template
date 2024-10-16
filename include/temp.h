#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <string.h>

inline std::string get_file_contents(const char *filename) {
    std::ifstream in(filename, std::ios::binary);
    if (in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return (contents);
    }
    std::cerr << "Error reading file: \'" << filename
              << "\': " << strerror(errno) << '\n';
    throw(errno);
}

inline static void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

inline static void key_callback(GLFWwindow *window, int key, int scancode,
                                int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
