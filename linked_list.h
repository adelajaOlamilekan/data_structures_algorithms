/* Date Started: 05/11/2021
   Date Completed: 13/11/2021
*/

//This contains an implemntation of a single linked list.
//It is a zero indexed linked list i.e first element is at position zero(0)

#define empty NULL
#define HEAD 0


struct Node{
    int data;
    Node* next;
    Node(): next(NULL) {};
    Node(int DATA, Node* NEXT): data(DATA), next(NEXT) {};
};

class Linked_List
{
private:
    Node* head;
    int size;
public:
    Linked_List(): head(empty), size(0) {};

    //Returns the amount of nodes in the list
    int get_size(){return size;}

    //Returns the head of the list
    Node* get_head(){return head;}
    
    //Takes the value to be inserted as parameter
    void insert_at_end(int);

    //Takes the value to be inserted as parameter
    void insert_at_beginning(int);

    //Takes the value and position to be inserted as parameter
    void insert_at_position(int, int);

    //Prints the list to the console
    void print();

    //Deletes a node at a position 
    //If given position is invalid; no node is deleted 
    void delete_node_at_position(int);

    //Uses loop to reverse the linked list
    void reverse();

    //Parameter: Lists' head
    //Prints the list recursively
    void recursive_print(Node*);

    //Parameter: Lists' head
    //Prints the list in reverse recursively
    void recursive_reverse_print(Node*);

    //Parameter: Lists's head
    //Reverses the list recursively
    void recursive_reverse(Node*);    
};
