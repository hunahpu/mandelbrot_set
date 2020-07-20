#include<glad/glad.h>
#include "Shader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Shader::Shader(const std::string filePath): _filePath{filePath}, _renderedId{0} {
    shaderSources source = parseShader("res/shaders/default.shader");
    _renderedId = createShader(source.vertexSource,source.fragmentSource);
}
Shader::~Shader(){
    //glDeleteProgram(_renderedId);
}
void Shader::bind() const{
    glUseProgram(_renderedId);
}
void Shader::unbind() const{
    glUseProgram(0);
}
void Shader::setUniform4f(const std::string& name, float v0, float v1, float f2, float f3){
    glUniform4f(getUniformLocation(name),v0,v1,f2,f3);
}
unsigned int Shader::getUniformLocation(const std::string& name){
    if(cache.find(name)!= cache.end())
        return cache[name];
    int location = glGetUniformLocation(_renderedId,name.c_str());
    if(location== -1)
        std::cout << "Location -1 for "<< name << std::endl;
    cache[name] = location;
    return location;
}

shaderSources Shader::parseShader(const std::string filename){
    std::fstream stream(filename);

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    if (stream.is_open())
    {
        
        std::cout << "Operation successfully performed\n";
    }
    else
    {
        std::cout << "Error opening file";
    }
    while(getline(stream,line)){
        if(line.find("#shader")!=std::string::npos){
            if(line.find("vertex")!=std::string::npos)
                type = ShaderType::VERTEX;
            if(line.find("fragment")!=std::string::npos)
                type = ShaderType::FRAGMENT;  
        }else{
            ss[(int)type] << line << '\n';
        }
    }
    
    return {ss[0].str(),ss[1].str()};
}

unsigned int Shader::compileShader(unsigned int type, const std::string& source){
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(id, 1,&src,nullptr);
    glCompileShader(id);
    int result;
    glGetShaderiv(id,GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE){
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *msg = (char*)alloca(length*sizeof(char));
        glGetShaderInfoLog(id,length,&length,msg);
        std::cout<< "Failed to Compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" <<std::endl;
        std::cout<<msg<<std::endl; 
        return 0;
    }
    return id;
}

unsigned int Shader::createShader(const std::string&  vertexShader,const std::string&  fragmentShader){
    int program = glCreateProgram();
    int success;
    char infoLog[512];
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    // check for linking errors
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        return 0;
    }
    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;

}