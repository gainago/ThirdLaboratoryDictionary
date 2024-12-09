#ifndef LINKED_LIST_H
#define LINKED_LIST_H


template <typename T> class LinkedList
{
private:
    int size;
    class Node
    {
    public:
        Node *pNext_;
        T data_;

        Node(T const & data = T(), Node *pNext = nullptr) : data_(data), pNext_(pNext)
        {}
    };

    Node *head_;

public:

    class Iterator{ // итератор не заботится о памяти на которую указывает
        private:

        Node* currentNode_;
        public:

            Iterator(Node* head = nullptr) : currentNode_(head) {}

            Iterator(Iterator const & other) : currentNode_(other.currentNode_) {}

            Iterator& operator++ ()     //prefix increment
            {
                if(currentNode_ == nullptr){
                    throw "indev out of range";
                }

                currentNode_ = currentNode_->pNext_;
                return *this; 
            }

            bool operator==(LinkedList<T>::Iterator const & other)
            {
                return this->currentNode_ == other.currentNode_;
            }

            bool operator!=(LinkedList<T>::Iterator const & other)
            {
                return !(this->currentNode_ == other.currentNode_);
            }

            void operator=(Iterator const & other)
            {
                currentNode_ = other.currentNode_;
            }

            T& operator*()
            {
                if(currentNode_ == nullptr){
                    throw "invalid index";
                }

                return currentNode_->data_;
            }
            


    };
    Iterator begin() { return Iterator(head_);}
    Iterator end() { return Iterator(nullptr);}
    
    LinkedList()
    {
        this->size = 0;
        this->head_ = nullptr;
    }

    LinkedList(int const size) : LinkedList()
    {
        if( size < 0)
        {    
            throw "Invalid size";
        }
        for(int i = 0; i < size; i++)
        {
            Append(T());
        }
    }

    LinkedList(T* items, int count) : LinkedList()
    {
        if (count < 0 || items == nullptr)
        {
            throw "Invalid argument";
        }
        for (int i = 0; i < count; i++)
        {
            Append(items[i]);
        }
    }

    LinkedList(const LinkedList<T> &list) : LinkedList()
    {
        Node *current = list.head_;
        for (int i = 0; i < list.size; i++)
        {
            Append(current->data_);
            current = current->pNext_;
        }
        this->size = list.size;
    }

    ~LinkedList()
    {
        Node *current = this->head_;
        Node *next;
        while (current != nullptr)
        {
            next = current->pNext_;
            delete current;
            current = next;
        }
        this->size = 0;
    }

    T const & GetFirst()
    {
        if (this->head_ == nullptr)
        {
            throw "Index out of range";
        }
        return this->head_->data_;
    }

    T const &GetLast()
    {
        Node *current = this->head_;
        if (this->head_ == nullptr)
        {
            throw "Index out of range";
        }
        for (int i = 0; i < this->size - 1; i++)
        {
            current = current->pNext_;
        }
        return current->data_;
    }

    T const & Get(int index) const
    {
        Node *current = this->head_;
        if (index < 0 || index >= this->size)
        {
            throw "Invalid argument";
        }
        for (int i = 0; i < index; i++)
        {
            current = current->pNext_;
        }
        return current->data_;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        if (startIndex < 0 || endIndex < 0 || endIndex >= this->size || endIndex < startIndex)
        {
            throw "Invalid argument";
        }
        LinkedList<T> *resultList = new LinkedList<T>();
        for (int i = startIndex; i < endIndex; i++)
        {
            resultList->Append(this->Get(i));
        }
        return resultList;
    }

    int GetLength() const
    {
        return this->size;
    }

    void Append(T const & item)
    {
        if (this->head_ == nullptr)
        {
            this->head_ = new Node(item);
        }
        else
        {
            Node *current = this->head_;
            for (int i = 1; i < this->size; i++)
            {
                current = current->pNext_;
            }
            current->pNext_ = new Node(item);
        }
        this->size++;
    }

    void Set(int const index, T const & item)
    {
        this->operator[](index) = item;
    }

    void Prepend(T const & item)
    {
        Node *newHead = new Node(item, this->head_);
        this->head_ = newHead;
        this->size++;
    }

    void InsertAt(T const & item, int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw "Invalid argument";
        }
        Node *newElement = new Node(item);
        Node *current = this->head_;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->pNext_;
        }
        newElement->pNext_ = current->pNext_;
        current->pNext_ = newElement;
        this->size++;
    }

    LinkedList<T>* Concat(LinkedList<T> &list)
    {
        LinkedList<T> *resultList = new LinkedList<T>();
        for (int i = 0; i < this->size; i++)
        {
            resultList->Append(this->Get(i));
        }
        for (int i = 0; i < list.size; i++)
        {
            resultList->Append(list.Get(i));
        }
        return resultList;
    }

    T &operator[] (int index)
    {
        if (index >= this->size || index < 0)
        {
            throw "Invalid argument";
        }

        Node *result = this->head_;

        for (int i = 0; i < index; i++)
        {
            result = result->pNext_;
        }
        return result->data_;
    }
};

#endif