template <typename T>
class DoublyNode
{
    public:
        DoublyNode(T data);
        ~DoublyNode();
        T get_data();
        DoublyNode<T>* get_next();
        DoublyNode<T>* get_prev();
        void set_data(T data);
        void set_next(DoublyNode<T>* next);
        void set_prev(DoublyNode<T>* prev);
    
    private:
        T data;
        DoublyNode<T>* next;
        DoublyNode<T>* prev;
};

template <typename T>
DoublyNode<T>::DoublyNode(T data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template <typename T>
DoublyNode<T>::~DoublyNode()
{
    if(this->get_next() != nullptr)
    {
        delete this->get_next();
    }
}

template <typename T>
T DoublyNode<T>::get_data()
{
    return this->data;
}

template <typename T>
DoublyNode<T>* DoublyNode<T>::get_next()
{
    return this->next;
}

template <typename T>
DoublyNode<T>* DoublyNode<T>::get_prev()
{
    return this->prev;
}

template <typename T>
void DoublyNode<T>::set_data(T data)
{
    this->data = data;
}

template <typename T>
void DoublyNode<T>::set_next(DoublyNode<T> *next)
{
    this->next = next;
}

template <typename T>
void DoublyNode<T>::set_prev(DoublyNode<T>* prev)
{
    this->prev = prev;
}