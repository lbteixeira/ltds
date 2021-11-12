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
  class List{
    public:
      List();
      List(const T[], int);

      nodeSingle<T>* head = nullptr;
      nodeSingle<T>* tail = nullptr;

      void pushFront(T const&);
      void popFront();
      void pushBack(T const&);
      void popBack();
      T topFront() const;
      T topBack() const;
      bool find(T const&) const;
      bool empty() const;
      void erase(T const&);
    private:
      nodeSingle<T>* findPosition(T const&) const;
  };

  template<typename T>
  List<T>::List(){};

  template<typename T>
  List<T>::List(const T input[], int size){
    for (int i = 0; i < size; ++i) { this->pushBack(input[i]); }
  };

  template<typename T>
  void List<T>::pushFront(const T& key){
    nodeSingle<T>* Node = new nodeSingle<T>;
    Node->key = key;
    Node->next = head;
    head = Node;
    if (tail == nullptr) {
      tail = head;
    }
  };

  template<typename T>
  void List<T>::popFront(){
    nodeSingle<T>* tempPtr = head;
    head = head->next;
    delete tempPtr;
    tempPtr = nullptr;
  }

  template<typename T>
  void List<T>::pushBack(const T& key){
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
  void List<T>::popBack(){
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

  template<typename T>
  bool List<T>::empty() const {
    if (head == nullptr) { return true; }
    else { return false; }
  }

  template<typename T>
  T List<T>::topFront() const {
    return head->key;
  }

  template<typename T>
  T List<T>::topBack() const {
    return tail->key;
  }

  template<typename T>
  nodeSingle<T>* List<T>::findPosition(const T &key) const {
    nodeSingle<T>* temp = head;
    while (temp != nullptr) {
      if (temp->key == key) { return temp; }
      else { temp = temp->next; }
    }
    return nullptr;
  }

  template<typename T>
  bool List<T>::find(const T &key) const {
    nodeSingle<T>* temp = findPosition(key);
    if (temp == nullptr) { return false; }
    else { return true; }
  }

  template<typename T>
  void List<T>::erase(const T &key){
    nodeSingle<T>* temp = head;
    nodeSingle<T>* tempDel = head;
    while (temp->next != nullptr) {
      if (temp->next->key == key) {
        tempDel = temp->next;
        temp->next = temp->next->next;
        delete tempDel;
        tempDel = nullptr;
        break;
      }
    }
  }

}
