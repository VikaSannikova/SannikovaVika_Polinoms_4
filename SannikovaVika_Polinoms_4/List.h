#pragma once
#include <stdlib.h>
#include"Monom.h"

template <class Type>
class Node
{
private:
	Type var;
	Node<Type> *next;
public:
	void SetVar(Type x)
	{
		var = x;
	}
	void SetNext(Node<Type> *n)
	{
		next = n;
	}
	Type GetVar()
	{
		return var;
	}
	Node<Type> GetNext()
	{
		return next;
	}
	Node()
	{
		SetVar(Type());
		SetNext(NULL);
	}
	Node(Type x)
	{
		SetVar(x);
		SetNext(NULL);
	}
	Node(Type x, Node<Type> *n)
	{
		SetVar(x);
		SetNext(n);
	}
};

template <class Type>
class List
{
private:
	Node<Type>*fhead;
	Node<Type>*tail;
	Node<Type>* head; 
	int length;
public:
	List()
	{
		fhead = new Node<Type>();
		head = fhead;
		tail = fhead;
		length = 0;
	}
	Node<Type>* GetHead()
	{
		return head;
	}
	int GetLength()
	{
		return length;
	}
	void SetLenght(int l)
	{
		if (i > 0) length = l;
		else
			throw 'NegL';
	}
	Node<Type> FindAtPos(int pos)
	{
		if (pos<0 || pos>length) trow 'ErrP';
		Node<Type>*current = head;
		for (int i = 0; i < pos; i++)
		{
			current = current->GetNext();
		}
		return current;
	}
	void AddToHead(Type x)
	{
		Node<Type>* tmp;
		if (length == 0)
		{
			tmp = new Node<Type>(x, NULL);
			tail = tmp;
		}
		else
		{
			tmp = new Node<Type>(x, head);
		}
		fhead->SetNext(tmp);
		head = tmp;
		length++;
	}
	void AddToTail(Type x)
	{
		Node<Type>* tmp = new Node<Type>(x, NULL);
		if (tail != NULL) { tail->SetNext(tmp); }
		tail = tmp;
		if (head = fhead)
		{
			head = tmp;
		}
		length++;
	}
	void AddElem(Type x, int pos)
	{
		if (pos == 0)
		{
			AddToHead(x);
			return;
		}
			Node<Type>*current = FindAtPos(pos - 1);
			Node<Type>*tmp = new Node<Type>(x, current);
			current->SetNext(tmp);
	}
	void AddElemInOrder(Type x)
	{
		Node<Type>*current = head;
		Node<Type>*previous = fhead;
		Node<Type>* tmp = new Node<Type>(x);
		if (current = fhead) 
		{
			AddToHead(x);
			return;
		}
		if (x > current->GetVar())
		{
			AddToHead(x);
			return;
		}
		if (x < tail->GetVar())
		{
			AddToTail(x);
			return;
		}
		
		while (x < current->GetVar())
		{
			previous = current;
			current = current->GetNext();
		}
		previous->SetNext(tmp);
		tmp->SetNext(current);
		lenght++;
	}
	void DeleteFirst()
	{
		if (length == 0) return;
		if (length == 1) { head = tail = NULL };
		Node<Type>*tmp = head;
		head = tmp->GetNext();
		fhead->SetNext(head);
		delete tmp;
		length--;
	}
	void DeleteAll()
	{
		while (length != 0)
		{
			DeleteFirst();
		}
	}
	void DeleteElement(Node<monom>* node)
	{
		Node<Type>*previous = fhead;
		Node<Type>*current = head;
		if (node = head)
		{
			DeleteFirst();
			return;
		}
		while (current != NULL)
		{
			if (corrent == node)
			{
				previous->SetNext(current->GetNext());
				delete current;
				length--;
				return;
			}
			previous = current;
			current = current->GetNext();
		}

	}
};