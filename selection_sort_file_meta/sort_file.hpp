// Do not change
#include <iostream>
#include <fstream>
#include <string>

#include <list>
#include <vector>
#include <deque>
#include <tuple>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful



template<class TYPE, class CONTAINER>
void read_file_to_cont(std::ifstream& f, CONTAINER& c) {
  if constexpr (std::is_same<TYPE, char>::value) {
    char tmp = '\n';
    while (f.get(tmp))
    {
      if (tmp != '\n') {
        c.push_back(tmp);
      }
    }
    
  } else {
    TYPE elm;
    while (f >> elm) {
      c.push_back(elm);
    }
  }

}



template<class TYPE ,class CONTAINER>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {

  CONTAINER container = {};

  read_file_to_cont<TYPE, CONTAINER>(fi, container);
  auto begin = container.begin();
  auto end = container.end();
    if constexpr (
    std::is_same_v<TYPE, char>
    || std::is_same_v<TYPE, int>
    || std::is_same_v<TYPE, unsigned int> ) {
    my_selection_sort(begin, end,[](TYPE l, TYPE r)->bool{return std::make_tuple(l%2, l) < std::make_tuple(r%2, r);} );
  } else {
    my_selection_sort(begin, end,[](TYPE l, TYPE r)->bool{return l > r; } );
  }

  for (TYPE& elm : container) {
    fo << elm << "\n";
  }

}


template<class TYPE>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  char line;
  fi >> line;

  fo << line << "\n";

  switch(line)
  {
    case 'l':
      read_and_sort<TYPE, std::list<TYPE>>(fi, fo);
      break;

    case 'v':
      read_and_sort<TYPE, std::vector<TYPE>>(fi, fo);
      break;

    case 'd':
      read_and_sort<TYPE, std::deque<TYPE>>(fi, fo);
      break;

    default:
      std::runtime_error("Type container doesn't match");
      break;
  }
}


void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
  char line;

  fi >> line;

  fo << line << "\n";
  
  switch(line)
  {
    case 'i':
      read_and_sort_decide_container<int>(fi, fo);
      
      break;

    case 'u':
      read_and_sort_decide_container<unsigned>(fi, fo);
      break;

    case 'f':
      read_and_sort_decide_container<float>(fi, fo);
      break;

    case 'd':
      read_and_sort_decide_container<double>(fi, fo);
      break;

    case 'c':
      read_and_sort_decide_container<char>(fi, fo);
      break;

    case 's':
      read_and_sort_decide_container<std::string>(fi, fo);
      break;

    default:
      std::runtime_error("Type value doesn't match");
      break;
  }
}



