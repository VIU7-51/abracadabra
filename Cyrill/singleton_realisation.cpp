#include <iostream>

using namespace std;

class Singleton
{
    public:
        static Singleton& inst();
        void print(char*);
    
    protected:
        static Singleton Inst;
        
    private:
        Singleton();
        ~Singleton();
};


Singleton Singleton::Inst;

Singleton& Singleton::inst()
{
    return Inst;
}

Singleton::Singleton()
{
    cout << "Construct it" << endl;
}

Singleton::~Singleton()
{
    cout << "Destruct it" << endl;
}

void Singleton::print(char* str)
{
    cout << "Print it here -> " << str << endl;
}

int main(int argc, char *argv[])
{
    Singleton::inst().print("First try");
    Singleton::inst().print("Else one first try");
    cin.get();
    return 0;
}
