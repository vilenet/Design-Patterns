#include <vector>
#include <queue>
using namespace std;

template <class TYPE>
struct object_pool
{
    std::vector<TYPE> pool;
    std::queue<size_t> avail;
	
    TYPE & operator[](const size_t & i) {
	  return pool[i]; 
	}
	
    void add(size_t & pos)
    {
        if(avail.empty()){ // no reusable object
         pool.push_back(TYPE()); pos = pool.size()-1; 
		}
        else{
         pos = avail.back(); avail.pop(); 
		}
    }
	
    void rem(size_t & a){ 
	  avail.push(a); 
	}
	
    size_t size(){ 
	  return pool.size(); 
	}
};

int main()
{
    
  
  return 0;   
}
