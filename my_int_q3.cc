// Simple class to illustrate separate compilation and const
// parameters
// 
// Written by Mal Gunasekera
// Modified by David M. Chelberg
// last-modified: Tue Apr 23 07:31:28 2013
// 
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class my_int
{
public:
  //*********************************************************
  // Function: my_int
  // Purpose:  Constructor initializes the val to x
  // Params:   x - the value for the val
  // Calls:    none
  // Uses:     none
  //*********************************************************
  my_int(int x);   

  //*********************************************************
  // Function: my_int       
  // Purpose:  Constructor initializes the val to 0      
  // Params:   none      
  // Calls:    none                                    
  // Uses:     none           
  //*********************************************************
  my_int();       

  //*********************************************************
  // Function: set
  // Purpose:  Sets the val to x
  // Params:   x - the new value for the val
  // Calls:    none
  // Uses:     none
  //*********************************************************
  void set(int x); 

  //*********************************************************************
  // Function: input
  // Purpose:  reads and stores a value from inp. if inp is a input 
  //           stream, then inp is already connected to a file.User enters 
  //           a value and ask the user to re-enter the data if the
  //           user enters an incorrect value.
  // Params:   inp -- the input stream
  // Calls:    none
  // Uses:     istream
  //*********************************************************************
  void input(istream& inp);  
 
  //*********************************************************************
  // Function: output
  // Purpose:  display the val on fout. if fout is a  output stream
  //           then fout is already  connected to a file
  // Params:   fout -- the output stream
  // Calls:    none
  // Uses:     ostream
  //*********************************************************************
  void output(ostream& fout) const;

  //*********************************************************
  // Function: get_int
  // Purpose:  returns the val
  // Params:   none
  // Calls:    none
  // Uses:     none
  //*********************************************************
  int get_int() const;

  //*******************************************************************************************
  // Operator: >
  // Purpose:  checks if the value of the first number is greater than that of the second
  // Params:   int1 -- the my_int containing the first value
  //           int2 -- the my_int containing the second value
  // Calls:    none
  // Uses:     none
  //*******************************************************************************************
  friend bool operator >(const my_int int1, const my_int int2);

private:
  int val;  // Variable to hold value for class
};

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
// Function: my_int
// Purpose:  Constructor initializes the val to x
// Params:   x - the value for the val
// Calls:    none
// Uses:     none
//*********************************************************
my_int::my_int(int x)
{
   val = x;
}

  //*********************************************************
  // Function: my_int       
  // Purpose:  Constructor initializes the val to 0      
  // Params:   none      
  // Calls:    none                                    
  // Uses:     none           
  //*********************************************************
my_int::my_int()
{
  val = 0;
}


  //*********************************************************
  // Function: set
  // Purpose:  Sets the val to x
  // Params:   x - the new value for the val
  // Calls:    none
  // Uses:     none
  //*********************************************************
void my_int::set(int a)
{
   val = a;
}


  //*********************************************************************
  // Function: output
  // Purpose:  display the val on fout. if fout is a  output stream
  //           then fout is already  connected to a file
  // Params:   fout -- the output stream
  // Calls:    none
  // Uses:     ostream
  //*********************************************************************
void my_int::output(ostream& fout) const
{
  fout<<" The value is equal to "<<val<<endl;
}


  //*********************************************************
  // Function: get_int
  // Purpose:  returns the val
  // Params:   none
  // Calls:    none
  // Uses:     none
  //*********************************************************
int my_int:: get_int() const
{
  return val;
}


  //*********************************************************************
  // Function: input
  // Purpose:  reads and stores a value from inp. if inp is a input 
  //           stream, then inp is already connected to a file.User enters 
  //           a value and ask the user to re-enter the data if the
  //           user enters an incorrect value.
  // Params:   inp -- the input stream
  // Calls:    none
  // Uses:     istream
  //*********************************************************************
void my_int:: input(istream& inp)
{
   cout<<"Enter a positive value greater than 1  ";
   inp >> val;
   while (val <= 1)
   {
    cout<<"Entered an Invalid value \n";
    cout<<"Enter a positive value greater than 1 \n";
    inp>> val;
   }  
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