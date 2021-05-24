// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//-----------------CONSTRUCTORS/DESTRUCTOR--------------
//
// Stack 
//
template <typename T>
Stack <T>::Stack (void) :
    Array <T> ()
{
    
}

//
// Stack (const Stack &)
//
template <typename T>
Stack <T>::Stack (const Stack & stack) :
    Array <T> (stack)
{
    
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//---------------------OPERATOR OVERLOADING---------------------
//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if (this != &rhs) {
        delete [] this->data_;
        this->data_ = nullptr;
        T * tmp = rhs.data_;
        this->cur_size_ = rhs.cur_size_;
        this->max_size_ = rhs.max_size_;
        this->data_ = tmp;
    }
    return *this;
}

//-------------------METHODS------------------------
//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    if (is_empty() == false) {
        T values[this->cur_size_];
        for (int i = 0; i < this->cur_size_; i++) {
            values[i] = this->data_[i];
        }
        delete [] this->data_;
        this->data_ = nullptr;
        this->cur_size_++;
        this->max_size_++;
        T * tmp = new T[this->cur_size_];
        this->data_ = tmp;
        for (int i = 0; i < this->cur_size_-1; i++) {
            this->data_[i] = values[i];
        }
        this->data_[this->cur_size_-1] = element;

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

/*
template <typename T>
size_t Stack <T>::getCurSize (void)
{
    return this->cur_size_;
}

template <typename T>
size_t Stack <T>::getMaxSize (void)
{
    return this->max_size_;
}
*/

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if (is_empty()) {
        throw std::out_of_range("empty_exception error: No elements present in stack");
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
        for (int i = 0; i < this->cur_size_; i++) {
            this->data_[i] = elements[i];
        }
    }
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    delete [] this->data_;
    this->data_ = nullptr;
    T * tmp = new T[0];
    this->data_ = tmp;
    this->cur_size_ = 0;
    this->max_size_ = 0;
}
