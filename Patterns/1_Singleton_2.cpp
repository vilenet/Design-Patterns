// Myers Singleton implementation
#include <iostream>

class Singleton{
private:
  Singleton(){ std::cout << "Singleton created\n"; }
  Singleton(const Singleton&);
  Singleton& operator=(Singleton&);

public:
  static Singleton& getSingleton(){
    static Singleton singleton;
    return singleton;
  }
};

int main()
{
    Singleton& singleton = Singleton::getSingleton();
}
