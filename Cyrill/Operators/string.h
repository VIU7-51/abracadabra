#ifndef STRING_H
#define STRING_H

class String
{
public:
    friend std::ostream & operator<<(std::ostream &, const String &);
    const char & operator[] (int)const;
    char & operator[] (int);
    friend bool  operator==(const String &, const String &);
    friend bool  operator>(const String &, const String &);
    String & operator+=(const String &);
    String & operator=(const String &);
    String(const char *str="");
    ~String();

    int Len()   const{ return n; }
    void Print()const;
private:
    char *s;
    int n;


};

String operator+(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>=(const String &, const String &);
bool operator< (const String &, const String &);

std::istream & operator>>(std::istream &, String &);


#endif // STRING_H
