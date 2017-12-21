// Simple Factory pattern
#include <iostream>

class Rational{
  private:
    int A,B;
    Rational(int a, int b){
      A=a; B=b;
    }  
   
  public: 
    static Rational make_from_two_ints(int a, int b){
       return Rational(a, b);   
    }
    //static Rational make_from_float(float f){
       //....   
    //}       

};

int main()
{
  Rational A = Rational::make_from_two_ints(10, 20);
  
 return 0;   
}
