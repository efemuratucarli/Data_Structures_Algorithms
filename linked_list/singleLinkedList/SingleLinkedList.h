#include "Node.h"
#include <iostream>

template <typename T>
class SingleLinkedList
{
    public:
        SingleLinkedList(); //constructor function of a Single Linked List (O(1) time complexity)
        ~SingleLinkedList(); //destructor function of a Single Linked List(O(n) time complexity)
        void clear(); //clears the entire list and sets head and tail data members to nullptr (O(n) time complexity)
        int size(); //returns the number of elements in the single linked list (O(1) time complexity)
        void add_first(T data); //inserts the specified element at the beginning of the Single Linked list (O(1) time complexity)
        void add_last(T data); //inserts the specified element at the end of the Single Linked list (O(1) time complexity)
        void add(T data); //this function is overloaded in order to call it with non-static member function
        void add(T data,int index); //inserts the specified element to the specified index of the Single Linked list (O(n) time complexity)
        void remove_first(); //removes first element of the Single Linked List (O(1) time complexity)
        void remove(int index = 0); //removes the element in the specified index (O(n) time complexity)
        T get_first(); //returns the first element of the Single Linked List (O(1) time complexity)
        T get_last(); //returns the last element of the Single Linked List (O(1) time complexity)
        T get(int index); //returns the element in the specified index (O(n) time complexity)
        bool contains(T data); //returns true if the element is in the linked list (O(n) time complexity)
        void print_list(); //prints the Single Linked List (O(n) time complexity)

    private:
        Node<T> *head;
        Node<T> *tail;
        int number_of_nodes;
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    number_of_nodes = 0;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    if(head != nullptr)
    {
        delete head;
    }
}

template <typename T>
void SingleLinkedList<T>::clear()
{
    if(head != nullptr)
    {
        delete head;
    }
    head = nullptr;
    tail = nullptr;
    number_of_nodes = 0;
}

template <typename T>
int SingleLinkedList<T>::size()
{
    return this->number_of_nodes;
}

template <typename T>
void SingleLinkedList<T>::add_first(T data)
{
    if(head == nullptr)
    {
        Node<T> *new_element = new Node<T> {data};
        head = new_element;
        tail = new_element;
        number_of_nodes++;
    }
    
    else
    {
        Node<T> *new_element = new Node<T> {data};
        new_element->set_next(head);
        head = new_element;
        number_of_nodes++;
    }
}

template <typename T>
void SingleLinkedList<T>::add_last(T data)
{
    if(tail == nullptr)
    {
        Node<T> *new_element = new Node<T> {data};
        tail = new_element;
        head = new_element;
        number_of_nodes++;
    }
    
    else
    {
        Node<T> *new_element = new Node<T> {data};
        tail->set_next(new_element);
        tail = new_element;
        number_of_nodes++;
    }
}

template <typename T>
void SingleLinkedList<T>::add(T data)
{
    add(data,size());
}

template <typename T>
void SingleLinkedList<T>::add(T data,int index)
{
    if(index < 0 || index > size())
    {
        throw std::logic_error("IndexOutOfBounds: the index is out of range (index < 0 || index > size())" );
    }
    
    else if(index == 0)
    {
        add_first(data);
        return;
    }
    
    else if(index == size())
    {
        add_last(data);
        return;
    }
    
   else
    {
        Node<T> *new_element = new Node<T> {data};
        Node<T> *curr = head->get_next();
        Node<T> *prev = head;
        for(int i = 1; i < size(); i++)
        {
            if(i == index)
            {
                prev->set_next(new_element);
                new_element->set_next(curr);
                number_of_nodes++;
                return;
            }
            prev = prev->get_next();
            curr = prev->get_next();
        }
    }
}

template <typename T>
void SingleLinkedList<T>::remove_first()
{
    if(head != nullptr)
    {
        Node<T> *temp = head;
        head = head->get_next();
        temp->set_next(nullptr);
        delete temp;
        number_of_nodes--;
        return;
    }
    throw std::logic_error("NoSuchElement: the list is empty!" );
}

template <typename T>
void SingleLinkedList<T>::remove(int index)
{
    if(index >= this->size() || index < 0)
    {
        throw std::logic_error("IndexOutOfBounds: the index is out of range (index < 0 || index >= size())" );
    }
    else if(index == 0)
    {
        remove_first();
    }
    else
    {
        Node<T> *curr = head->get_next();
        Node<T> *prev = head;
        for(int i = 1; i < size() ; i++)
        {
            if(index == i && index == size() - 1)
            {
                prev->set_next(curr->get_next());
                curr->set_next(nullptr);
                tail = prev;
                delete curr;
                number_of_nodes--;
                break;
            }
           
            if(index == i)
            {
                prev->set_next(curr->get_next());
                curr->set_next(nullptr);
                delete curr;
                number_of_nodes--;
                break;
            }
            prev = prev->get_next();
            curr = curr->get_next();
        }
    }
}

template <typename T>
T SingleLinkedList<T>::get_first()
{
    if(head != nullptr)
    {
        return head->get_data();
    }
    throw std::logic_error("NoSuchElement: the list is empty!" );
}

template <typename T>
T SingleLinkedList<T>::get_last()
{
    if(tail != nullptr)
    {
        return tail->get_data();
    }
    throw std::logic_error("NoSuchElement: the list is empty!" );
}

template <typename T>
T SingleLinkedList<T>::get(int index)
{
    if(index < 0 || index >= size())
    {
        throw std::logic_error("IndexOutOfBounds: the index is out of range (index < 0 || index >= size())" );
    }

    else if(index == 0)
    {
        return get_first();
    }

    else if(index == size() - 1)
    {
        return get_last();
    }

    else
    {
        Node<T> *temp = head->get_next();
        T wanted_data;
        for(int i = 1; i < size(); i++)
        {
            if(index == i)
            {
                wanted_data = temp->get_data();
                break;
            }
            temp = temp->get_next();
        }
        return wanted_data;
    }
}

template <typename T>
bool SingleLinkedList<T>::contains(T data)
{
    Node<T> *temp = head;
    while(temp != nullptr)
    {
        if(data == temp->get_data()) //for non primitve data structures specific object equality member function should be implemented
        {
            return true;
        }
        temp = temp->get_next(); 
    }
    return false;
}

template <typename T>
void SingleLinkedList<T>::print_list()
{
    Node<T> *temp = head;
    while(temp != tail && head != nullptr)
    {
        std::cout << temp->get_data() << " --> ";
        temp = temp->get_next();
    }
    
    if(temp != nullptr)
    {
        std::cout << temp->get_data() << std::endl;
    }
}