#ifndef LISTDOUBLY_HPP
#define LISTDOUBLY_HPP

#include "listSingly.hpp"

namespace ltds {
  template<typename T>
    class ListDoubly : public List<T>{
      using List<T>::List;
    };
}

#endif /* end of include guard: LISTDOUBLY_HPP */
