/***
Boost.Container is a Boost library that provides the same containers as the standard library.
 Boost.Container focuses on additional flexibility.
 For example, all containers from this library can be used with Boost.Interprocess in shared memory

***/


#include <boost/container/vector.hpp>
#include <boost/container/stable_vector.hpp>
struct animal
{
  vector<animal> children;
};


int main()
{
/***
the type of the member variable children is based on the class animal, which defines the variable children.
 At this point, animal hasn’t been defined completely. While the standard doesn’t require containers
 from the standard library to support incomplete types,
recursive containers are explicitly supported by Boost.Container.


***/

    animal parent, child1, child2;
  parent.children.push_back(child1);
  parent.children.push_back(child2);


/***********************/
  /***
  boost::container::stable_vector, which behaves similarly to std::vector, except that if boost::container::stable_vector is changed,
  all iterators and references to existing elements remain valid.
   This is possible because elements aren’t stored contiguously in boost::container::stable_vector.
    It is still possible to access elements with an index even though elements are not stored next to each other in memory.
  ***/
  stable_vector<int> v(2, 1);
  int &i = v[1];
  v.erase(v.begin());
  std::cout << i << '\n';

}

/***
Additional
boost::container::flat_set and boost::container::flat_map resemble std::set and std::map. However they are implemented as sorted vectors,
 not as a tree. This allows faster lookups and iterations, but inserting and removing elements is more expensive.

boost::container::slist is a singly linked list. It is similar to std::forward_list,
which was added to the standard library with C++11. boost::container::slist provides a member function size(),
 which is missing in std::forward_list.

boost::container::static_vector stores elements like std::array directly in the container.
Like std::array, the container has a constant capacity,
though the capacity doesn’t say anything about the number of elements.
The member functions push_back(), pop_back(), insert(), and erase() are available to insert or remove elements.
In this regard, boost::container::static_vector is similar to std::vector.
The member function size() returns the number of currently stored elements in the container.

***/
