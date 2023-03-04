#include "SingleLinkedList.h"

void Node_tests();
void SingleLinkedList_tests();
int main()
{
   /* Node_tests(); */
    SingleLinkedList_tests();
    return 0;
}

void Node_tests()
{
    Node<int> n {5};
    std::cout << n.get_data() <<std::endl;
    std::cout << n.get_next() <<std::endl;
}

void SingleLinkedList_tests()
{
    SingleLinkedList<int> *new_list = new SingleLinkedList<int>;
    for(int i = 0; i < 10; i++)
    {
        new_list->add(i*2);
    }
    new_list->print_list();
    new_list->clear();
    for(int i = 0; i < 10; i++)
    {
        new_list->add(i*2);
    }
    new_list->remove_first();
    new_list->print_list();
    new_list->remove(3);
    new_list->print_list();
    new_list->add_last(5);
    new_list->print_list();
    new_list->add(8,1);
    new_list->add_first(89);
    new_list->print_list();
    std::cout << new_list->get(1) << std::endl;
    std::cout << new_list->get_first() << std::endl;
    std::cout << new_list->get_last() << std::endl;
    std::cout << new_list->contains(729) << std::endl;
    std::cout << new_list->contains(8) << std::endl;
    new_list->remove(777); //throws logical error as expected(IndexOutOfBounds)
    delete new_list;
}