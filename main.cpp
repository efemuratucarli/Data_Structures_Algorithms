/*
@author: efemuratucarli
date: 26/02/2023
*/

#include "Stack_array.h"
#include <iostream>

void stack_examples();

int main()
{
    stack_examples();
    return 0;
}

void stack_examples()
    {
        Stack<int> new_stack; //creating an instance of a Stack class which consists of ints
        for(int i = 0; i < 10 ; i++)
        {
            new_stack.push(i*2);
        }
        new_stack.printStack();
        std::cout << "next test" <<std::endl;
        for(int i = 0; i < 10 ; i++)
        {
            std::cout << new_stack.pop() << std::endl;
        }
        std::cout << "next test" <<std::endl;
        for(int i = 0; i < 10 ; i++)
        {
            new_stack.push(i*2);
        }
        new_stack.clear();
        new_stack.pop();
    }