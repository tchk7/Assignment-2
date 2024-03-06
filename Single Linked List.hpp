#ifndef Single_Linked_List_hpp
#define Single_Linked_List_hpp

#include <stdio.h>

template <typename type>
class singleLinkedList {
private:
    
    // Stucture of the node
    struct Node {
        
        //Data to be stored in the node
        type data;
        
        //Pointer for the next node
        Node* next;
        
        //Constructor of node
        Node(const type& value, Node* nextPoint = nullptr) : data(value), next(nextPoint) {}
    };
    
    //Pointer to first node
    Node* head;
    
    //Pointer to last node
    Node* tail;
    
    //Number of items in list
    size_t num_items;
    
public:
    
    //Linkeed List Constructor
    singleLinkedList();
    
    //Linked List Deconstructor
    ~singleLinkedList();
    
    //Add item to the front
    void push_front(const type& item);
    
    //Add item to the back
    void push_back(const type& item);
    
    //Remove item from the front
    void pop_front();
    
    //Remove item from the back
    void pop_back();
    
    //Get value of first item
    const type& front();
    
    //Get value of last item
    const type& back();
    
    //Check if list is empty
    bool empty();
    
    //Insert an item at position
    void insert(size_t index, const type& item);
    
    //Remove item at position
    bool remove(size_t index);
    
    //Find position of item
    size_t find(const type& item);
    
    //Access num_items
    size_t size() const;
    
    //Access an index
    const type& operator[](size_t index);
    
    //Prints the list
    void print();
};

#endif 
