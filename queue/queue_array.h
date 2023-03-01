#define TOTAL_QUEUE_SIZE 10
#include <iostream>

template <typename T>
class Queue
{   
    public:
        Queue(); //constructor function of a Queue (O(1) time complexity)
        T pop_front(); //to remove first element of the Queue (O(1) time complexity)
        bool push_back(T); //to add new element to the end of the Queue (O(1) time complexity)
        bool isEmpty(); // it shows whether queue is empty or not (O(1) time complexity)
        bool isFull(); // it shows whether queue is full or not (O(1) time complexity)
        T peek_front(); // to obtain the first element of the queue (O(1) time complexity)
        T peek_back(); // to obtain the last element of the queue (O(1) time complexity)
        void clear(); // to empty entire Queue (O(1) time complexity)
        void print_Queue(); // to print entire Queue (O(n) time complexity n is the TOTAL_QUEUE_SIZE in this case)

    private:
        int front;
        int back;
        int number_of_elements;
        int arr[TOTAL_QUEUE_SIZE];
};

template <typename T>
Queue<T>::Queue()
{
    this->front = 0;
    this->back = -1;
    this->number_of_elements = 0;
}

template <typename T>
bool Queue<T>::push_back(T new_elem)
{
    if(!(this->isFull()))
    {
        this->back = (this->back + 1) % TOTAL_QUEUE_SIZE;
        arr[(this->back)] = new_elem; 
        this->number_of_elements++;
        return true;      
    }
    return false;
}

template <typename T>
T Queue<T>::pop_front()
{
    if(!(this->isEmpty()))
    {   
        T popped_element = arr[front];
        this->front = (this->front + 1) % 10;
        this->number_of_elements--;
        return popped_element;
    }
    throw std::logic_error( "Queue is empty so calling pop_front is not legal!" );
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return (this->number_of_elements) == 0;
}

template <typename T>
bool Queue<T>::isFull()
{
    return (this->number_of_elements) == TOTAL_QUEUE_SIZE;
}

template <typename T>
T Queue<T>::peek_front()
{
    if(!(this->isEmpty()))
    {
        return arr[front];   
    }
    throw std::logic_error( "Queue is empty so calling peek_front is not legal!" );
}

template <typename T>
T Queue<T>::peek_back()
{
    if(!(this->isEmpty()))
    {
        return arr[back];   
    }
    throw std::logic_error( "Queue is empty so calling peek_back is not legal!" );
}

template <typename T>
void Queue<T>::clear()
{
    number_of_elements = 0;
    front = 0;
    back = -1;
}

template <typename T>
void Queue<T>::print_Queue()
{
    if(!(this->isEmpty()))
    {
        for(int i = 0; i < TOTAL_QUEUE_SIZE; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
}