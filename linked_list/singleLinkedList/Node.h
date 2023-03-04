template <typename T>
class Node
{
    public:
        Node(T data);
        ~Node();
        T get_data();
        Node* get_next();
        void set_data(T data);
        void set_next(Node<T> *next);
    
    private:
        T data;
        Node<T>* next;
};

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
}

template <typename T>
Node<T>::~Node()
{
    if(this->get_next() != nullptr)
    {
        delete this->get_next();
    }
}

template <typename T>
T Node<T>::get_data()
{
    return this->data;
}

template <typename T>
Node<T>* Node<T>::get_next()
{
    return this->next;
}

template <typename T>
void Node<T>::set_data(T data)
{
    this->data = data;
}

template <typename T>
void Node<T>::set_next(Node<T> *next)
{
    this->next = next;
}