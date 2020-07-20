#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H

#include <glad/glad.h>
#include <vector>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalize;

    static unsigned int getSizeofType(unsigned int type){
        switch (type)
        {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1;
            
        }
        return 0;
    }
};

class VertexBufferLayout{
    public:
        VertexBufferLayout(): _stride{0}{}
        //~VertexBufferLayout();
        template<typename T>
        void push(unsigned int count);

        inline unsigned int stride() const {return _stride;}
        inline std::vector<VertexBufferElement> elements() const {return _elements;}
        
    private:
        std::vector<VertexBufferElement> _elements;
        unsigned int _stride;
};
#endif