#ifndef IndexBuffer_H
#define IndexBuffer_H
class IndexBuffer{
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();
        void bind() const;
        void unbind() const;

        inline unsigned int count() const{return _count;}

    private:
        unsigned int _rendererId;
        unsigned int _count;
};
#endif