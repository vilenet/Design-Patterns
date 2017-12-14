// ���������� ���������� ������� �������� Singleton �� �++11
#include <new>
//#include <iostream>

class Singleton
{
  private:
     Singleton()  = default; // ���� ����������� ������� ����������� �� ���
     ~Singleton() = default; // �� �� ��� � ������ {}. ������� ���� ����������.
     
     Singleton(const Singlrton&) = delete; // ���������� �����������. delete ���
     Singleton& operator=(const Singleton&) = delete; //�� ��������� ��� �������.
     
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















                   
          
          
          
          
