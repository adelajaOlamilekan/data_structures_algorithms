/* Date Started: 14/11/2021
   Date Completed: 15/11/2021
   Programmer: Adelaja Qowiyyu
*/

//Contains a doubly linked list class

#define head_position 1

namespace LINKED_LIST{

template<typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
    Node(T Data, Node* Next, Node* Prev): data(Data), next(Next), prev(Prev) {};
    Node(): next(NULL), prev(NULL) {};
};

template<typename T>
class Doubly_Linked_List
{ 
public:
    Doubly_Linked_List(): head(NULL), last_node(NULL), size(0) {};
    Doubly_Linked_List(T data): head( new Node<T>(data, NULL, NULL) ), last_node(head),size (1) {};
    int get_size(){ return size; }
    Node<T>* get_head() { return head; }
    void insert_at_end(T);
    void insert_at_beginning(T);
    void insert_at_position(T, int);
    void delete_at_position(int);
    void print();
    void reverse_print();

private:
    Node<T>* head;
    Node<T>* last_node;
    int size;
};

}
