#pragma once

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

      nodeSingle<T> head;
      nodeSingle<T> tail;

      void pushFront(T const&);
      void popFront();
      void pushBack(T const&);
      void popBack();
      void addBefore(nodeSingle<T> const&, T const&);
      void addAfter(nodeSingle<T> const&, T const&);
      T topFront();
      T topBack();
      bool find(T const&);
      bool empty();
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
    Node->next = head.next;
    head.next = Node;
    if (tail.next == nullptr) {
      tail.next = head.next;
    }
  };

  template<typename T>
  void singlyLinkedList<T>::popFront(){
    // TODO exception when the list is empty
    nodeSingle<T>* tempPtr = head.next;
    head.next = head.next->next;
    delete tempPtr;
    tempPtr = nullptr;
  };

  template<typename T>
  void singlyLinkedList<T>::pushBack(const T& key){
    nodeSingle<T>* Node = new nodeSingle<T>;
    Node->key = key;
    Node->next = nullptr;

    if (tail.next == nullptr) {
      head.next = Node;
      tail.next = Node;
    }
    else {
      tail.next->next = Node;
      tail.next = Node;
    }
  }

  template<typename T>
  bool singlyLinkedList<T>::empty(){
    if (head.next == nullptr) { return true; }
    else { return false; }
  }

}
