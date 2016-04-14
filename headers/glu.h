#ifndef _GLU_H
#define _GLU_H
#include <GL/glew.h>

#ifdef __cplusplus
#define EXTERN_C extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C
#define EXTERN_C_END
#endif

#define GLU_DYNAMIC -1
EXTERN_C

GLuint gluShaderFromFile(const char* filename, GLenum shaderType);
int gluShaderIsCompiled(GLuint shader);
GLint gluGetLogSize(GLuint shader);
int gluGetShaderLog(GLuint shader, int max_size, GLchar** log);

EXTERN_C_END
#endif
