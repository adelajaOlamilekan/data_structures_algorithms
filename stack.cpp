#include<iostream>
#include "stack.h"

using std::cout;
using std::endl;

void Stack_Size_Error::what()
{ 
    cout << "Stack is empty\n"; 
}

template <typename T>
void Stack<T>::push(T data)
{
    top_node = new Node<T>(data, top_node);
    ++size;
}

template<typename T>
void Stack<T>::pop()
{
    try{
        if( this->is_empty() )
             throw Stack_Size_Error{};

        Node<T>* prev_top_node = top_node;
        top_node = top_node->prev;
        delete prev_top_node;
        --size;
    }

    catch(Stack_Size_Error& error){
        error.what();
        return;
    }

}