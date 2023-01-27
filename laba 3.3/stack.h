#pragma once
#include "ArraySequence.h"
template<typename T>
class Stack
{
private:
	ArraySequence<T>* buffer;
public:
	Stack();
	Stack(T* items, int count);
public:
	T Extract();
	int GetLength();
	void Add(T item);
};
template<typename T>
Stack<T>::Stack()
{
	this->buffer = new ArraySequence<T>();
}
template<typename T>
Stack<T>::Stack(T* items, int count)
{
	this->buffer = new ArraySequence<T>(items, count);
}
template<typename T>
T Stack<T>::Extract()
{
	T result = this->buffer->GetLast();
	this->buffer->Remove(this->buffer->GetLength() - 1);
	return result;
}
template<typename T>
int  Stack<T> ::GetLength()
{
	return this->buffer->GetLength();
}

template<typename T>
void Stack<T> ::Add(T item)
{
	this->buffer->Append(item);
}
