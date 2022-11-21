//dont forget to include the .h file!
//implementation for strvector.cpp goes here!
#include "strvector.h"


StrVector::StrVector(size_t n, std::string &s)
    : size_(n)
{
    int i = 0;
    for (i = 0; (n >> i) > 0; ++i);
    this->alloc_size_ = std::max(size_t(1 << i), INIT_SIZE);
    this->elems_ = new std::string[alloc_size_];
    for (iterator iter = begin(); iter != end(); ++iter)
        *iter = s;
    // std::fill(begin(), end(), s);
}


StrVector::~StrVector()
{
    delete [] this->elems_;
    this->size_ = 0;
    this->alloc_size_ = 0;
    this->elems_ = nullptr;
}


void StrVector::resize()
{
    iterator new_elems = new std::string[alloc_size_ << 1];
    std::copy(begin(), end(), new_elems);
    delete [] this->elems_;
    this->alloc_size_ <<= 1;
    this->elems_ = new_elems;
}


void StrVector::insert(iterator pos, std::string &s)
{
    index_type idx = pos - begin();
    if (this->size_ * 4 >= this->alloc_size_ * 3)
        resize();
    pos = begin() + idx;
    std::copy_backward(pos, end(), end() + 1);
    *pos = s;
    this->size_++;
}


void StrVector::push_back(std::string &s)
{
    insert(end(), s);
}


std::string StrVector::remove(iterator pos)
{
    std::string s = *pos;
    std::copy_backward(pos + 1, end(), end() - 1);
    this->size_--;
    return s;
}


std::string StrVector::pop_back()
{
    return remove(end() - 1);
}


void StrVector::clear()
{
    delete [] this->elems_;
    this->size_ = 0;
    this->alloc_size_ = INIT_SIZE;
    this->elems_ = new std::string[this->alloc_size_];
}


const std::string &StrVector::operator[](index_type idx) const
{
    return *(begin() + idx);
}


std::string &StrVector::operator[](index_type idx)
{
    return *(begin() + idx);
}


StrVector::iterator StrVector::begin()
{
    return this->elems_;
}


StrVector::iterator StrVector::end()
{
    return this->elems_ + this->size_;
}


const StrVector::iterator StrVector::begin() const
{
    return this->elems_;
}


const StrVector::iterator StrVector::end() const
{
    return this->elems_ + this->size_;
}