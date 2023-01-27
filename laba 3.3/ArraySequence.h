#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;
    int count;
public:
    ArraySequence(T* items, int count);
    ArraySequence(int size);
    ArraySequence();
    ArraySequence(const DynamicArray<T>* dynamicArray);
    ArraySequence(const ArraySequence<T>* dynamicArray);
    ~ArraySequence();
public:
    virtual T GetFirst()const override;
    virtual T GetLast()const override;
    virtual T Get(int index)const override;
    virtual int GetLength()const override;
    virtual void Remove(int index)override;
    virtual void Append(T item)override;
    virtual void Prepend(T item)override;
    virtual void InsertAt(T item, int index)override;
    virtual Sequence<T>* Concat(Sequence<T>* list) const override;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override;
    //virtual void Swap(int index1, int index2) override;
    //virtual Sequence<T>* QuickSort() override;
    //virtual Sequence<T>* QuickSort(int (*cmp)(T, T)) override;
    //virtual Sequence<T>* ShellSort() override;
    //virtual Sequence<T>* ShellSort(int (*cmp)(T, T)) override;
    //virtual Sequence<T>* MergeSort() override;
    //virtual Sequence<T>* MergeSort(int (*cmp)(T, T)) override;
    //virtual Sequence<T>* ShakerSort() override;
    //virtual Sequence<T>* ShakerSort(int (*cmp)(T, T)) override;
    friend std::ostream& operator<<(std::ostream&, const ArraySequence<T>&);
};

template <class T>
ArraySequence<T>::ArraySequence(T* items, int count) :count(count)
{
    this->items = new DynamicArray<T>(items, count);
}
template <class T>
ArraySequence<T>::ArraySequence(int size) : count(0)
{
    this->items = new DynamicArray<T>(size);
}

template <class T>
ArraySequence<T>::ArraySequence() : count(0)
{
    this->items = new DynamicArray<T>();
}

template <class T>
ArraySequence<T>::ArraySequence(const DynamicArray<T>* dynamicArray) :count(dynamicArray->GetCount())
{
    this->items = new DynamicArray<T>(*dynamicArray);
}
template <class T>
ArraySequence<T>::ArraySequence(const ArraySequence<T>* dynamicArray) : count(dynamicArray->GetCount())
{
    this->items = new DynamicArray<T>(*dynamicArray);
}

template <class T>
ArraySequence<T> :: ~ArraySequence()
{
    delete this->items;
}

template <class T>
T ArraySequence<T>::GetFirst() const
{
    return this->items->Get(0);
}

template <class T>
T ArraySequence<T>::GetLast()const
{
    return this->items->Get(this->items->GetCount() - 1);
}

template <class T>
T ArraySequence<T>::Get(int index) const
{
    return this->items->Get(index);
}

template <class T>
int ArraySequence<T> ::GetLength() const
{
    return this->items->GetCount();
}

template <class T>
void ArraySequence<T>::Remove(int index)
{
    this->count--;
    this->items->Remove(index);
}

template <class T>
void ArraySequence<T>::Append(T item)
{
    this->count++;
    this->items->Set(this->items->GetCount(), item);
}

template <class T>
void ArraySequence<T>::Prepend(T item)
{
    this->count++;
    this->items->Set(0, item);
}

template <class T>
void ArraySequence<T>::InsertAt(T item, int index)
{
    this->count++;
    this->items->Set(index, item);
}

template <class T>
Sequence<T>* ArraySequence<T>::Concat(Sequence<T>* list) const
{
    if (list == NULL) { errors(NULLPointer, "ArraySequence<T>::Concat(Sequence<T>* list) "); throw; }
    list = (ArraySequence*)list;
    ArraySequence<T>* result = new ArraySequence(this->items);
    for (int i = 0; i < list->GetLength(); i++)
    {
        result->Append(list->Get(i));
    }
    return result;
}

