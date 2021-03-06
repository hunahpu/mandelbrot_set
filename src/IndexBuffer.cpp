#include "IndexBuffer.h"
#include <glad/glad.h>
IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count): _count{count }{
    glGenBuffers(1, &_rendererId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer(){
    glDeleteBuffers(1, &_rendererId);
}
void IndexBuffer::bind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererId);
}
void IndexBuffer::unbind()const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}