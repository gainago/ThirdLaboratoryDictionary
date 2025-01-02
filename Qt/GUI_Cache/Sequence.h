#ifndef SEQUENCE_H
#define SEQUENCE_H

template <typename T>
class Sequence
{
public:
    virtual T const & GetFirst() const = 0;
    virtual T const & GetLast() const = 0;
    virtual T const & Get(int index) const = 0;
    virtual int GetLength() const = 0;
    virtual Sequence<T>* Append(T const & item) = 0;
    virtual Sequence<T>* Prepend(T const & item) = 0;
    virtual Sequence<T>* InsertAt(T const & item, int index) = 0;
    virtual Sequence<T>* GetSubSequence(int startIndex, int endIndex) const = 0; // первый элемент включается, последний не включается
    virtual Sequence<T>* Concat(Sequence<T> const & seq) = 0;
    //virtual Sequence<T>* GetInstance() = 0;
    virtual Sequence<T>* GetNewSequence(int const size) = 0;
    virtual Sequence<T>* Set(int const index, T const & item) = 0;
    virtual T &operator[] (int index) = 0;

    bool operator==(const Sequence<T> &seq);


    bool operator!=(const Sequence<T> &seq);
    virtual ~Sequence() {}

};

template<typename T>  bool Sequence<T>::operator==(const Sequence<T> & Other)
{
    if (Other.GetLength() == this->GetLength())
    {
        for (int i = 0; i < this->GetLength(); i++)
        {
            if (this->Get(i) != Other.Get(i))
            {
                return false;
            }
        }
    }
    return Other.GetLength() == this->GetLength();
}
template<typename T>  bool Sequence<T>::operator!=(const Sequence<T> &seq)
{
    if (seq.GetLength() == this->GetLength())
    {
        for (int i = 0; i < this->GetLength(); i++)
        {
            if (this->Get(i) != seq.Get(i))
            {
                return true;
            }
        }
    }
    return seq.GetLength() != this->GetLength();
}


#endif