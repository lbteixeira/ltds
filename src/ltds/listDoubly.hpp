/*
 * Template class to represent doubly linked lists.
 *
 * This class implements the basic capabilities of a doubly linked list. It is
 * the equivalent of STL's std::list. It is not a proper C++ container, meaning
 * that it doesn't implement the Iterator class.
 *
 * @author: Lucas Teixeira
 */

#pragma once

namespace ltds {
  template<typename T>
  class ListDouble{
    private:
      class node;

      node* head;
      node* tail;

    public:
      ListDouble();
      ListDouble(const T[], int);
      ~ListDouble();

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
  };

  /******************************
   * Beginning of implementations
   ******************************/

  /*
   * Implementations related to the node class
   */

  template<typename T>
  class ListDouble<T>::node{
    public:
      node(const T&, node*, node*);

      T key;
      node* next;
      node* prev;
  };

  template<typename T>
  ListDouble<T>::node::node(const T& _key, node* _next, node* _prev) : key(_key), next(_next), prev(_prev) {}

  /*
   * Implementations related to the list class
   */

  // Constructors
  template<typename T>
  ListDouble<T>::ListDouble() : head(nullptr), tail(nullptr){}

  template<typename T>
  ListDouble<T>::ListDouble(const T input[], int size) : head(nullptr), tail(nullptr){
    for (auto i = 0; i < size; ++i) { this->pushBack(input[i]); }
  }

  // Destructor deletes all nodes before deleting the list
  template<typename T>
  ListDouble<T>::~ListDouble(){
    this->clear();
  }

  // Member functions
  template<typename T>
  void ListDouble<T>::pushBack(const T& key){
    auto Node = new node(key, nullptr, tail);

    if (tail == nullptr) {
      head = Node;
      tail = Node;
    }
    else {
      tail->next = Node;
      Node->prev = tail;
      tail = Node;
    }
  }

  template<typename T>
  bool ListDouble<T>::empty() const {
    if (head == nullptr) { return true; }
    else { return false; }
  }

  template<typename T>
  void ListDouble<T>::clear(){
    while (!this->empty()) {
      this->popBack();
    }
  }

  template<typename T>
  void ListDouble<T>::popBack(){
    if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
    }
    else {
      tail = tail->prev;
      delete tail->next;
      tail->next = nullptr;
    }
  }

  template<typename T>
  T ListDouble<T>::topFront() const {
    return head->key;
  }

  template<typename T>
  T ListDouble<T>::topBack() const {
    return tail->key;
  }

}
