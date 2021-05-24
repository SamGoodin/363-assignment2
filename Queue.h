#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <cstring>

template <typename T>
class Queue : public Array <T> 
{
    public:
        typedef T type;

        //Constructors/Destructor
        Queue(void);
        Queue(const Queue & queue);
        ~Queue(void);

        //Operator Overloading
        const Queue <T> & operator = (const Queue <T> & rhs);

        //Methods
        void enqueue(T element);
        T dequeue(void);
        bool is_empty(void);
        size_t getSize(void);
        void clear(void);

    private:
  // COMMENT Per the assignment directions, you are required to use the
  // Array class from assignment 1. Becasue you failed to follow directions
  // you will not be receiving any feedback on your stack implementation.
  
        //Implemented Queue using Arrays
        //Member variables
        //size_t size;

        //T * data_;
};

#include "Queue.cpp"

#endif
