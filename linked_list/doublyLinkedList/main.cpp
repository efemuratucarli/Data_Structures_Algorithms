#include "DoublyLinkedList.h"

void DoublyNode_tests();
void DoublyLinkedList_tests();
int main()
{
   /* DoubleNode_tests(); */
    DoublyLinkedList_tests();
    return 0;
}

void DoublyNode_tests()
{
    DoublyNode<int> n {5};
    std::cout << n.get_data() <<std::endl;
    std::cout << n.get_next() <<std::endl;
}

void DoublyLinkedList_tests()
{
    DoublyLinkedList<int>* new_list = new DoublyLinkedList<int>;
    for(int i = 0; i < 10; i++)
    {
        new_list->add(i*2);
    }
    
    new_list->print_list();
    new_list->print_reverse_list();
    new_list->clear();
    
    for(int i = 0; i < 10; i++)
    {
        new_list->add(i*2);
    }
    
    new_list->remove_first();
    new_list->print_list();
    new_list->print_reverse_list();
    new_list->remove(3);
    new_list->print_reverse_list();
    new_list->print_list();
    new_list->add_last(5);
    new_list->print_list();
    new_list->add(8,1);
    new_list->add_first(89);
    new_list->print_list();
    new_list->print_reverse_list();
    new_list->remove(10);
    new_list->print_list();
    new_list->print_reverse_list();
    std::cout << new_list->get(1) << std::endl;
    std::cout << new_list->get_first() << std::endl;
    std::cout << new_list->get_last() << std::endl;
    std::cout << new_list->contains(729) << std::endl;
    std::cout << new_list->contains(8) << std::endl;
    
    new_list->remove(777); //throws logical error as expected(IndexOutOfBounds)
    delete new_list;
}