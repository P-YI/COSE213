#include "doublylinkedlist.h"
#include <iostream>
#include <math.h>

/** 
  * Assignment 2 for COSE213 Data Structures
  *
  * 2022. 4. 4  Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  */

/*
 * Iterator
 */
template<class T>
typename DoublyLinkedList<T>::Iterator& 
DoublyLinkedList<T>::Iterator::operator++() 
{ 
	this->current = this->current->llink;
	return *this;
	
}

template<class T>
typename DoublyLinkedList<T>::Iterator  
DoublyLinkedList<T>::Iterator::operator++(int) 
{ 
	Iterator it = *this;
	this->current = this->current->llink;
	return it;	
}

template<class T>
typename DoublyLinkedList<T>::Iterator& 
DoublyLinkedList<T>::Iterator::operator--() 
{ 
	this->current = this->current->rlink;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::Iterator  
DoublyLinkedList<T>::Iterator::operator--(int) 
{ 
	Iterator it = *this;
	this->current = this->current->rlink;
	return it;
}


/*
 * Reverse Iterator
 */
template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator&
DoublyLinkedList<T>::Reverse_Iterator::operator++() 
{ 
	this->current = this->current->rlink;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator
DoublyLinkedList<T>::Reverse_Iterator::operator++(int)
{ 
	Reverse_Iterator rit = *this;
	this->current = this->current->rlink;
	return rit;
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator&
DoublyLinkedList<T>::Reverse_Iterator::operator--() 
{ 
	this->current = this->current->llink;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator
DoublyLinkedList<T>::Reverse_Iterator::operator--(int)
{ 
	Reverse_Iterator rit = *this;
	this->current = this->current->llink;
	return rit;
}

/*
 * Doubly linked list
 */
// Default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	DoublyLinkedListNode<T>* front = new DoublyLinkedListNode<T>;
	first = front;
	first->rlink = first;
	first->llink = first;
}

// Copy constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& source)
{
	if (source.first == nullptr)
	{
		this->first = nullptr;
	}
	else
	{
		first = new NodeType;
		NodeType* tmp = source.first;
		*(first) = *(tmp);
		first->rlink = first;
		first->llink = first;

		while (tmp->llink != source.first)
		{
			NodeType* tmp2 = tmp->llink;
			InsertLast(tmp2->data);
			tmp = tmp2;
		}
	}
}


// Destructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (first != nullptr)
	{
		delete first;
	}
}


// Assignment operator
template<class T>
DoublyLinkedList<T>& 
DoublyLinkedList<T>::operator = (const DoublyLinkedList<T>& source)
{
	if (this != &source)
	{
		NodeType* tmp = source.first;
		while (tmp->llink != source.first)
		{
			NodeType* tmp2 = tmp->llink;
			InsertLast(tmp2->data);
			tmp = tmp2;
		}
	}

	return *this;
	
}



// Total number of nodes in the list
template<class T>
int 
DoublyLinkedList<T>::Size() const
{
	int i = 0;

	if (first != nullptr)
	{
		for(Iterator it = Begin(); it!=End(); it++)
		{	
			i++;
		}		
	}
	return i;
	
}


// Insert a new node to the list as the first node
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
//typename Iterator
DoublyLinkedList<T>::InsertFirst(const T& data)
{
	NodeType* tmp = new NodeType;
	tmp->data = data;
	
	if (first == nullptr)
	{
		first = tmp;
		tmp->rlink = tmp;
		tmp->llink = tmp;
	}
	else
	{
		NodeType* tmp2 = new NodeType;
		tmp2 = first;
		while (tmp2->rlink != first)
		{
			tmp2 = tmp2->rlink;
		}
		tmp->rlink = first;
		tmp->llink = tmp2;
		tmp2->rlink = tmp;
		first->llink = tmp;
	}
	return tmp;

}


// Insert a new node to the list as the last node
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::InsertLast(const T & data)
{
	NodeType* tmp = new NodeType;
	tmp->data = data;
	
	if (first == nullptr)
	{
		first = tmp;
		tmp->llink = tmp;
		tmp->rlink = tmp;
	}
	else
	{
		NodeType* tmp2 = new NodeType;
		tmp2 = first;
		while (tmp2->llink != first)
		{
			tmp2 = tmp2->llink;
		}
		tmp->llink = first;
		tmp->rlink = tmp2;
		tmp2->llink = tmp;
		first->rlink = tmp;
	}
	return tmp;
}


// Insert a new node to the list after pos
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
DoublyLinkedList<T>::InsertNext(DoublyLinkedList<T>::Iterator pos, const T & data)
{
	NodeType* tmp = new NodeType;
	tmp->data = data;
	
	if (first == nullptr)
	{
		first = tmp;
		tmp->llink = first;
		tmp->rlink = first;
	}
	else
	{
		NodeType* tmp2 = pos.GetNodePointer();
		NodeType* tmp3 = tmp2->llink;
		tmp->llink = tmp3;
		tmp3->rlink = tmp;
		tmp->rlink = tmp2;
		tmp2->llink = tmp;
	}
	return tmp;
}


// Insert a new node to the list before pos
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
DoublyLinkedList<T>::InsertPrev(DoublyLinkedList<T>::Iterator pos, const T & data)
{
	NodeType* tmp = new NodeType;
	tmp->data = data;
	
	if (first == nullptr)
	{
		first = tmp;
		tmp->llink = first;
		tmp->rlink = first;
	}
	else
	{
		NodeType* tmp2 = pos.GetNodePointer();
		NodeType* tmp3 = tmp2->rlink;
		tmp->rlink = tmp3;
		tmp3->llink = tmp;
		tmp->llink = tmp2;
		tmp2->rlink = tmp;
	}
	return tmp;
}


// Delete node at pos in the list
template<class T>
bool 
DoublyLinkedList<T>::DeleteNode(Iterator pos)
{
	if (first == nullptr)
	{
		return false;
	}
	else
	{
		NodeType* tmp = pos.GetNodePointer();
		NodeType* tmp2 = tmp->llink;
		NodeType* tmp3 = tmp->rlink;
		tmp2->rlink = tmp3;
		tmp3->llink = tmp2;

		delete tmp;

		return true;
	}
}


// Delete first node
template<class T>
bool 
DoublyLinkedList<T>::DeleteFirst()
{
	if (first == nullptr)
	{
		return false;
	}
	else
	{
		NodeType* tmp = new NodeType;
		tmp = first->llink;
		NodeType* tmp2 = new NodeType;
		tmp2 = tmp->llink;

		first->llink = tmp2;
		tmp2->rlink = first;

		delete tmp;

		return true;
	}
}


// Delete last node
template<class T>
bool 
DoublyLinkedList<T>::DeleteLast()
{
	if (first == nullptr)
	{
		return false;
	}
	else
	{
		NodeType* tmp = new NodeType;
		tmp = first->rlink;
		NodeType* tmp2 = new NodeType;
		tmp2 = tmp->rlink;

		first->rlink = tmp2;
		tmp2->llink = first;

		delete tmp;

		return true;
	}
}


template<class T>
void 
DoublyLinkedList<T>::Print(bool reverse)
{
	if(reverse)
	{
		for(Reverse_Iterator rit = rBegin(); rit!=rEnd(); rit++)
		{	
			std::cout << *rit << ", ";
		}
	}
	else 
	{		
		for(Iterator it = Begin(); it!=End(); it++)
		{	
			std::cout << *it << ", ";
		}		
	}
	
	std::cout << std::endl;
}

