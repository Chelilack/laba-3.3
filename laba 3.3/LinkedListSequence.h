#pragma once
#include "Sequence.h"
#include "LinkedList.h"
template <class T>
class LinkedListSequence :public Sequence<T>
{
private:
    LinkedList<T>* items;
    int lenght;
public:
    LinkedListSequence(T* items, int count);
    LinkedListSequence();
    LinkedListSequence(const LinkedList <T>* list);
    ~LinkedListSequence();
public:
    virtual T GetFirst()const;
    virtual T GetLast()const;
    virtual T Get(int index)const;
    virtual int  GetLength()const override;
    virtual void Remove(int index)override;
    virtual void Append(T item)override;
    virtual void Prepend(T item)override;
    virtual void InsertAt(T item, int index)override;
    virtual Sequence<T>* Concat(Sequence<T>* list)const override;
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
};
template <class T>
LinkedListSequence<T>::LinkedListSequence(T* items, int count) : lenght(count)
{
    this->items = new LinkedList<T>(items, count);
}
template <class T>
LinkedListSequence<T>::LinkedListSequence() : lenght(0)
{
    this->items = new LinkedList<T>();
}
template <class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedList <T>* list) : lenght(list->GetLength())
{
    this->items = new LinkedList<T>(list);
}
template <class T>
LinkedListSequence<T>::~LinkedListSequence()
{
    delete this->items;
}


template <class T>
T LinkedListSequence<T>::GetFirst()const
{
    return this->items->GetFirst();
}

template <class T>
T LinkedListSequence<T>::GetLast()const
{
    return this->items->GetLast();
}

template <class T>
T LinkedListSequence<T>::Get(int index)const
{
    return this->items->Get(index);
}

template <class T>
int LinkedListSequence<T>::GetLength() const
{
    return this->lenght;
}

template <class T>
void LinkedListSequence<T>::Remove(int index)
{
    this->lenght--; this->items->Remove(index);
}

template <class T>
void LinkedListSequence<T>::Append(T item)
{
    this->lenght++; this->items->Append(item);
}

template <class T>
void LinkedListSequence<T>::Prepend(T item)
{
    this->lenght++; this->items->Prepend(item);
}

template <class T>
void LinkedListSequence<T>::InsertAt(T item, int index)
{
    this->lenght++; this->items->InsertAt(item, index);
}
template <class T>
Sequence<T>* LinkedListSequence<T>::Concat(Sequence<T>* list)const
{
    if (list == NULL) { errors(NULLPointer, "LinkedListSequence<T>::Concat(Sequence<T>* list)"); throw; }
    list = (LinkedListSequence*)list;
    LinkedListSequence<T>* concatedSequence = new LinkedListSequence(this->items);
    for (int i = 0; i < list->GetLength(); i++)
    {
        concatedSequence->Append(list->Get(i));
    }
    return (Sequence<T>*)concatedSequence;
}

