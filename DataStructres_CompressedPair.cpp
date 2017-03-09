/***
Boost.CompressedPair provides boost::compressed_pair, a class that behaves like std::pair.
However, if one or both template parameters are empty classes, boost::compressed_pair consumes less memory.
boost::compressed_pair uses a technique known as empty base class optimization.
***/

#include <boost/compressed_pair.hpp>
#include <iostream>

struct empty {};

int main()
{ empty emp;
  std::pair<int, empty> p(23,emp);

  std::cout << sizeof(p) << '\n';

  boost::compressed_pair<int, empty> cp(23,emp);
  std::cout << sizeof(cp) << '\n';


 /***
 Please note that there is another difference between boost::compressed_pair and std::pair:
 the values stored in boost::compressed_pair are accessed through the member functions first() and second().
 std::pair uses two identically named member variables instead.
 ***/
 std::cout <<cp.first() << '\n';
 std::cout <<p.first << '\n';
}
