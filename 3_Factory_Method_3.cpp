// C++ program to demonstrate factory method design pattern
#include <iostream>
using namespace std;
 
enum RoboType { robotA, robotB, robotC };
 
// Класс библиотеки
class Robot {
public:
    virtual void printRobot() = 0;
    static Robot* Create(RobotType type);
};
class RobotA : public Robot {
public:
    void printRobot() {
        cout << "I am RobotA" << endl;
    }
};
class RobotB : public Robot {
public:
    void printVehicle() {
        cout << "I am RobotB" << endl;
    }
};
class RobotC : public Robot {
    public:
    void printVehicle() {
        cout << "I am RobotC" << endl;
    }
};
 
// Factory method для создания объектов разных типов.
// Изменение требуется только в этой функции для создания нового типа объекта
Robot* Robot::Create(RobotType type) {
    if (type == robotA)
        return new RobotA();
    else if (type == robotB)
        return new RobotB();
    else if (type == robotC)
        return new RobotC();
    else return NULL;
}
 
// Класс клиента
class Client {
public:
 
    // Клиент явно не создает объекты
    // но передает тип фабричному методу "Create()"
    Client()
    {
        RobotType type = robotB;
        pRobot = Robot::Create(type);
    }
    ~Client() {
        if (pRobot) {
            delete[] pRobot;
            pRobot = NULL;
        }
    }
    Robot* getRobot()  {
        return pRobot;
    }
 
private:
    Robot *pRobot;
};
 
int main() {
    Client *pClient = new Client();
    Robot * pRobot = pClient->getRobot();
    pRobot->printRobot();
    return 0;
}
