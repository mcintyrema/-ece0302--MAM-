//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include<cassert>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack()
{
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	//pop until stack is empty
	while(currentSize > 0)
		pop();
	delete headPtr;	
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if(currentSize == 0){
		return true;
	}
	else{
		return false;
	}
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>();
	newNodePtr->setItem(newItem);
	newNodePtr->setNext(headPtr);
	headPtr = newNodePtr;
	newNodePtr = nullptr; //questionable
	currentSize++;
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	assert(!isEmpty());
	return headPtr->getItem();
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	bool result = false;
	if(!isEmpty()){
		//stack is not empty; delete top
		Node<ItemType>* nodeToDeletePtr = new Node<ItemType>();
		nodeToDeletePtr = headPtr;
		headPtr = nodeToDeletePtr->getNext();
		delete nodeToDeletePtr;

		//return deleted node to system
		//nodeToDeletePtr->setNext(nullptr);
		
		nodeToDeletePtr = nullptr;
		currentSize--;
		result = true;
	}

	return result;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	while(headPtr != nullptr){
		pop();
	}
}  // end clear

