#include <iostream>
#include "Single Linked List.cpp"
#include "Stack.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    singleLinkedList<int> list;
    
    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    cout << "List after push_front: ";
    list.print();
    cout << endl;
    
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    
    cout << "List after push_back: ";
    list.print();
    cout << endl;
    
    list.pop_front();
    
    cout << "List after pop_front: ";
    list.print();
    cout << endl;
    
    list.pop_back();
    
    cout << "List after pop_back: ";
    list.print();
    cout << endl;
    
    cout << "Item at front is: " << list.front() << endl;
    
    cout << "Item at back is: " << list.back() << endl;
    
    list.insert(4, 20);
    
    cout << "List after inserting 20 at index 4: ";
    list.print();
    cout << endl;
    
    list.remove(4);
    
    cout << "List after removing index 4: ";
    list.print();
    cout << endl;
    
    cout << "Finding the index of number 20: " << list.find(20) << endl;

    Stack<int> stack;
    
    cout << "Is stack empty: " << stack.isEmpty() << endl;
    
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    
    cout << "Is stack empty: " <<stack.isEmpty() << endl;
    
    cout << "Top of stack is: " << stack.top() << endl;
    
    stack.pop();
    
    cout << "New top of stack is: " << stack.top() << endl;
    
    cout << "Average value of stack is: " << stack.average() << endl;
    
        
        
    return 0;
}
