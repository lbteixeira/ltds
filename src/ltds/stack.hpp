#pragma once

#include "ltds/listSingly.hpp"

namespace ltds {
  template<typename T>
  class Stack{
    private:
      ltds::List<T>* list;

    public:
      Stack();
      Stack(const T[], int);
      Stack(const Stack&);
      ~Stack();

      void push(const T&);
      T top() const;
      T pop();
      bool empty() const;

      Stack<T>& operator=(const Stack<T>& other){
        list = new ltds::List<T>(*other.list);
        return *this;
      }
  };

  /******************************
   * Beginning of implementations
   ******************************/

  // Constructors
  template<typename T>
  Stack<T>::Stack(){
    list = new ltds::List<T>();
  }

  template<typename T>
  Stack<T>::Stack(const T input[], int size){
    list = new ltds::List<T>();
    for (int i = 0; i < size; ++i) { list->pushFront(input[i]); }
  }

  template<typename T>
  Stack<T>::~Stack(){ delete list; }

  // Member functions
  template<typename T>
  void Stack<T>::push(const T& key){ list->pushFront(key); }

  template<typename T>
  T Stack<T>::top() const { return list->topFront(); }

  template<typename T>
  T Stack<T>::pop() {
    T temp = list->topFront();
    list->popFront();
    return temp;
  }

  template<typename T>
  bool Stack<T>::empty() const { return list->empty(); }

}

