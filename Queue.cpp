#include "Queue.h"
#include <stdexcept>

//Constructors/Destructors
template <typename T>
Queue <T>::Queue (void) :
    Array <T> ()
{
    
}

template <typename T>
Queue <T>::Queue (const Queue & queue) :
    Array <T> (queue)
{

}

template <typename T>
Queue <T>::~Queue (void) 
{
    
}

//Operator Overloading
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue <T> & rhs)
{
    if (this != &rhs) {
        delete [] this->data_;
        this->data_ = nullptr;
        T * tmp = new T[rhs.max_size_];
        this->data_ = tmp;
        for (int i = 0; i < rhs.cur_size_; i++) {
            this->data_[i] = rhs.get(i);
        }
        this->max_size_ = rhs.max_size_;
        this->cur_size_ = rhs.cur_size_;
    }
    return *this;
}

template <typename T>
void Queue <T>::enqueue (T element) 
{
    if (is_empty() == false) {
        T values[this->cur_size_];
        for (int i = 0; i < this->cur_size_; i++) {
            values[i] = this->data_[i];
        }
        this->cur_size_++;
        this->max_size_++;
        delete [] this->data_;
        this->data_ = nullptr;
        T * tmp = new T[this->cur_size_];
        this->data_ = tmp;
        for (int i = 0; i < this->cur_size_-1; i++) {
            this->data_[i] = values[i];
        }
        this->data_[this->cur_size_ - 1] = element;
    }
    else {
        delete [] this->data_;
        this->data_ = nullptr;
        this->cur_size_++;
        this->max_size_++;
        T * tmp = new T[this->cur_size_];
        this->data_ = tmp;
        this->data_[0] = element;
    }
}

template <typename T>
T Queue <T>::dequeue (void) 
{
    if (this->cur_size_ == 0) {
        throw std::out_of_range("empty_exception error: No elements present in queue");
    }
    else {
        T elements[this->cur_size_];
        for (int i = 0; i < this->cur_size_; i++) {
            elements[i] = this->data_[i];
        }
        delete [] this->data_;
        this->data_ = nullptr;
        this->cur_size_--;
        this->max_size_--;
        T * tmp = new T[this->cur_size_];
        this->data_ = tmp;
        for (int i = 1; i < this->cur_size_+1; i++) {
            //Move data up in queue
            this->data_[i-1] = elements[i];
        }
        return elements[0];
    }
}

template <typename T>
bool Queue <T>::is_empty (void)
{
    if (this->cur_size_ == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
size_t Queue <T>::getSize (void)
{
    return this->size();
    //return this->cur_size_;
}

template <typename T>
void Queue <T>::clear (void)
{
    delete [] this->data_;
    this->data_ = nullptr;
    T * tmp = new T[0];
    this->data_ = tmp;
    this->cur_size_ = 0;
    this->max_size_ = 0;
}