template <class T>
Sequence<T>* LinkedListSequence<T>::GetSubsequence(int startIndex, int endIndex) const
{
    if (startIndex > endIndex)
    {
        cout << "(startIndex > endIndex) in LinkedListSequence<T>::GetSubsequence(int startIndex, int endIndex)" << endl;
        throw;
    }
    else if (startIndex < 0)
    {
        errors(NegativeIndex, "LinkedListSequence<T>::GetSubsequence(int startIndex, int endIndex)");
        throw;
    }
    else if (endIndex > this->items->GetLength())
    {
        errors(IndexOutOfRange, "LinkedListSequence<T>::GetSubsequence(int startIndex, int endIndex) ");
        throw;
    }
    Sequence<T>* subSequence = new LinkedListSequence();

    for (int i = startIndex; i < endIndex + 1; i++)
    {
        subSequence->Append(this->Get(i));
    }
    return subSequence;
}
//template<typename T>
//void LinkedListSequence<T>::Swap(int index1, int index2)
//{
//    if (index1 == index2) { return; }
//    this->items->Swap(index1, index2);
//
//
//}
//template<typename T>
//void QuickSortInside(LinkedListSequence<T>* seq, int start, int end)
//{
//    auto partition = [&](LinkedListSequence<T>* seq, int start, int end)
//    {
//        T pivot = seq->Get(end);
//        int pIndex = start;
//
//        for (int i = start; i < end; i++)
//        {
//            if (seq->Get(i) <= pivot)
//            {
//                seq->Swap(i, pIndex);
//                pIndex++;
//            }
//        }
//        seq->Swap(pIndex, end);
//        return pIndex;
//    };
//    if (start >= end)
//    {
//        return;
//    }
//    int pivot = partition(seq, start, end);
//    QuickSortInside(seq, start, pivot - 1);
//    QuickSortInside(seq, pivot + 1, end);
//}
//template<typename T>
//Sequence<T>* LinkedListSequence<T>::QuickSort()
//{
//    LinkedListSequence<T>* seq = new LinkedListSequence<T>();
//    for (int i = 0; i < this->GetLength(); i++)
//    {
//        seq->Append(this->Get(i));
//    }
//    QuickSortInside(seq, 0, seq->GetLength() - 1);
//    return seq;
//}
//template<typename T>
//void QuickSortInsideCmp(LinkedListSequence<T>* seq, int start, int end, int (*cmp)(T, T))
//{
//    auto partition = [&](LinkedListSequence<T>* seq, int start, int end)
//    {
//        T pivot = seq->Get(end);
//        int pIndex = start;
//
//        for (int i = start; i < end; i++)
//        {
//            if (cmp(seq->Get(i), pivot) == 0 || cmp(seq->Get(i), pivot) == 2)
//            {
//                seq->Swap(i, pIndex);
//                pIndex++;
//            }
//        }
//        seq->Swap(pIndex, end);
//        return pIndex;
//    };
//    if (start >= end)
//    {
//        return;
//    }
//    int pivot = partition(seq, start, end);
//    QuickSortInsideCmp(seq, start, pivot - 1, cmp);
//    QuickSortInsideCmp(seq, pivot + 1, end, cmp);
//}
//template<typename T>
//Sequence<T>* LinkedListSequence<T>::QuickSort(int (*cmp)(T, T))
//{
//    LinkedListSequence<T>* seq = new LinkedListSequence<T>();
//    for (int i = 0; i < this->GetLength(); i++)
//    {
//        seq->Append(this->Get(i));
//    }
//    QuickSortInsideCmp(seq, 0, seq->GetLength() - 1, cmp);
//    return seq;
//}
//template<typename T>
//Sequence<T>* LinkedListSequence<T>::ShellSort() 
//{
//    T pass;
//    LinkedListSequence<T>* seq = new LinkedListSequence<T>();
//    for (int i = 0; i < this->GetLength(); i++)
//    {
//        seq->Append(this->Get(i));
//    }
//    for (int step = seq->GetLength() / 2; step > 0; step /= 2)
//        for (int i = step; i < seq->GetLength(); i++)
//        {
//            pass = seq->Get(i);
//            for (int j = i; j >= step; j -= step)
//            {
//                if (pass < seq->Get(j - step))
//                {
//                    seq->Swap(j, j - step);
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//    return seq;
//}
//template<typename T>
//Sequence<T>* LinkedListSequence<T>::ShellSort(int (*cmp)(T, T)) 
//{
//    T pass;
//    LinkedListSequence<T>* seq = new LinkedListSequence<T>();
//    for (int i = 0; i < this->GetLength(); i++)
//    {
//        seq->Append(this->Get(i));
//    }
//    for (int step = seq->GetLength() / 2; step > 0; step /= 2)
//        for (int i = step; i < seq->GetLength(); i++)
//        {
//            pass = seq->Get(i);
//            for (int j = i; j >= step; j -= step)
//            {
//                if (cmp(pass, seq->Get(j - step)) == 0)
//                {
//                    seq->Swap(j, j - step);
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//    return seq;
//}
//template<typename T>
//Sequence<T>* LinkedListSequence<T>::MergeSort()
//{
//    T pass;
//    LinkedListSequence<T>* seq = new LinkedListSequence<T>();
//    for (int i = 0; i < this->GetLength(); i++)
//    {
//        seq->Append(this->Get(i));
//    }
//    seq->items->MergeSort();
//    return seq;
//}
//template<typename T>
//Sequence<T>* LinkedListSequence<T>::MergeSort(int (*cmp)(T, T))
//{
//    T pass;
//    LinkedListSequence<T>* seq = new LinkedListSequence<T>();
//    for (int i = 0; i < this->GetLength(); i++)
//    {
//        seq->Append(this->Get(i));
//    }
//    seq->items->MergeSort(cmp);
//    return seq;
//}
//template<typename T>
//Sequence<T>* LinkedListSequence<T>::ShakerSort()
//{
//    T pass;
//    LinkedListSequence<T>* seq = new LinkedListSequence<T>();
//    for (int i = 0; i < this->GetLength(); i++)
//    {
//        seq->Append(this->Get(i));
//    }
//    seq->items->ShakerSort();
//    return seq;
//}
//template<typename T>
//Sequence<T>* LinkedListSequence<T>::ShakerSort(int (*cmp)(T, T))
//{
//    T pass;
//    LinkedListSequence<T>* seq = new LinkedListSequence<T>();
//    for (int i = 0; i < this->GetLength(); i++)
//    {
//        seq->Append(this->Get(i));
//    }
//    seq->items->ShakerSort(cmp);
//    return seq;
//}