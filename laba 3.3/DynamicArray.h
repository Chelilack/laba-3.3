#pragma once
#include "Errors.h"
#include <string.h>

using namespace std;

template<typename T>
class DynamicArray
{
private:
	T* arrayPointer;
	int size;
	int count;

public:
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(T* items, int count);
	DynamicArray(const DynamicArray<T>* dynamicArray);
	~DynamicArray();
public:
	int GetSize()const;
	int GetCount() const;
	T Get(int index) const;
	void Set(int index, T value);
	void Resize(int newSize);
	void Remove(int index);
	void Swap(int index1, int index2);
	void InsideMerge(int j, int  r, int  m);
	void MergeSort();
	void InsideMerge(int j, int  r, int  m, int (*cmp)(T, T));
	void MergeSort(int (*cmp)(T, T));
	void ShakerSort();
	void ShakerSort(int (*cmp)(T, T));
	//void Print();
};
template<typename T>
DynamicArray<T>::DynamicArray() : count(0) 
{
	this->arrayPointer = new T[0];
	this->size = 0;
}
template<typename T>
DynamicArray<T>::DynamicArray(int size) : count(0)
{
	if (size < 0)
	{
		errors(NegativeSize, "DynamicArray(int size)");
		throw;
	}
	this->arrayPointer = new T[size];
	this->size = size;
}

