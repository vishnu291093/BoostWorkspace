/***
boost::any can store arbitrary types of information in a single variable
***/

#include <boost/any.hpp>
#include<iostream>

int main()
{
  boost::any a = 1;
  a = 3.14;
  a = 22;

/***
Variables of type boost::any are not completely unlimited in what they can store;
 there are some preconditions, albeit minimal ones.
  Any value stored in a variable of type boost::any must be copy-constructible.
  Thus, it is not possible to store a C array, since C arrays aren’t copy-constructible.
***/


/***
TO access the value of the varialbe , an any_cast is used as shown below.
***/
std::cout<<boost::any_cast<int>(a)  <<std::endl;

/***
To check whether or not a variable of type boost::any contains information, use the member function empty().

***/
std::cout<<a.empty() <<std::endl;

/***
A pointer to the value inside any can be acquired using any_Cast
***/
int *i = boost::any_cast<int>(&a);
}