template <class T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) const
{
    if (startIndex > endIndex)
    {
        cout << "(startIndex > endIndex) in ArraySequence<T>::GetSubsequence(int startIndex, int endIndex)" << endl;
        throw;
    }
    else if (startIndex < 0)
    {
        errors(NegativeIndex, "ArraySequence<T>::GetSubsequence(int startIndex, int endIndex)->startIndex");
        throw;
    }
    else if (endIndex > this->items->GetCount())
    {
        errors(IndexOutOfRange, " ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) ");
        throw;
    }
    Sequence<T>* subSequence = new ArraySequence();
    for (int i = startIndex; i < endIndex + 1; i++)
    {
        subSequence->Append(this->Get(i));
    }
    return subSequence;
}
/*
template<typename T>
void ArraySequence<T>::Swap(int index1, int index2)
{
    if (index1 == index2) { return; }
    this->items->Swap(index1, index2);

}
template<typename T>
void QuickSortInside(ArraySequence<T>* seq, int start, int end) 
{
    auto partition = [&](ArraySequence<T>* seq, int start, int end)
    {
        T pivot = seq->Get(end);
        int pIndex = start;

        for (int i = start; i < end; i++)
        {
            if (seq->Get(i) <= pivot)
            {
                seq->Swap(i, pIndex);
                pIndex++;
            }
        }
        seq->Swap(pIndex, end);
        return pIndex;
    };
    if (start >= end)
    {
        return;
    }
    int pivot = partition(seq, start, end);
    QuickSortInside(seq, start, pivot - 1);
    QuickSortInside(seq, pivot + 1, end);
}
template<typename T>
Sequence<T>* ArraySequence<T>::QuickSort()
{
    ArraySequence<T>* seq = new ArraySequence<T>();
    for (int i = 0; i < this->GetLength(); i++)
    {
        seq->Append(this->Get(i));
    }
    QuickSortInside(seq, 0, seq->GetLength() - 1);
    return seq;
}
template<typename T>
void QuickSortInsideCmp (ArraySequence<T>* seq, int start, int end, int (*cmp)(T, T))
{
    auto partition = [&](ArraySequence<T>* seq, int start, int end)
    {
        T pivot = seq->Get(end);
        int pIndex = start;

        for (int i = start; i < end; i++)
        {
            if (cmp(seq->Get(i), pivot) == 0 || cmp(seq->Get(i), pivot) == 2)
            {
                seq->Swap(i, pIndex);
                pIndex++;
            }
        }
        seq->Swap(pIndex, end);
        return pIndex;
    };
    if (start >= end)
    {
        return;
    }
    int pivot = partition(seq, start, end);
    QuickSortInsideCmp(seq, start, pivot - 1,cmp);
    QuickSortInsideCmp(seq, pivot + 1, end , cmp);
}
template<typename T>
Sequence<T>* ArraySequence<T>::QuickSort(int (*cmp)(T, T))
{
    ArraySequence<T>* seq=new ArraySequence<T>();
    for (int i = 0; i < this->GetLength(); i++)
    {
        seq->Append(this->Get(i));
    }
    QuickSortInsideCmp(seq, 0, seq->GetLength() - 1,cmp);
    return seq;
}
template<typename T>
Sequence<T>* ArraySequence<T>::ShellSort() 
{
    T pass;
    ArraySequence<T>* seq = new ArraySequence<T>();
    for (int i = 0; i < this->GetLength(); i++)
    {
        seq->Append(this->Get(i));
    }
    for (int step = seq->GetLength() / 2; step > 0; step /= 2)
        for (int i = step; i < seq->GetLength(); i++)
        {
            pass = seq->Get(i);
            for (int j = i; j >= step; j -= step)
            {
                if (pass < seq->Get(j - step))
                {
                    seq->Swap(j, j - step);
                }
                else
                {
                    break;
                }
            }
        }
    return seq;
}
template<typename T>
Sequence<T>* ArraySequence<T>::ShellSort(int (*cmp)(T, T)) 
{
    T pass;
    ArraySequence<T>* seq = new ArraySequence<T>();
    for (int i = 0; i < this->GetLength(); i++)
    {
        seq->Append(this->Get(i));
    }
    for (int step = seq->GetLength() / 2; step > 0; step /= 2)
        for (int i = step; i < seq->GetLength(); i++)
        {
            pass = seq->Get(i);
            for (int j = i; j >= step; j -= step)
            {
                if (cmp(pass,seq->Get(j - step))==0)
                {
                    seq->Swap(j, j - step);
                }
                else
                {
                    break;
                }
            }
        }
    return seq;
}
template<typename T>
Sequence<T>* ArraySequence<T>::MergeSort() 
{
    T pass;
    ArraySequence<T>* seq = new ArraySequence<T>();
    for (int i = 0; i < this->GetLength(); i++)
    {
        seq->Append(this->Get(i));
    }
    seq->items->MergeSort();
    return seq;
}
template<typename T>
Sequence<T>* ArraySequence<T>::MergeSort(int (*cmp)(T, T)) 
{
    T pass;
    ArraySequence<T>* seq = new ArraySequence<T>();
    for (int i = 0; i < this->GetLength(); i++)
    {
        seq->Append(this->Get(i));
    }
    seq->items->MergeSort(cmp);
    return seq;
}
template<typename T>
Sequence<T>* ArraySequence<T>::ShakerSort()
{
    T pass;
    ArraySequence<T>* seq = new ArraySequence<T>();
    for (int i = 0; i < this->GetLength(); i++)
    {
        seq->Append(this->Get(i));
    }
    seq->items->ShakerSort();
    return seq;
}
template<typename T>
Sequence<T>* ArraySequence<T>::ShakerSort(int (*cmp)(T, T)) 
{
    T pass;
    ArraySequence<T>* seq = new ArraySequence<T>();
    for (int i = 0; i < this->GetLength(); i++)
    {
        seq->Append(this->Get(i));
    }
    seq->items->ShakerSort(cmp);
    return seq;
}*/
