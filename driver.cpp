#include <iostream>
#include <exception>
#include <stdexcept>

#include "Array.h"
#include "Fixed_Array.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main (int argc, char * argv [])
{
    
    Queue <int> queue;
    cout << "Empty: " << queue.is_empty() << "\n";
    queue.enqueue(7);
    queue.enqueue(6);
    queue.enqueue(5);
    queue.clear();
    cout << "Empty: " << queue.is_empty() << "\n";
	
}
