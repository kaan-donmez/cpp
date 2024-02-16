#include "IconOfApplication.h"

void setIconOfApplication(GLFWwindow *mainWindow)
{
    int width, height, channels;
    std::string path = "Assets/images/icon.png";
    unsigned char* pixels = stbi_load(path.c_str(), &width, &height, &channels, 4);

    GLFWimage icon[1];
    icon[0].width = width;
    icon[0].height = height;
    icon[0].pixels = pixels;

    glfwSetWindowIcon(mainWindow, 1, icon);
}