
#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>


class Shader {
public:
    GLuint program;

    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);

    void configureProgram(float value);

    void use() const;
private:
    std::string loadShaderSource(const GLchar * path);
    GLuint compileShader(const GLchar * source, GLenum type);
};


#endif //OPENGL_SHADER_H
