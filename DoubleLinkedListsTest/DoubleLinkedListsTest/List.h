#pragma once
#include "Node.h"
#include "Iterator.h"
#include <initializer_list>

template<typename T>
class List
{
public:
	List<T>();
	List<T>(std::initializer_list<T> list);
	~List<T>();

	void pushFront(const T& value);
	void pushBack(const T& value);
	T popFront();
	T popBack();
	bool insert(const T& value, int index);
	bool remove(const T& value);
	T first() const;
	T last() const;
	Iterator<T> begin() const;
	Iterator<T> end() const;
	void destroy();
	int getLength() const;

private:
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_length;
};

template<typename T>
inline List<T>::List() : m_head(nullptr), m_tail(nullptr), m_length(0)
{
}

template<typename T>
inline List<T>::List(std::initializer_list<T> list) : m_length(list.size()), m_head(nullptr), m_tail(nullptr)
{
	if (m_length <= 0)
	{
		return;
	}


	for (int i = 0; i < list.size(); i++)
	{
		pushBack(list[i]);
	}
}

template<typename T>
inline List<T>::~List()
{
	destroy();
	delete m_head;
	m_head = nullptr;
	delete m_tail;
	m_tail = nullptr;

}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	m_length++;
	if (!m_tail)
	{
		m_head = newNode;
		m_tail = newNode;
		return;
	}

	m_head->previous = newNode;
	newNode->next = m_head;
	m_head = newNode;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	m_length++;
	if (!mtail)
	{
		m_head = newNode;
		m_tail = newNode;
		return;
	}
	m_tail->next = newNode;
	newNode->previous = m_tail;
	m_tail = newNode;
}

template<typename T>
inline T List<T>::popFront()
{
	if (m_length <= 0)
		returnT();

	T value = m_head->value;

	if (m_head->next)
	{
		delete m_head;
		m_head = nullptr;
		m_tail = nullptr;
		m_length = 0;
		return value;
	}
	else
	{
		m_head = m_head->next;
		delete m_head->previous;
		m_head->previous = nullptr;
		m_length--;
		return value;

	}
}

template<typename T>
inline T List<T>::popBack()
{
	if (!m_tail)
		returnT();

	T value = m_tail->value;

	if (!m_tail->previous)
	{
		delete m_tail;
		m_tail = nullptr;
		m_head = nullptr;
		m_length = 0;
		return value;
	}
	else
	{
		m_tail = m_tail->previous;
		delete m_tail->next;
		m_tail->next = nullptr;
		m_length--;
	}
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	if (index < 0 || index >= m_length)
		return false;
	
	if (!m_tail || index == 0)
	{
		pushFront(value);
		return true;
	}

	if (index == m_length - 1)
	{
		pushBack(value);
		return true;
	}

	Node<T>* node = m_head;
	for (int i = 0; i < index; i++)
	{
		if (node->next == nullptr)
			return false;

		node = node->next;
	}

	Node<T>* newNode = new Node<T>(value);
	newNode->previous = node->previous;
	newNode->next = node;
	node->previous = newNode;
	newNode->previous->next = newNode;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	return false;
}

template<typename T>
inline T List<T>::first() const
{
	return T();
}

template<typename T>
inline T List<T>::last() const
{
	return T();
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>();
}

template<typename T>
inline void List<T>::destroy()
{
}

template<typename T>
inline int List<T>::getLength() const
{
	return 0;
}
