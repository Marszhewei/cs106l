#ifndef REAL_VECTOR_H_
#define REAL_VECTOR_H_

#include <iostream>
#include <algorithm>
#include <string>

template <typename Type>
class RealVector
{
public:
    using iterator = Type*;
    using index_type = size_t;
    using const_iterator = const Type*;

    const size_t INIT_SIZE = 4;
    
    RealVector() : size_(0), alloc_size_(INIT_SIZE) {
        this->elems_ = new Type[alloc_size_];
    }
    RealVector(index_type n, Type &s);
    ~RealVector();

    size_t length() const { return this->size_; }
    size_t mem_size() const { return this->alloc_size_; }
    bool empty() const { return this->size_ == 0; }

    void push_back(Type &s);
    void insert(iterator pos, Type &s);
    Type pop_back();
    Type remove(iterator pos);

    void clear();

    // const Type &operator[](index_type idx) const;
    Type &operator[](index_type idx);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    void resize();

    iterator elems_;
    index_type size_;
    index_type alloc_size_;
};

#include "realvector.cpp"

#endif

