// Improved version of the classic Singleton implementation
// (automatic object destruction Singleton)
#include <iostream>

class Singleton;

class Destroyer{
    Singleton* singleton;
  public:
    Destroyer(){ std::cout << "Destroyer created\n"; }
    ~Destroyer(){ delete singleton; }
    void initialize(Singleton* s){ singleton = s; }
};

class Singleton{
private:
  static Singleton* singleton;
  static Destroyer destroyer;

protected:
  Singleton(){ std::cout << "Singleton created\n"; }
  Singleton(const Singleton&);
  Singleton& operator=(Singleton&);
  ~Singleton(){}
  friend class Destroyer;

public:
  static Singleton& getSingleton(){
    if(!singleton){
        singleton = new Singleton();
        destroyer.initialize( singleton );
    }
    return *singleton;
  }
};

Singleton * Singleton::singleton = 0;
Destroyer Singleton::destroyer;

int main()
{
  Singleton& singleton = singleton.getSingleton();
}
