#ifndef SHADER_H
#define SHADER_H

#include<string>
#include <unordered_map>
struct shaderSources{
    std::string vertexSource;
    std::string fragmentSource;
};
enum class ShaderType{NONE=-1, VERTEX=0,FRAGMENT=1};
class Shader{
    public:
        Shader(const std::string filepath);
        ~Shader();
        void bind() const;
        void unbind() const;
        void setUniform4f(const std::string& name, float v0, float v1, float f2, float f3);

    private:     
        unsigned int getUniformLocation(const std::string& name);
        unsigned int compileShader(unsigned int type, const std::string& source);
        unsigned int createShader(const std::string&  vertexShader,const std::string&  fragmentShader);
        shaderSources parseShader(const std::string filename);
    private:
        std::unordered_map<std::string,int> cache;
        std::string _filePath;
        unsigned int _renderedId;
        
        
};
#endif