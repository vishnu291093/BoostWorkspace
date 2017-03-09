/***
The library Boost.Tuple provides a class called boost::tuple, which is a generalized version of std::pair.
While std::pair can only store exactly two values, boost::tuple lets you choose how many values to store.
boost::tuple and std::tuple are identical.
***/
//main header
#include <boost/tuple/tuple.hpp>
//for writing to streams
#include <boost/tuple/tuple_io.hpp>

#include<iostream>
//Works same as std::pair

boost::tuple<std::string, int> new_cat()
{
  return boost::make_tuple("cat", 4);
}

int main()
{

 boost::tuple<std::string, int> a{"cat", 4};

  std::cout << a << '\n';
  boost::tuple<int,bool,std::string> b{3,true,"here"};
  std::cout << b << '\n';
/***
You can create a tuple using the helper function boost::make_tuple(),
 which works like the helper function std::make_pair() for std::pair
***/
b= boost::make_tuple(33,false,"dfef");

 std::cout << b << '\n';

 /***
 To read elements from a tuple u need to use get .
 You can call the member function get(), or you can pass the tuple to the free-standing function boost::get().
 In both cases, the index of the corresponding element in the tuple must be provided as a template parameter
 ***/

  std::cout << b.get<1>() << '\n';
  std::cout<< boost::get<1>(a)<<'\n';
  /***
  The member function get() and the free-standing function boost::get()
  both return a reference that allows you to change a value inside a tuple.
 ***/
  b.get<1>() = false;
  std::cout << b.get<1>() << '\n';

  /***
  Boost.Tuple supports a specific form of tuples called tier.
  Tiers are tuples whose elements are all reference types.
   They can be constructed with the function boost::tie().

  ***/
  std::string name = "cat";
  int legs = 4;
  bool tail = true;
  boost::tuple<int&,std::string&, bool&> kal = boost::tie(legs,name,tail);
    std::cout << kal << '\n';
  boost::tuple<std::string, int> kal2 =new_cat();
std::cout << kal2 << '\n';
}
