#include "VertexBufferLayout.h"
#include <iostream>
template <>
void VertexBufferLayout::push<float>(unsigned int count)
{
    _elements.push_back({GL_FLOAT, count, GL_FALSE});
    _stride += count * VertexBufferElement::getSizeofType(GL_FLOAT);
}
template <>
void VertexBufferLayout::push<unsigned int>(unsigned int count)
{
    _elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    _stride += count *  VertexBufferElement::getSizeofType(GL_UNSIGNED_INT);
}
template <>
void VertexBufferLayout::push<unsigned char>(unsigned int count)
{
    _elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    _stride += count *  VertexBufferElement::getSizeofType(GL_UNSIGNED_INT);
}
