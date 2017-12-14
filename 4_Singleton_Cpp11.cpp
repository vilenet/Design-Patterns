// Нормальная реализация плохого паттерна Singleton на С++11
#include <new>
//#include <iostream>

class Singleton
{
  private:
     Singleton()  = default; // Дать компилятору создать конструктор за нас
     ~Singleton() = default; // то же что и скобки {}. Обнулит наши переменные.
     
     Singleton(const Singlrton&) = delete; // Копирующий конструктор. delete озн
     Singleton& operator=(const Singleton&) = delete; //не создавать эти функции.
     
     void* operator new(std::size_t)   = delete;
     void* operator new[](std::size_t) = delete;
     
     void operator delete(void*)   = delete;
     void operator delete[](void*) = delete;
  
  public:
     static Singleton& getInst()
     {
       static Singleton object;
       return object;
     }
};

/*void foo(){
    auto& a = Singleton::getInst();
    std::cout << &a << std:::endl;
}
void bar(){
    auto& b = Singleton::getInst();
    std::cout << &b << std:::endl;   
}*/

int main()
{
  auto& s = Singleton::getInst();   
  //foo();
  //bar(); 
    
  return 0;  
}















                   
          
          
          
          
