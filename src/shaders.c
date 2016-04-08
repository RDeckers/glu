#include <glu.h>
#include <utilities/file.h>
#include <utilities/logging.h>
#include <errno.h>
#include <string.h>


GLuint gluShaderFromFile(const char* filename, GLenum shaderType){
  char *src = NULL;
  file_to_string(filename, 0, &src);
  GLuint shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, (const char* const*)&src, NULL);
  glCompileShader(shader);
  return shader;
}

int gluShaderIsCompiled(GLuint shader){
  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  return GL_TRUE == status;
}

GLint gluGetLogSize(GLuint shader){
  GLint log_size;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_size);
  if(log_size <= 1){//standard says zero, but if it's 1 it's just a null terminator.
    return 0;
  }
  return log_size;
}

int gluGetShaderLog(GLuint shader, int max_size, GLchar** log){
  GLint log_size = gluGetLogSize(shader);
  if(!log_size)
    return 0;
  if(GLU_DYNAMIC == max_size){
    max_size = log_size;
    free(*log);
    *log = malloc(log_size*sizeof(GLchar));
    if(!log){
      report(FAIL, "Allocation failed in %s: %s (%d)", __func__, strerror(errno), errno);
      return 0;
    }
  }
  else if(max_size < log_size){
    report(WARN, "Log buffer to small to hold entire shader log");
  }
  glGetShaderInfoLog(shader, max_size*sizeof(GLchar), NULL, *log);
  return 1;
}
