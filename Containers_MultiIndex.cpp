/***
 the containers from this library can support multiple interfaces from other containers at the same time.
 Containers from Boost.MultiIndex are like merged containers
 and provide the advantages of all of the containers they have been merged with.
 Boost.MultiIndex makes it possible to define containers that support an arbitrary number of interfaces.
 While std::vector provides an interface that supports direct access to elements with an index
 and std::set provides an interface that sorts elements, Boost.MultiIndex lets you define containers that support both interfaces.
 Such a container could be used to access elements using an index and in a sorted fashion.
***/
//include for used for container definition
#include <boost/multi_index_container.hpp>
//include used for hashing the container.It behaves like an unordered map and values can be looked up using a hash table
#include <boost/multi_index/hashed_index.hpp>
//inlude to access the member variable
#include <boost/multi_index/member.hpp>

#include <iostream>

struct animal
{
  std::string name;
  int legs;
};


typedef boost::multi_index::multi_index_container<
  animal,    // pasing the type of object to store in the container
  boost::multi_index::indexed_by<  // the first index of the container
    boost::multi_index::hashed_non_unique<
      boost::multi_index::member<   //the member is used for accessing the object member to find the varible to order by
        animal, std::string, &animal::name   // need the name of the object, the type, and variable
      >
    >,
    boost::multi_index::hashed_unique<   //all keys should be unique
      boost::multi_index::member<    // index number 2
        animal, int, &animal::legs
      >
    >
     boost::multi_index::sequenced<>,  //can be accessed by the order in which we put them in,like list
     boost::multi_index::ordered_non_unique< //objects are automatically sorted upon input, specify how to sort
       boost::multi_index::member<
        animal, int, &animal::legs
      >
    >,
     boost::multi_index::random_access<>  //allowing to be used as vector with [] and at()
  >
> animal_multi;


int main()
{
animal_multi animals;
 animals.insert({"cat", 4});
/***
To access a MultiIndex container, you need to select an interface.
If you directly access the object animals using insert() or count(), the first interface is used
Interfaces are numbered consecutively, starting at index 0 for the first interface.
***/

 std::cout << animals.count("cat") << '\n';
/***
To access the second interface  call the member function get()
and pass in the index of the desired interface as the template parameter.
***/


 const animal_multi::nth_index<1>::type &legs_index = animals.get<1>();
/***
It accesses a class of the MultiIndex container called nth_index which, again, is a template.
The index of the interface to be used must be specified as a template parameter.
This index must be the same as the one passed to get().
 The final step is to access the type definition named type of nth_index.
The value of type represents the type of the corresponding interface.
***/
/***
Just as the keys in a container of type std::unordered_map cannot be modified, neither can data stored within a MultiIndex container.
 Strictly speaking, all data stored in a MultiIndex container is constant.
This includes member variables that aren’t used by any interface. Even if no interface accesses legs, legs cannot be changed.
***/
std::cout << legs_index.count(8) << '\n';
/***
MultiIndex provides the member function modify(), which operates directly on the container.
The object to be modified is identified through an iterator passed as the first parameter to modify().
The second parameter is a function or function object that expects as its sole parameter an object of the type stored in the container.
 The function or function object can change the element as much as it wants
***/

 auto &legs_index = animals.get<1>();
  auto it = legs_index.find(4);
  legs_index.modify(it, [](animal &a){ a.name = "dog"; });

/***
In order to guarantee that no value is stored twice, use boost::multi_index::hashed_unique.
Please note that values cannot be stored if they don’t satisfy the requirements of all interfaces of a particular container.
If one interface does not allow you to store values multiple times, it does not matter whether another interface does allow it.
/***
If the sorted interface is used then certain functions like upper_bound and lower_bound can be use.They retrun iterators which specify those elements
auto it = legs_index.lower_bound(4);
  auto end = legs_index.upper_bound(8);
  for (; it != end; ++it)
    std::cout << it->name << '\n';

***/
}
