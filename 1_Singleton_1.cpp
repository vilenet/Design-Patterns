// Classic Singeton implementation
#include <iostream>
using namespace std;

class Singleton{
  private:
    static Singleton* instance;
    Singleton(){ cout << "singleton created\n"; }

  public:
    static Singleton* getInstance(){
      if(instance == NULL){
        instance = new Singleton;
      }
      return instance;
    }
};

Singleton* Singleton::instance = NULL;

int main()
{
   Singleton* singleton;
   singleton = singleton->getInstance();
   delete singleton;
}
