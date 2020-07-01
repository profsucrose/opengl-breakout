#pragma once

#include <string>

const std::string WORKING_PATH = "/Users/moffice/Documents/Cpp/opengl/OpenGL Breakout/OpenGL Breakout/";

const char* GetPath(const std::string path) {
    return (WORKING_PATH + path).c_str();
}
