#include "VertexBuffer.h"
#include <glad/glad.h>
VertexBuffer::VertexBuffer(const void* data, unsigned int size){
    glGenBuffers(1, &_rendererId);
    glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &_rendererId);
}
void VertexBuffer::bind() const{
    glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
}
void VertexBuffer::unbind()const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}