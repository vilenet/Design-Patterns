#include <iostream>

class Adaptee{
public:
  void info(){
    std::cout << "hello";
  }
};

class Target{
public:
  virtual void info() = 0;
};

class Client{
public:
  void info(Target* target){
    target->info();
  }
};

class Adapter: public Target{
private:
  Adaptee* adaptee = new Adaptee();

public:
  virtual void info(){
    adaptee->info();
    std::cout << " world" << std::endl;
  }
};

int main()
{
    //Target* p = new Adapter;
    //p->info();

    Client client;
    client.info(new Adapter);
}


