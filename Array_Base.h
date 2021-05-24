#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>  //size_t

template <typename T>
class Array_Base {

    public:
        typedef T type;

        //Constructors/Destructor
        Array_Base (void);
        Array_Base (const Array_Base <T> & arr);
        
        Array_Base (size_t length);
        Array_Base (size_t length, T fill);
        ~Array_Base (void);

        //Operator Overloading
        T & operator [] (size_t index);
        const T & operator [] (size_t index) const;
        bool operator == (const Array_Base <T> & rhs) const;
        bool operator != (const Array_Base <T> & rhs) const;
        const Array_Base <T> & operator = (const Array_Base <T> & rhs);


        //Methods
        virtual size_t size (void) const;
        virtual size_t max_size (void) const;
        virtual T get (size_t index) const;
        virtual void set (size_t index, T value);
        virtual int find (T element) const;
        virtual int find (T element, size_t start) const;
        virtual void fill (T element);
        virtual void reverse (void);
        virtual Array_Base <T> slice (size_t begin) const;
        virtual Array_Base <T> slice (size_t begin, size_t end) const;

    protected:
        T * data_;
        size_t cur_size_;
        size_t max_size_;

};

#include "Array_Base.inl"
#include "Array_Base.cpp"

#endif