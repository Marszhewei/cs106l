#include "realvector.h"


template <typename Type>
RealVector<Type>::RealVector(size_t n, Type &s)
    : size_(n)
{
    int i = 0;
    for (i = 0; (n >> i) > 0; ++i);
    this->alloc_size_ = std::max(size_t(1 << i), INIT_SIZE);
    this->elems_ = new Type[alloc_size_];
    // for (iterator iter = begin(); iter != end(); ++iter)
    //     (*iter) = s;
    std::fill(begin(), end(), s);
}


template <typename Type>
RealVector<Type>::~RealVector()
{
    delete [] this->elems_;
    this->size_ = 0;
    this->alloc_size_ = 0;
    this->elems_ = nullptr;
}


template <typename Type>
void RealVector<Type>::resize()
{
    iterator new_elems = new Type[alloc_size_ << 1];
    std::copy(cbegin(), cend(), new_elems);
    delete [] this->elems_;
    this->alloc_size_ <<= 1;
    this->elems_ = new_elems;
}


template <typename Type>
void RealVector<Type>::insert(iterator pos, Type &s)
{
    index_type idx = pos - begin();
    if (this->size_ * 4 >= this->alloc_size_ * 3)
        resize();
    pos = begin() + idx;
    std::copy_backward(pos, end(), end() + 1);
    *pos = s;
    this->size_++;
}


template <typename Type>
void RealVector<Type>::push_back(Type &s)
{
    insert(end(), s);
}


template <typename Type>
Type RealVector<Type>::remove(iterator pos)
{
    Type s = *pos;
    std::copy_backward(pos + 1, end(), end() - 1);
    this->size_--;
    return s;
}


template <typename Type>
Type RealVector<Type>::pop_back()
{
    return remove(end() - 1);
}


template <typename Type>
void RealVector<Type>::clear()
{
    delete [] this->elems_;
    this->size_ = 0;
    this->alloc_size_ = INIT_SIZE;
    this->elems_ = new Type[this->alloc_size_];
}


// template <typename Type>
// const Type &RealVector<Type>::operator[](index_type idx) const
// {
//     return *(begin() + idx);
// }


template <typename Type>
Type &RealVector<Type>::operator[](index_type idx)
{
    return *(begin() + idx);
}


template <typename Type>
typename RealVector<Type>::iterator RealVector<Type>::begin()
{
    return this->elems_;
}


template <typename Type>
typename RealVector<Type>::iterator RealVector<Type>::end()
{
    return this->elems_ + this->size_;
}


template <typename Type>
typename RealVector<Type>::const_iterator RealVector<Type>::cbegin() const
{
    return this->elems_;
}


template <typename Type>
typename RealVector<Type>::const_iterator RealVector<Type>::cend() const
{
    return this->elems_ + this->size_;
}