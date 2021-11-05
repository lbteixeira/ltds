#pragma once

namespace ltds {
    template<typename T>
    struct node{
      T key;
      node* next = nullptr;
    };
}
