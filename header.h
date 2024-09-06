#ifndef HEAD_H
#define HEAD_H

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

// struct for linkedList
struct Node 
{
	string value;
	Node* next = nullptr;
};

// Nodes for every ride
class MyNode 
{
	private:
		int value;
		MyNode* next = nullptr;

	public:
		void setValue (int val)
        {
			value = val;
		}

		int getValue () 
        {
			return value;
		}

		MyNode* getNext() 
        {
			return next;
		}

		void setNext (MyNode* temp) 
        {
			next = temp;
		}
};

class MyList 
{
	private:
		MyNode* head;

	public:
		MyList() 
        {
			head = new MyNode;
		}

		MyNode* getHead() 
        {
			return head;
		}

		void setHead(MyNode* temp) 
        {
			head = temp;
		}

};

class Island 
{
	private:
		int visited = -1;
		MyList linkedList;

	public:
		void setValue(int val);
		int getValue ();
		void setDefault(int val);
		void insert(int val);
		void printList();
		bool exists(int val);
		void remove(int val);
		void clear();
		void setVisited(int input);
		MyNode* getHead();
		int getVisited();
};

class IslandStack : public MyList 
{
	public:
		IslandStack() : MyList() 
        {
			setHead(nullptr);
		}

		void push (int val) 
        {
			MyNode *n = new MyNode;
			n->setValue(val);
			n->setNext(getHead());
			setHead(n);
		}

		int top() 
        {
			return getHead()->getValue();
		}

		void pop() 
        {
			if (getHead() == nullptr) 
            {
				return;
			}
			
			MyNode *temp = getHead();
			setHead(getHead()->getNext());
			delete temp;
		}

		bool is_empty() 
        {
			return getHead() == nullptr;
		}
};

class IslandQueue : public MyList 
{
	public:
		IslandQueue() : MyList() 
        {
			setHead(nullptr);
		}

		void enqueue(int val) 
        {
			MyNode *n = new MyNode;
			n->setValue(val);

			if (getHead() == nullptr) 
            {
				setHead(n);
				return;
			}

			MyNode *temp = getHead();

			while (temp->getNext() != nullptr) 
            {
				temp = temp->getNext();
			}

			temp->setNext(n);

		}

		int peak() 
        {
			return getHead()->getValue();
		}

		void dequeue() 
        {
			if (getHead() == nullptr) 
            {
				return;
			}

			MyNode* temp = getHead();
			setHead(getHead()->getNext());
			delete temp;
		}

		bool is_empty() 
        {
			return getHead() == nullptr;
		}
};

#endif