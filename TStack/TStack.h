#pragma once

#include <iostream>

using namespace std;

template <class T>
class TStack
{
	int max_size;
	int num_last_element;
	T* pMem;
public:
	TStack(int max_size = 10);
	TStack(const TStack<T>& other_stack);
	~TStack();

	TStack& operator=(const TStack<T>& other_stack);
	bool operator==(const TStack<T>& other_stack) const;
	bool operator!=(const TStack<T>& other_stack) const;

	T Pop();
	void Push(T element);

	bool IsFull() const;
	bool IsEmpty() const;

	T Top() const;
	void Clear();

	friend ostream& operator<<(ostream& out, const TStack<T>& stack)
	{
		for (int i = 0; i <= stack.num_last_element; i++)
		{
			out << stack.pMem[i] << " ";
		}
		return out;
	}
};

template <class T>
TStack<T>::TStack(int max_size)
{
	this->max_size = max_size;
	pMem = new T[max_size];
	num_last_element = -1;
}

template <class T>
TStack<T>::TStack(const TStack<T>& other_stack)
{
	max_size = other_stack.max_size;
	pMem = new T[max_size];
	num_last_element = other_stack.num_last_element;
	for (int i = 0; i <= num_last_element; i++)
	{
		pMem[i] = other_stack.pMem[i];
	}
}

template <class T>
TStack<T>::~TStack()
{
	delete[] pMem;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& other_stack)
{
	if (*this == other_stack)
		return *this;
	if (max_size != other_stack.max_size)
	{
		max_size = other_stack.max_size;
		delete[] pMem;
		pMem = new T[max_size];
	}
	num_last_element = other_stack.num_last_element;
	for (int i = 0; i <= num_last_element; i++)
	{
		pMem[i] = other_stack.pMem[i];
	}
	return *this;
}

template <class T>
bool TStack<T>::operator==(const TStack<T>& other_stack) const
{
	if (max_size != other_stack.max_size)
		return false;
	if (num_last_element != other_stack.num_last_element)
		return false;
	for (int i = 0; i <= num_last_element; i++)
	{
		if (pMem[i] != other_stack.pMem[i])
			return false;
	}
	return true;
}

template <class T>
bool TStack<T>::operator!=(const TStack<T>& other_stack) const
{
	return (!(*this == other_stack));
}

template <class T>
T TStack<T>::Pop()
{
	if (this->IsEmpty())
		throw - 1;
	T result = pMem[num_last_element--];
	return result;
}

template <class T>
void TStack<T>::Push(T new_element)
{
	if (this->IsFull())
		throw - 1;
	pMem[++num_last_element] = new_element;
}

template <class T>
bool TStack<T>::IsEmpty() const
{
	if (num_last_element == -1)
		return true;
	return false;
}

template <class T>
bool TStack<T>::IsFull() const
{
	if (num_last_element == max_size - 1)
		return true;
	return false;
}

template <class T>
T TStack<T>::Top() const
{
	return pMem[num_last_element];
}

template <class T>
void TStack<T>::Clear()
{
	num_last_element = -1;
}