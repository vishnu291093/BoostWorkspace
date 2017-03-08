/***
Boost.Heap could have also been called Boost.PriorityQueue since the library provides several priority queues.
 However, the priority queues in Boost.Heap differ from std::priority_queue by supporting more functions.
***/

#include <boost/heap/priority_queue.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <iostream>

/***
boost::heap::priority_queue
.Its different from the normal priority queue in the sense it lets you iterate over them and
Object of this type can be compared with each other.
if one has more elements than the other then it is higher.else the element are compared element wise

boost::heap::binomial_heap.
Through this 2 different heaps can be merged into one.
This also lets you update an existing input value in the heap
***/

int main()
{
  boost::heap::priority_queue<int> pq;
  pq.push(2);
  pq.push(3);
  pq.push(1);

  for (int i : pq)
    std::cout << i << '\n';  //range for loop

  boost::heap::priority_queue<int> pq2;
  pq2.push(4);
  std::cout <<  (pq > pq2) << '\n';  // comparison operation

  boost::heap::binomial_heap<int> bh2;
  bh2.push(4);
  //bh.merge(bh2);  merging with another heap

  for (auto it = bh2.ordered_begin(); it != bh2.ordered_end(); ++it)
    std::cout << *it << '\n';
  std::cout << std::boolalpha << bh2.empty() << '\n';

  auto handle = bh2.push(2); // a handle to the inserted element

  bh2.update(handle, 4); // update the value

}