template<typename T>
DynamicArray<T> ::DynamicArray(T* items, int count) : size(count), count(count)
{
	if (count < 0)
	{
		errors(NegativeCount, "DynamicArray(T* items, int count)");
		throw;
	}
	else if (items == NULL) { errors(NULLPointer, "DynamicArray(T* items, int count)"); throw; }
	this->arrayPointer = new T[this->size];
	for (int i = 0; i < count; i++)
	{
		this->arrayPointer[i] = items[i];
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>* dynamicArray)
{
	if (dynamicArray == NULL) { errors(NULLPointer, "DynamicArray(const DynamicArray<T>* dynamicArray) "); throw; }
	this->arrayPointer = new T[dynamicArray->GetSize()];
	this->count = dynamicArray->GetCount();
	this->size = dynamicArray->GetSize();
	this->Resize(dynamicArray->GetSize());
	//memcpy(this->arrayPointer, dynamicArray->arrayPointer, dynamicArray->count * sizeof(T));
	for (int i = 0; i < dynamicArray->GetCount(); i++)
	{
		this->Set(i, dynamicArray->Get(i));
	}
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->arrayPointer;
}

template<typename T>
int DynamicArray<T>::GetSize() const
{
	return this->size;
}

template<typename T>
int DynamicArray<T>::GetCount() const
{
	return this->count;
}

template<typename T>
T DynamicArray<T>::Get(int index) const
{
	if (index < 0)
	{
		errors(NegativeIndex, "DynamicArray->Get()");
		throw;
	}
	else if (index >= this->GetSize()) { errors(IndexOutOfRange, "DynamicArray->Get()"); throw; }
	return this->arrayPointer[index];
}

template<typename T>
void DynamicArray<T>::Set(int index, T value)
{
	if (index < 0)
	{
		errors(NegativeIndex, "DynamicArray->Set()");
		throw;
	}
	this->count += 1;
	while (this->count + 1 > this->size)
	{
		this->Resize((this->GetSize()+1)*2);
	}
	memmove(this->arrayPointer + index + 1, this->arrayPointer + index, (this->count - index - 1) * sizeof(T));
	this->arrayPointer[index] = value;

}

template<typename T>
void DynamicArray<T>::Resize(int newSize)
{
	if (newSize < 0)
	{
		errors(NegativeSize, "DynamicArray->Resize()");
		throw;
	}
	else if (newSize == 0)
	{
		errors(ZeroSize, "DynamicArray->Resize()");
		throw;
	}
	T* newSizePointer = new T[newSize];
	int copySize = newSize > (this->size) ? this->size : newSize;
	memcpy(newSizePointer, this->arrayPointer, copySize * sizeof(T));
	this->count = newSize > this->size ? this->count : newSize;
	this->size = newSize;
	delete[] this->arrayPointer;
	this->arrayPointer = newSizePointer;
}

template<typename T>
void DynamicArray<T>::Remove(int index)
{

	if (index < 0)
	{
		errors(NegativeIndex, "DynamicArray->Remove()");
		throw;
	}
	else if (index >= this->GetCount()) { errors(IndexOutOfRange, "DynamicArray->Remove()"); throw; }
	this->count -= 1;
	memmove(this->arrayPointer + index, this->arrayPointer + (index + 1), (this->count - index) * sizeof(T));
}
/*template<typename T>
void DynamicArray<T>::Print()
{
	for (int i = 0; i < this->GetCount(); i++)
	{
		cout << this->Get(i);
	}
	cout << endl;
}*/
//template<typename T>
//void DynamicArray<T>::Swap(int index1, int index2) 
//{
//	std::swap(this->arrayPointer[index1], this->arrayPointer[index2]);
//}
//template<typename T>
//void DynamicArray<T>:: InsideMerge(int j,int  r,int  size ) 
//{
//	if (j + r < this->count)
//	{
//		if (size == 1)
//		{
//			if (this->arrayPointer[j] > this->arrayPointer[j + r])
//			{
//				Swap(j, j + r);
//			}
//		}
//		else
//		{
//			size = size / 2;
//			InsideMerge(j, r, size);
//			if (j + r + size < this->count)
//			{
//				InsideMerge(j + size, r, size);
//			}
//			InsideMerge(j + size, r - size, size);
//		}
//	}
//}
//template<typename T>
//void DynamicArray<T>::MergeSort() 
//{
//	int size = 1;
//	int j = 0;
//	while (size < this->count) 
//	{
//		j = 0;
//		while (j + size < this->count) 
//		{
//			InsideMerge(j, size, size);
//			j += 2*size;
//		}
//		size +=size;
//	}
//}
//template<typename T>
//void DynamicArray<T>:: InsideMerge(int j,int  r,int  size,int (*cmp)(T, T))
//{
//	if (j + r < this->count)
//	{
//		if (size == 1)
//		{
//			if (cmp(this->arrayPointer[j],this->arrayPointer[j + r])==1)
//			{
//				Swap(j, j + r);
//			}
//		}
//		else
//		{
//			size = size / 2;
//			InsideMerge(j, r, size);
//			if (j + r + size < this->count)
//			{
//				InsideMerge(j + size, r, size);
//			}
//			InsideMerge(j + size, r - size, size);
//		}
//	}
//}
//template<typename T>
//void DynamicArray<T>::MergeSort(int (*cmp)(T, T))
//{
//	int size = 1;
//	int j = 0;
//	while (size < this->count) 
//	{
//		j = 0;
//		while (j + size < this->count) 
//		{
//			InsideMerge(j, size, size,cmp);
//			j += 2*size;
//		}
//		size +=size;
//	}
//}
//template<typename T>
//void DynamicArray<T>::ShakerSort()
//{
//	bool swapped = true;
//	int start = 0;
//	int end = this->count - 1;
//	while (swapped) 
//	{
//		swapped = false;
//		for (int i = start; i < end; ++i) {
//			if (this->arrayPointer[i] > this->arrayPointer[i + 1])
//			{
//				Swap(i, i + 1);
//				swapped = true;
//			}
//		}
//		if (!swapped)
//			return;
//		swapped = false;
//		--end;
//		for (int i = end - 1; i >= start; --i) {
//			if (this->arrayPointer[i] > this->arrayPointer[i + 1])
//			{
//				Swap(i, i + 1);
//				swapped = true;
//			}
//		}
//		++start;
//	}
//}
//template<typename T>
//void DynamicArray<T>::ShakerSort(int (*cmp)(T, T))
//{
//	bool swapped = true;
//	int start = 0;
//	int end = this->count - 1;
//	while (swapped)
//	{
//		swapped = false;
//		for (int i = start; i < end; ++i) {
//			if (cmp(this->arrayPointer[i], this->arrayPointer[i + 1]) == 1)
//			{
//				Swap(i, i + 1);
//				swapped = true;
//			}
//		}
//		if (!swapped)
//			return;
//		swapped = false;
//		--end;
//		for (int i = end - 1; i >= start; --i) {
//			if (cmp(this->arrayPointer[i], this->arrayPointer[i + 1]) == 1)
//			{
//				Swap(i, i + 1);
//				swapped = true;
//			}
//		}
//		++start;
//	}
//}
