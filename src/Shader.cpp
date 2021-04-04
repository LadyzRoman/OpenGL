//
// Created by Roman on 04.04.2021.
//

#include "Shader.h"

Shader::Shader(const GLchar *vertexPath, const GLchar *fragmentPath) {
    std::string vertexCode;
    std::string fragmentCode;
    try {
        vertexCode = loadShaderSource(vertexPath);
        fragmentCode = loadShaderSource(fragmentPath);
    } catch (std::ifstream::failure &e) {
        std::cout << "Failed to read shader file";
    }

    GLuint vertexShader = compileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);
    
    this->program = glCreateProgram();
    glAttachShader(this->program, vertexShader);
    glAttachShader(this->program, fragmentShader);
    glLinkProgram(this->program);

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(this->program, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
        std::cout << infoLog;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void Shader::use() const {
    glUseProgram(this->program);
}

std::string Shader::loadShaderSource(const GLchar *path) {
    std::string shaderSource;
    std::ifstream shaderFile;

    shaderFile.open(path);
    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();

    return shaderStream.str();
}

GLuint Shader::compileShader(const GLchar *source, GLenum type) {
    GLuint shader;
    GLint success;
    GLchar infoLog[512];

    shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << infoLog;
    }
    return shader;
}

void Shader::configureProgram(float value) {
    glUniform1f(glGetUniformLocation(this->program, "xOffset"), value);
}
