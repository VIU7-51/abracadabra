#include <iostream>

using namespace std;

class Singleton{
private:
    static Singleton* instance;
    Singleton() = default;
    ~Singleton() = default;

public:
    static Singleton* getInstance(){
        if(!instance)
            instance = new Singleton();
        return instance;
    }

};

int main() {
    Singleton* s = Singleton::getInstance();

    return 0;
}