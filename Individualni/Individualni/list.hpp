#ifndef LIST_DEF
#define LIST_DEF

template<class T>
class List
{
private:
    struct Node
    {
        T* element;
        Node* next;
        Node* previous;
    };
    Node* first;
    Node* last;
    int length;
public:
    List<T>()
    {
        first = null;
        last = null;
        length = 0;
    }

    int Length()const{ return length; }

    void Add(T* element);

    void Add(T element){ Add(new T(element)); }

    void Remove(T* element);

    void Remove(T element);

    void RemoveAt(int index);

    T& operator[](int index);

    ~List<T>() 
    {
        while (length > 0)
        {
            RemoveAt(0);
        }
    };
};

template <class T>
void List<T>::Add(T* element)
{
    Node* node = new Node;
    node->element = element;
    node->next = null;
    node->previous = null;
    if (first == null)
    {
        first = node;
        last = node;
        length = 1;
        return;
    }
    last->next = node;
    node->previous = last;
    last = node;
    length += 1;
}

template <class T>
void List<T>::Remove(T* element)
{
    Node* current = first;
    for (int i = 0; i < length; i++)
    {
        if (current->element == element)
        {
            RemoveAt(i);
            break;
        }
        current = current->next;
    }
}
template <class T>
void List<T>::Remove(T element)
{
    Node* current = first;
    for (int i = 0; i < length; i++)
    {
        if (*(current->element) == element)
        {
            RemoveAt(i);
            break;
        }
        current = current->next;
    }
}
template <typename T>
void List<T>::RemoveAt(int index)
{

    {
        if (index < 0 || index >= length)
            return;
        Node* temp;
        if (index == 0)
        {
            temp = first;
            first = first->next;
            if (length == 1)
            {
                last = null;
            }
        }
        else if (index == length - 1)
        {
            temp = last;
            last = last->previous;
            last->next = null;
        }
        else
        {
            if (index < length / 2)
            {
                temp = first;
                for (int i = 0; i < index; i++)
                {
                    temp = temp->next;
                }
            }
            else
            {
                temp = last;
                for (int i = length - 1; i > index; i--)
                {
                    temp = temp->previous;
                }
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
        }
        length -= 1;
        delete temp;

    }
}
template <typename T>
T& List<T>::operator[](int index)
{
    if (index < 0 || index >= length)
    {
        cout << "\n**************************************\nERROR ACCESING ELEMENT WITH INDEX " << index << "\n**************************************";
    }
    Node* temp;
    if (index < length / 2)
    {
        temp = first;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
    }

    else
    {
        temp = last;
        for (int i = length - 1; i > index; i--)
        {
            temp = temp->previous;
        }
    }
    return *(temp->element);
}
#endif