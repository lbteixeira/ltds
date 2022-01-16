#pragma once

namespace ltds {
  template<typename T>
  class List{
    private:
      struct node;

    public:
      List();
      List(const T[], int);

      node* head;
      node* tail;

      void pushFront(T const&);
      void popFront();
      void pushBack(T const&);
      void popBack();
      T topFront() const;
      T topBack() const;
      bool find(T const&) const;
      bool empty() const;
      void erase(T const&);
  };

  template<typename T>
  struct List<T>::node{
    T key;
    node* next = nullptr;
  };

  template<typename T>
  List<T>::List() : head(nullptr), tail(nullptr){}

  template<typename T>
  List<T>::List(const T input[], int size) : head(nullptr), tail(nullptr){
    for (int i = 0; i < size; ++i) { this->pushBack(input[i]); }
  }

  template<typename T>
  void List<T>::pushFront(const T& key){
    node* Node = new node;
    Node->key = key;
    Node->next = head;
    head = Node;
    if (tail == nullptr) {
      tail = head;
    }
  }

  template<typename T>
  void List<T>::popFront(){
    node* tempPtr = head;
    head = head->next;
    delete tempPtr;
    tempPtr = nullptr;
  }

  template<typename T>
  void List<T>::pushBack(const T& key){
    node* Node = new node;
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
      node* temp = head;
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
  bool List<T>::find(const T &key) const {
    node* temp = head;
    while (temp != nullptr) {
      if (temp->key == key) { return true; }
      else { temp = temp->next; }
    }
    return false;
  }

  template<typename T>
  void List<T>::erase(const T &key){
    node* temp = head;
    node* tempDel = head;
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

