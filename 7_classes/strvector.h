//in case mutliple files in a project include strvector, 
//this instruction says only compile this file once!
#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <string>
#include <algorithm>


class StrVector {
    public:
        //type alias (this is how iterator types work!)
        using iterator = std::string*;
        using index_type = size_t;

        //define an initial size for your underlying array
        const size_t INIT_SIZE = 4;
        
        //constructors and destructor
        StrVector() : size_(0), alloc_size_(INIT_SIZE) {
            this->elems_ = new std::string[alloc_size_];
        }
        StrVector(size_t n, std::string &s);
        ~StrVector();

        // some basic methods
        size_t length() const { return this->size_; }
        size_t mem_size() const { return this->alloc_size_; }
        bool empty() const { return this->size_ == 0; }

        void resize();

        void push_back(std::string &s);
        void insert(iterator pos, std::string &s);
        std::string pop_back();
        std::string remove(iterator pos);

        void clear();

        // overload operator []
        const std::string &operator[](index_type idx) const;
        std::string &operator[](index_type idx);

        // iterator
        iterator begin();
        iterator end();
        const iterator begin() const;
        const iterator end() const;

    private:
       iterator elems_;
       size_t size_;
       size_t alloc_size_;
};

#endif // STRVECTOR_H


