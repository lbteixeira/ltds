/*
 * Template class to represent singly linked lists.
 *
 * This class implements the basic capabilities of a singly linked list. It is
 * the equivalent of STL's std::forward_list. It is not a proper C++ container,
 * meaning that it doesn't implement the Iterator class.
 *
 * @author: Lucas Teixeira
 */

#pragma once

namespace ltds {
  template<typename T>
  class List{
    private:
      class node;

      node* head;
      node* tail;

    public:
      List();
      List(const T[], int);
      List(const List&);
      ~List();

      void pushFront(T const&);
      void popFront();
      void pushBack(T const&);
      void popBack();
      T topFront() const;
      T topBack() const;
      bool find(T const&) const;
      bool empty() const;
      void erase(T const&);
      void clear();

      List<T>& operator=(const List<T>& other){
        this->clear();
        auto tempPtr = other.head;
        while (tempPtr) {
          this->pushBack(tempPtr->key);
          tempPtr = tempPtr->next;
        }
        tempPtr = nullptr;
        return *this;
      }
  };

  /******************************
   * Beginning of implementations
   ******************************/

  /*
   * Implementations related to the node class
   */

  template<typename T>
  class List<T>::node{
    public:
      node(const T&, node*);
      node(const node&) = delete;

      T key;
      node* next;
  };

  template<typename T>
  List<T>::node::node(const T& _key, node* _next) : key(_key), next(_next) {}

  /*
   * Implementations related to the list class
   */

  // Constructors
  template<typename T>
  List<T>::List() : head(nullptr), tail(nullptr){}

  template<typename T>
  List<T>::List(const T input[], int size){
    for (auto i = 0; i < size; ++i) { this->pushBack(input[i]); }
  }

  template<typename T>
  List<T>::List(const List<T>& other){
    // Copy const. and copy assignment operator have the same internal code
    *this = other;
  }

  // Destructor deletes all nodes before deleting the list
  template<typename T>
  List<T>::~List(){
    this->clear();
  }

  // Member functions
  template<typename T>
  void List<T>::pushFront(const T& key){
    auto Node = new node(key, head);
    head = Node;
    if (tail == nullptr) {
      tail = head;
    }
  }

  template<typename T>
  void List<T>::popFront(){
    auto tempPtr = head;
    head = head->next;
    delete tempPtr;
    tempPtr = nullptr;
  }

  template<typename T>
  void List<T>::pushBack(const T& key){
    auto Node = new node(key, nullptr);

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
      delete head;
      head = nullptr;
      tail = nullptr;
    }
    else {
      auto temp = head;
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
    auto temp = head;
    while (temp != nullptr) {
      if (temp->key == key) { return true; }
      else { temp = temp->next; }
    }
    return false;
  }

  template<typename T>
  void List<T>::erase(const T &key){
    auto temp = head;
    auto tempDel = head;
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

  template<typename T>
  void List<T>::clear(){
    while (!this->empty()) {
      this->popBack();
    }
  }

}

