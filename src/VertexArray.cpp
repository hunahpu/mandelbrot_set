#include "VertexArray.h"
#include <iostream>
VertexArray::VertexArray(){
    glGenVertexArrays(1, &_rendererId);
}
VertexArray::~VertexArray(){
    glDeleteVertexArrays(1,&_rendererId);

}
void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& vbl){
    bind();
    vb.bind();
    const auto& elements = vbl.elements();
    unsigned int offset{0};
    for(unsigned int i=0; i < elements.size(); i++){
        
        const auto& element = elements[i];
        //std::cout <<element.count<<std::endl;
        //std::cout <<element.type<<std::endl;
        //std::cout <<element.normalize<<std::endl;
        //std::cout <<vbl.stride()<<std::endl;

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(i, element.count, element.type, element.normalize, vbl.stride(), (const void*)offset);
        offset+= element.count * VertexBufferElement::getSizeofType(element.type);
    }
}

void VertexArray::bind() const{
    glBindVertexArray(_rendererId);
}
void VertexArray::unbind() const{
    glBindVertexArray(0);
}