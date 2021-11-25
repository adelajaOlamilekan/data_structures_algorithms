 /* Start Date: 15/11/2021
    Completion Date: 15/11/2021
    Programmer: Adelaja Qowiyyu
*/

template <typename T>
struct Node
{
    T data;
    Node<T>* prev;
    Node(): prev(NULL) {};
    Node(T Data, Node<T>* Prev): data(Data), prev(Prev) {};
};


//Stack Error class; thrown for operation that requires stack to be filled
class Stack_Size_Error
{
public:
    void what();

};

template <typename T>
class Stack
{
private:
    int size;
    Node<T>* top_node;
public:
    Stack(): top_node(NULL), size(0) {};

    Stack(T data): top_node( new Node<T>(data, top_node) ), size(1) {};

    int get_size() { return size; }

    //Adds new node to the top of the stack
    void push(T);

    //Removes and returns the top-node from the stack
    void pop();

    /*  Checks if the stack is empty
        Return value: true if stack is empty
                      false otherwise
    */
    bool is_empty() { return !( bool(size) ); }

    //Prints the data value of the top-node
    T peek() { return top_node->data; }
};
