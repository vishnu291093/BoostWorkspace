/***
The library Boost.Bimap is based on Boost.MultiIndex and provides a container that can be used immediately without being defined first.
 The container is similar to std::map, but supports looking up values from either side.
 Boost.Bimap allows you to create maps where either side can be the key, depending on how you access the map.
 When you access the left side as the key, the right side is the value, and vice versa.
***/

#include <boost/bimap.hpp>
#include <iostream>
int main()
{
  typedef boost::bimap<std::string, int> bimap;
  bimap animals;

  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"spider", 8});

  std::cout << animals.left.at("cat") << '\n'; //left and right keywords can be used to use either as the key
  std::cout << animals.right.count(8) << '\n';
}

/***
Cant normally store items having the same key
***/
