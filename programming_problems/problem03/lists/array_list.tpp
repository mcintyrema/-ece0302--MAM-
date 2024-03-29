#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  size = 0;
  arr = new T[size]; // bag initialized empty
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] arr;
  arr = nullptr;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
  size = 0;
  arr = new T[rhs.size]; // same size bag

  for(int i = 0; i < rhs.size; i++){
    arr[i] = rhs.arr[i]; // copying array
    size = rhs.size;
  }
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  for(int i = 0; i < rhs.size; i++){
    insert(i, rhs.arr[i]);
  }
  return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return size;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  
  if(position > size){ //position indexed greater than current size of array
    T *temp = new T[position]; //initialize array to size of position
    for(int i = 0; i < position; i++){ //copying array
      temp[i] = arr[i];
    }
    size = position; // changing size of original array to fit item at index position
    delete [] arr;
    arr = temp;
    arr[position] = item; //adding item at end of array
    return true;
  }
  else if(position <= size){
    T *temp = new T[size+1];
    for(int i = 0; i < size; i++){
      temp[i] = arr[i]; //copy all elemenmts to temp
    }

    temp[position] = item;
    for(int i = position + 1; i < size; i++){ //shifting array
      temp[i] = arr[i-1];
    }

    delete [] arr;
    arr = temp;
    return true;
  }
  else{
    return false;
  }
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  if(position <= size){
    for(int i = 0; i < size; i++){
      if(arr[i] == arr[position]){
        T *temp = new T[size];
        std::copy(arr, arr+i, temp);
        std::copy(arr+i+1, arr+size, temp+i);
        delete [] arr;
        arr = temp;
        for(int i = position; i <= size; i++){
          arr[i] = arr[i + 1];
        }
        --size;
      }
    }
    return true;
  }
  else{
    return false;
  }
}

template <typename T>
void ArrayList<T>::clear() {
  size = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  if(position <= size){
    return arr[position];
  }
  else{
    return T();
  }
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  if(position <= size){
    T *temp = new T[size+1];
    for(int i = 0; i < size; i++){
      temp[i] = arr[i];
    }

    temp[position] = newValue;

    for(int i = position + 1; i < size; i++){
        temp[i] = arr[i-1];
    }

    delete [] arr;
    arr = temp;

  }
  else{
    
  }
}

template <typename T>
void ArrayList<T>::setLength(std::size_t dim){
  size = dim;
}
