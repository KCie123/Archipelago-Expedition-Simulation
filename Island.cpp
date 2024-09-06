#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

#include "header.h"

using namespace std;

void Island::printList() 
{
	MyNode* temp = linkedList.getHead()->getNext();
	while (temp != nullptr) 
    {
		cout << temp->getValue() << "  ";
		temp = temp->getNext();
	}
}

void Island::setValue(int val) 
{
	MyNode* temp = linkedList.getHead();
	while (temp != nullptr) 
    {
		temp = temp->getNext();
	}
}

int Island::getValue() 
{
	return linkedList.getHead()->getValue();
}

void Island::setDefault(int val) 
{
	linkedList.getHead()->setValue(val);
}

void Island::insert(int val) 
{
	MyNode* temp = linkedList.getHead();
	while (temp->getNext() != nullptr) 
    {
		temp = temp->getNext();
	}
	MyNode* newNode = new MyNode;
	newNode->setValue(val);
	temp->setNext(newNode);
}

bool Island::exists(int val) 
{
	MyNode* temp = linkedList.getHead()->getNext();
	while (temp != nullptr) 
    {
		if (temp->getValue() == val) 
        {
			return true;
		}

		temp = temp->getNext();
	}
			return false;
}

void Island::setVisited(int input) 
{
	visited = input;
}

MyNode* Island::getHead()
{
	return linkedList.getHead();
}
	
int Island::getVisited() 
{
	return visited;
}

void Island::clear()
{
	MyNode* temp = linkedList.getHead();
	while (temp != nullptr) 
    {
		MyNode* next = temp->getNext();
		delete temp;
		temp = next;
	}
}

void Island::remove(int val) 
{
	MyNode* temp = linkedList.getHead()->getNext();
	MyNode* prev = linkedList.getHead();

	while (temp != nullptr) 
    {
		if (temp->getValue() == val) 
        {
			break;
		}
		prev = temp;
		temp = temp->getNext();
	
	}

	MyNode* next = temp->getNext();
	
	if (prev == linkedList.getHead()) 
    {
		linkedList.getHead()->setNext(next);
		delete temp;
	} 

    else 
    {
		prev->setNext(next);
		delete temp;
	}
}
	