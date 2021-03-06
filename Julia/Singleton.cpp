#include <iostream>

class Singleton{
private:
    Singleton() = default;
    ~Singleton() = default;

    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;

public:
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }
};

int main(){
    Singleton& s = Singleton::getInstance();
    std::cout<<&s;
    return 0;
}
