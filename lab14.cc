/**
 *    @file: lab14.cc
 *  @author: Josh Marusek
 *    @date: 2021-12-03
 *   @brief: 
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "my_int.h"
using namespace std;


//*********************************************************
// Function: is_prime
// Purpose:  object num contains a valid positive value
//           returns true if num is prime; otherwise
//           returns false
// Params:   num  - the value to be checked for prime
// Calls:    sqrt
// Uses:     cmath 
//*********************************************************
bool is_prime(const my_int& num);


int main()
{ 
  my_int value1;
  my_int value2;

  value1.input(cin);
  value1.output(cout);

  value2.input(cin);
  value2.output(cout);

  if (value1 > value2) {
    cout << "First is greater than second" << endl;
  }
  else {
    cout << "First is not greater than second" << endl;
  }

  return 0;
}




          
//*********************************************************
// Function: is_prime
// Purpose:  object num contains a valid positive value
//           returns true if num is prime; otherwise
//           returns false
// Params:   num  - the value to be checked for prime
// Calls:    sqrt
// Uses:     cmath 
//*********************************************************
bool is_prime(const my_int& num)
{
  double limit;
  int n;      //divisor
  bool prime= true; 

  limit = sqrt(static_cast<double>(num.get_int()));
  
  n = 2;

  while (n <= limit && prime)
  {
    if (num.get_int() % n == 0)
     prime = false;
    else
     n++;
   }
   return prime;
}
 

bool operator >(const my_int int1, const my_int int2) {
  return int1.get_int() > int2.get_int();
}