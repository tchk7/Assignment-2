#include "Stack.hpp"

//Constructor
template <typename type>
Stack<type>::Stack() {}

//Check if stack is empty
template <typename type>
bool Stack<type>::isEmpty() const {
    
    return items.empty();
}

//Function to push item onto stack
template <typename type>
void Stack<type>::push(const type &item) {
    
    //Add item to the stack
    items.push_back(item);
}

//Function to remove item from top of stack
template <typename type>
void Stack<type>::pop() {
    
    //Check if stack is empty
    if (isEmpty()) {
        
        //Throw error
        throw runtime_error("Stack is empty.");
    }
    
    items.pop_back();
    
}

//Return value at top of stack
template <typename type>
const type& Stack<type>::top() {
    
    //Check if stack is empty
    if (isEmpty()) {
        
        //Throw error
        throw runtime_error("Stack is empty");
    }
    else {
        
        //Return top of the stack
        return items.back();
    }
}

//Find average of stack if values are numbers
template <typename type>
double Stack<type>::average() const {
    
    //Check if stack is empty
    if (isEmpty()) {
        
        //Throw error
        throw runtime_error("Stack is empty.");
    }
    
    //Initialize counter
    double total = 0.0;
    
    //iterate through stack
    for (size_t i = 0; i < items.size(); i++) {
        
        //Add item value to total
        total += items[i];
    }
    
    return total / items.size();
    
}
