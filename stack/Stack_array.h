/*
@author: efemuratucarli
date: 26/02/2023
*/

#define TOTAL_STACK_SIZE 10
#include <stdexcept>
#include <iostream>

template <typename T> 
class Stack //array implementation of Stack data structure(using LIFO principle)
{
    private:
        int top;
        T arr[TOTAL_STACK_SIZE];
    
    public:
        Stack(); //constructor function of a Stack (O(1) complexity)
        bool push(T); //to add a new element (O(1) complexity)
        T  pop(); //to remove last element (O(1) complexity)
        bool isEmpty(); //it shows whether stack is empty or not (O(1) complexity)
        bool isFull(); //it shows whether stack is full or not (O(1) complexity)
        void clear(); //to empty entire Stack (O(1) complexity)
        T peek(); //it returns the element at the top of the stack (O(1) complexity)
        void printStack(); //it prints the entire stack (O(n) complexity n is TOTAL_STACK_SIZE in this case)
};

template <typename T>
Stack<T>::Stack()
{
    this->top = -1;
}

template <typename T>
bool Stack<T>::push(T new_element)
{
    if(!this->isFull())
    {
        this->arr[++top] = new_element;
        return true;
    }
    return false;
}

template <typename T>
T Stack<T>::pop()
{
    if(!this->isEmpty())
    {
        return arr[top--];
    }
    throw std::logic_error( "Stack is already empty so calling pop is not legal!" );
}

template <typename T>
bool Stack<T>::isEmpty(){
    return top == -1;
}

template <typename T>
bool Stack<T>::isFull()
{
    return top == TOTAL_STACK_SIZE;
}

template <typename T>
void Stack<T>::clear()
{
    this->top = -1;
}

template <typename T>
T Stack<T>::peek()
{
    if(!this->isEmpty())
    {
        return this->arr[top];
    }
    throw std::logic_error( "Stack is empty so calling peek is not legal!" );
}
template <typename T>
void Stack<T>::printStack()
{
    int temp = 0;
    for(int i = 0;i<TOTAL_STACK_SIZE;i++)
    {
        std::cout << this->arr[i] <<std::endl;
    }
}