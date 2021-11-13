#include<iostream>
#include "linked_list.h"

using namespace std;


void Linked_List :: insert_at_beginning(int value){
    Node* new_node = new Node(value, head);
    head = new_node;
    ++size;            
}

 void Linked_List :: insert_at_end(int value){
    if( head == empty )
        head = new Node(value, NULL);
    else{
        Node* current_node = head;
        while(current_node->next != empty)
            current_node = current_node->next;
        current_node->next = new Node(value, NULL);
    }
    ++size;
}

void Linked_List :: insert_at_position(int value, int position){
    int count = 0;
    const int node_before_target = position-1;
    Node* current_node = head;

    //If position is less than or equal starting position(0), Node is added as the head
    if(position <= HEAD)
        insert_at_beginning(value);
    //Handling of case when position is greater than list size
    else if( position > size){
        insert_at_end(value);
        cout<<"\nInvalid node postion, node inserted at the end\n";
    }
    else{
        while(count < node_before_target){
            current_node = current_node->next;
            ++count;
        }
        Node* node_at_target = current_node->next;
        current_node->next = new Node(value, node_at_target);
        ++size;
    }            
}

void Linked_List :: print(){
    Node* current_node = head;
    while(current_node != empty){
        cout << current_node->data << endl;
        current_node = current_node->next;
    }
}

void Linked_List :: delete_node_at_position(int position){
    Node* node_after_target = NULL;

    if(position == HEAD){
        node_after_target = head->next;
        delete head;
        head = node_after_target;
        --size;
    }               
    //Do nothing to invalid position
    else if(position < 0 || position > size-1);
    else{
        int node_position = 0;
        const int one_node_away = position - 1;
        Node* current_node = head;
        while(node_position != one_node_away){
            current_node = current_node->next; 
            ++node_position;
        }
        node_after_target= current_node->next->next;   
        delete current_node->next;  
        current_node->next = node_after_target; 
        --size;              
    }            
}

void Linked_List :: reverse(){
    Node* prev_node = NULL;
    Node* current_node = head;
    Node* next_node = current_node->next;

    while(current_node != NULL){
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;       
    }
    head = prev_node;
} 

void Linked_List::recursive_print(Node* current_node){   
    if (current_node == NULL)
        return;
    cout<<current_node->data<<"\n";
    recursive_print(current_node->next);
}

void Linked_List::recursive_reverse_print(Node* current_node){
    if (current_node == NULL)
        return;
    recursive_reverse_print(current_node->next);
    cout<<current_node->data<<"\n";
}

void Linked_List :: recursive_reverse(Node* current_node)
{
    if( current_node->next == NULL){
        head = current_node;
        return;
    }
    recursive_reverse(current_node->next);
    Node* next_node = current_node->next;
    next_node->next = current_node;
    current_node->next = NULL;
}

int main()
{
    Linked_List myList;
    myList.insert_at_beginning(0);
    myList.insert_at_position(1,1);
    myList.insert_at_end(2);
    myList.insert_at_end(3);
    myList.insert_at_end(4);
    myList.insert_at_end(5);
    myList.insert_at_end(6);
    myList.insert_at_end(7);
    myList.insert_at_end(8);

    cout<<myList.get_size();
}