/* Date Started: 14/11/2021
   Date Completed: 15/11/2021
   Programmer: Adelaja Qowiyyu
*/

//Contains Implementation of doubly linked list class


#include<iostream>
#include "doubly_linked_list.h"

using std::cout;
using std::endl;

namespace LINKED_LIST{

template<typename T>
void Doubly_Linked_List<T>::insert_at_end(T data)
{
    if( head == NULL){
        last_node = new Node<T>(data, NULL, NULL);
        head = last_node;
    }
    else{
        last_node->next = new Node<T>(data, NULL, last_node);
        last_node = last_node->next; 
    }
    ++size;
    return;
}

template<typename T>
void Doubly_Linked_List<T>::insert_at_beginning(T data)
{
    Node<T>* new_node = new Node<T>(data, head, NULL);
    head->prev = new_node;
    head = new_node;
    ++size;
}

template<typename T>
void Doubly_Linked_List<T>::insert_at_position(T data, int position)
{
    if(position <= head_position){
        insert_at_beginning(data);
        return;
    }
    else if( position > size){
        insert_at_end(data);
        return;
    }
    else{
        Node<T>* target_node = head;

        for(int count = 1; count < position; ++count)
            target_node = target_node->next;
        Node<T>* node_before_target = target_node->prev;
        Node<T>* new_node = new Node<T>(data, target_node, node_before_target);
        target_node->prev = new_node;
        node_before_target->next = new_node;
        ++size;
        return;
    }

    
}

template<typename T>
void Doubly_Linked_List<T>::delete_at_position(int position)
{   
    Node<T>* target_node = head;
    Node<T>* node_before_target = NULL;
    Node<T>* node_after_target = NULL;

    if(position == head_position){
        node_after_target = target_node->next;
        node_after_target->prev = NULL;
        delete target_node;
        --size;
        head = node_after_target;
        return;
    }
    else if(position == size){
        target_node = last_node;
        node_before_target = target_node->prev;
        node_before_target->next = NULL;
        delete target_node;
        --size;
        last_node = node_before_target;
        return;
    }
    else{
        for(int count = 1; count < position; ++count)
            target_node = target_node->next;
    
        node_before_target = target_node->prev;
        node_after_target = target_node->next;

        node_before_target->next = node_after_target;
        node_after_target->prev = node_before_target;

        delete target_node;
        --size;
        return;
    }

}

template<typename T>
void Doubly_Linked_List<T>::print()
{
    Node<T>* current_node = head;

    while(current_node != NULL){
        cout << current_node->data <<endl;
        current_node = current_node->next;
    }
}

template<typename T>
void Doubly_Linked_List<T>::reverse_print()
{
    Node<T>* current_node = last_node;
    while(current_node != NULL){
        cout << current_node->data << endl;
        current_node = current_node->prev;
    }
}

}
