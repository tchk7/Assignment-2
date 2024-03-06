#include "Single Linked List.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

//Constructor
 template <typename type>
singleLinkedList<type>::singleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

//Deconstructor
template <typename type>
singleLinkedList<type>::~singleLinkedList() {
    
    //Check if empty
    while (!empty()) {
        
        //Remove items until empty
        pop_front();
    }
}

//Add item to the front
template <typename type>
void singleLinkedList<type>::push_front(const type& item){
    
    Node* newNode = new Node(item);
    
    //Check if list is empty
    if (empty()) {
        
        //Set newNode as head and tail
        head = tail = newNode;
    }
    else {
        //Set newNode next to current head
        newNode->next = head;
        //Update head to newNode
        head = newNode;
        
    }
    num_items++;
    
}

//Add item to the back
template <typename type>
void singleLinkedList<type>::push_back(const type& item){
    
    Node* newNode = new Node(item);
    
    //Check if list is empty
    if (empty()) {
        
        //First node is head and tail
        head = tail = newNode;
    }
    else {
        //Set previous tail to newNode
        tail->next = newNode;
        //newNode is tail
        tail = newNode;
        
    }
    num_items++;
}

//Remove item from the front
template <typename type>
void singleLinkedList<type>::pop_front(){
    
    //Check if list is empty
    if (empty()) {
        
        //Throw Error
        throw runtime_error("Can't remove from empty list");
    }
    
    //Create temp node
    Node* temp = head;
    //Set next node as head
    head = head->next;
    //If there is no data tail should equal head
    if (head == nullptr) {
        
        tail = nullptr;
    }
    delete temp;
    num_items--;
}

//Remove item from the back
template <typename type>
void singleLinkedList<type>::pop_back(){
    
    //Check if list is empty
    if (empty()) {
        
        //Throw Error
        throw runtime_error("Can't remove from empty list");
    }
    
    Node* temp = tail;
    //If head is tail set node to null
    if(head == tail) {
        
        head = tail = nullptr;
    }
    else {
        
        //Node to track position
        Node* current = head;
        //Iterate through list until reached the end
        while (current->next != tail) {
            current = current->next;
        }
        
        //Next node is tail, set current to tail
        tail = current;
        tail->next = nullptr;
    }
    
    delete temp;
    num_items--;
}

//Get value of first item
template <typename type>
const type& singleLinkedList<type>::front(){
    
    //Check if list is empty
    if (empty()) {
        throw runtime_error("List is empty");
    }
    
    return head->data;
}

//Get value of last item
template <typename type>
const type& singleLinkedList<type>::back(){
    
    //Check if list is empty
    if (empty()) {
        throw runtime_error("List is empty");
    }
    
    return tail->data;

}

//Check if list is empty
template <typename type>
bool singleLinkedList<type>::empty(){
    
    return num_items == 0;
}

//Insert an item at position
template <typename type>
void singleLinkedList<type>::insert(size_t index, const type& item){
    
    //Throw error if index not in list
    if (index > num_items){
        throw out_of_range("Index not in list");
    }
    
    //Create new node
    Node* newNode = new Node(item);
    //Check if new node will be new head
    if(index == 0){
        
        push_front(item);
    }
    //Check if new node will be new tail
    else if (index == num_items){
        
        push_back(item);
    }
    else {
        
        //Create iterator node
        Node* current = head;
        
        //Iterate through linked list
        for (size_t i = 0; i < index; i++) {
            
            current = current->next;
        }
        //Found insert point
        //Set new node next to current next
        newNode->next = current->next;
        
        //Set current next to new node
        current->next = newNode;
        
        num_items++;
    }
}

//Remove item at position
template <typename type>
bool singleLinkedList<type>::remove(size_t index){
    
    //Throw error if index not in list
    if (index >= num_items){
        throw out_of_range("Index not in list");
        return false;
    }
    
    //Create interator node
    Node* current = head;
    
    //Create last node tracker
    Node* last = nullptr;
    
    //Iterate through list
    for(size_t i = 0; i < index; i++) {
        
        //Last will equal current
        last = current;
        current = current->next;
    }
    //Check if index is zero
    if (last == nullptr) {
        
        //Remove first node
        pop_front();
    }
    //Check if index is last node
    else if (current == tail) {
        
        //Remove last node
        pop_back();
    }
    else {
        //Set last node next to current node next
        last->next = current->next;
        
        //Delete current node
        delete current;
        
        num_items--;
    }
    
    return true;
    
}

//Find position of item
template <typename type>
size_t singleLinkedList<type>::find(const type& item){
    
    //Create iterator node
    Node* current = head;
    
    //Iterate through list
    for (size_t i = 0; i < num_items; i++) {
        
        //Check if current node contains item
        if (current->data == item) {
            
            return i;
        }
        
        current = current->next;
    }
    
    return num_items;
}

//Access num items
template <typename type>
size_t singleLinkedList<type>::size() const {
    
    return num_items;
}

//Access the index
template <typename type>
const type& singleLinkedList<type>::operator[](size_t index) {
    
    //Check if index is out of range
    if (index >= num_items) {
        
        throw out_of_range("Index not in list");
    }
    
    //Create iterator node
    Node* current = head;
    
    //Iterate through list
    for (size_t i = 0; i < index; i++) {
        
        current = current->next;
    }
    
    return current->data;
}

template <typename type>
void singleLinkedList<type>::print() {
    
    //Check if list is empty
    if (empty()) {
        
        throw runtime_error("List is empty");
    }
    
    //Create tracker node
    Node* current = head;
    
    //Iterate through list
    for (size_t i = 0; i < num_items; i++) {
        
        //If last item in list
        if (i == num_items - 1) {
            
            //Only print item
            cout << current->data;
        }
        else {
            
            //Print spacer between items
            cout << current->data << ", ";
            
        }
        
        current = current->next;

    }
}
