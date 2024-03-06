#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <vector>
using namespace std;

template <typename type>
class Stack {
    
private:
    //Vector to store items
    vector<type> items;
    
public:
    //Stack Constructor
    Stack();
    
    //Check if stack is empty
    bool isEmpty() const;
    
    //Function to push item onto stack
    void push(const type& item);
    
    //Function to remove item from top of stack
    void pop();
    
    //Return value at top of stack
    const type& top();
    
    //Find average of stack if values are numbers
    double average() const;
    
};

#endif
