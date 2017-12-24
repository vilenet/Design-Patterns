#include <iostream>
#include <vector>
using namespace std;

class Object{
	// ...
};

class ObjectPool{
 private:
    
  struct PoolRecord{
    Object* instance;
    bool    in_use;
  };

  std::vector<PoolRecord> m_pool;

public:
  Object* createNewObject(){
    for (unsigned int i = 0; i < m_pool.size(); ++i){
      if (! m_pool[i].in_use){
        m_pool[i].in_use = true; // ��������� ������ � ������ ������������
        return m_pool[i].instance;
      }
    }
    // ���� �� ����� ��������� ������, �� ��������� ���
    PoolRecord record;
    record.instance = new Object;
    record.in_use   = true;

    m_pool.push_back(record);

    return record.instance;
  }

  void deleteObject(Object* object){
    // � ���������� �� �������, � ���� ��������, ��� ����� ��������
    for (size_t i = 0; i < m_pool.size(); ++i){
      if (m_pool[i].instance == object){
        m_pool[i].in_use = false;
        break;
      }
    }
  }

  virtual ~ObjectPool(){
    // ������ ��� "��-����������" ������� �������
    for (size_t i = 0; i < m_pool.size(); ++i)
      delete m_pool[i].instance;
    }
};

int main()
{
	ObjectPool pool;
	for (int i = 0; i < 100; ++i){
		Object* object = pool.createNewObject();
		// ...
		pool.deleteObject(object);
	}
	return 0;
}

// ! ������ �� ��������� !
