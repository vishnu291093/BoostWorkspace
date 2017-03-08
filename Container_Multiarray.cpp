/***
Boost.MultiArray is a library that simplifies using arrays with multiple dimensions.
The most important advantage is that multidimensional arrays can be used like containers from the standard library.
For example, there are member functions, such as begin() and end(), that let you access elements in multidimensional arrays through iterators
***/
#include <boost/multi_array.hpp>
#include <iostream>

int main()
{
/***
boost::multi_array is a template expecting two parameters:
The first parameter is the type of the elements to store in the array.
The second parameter determines how many dimensions the array should have.
***/
/***
multi_array is a container template. When instantiated, it allocates space for the number of elements corresponding
to the dimensions specified at construction time. A multi_array may also be default constructed and resized as needed.

multi_array_ref adapts an existing array of data to provide the multi_array interface. multi_array_ref does not own the data passed to it.

const_multi_array_ref is similar to multi_array_ref but guarantees that the contents of the array are immutable.
It can thus wrap pointers of type T const*.

The three components exhibit very similar behavior. Aside from constructor parameters,
multi_array and multi_array_ref export the same interface. const_multi_array_ref provides
 only the constness-preserving portions of the multi_array_ref interface.
***/



//second type of initialization
//The second method involves passing the constructor an extent_gen object, specifying the matrix dimensions
  boost::multi_array<char, 1> a{boost::extents[6]};

  a[0] = 'B';
  a[1] = 'o';
  a[2] = 'o';
  a[3] = 's';
  a[4] = 't';
  a[5] = '\0';

  std::cout << a.origin() << '\n';
/***
Unlike containers from the standard library,
operator[] checks whether an index is valid. If an index is not valid,
the program exits with std::abort().
***/
}
