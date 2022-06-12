#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  //TODO
  start = NULL;
  end = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
 delete start;
 delete end;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //TODO
  start = NULL;
  end = NULL;
  for(int i = 0; i< x.getLength(); i++){
    insert(i, x.getEntry(i));
  }
} 
   
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //TODO
  for(int i = 0; i <= x.getLength(); i++){
    insert(i, x.getEntry(i));
  }
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  //TODO
  if(getLength() == 0){
    return true;
  }
  else{
    return false;
  }
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //TODO
  if(start == NULL){
    return 0;
  }
  else{
    return size;
  }
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  Node<T>* newNode = new Node<T>();
  Node<T> *prev = new Node<T>();
  
  if(position < 0 || position > size + 1){ //invalid position
    return false;
  }
  else if(position > size){ // adding node at end of list
    newNode->setItem(item);
    newNode->setNext(NULL);

    end = start;
    while(end->getNext() != NULL){ //traversing to end of list
      end = end->getNext();
    }
    end->setNext(newNode); //setting last node as the new node
    size = size + 1; // increase size bc position > size
    return true;
  }
  else if(position == 0){ //inserting at beginning of list
    newNode->setItem(item);
    newNode -> setNext(start);
    start = newNode;
    size = size + 1;
    return true;
  }
  else if(size == 0){ // list is empty
    newNode = nullptr;
    newNode->setItem(item);
    start = newNode;
    size = size + 1;
    return true;
  }
  else{ //inserting in middle
    prev = start;

    for(int i = 1; i < position-1; i++){
      prev = prev->getNext();
    }

    newNode->setItem(item);
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
    size = size+1;
    return true;
  }
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  Node<T>* temp = new Node<T>();
  Node<T>* prev = new Node<T>();

  //is starter node = to position
  if(position == 0){
    prev = start;
    start = prev->getNext();
    delete prev;
    size = size-1;
    return true;
  }
  else if(position < 0 || position > size){
    return false;
  }
  else{
    prev = start;
    for(int i = 1; i < position-1; i++){
      prev = prev->getNext();
    }
    temp = prev->getNext();
    prev->setNext(temp->getNext());
    delete temp;
    size= size-1;
    return true;
  }
}

template <typename T>
void LinkedList<T>::clear()
{
  //TODO
  Node<T>* current = start;
  Node<T>* next;
  while(current != NULL){
    next = current->getNext();
    delete[] current;
    current = next;
  }
  start = NULL;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //TODO
  Node<T>* current = start;
  int count = 0;
  while(current != NULL){
    if(count == position){
      return (current->getItem());
    }
    count++;
    current = current->getNext();
  }
  return current->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
  Node<T>* current = start;
  for(int i = 0; i < position; i++){
    current = current->getNext();
  }
  current->setItem(newValue);
}
