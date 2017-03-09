
/***

The library Boost.Tribool provides the class boost::logic::tribool,
which is similar to bool. However, while bool can distinguish two states,
boost::logic::tribool handles three.

***/

#include <boost/logic/tribool.hpp>
#include <iostream>


int main()
{
  boost::logic::tribool b;

/***
A variable of type boost::logic::tribool can be set to true,
false, or indeterminate. The default constructor initializes the variable to false.
***/
b=true;
b= false;
b =boost::logic::indeterminate;
/***
Boost.Tribool also provides the function boost::logic::indeterminate().
If you pass a variable of type boost::logic::tribool that is set to indeterminate,
this function will return true. If the variable is set to true or false, it will return false.
***/

if(boost::logic::indeterminate(b))
{
std::cout<<"ind"<<std::endl;
}

}
