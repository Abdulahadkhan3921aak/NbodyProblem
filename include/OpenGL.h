#pragma once

#define GLFW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <iostream>

static unsigned int CompileShader(unsigned int type, const std::string &source);

static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);

int InitialiseOpenGL(void);