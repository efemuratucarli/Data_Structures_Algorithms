#include "queue_array.h"

void test_queue();

int main()
{ 
    test_queue();
    return 0;
}

void test_queue()
{
    Queue<int> queue;
    for(int i = 0; i < TOTAL_QUEUE_SIZE ; i++)
    {
        queue.push_back(i);
    }
    queue.print_Queue();
    for(int i = 0; i < TOTAL_QUEUE_SIZE ; i++)
    {
        queue.pop_front();
    }
    queue.pop_front(); //expected thing to throw logical error and terminate the program
}