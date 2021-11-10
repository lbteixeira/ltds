#pragma once

#include <iostream>
#include <stdexcept>

namespace ltds {
  template<typename T>
  struct nodeSingle{
    T key;
    nodeSingle* next = nullptr;
  };

  template<typename T>
  class singlyLinkedList{
    public:
      singlyLinkedList();
      singlyLinkedList(const T[], int);

      nodeSingle<T>* head = nullptr;
      nodeSingle<T>* tail = nullptr;

      void pushFront(T const&);
      void popFront();
      void pushBack(T const&);
      void popBack();
      void addBefore(nodeSingle<T> const&, T const&);
      void addAfter(nodeSingle<T> const&, T const&);
      T topFront() const;
      T topBack() const;
      bool find(T const&) const;
      bool empty() const;
      void erase(T const&);
  };

  template<typename T>
  singlyLinkedList<T>::singlyLinkedList(){};

  template<typename T>
  singlyLinkedList<T>::singlyLinkedList(const T input[], int size){
    for (int i = 0; i < size; ++i) { this->pushBack(input[i]); }
  };

  template<typename T>
  void singlyLinkedList<T>::pushFront(const T& key){
    nodeSingle<T>* Node = new nodeSingle<T>;
    Node->key = key;
    Node->next = head;
    head = Node;
    if (tail == nullptr) {
      tail = head;
    }
  };

  template<typename T>
  void singlyLinkedList<T>::popFront(){
    try{
      if (this->empty()) {
        throw std::out_of_range("The list is empty, can't pop");
      }
      else{
        nodeSingle<T>* tempPtr = head;
        head = head->next;
        delete tempPtr;
        tempPtr = nullptr;
      }
    }

    catch(std::out_of_range &error){
      std::cerr << error.what() << std::endl;
    }
  }

  template<typename T>
  void singlyLinkedList<T>::pushBack(const T& key){
    nodeSingle<T>* Node = new nodeSingle<T>;
    Node->key = key;
    Node->next = nullptr;

    if (tail == nullptr) {
      head = Node;
      tail = Node;
    }
    else {
      tail->next = Node;
      tail = Node;
    }
  }

  template<typename T>
  void singlyLinkedList<T>::popBack(){
    try {
      if (tail == nullptr) {
        throw std::out_of_range("The list is empty, can't pop");
      }
      else {
        if (head == tail) {
          head = nullptr;
          tail = nullptr;
        }
        else {
          nodeSingle<T>* temp = head;
          while (temp->next->next != nullptr) { temp = temp->next; }
          delete temp->next;
          temp->next = nullptr;
          tail = temp;
        }
      }

    }catch(std::out_of_range &error) {
      std::cerr << error.what() << std::endl;
    }
  }

  template<typename T>
  bool singlyLinkedList<T>::empty() const {
    if (head == nullptr) { return true; }
    else { return false; }
  }

  template<typename T>
  T singlyLinkedList<T>::topFront() const {
    return head->key;
  }

  template<typename T>
  T singlyLinkedList<T>::topBack() const {
    return tail->key;
  }

  template<typename T>
  bool singlyLinkedList<T>::find(const T &key) const {
    nodeSingle<T>* temp = head;
    while (temp != nullptr) {
      if (temp->key == key) { return true; }
      else { temp = temp->next; }
    }
    return false;
  }

}
