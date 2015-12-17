#include <iostream>

using namespace std;

class MyString {
public:
	MyString(const char* s) {
		value = new char[strlen(s)+1];
		memcpy(value, s, strlen(s)+1);
	};

	friend MyString operator+(const MyString& lhs, const MyString& rhs){
		char* temp = new char[1];
		temp[0] = '\0';
		strcat(temp, lhs.value);
		strcat(temp, rhs.value);
		return MyString(temp);
	};

	friend ostream &operator <<(ostream &, const MyString& s){
		cout << s.value;
	};

	MyString& operator=(const MyString& s){
		return MyString(s.value);
	};

	char* value;

	
};

void main(){
	MyString s1("qwe");
	MyString s2("123");
	MyString s3 = s1 + s2;
	cout << s3 << endl;
	system("pause");
}