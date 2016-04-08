#ifndef _GLU_H
#define _GLU_H
#include <GL/glew.h>

#define GLU_DYNAMIC -1

GLuint gluShaderFromFile(const char* filename, GLenum shaderType);
int gluShaderIsCompiled(GLuint shader);
GLint gluGetLogSize(GLuint shader);
int gluGetShaderLog(GLuint shader, int max_size, GLchar** log);

#endif
