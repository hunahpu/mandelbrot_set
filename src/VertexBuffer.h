#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H
class VertexBuffer{
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();
        void bind() const;
        void unbind() const;

    private:
        unsigned int _rendererId;
};
#endif