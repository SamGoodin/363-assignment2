#include "Array_Base.h"

//-------------------CONSTRUCTORS/DESTRUCTOR----------------------
//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void) :
    data_(new T [0]),
    cur_size_(0),
    max_size_(0)
{

}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base <T> & arr) :
    data_(arr.data_),
    cur_size_(arr.cur_size_),
    max_size_(arr.max_size_)
{

}

//
// Array_Base (length)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length) :
    data_(new T [length]),
    cur_size_(0),
    max_size_(length)
{

}

//
// Array_Base (length, fill)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill) :
    data_(new T [length]),
    cur_size_(0),
    max_size_(length)
{
    this->fill(fill);
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
    delete [] data_;
    data_ = nullptr;
}

//-------------------OPERATOR OVERLOADING----------------------
//
// []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index) 
{
    if (index >= max_size_ || index < 0) {
        throw std::out_of_range ("out_of_range error: Index out of range for array");
    }
    else {
        return data_[index];
    }
}

//
// [] const
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    if (index >= max_size_ || index < 0) {
        throw std::out_of_range ("out_of_range error: Index out of range for array");
    }
    else {
        return data_[index];
    }
}

//
// == 
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base <T> & rhs) const
{
    if (this == &rhs) {
		return true;
	}
	else{
		if (max_size_ == rhs.max_size_ && cur_size_ == rhs.cur_size_) {
			for (int i = 0; i < max_size_; i++) {
				if (rhs.data_[i] != data_[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
}

//
// !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base <T> & rhs) const 
{
    if (this == &rhs) {
		return false;
	}
	else{
		if (max_size_ == rhs.max_size_ && cur_size_ == rhs.cur_size_) {
			for (int i = 0; i < max_size_; i++) {
				if (rhs.data_[i] != data_[i]) {
					return true;
				}
			}
			return false;
		}
		else {
			return true;
		}
	}
}

//
// =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base <T> & rhs)
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

//-------------------METHODS----------------------
//
// set (index, value)
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    if (index >= max_size_ || index < 0) {
        throw std::out_of_range ("out_of_range error: Index out of range for array");
    }
    else {
        if (index >= cur_size_) {
            cur_size_++;
        }
        data_[index] = value;
    }
}

//
// find (value)
//
template <typename T>
int Array_Base <T>::find (T value) const
{
    for (int i = 0; i < cur_size_; i++) {
        if (data_[i] == value) {
            return i;
        }
    }
    return -1;
}

//
// find (value, start)
//
template <typename T>
int Array_Base <T>::find (T value, size_t start) const
{
    if (start >= cur_size_ || start < 0) {
        throw std::out_of_range ("out_of_range error: Index out of range for array");
    }
    else {
        for (int i = start; i < cur_size_; i++) {
            if (data_[i] == value) {
                return i;
            }
        }
        return -1;
    }
}

//
// get (index)
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
    if (index >= max_size_ || index < 0) {
        throw std::out_of_range ("out_of_range error: Index out of range for array");
    }
    else {
        return data_[index];
    }
}

//
// fill (value)
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for (int i = 0; i < max_size_; i++) {
        data_[i] = value;
    }
    cur_size_ = max_size_;
}

//
// reverse 
//
template <typename T>
void Array_Base <T>::reverse (void)
{
    if (cur_size_ > 0) {
        char placeholder;
        int length = cur_size_ / 2;
        for (int i = 0; i < length; i++) {
            placeholder = data_[i];
            data_[i] = data_[cur_size_ - (1+i)];
            data_[cur_size_ - (1+i)] = placeholder;
        }
    }
}

//
// slice (begin)
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin) const 
{
    if (cur_size_ > 0) {
        if (begin >= 0 && begin < cur_size_) {
            Array_Base <T> newArray(cur_size_ - begin);
            int counter = 0, i;
            char c;
            for (i = begin; i < cur_size_; i++) {
                c = data_[i];
                newArray.set(counter, c);
                counter++; 
            }
            return newArray;
        }
    }
    return *this;
}

//
// slice (begin, end)
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin, size_t end) const
{
    if (cur_size_ > 0) {
        if ((begin >= 0 && begin < cur_size_) && (end >= 0 && end < cur_size_)) {
            Array_Base <T> newArray(end - begin);
            int counter = 0, i;
            char c;
            for (i = begin; i < end; i++) {
                c = data_[i];
                newArray.set(counter, c);
                counter++; 
            }
            return newArray;
        }
    }
    return *this;
}