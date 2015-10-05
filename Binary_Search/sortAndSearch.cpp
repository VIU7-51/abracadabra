#include <iostream>
#include <cmath>

using namespace std;

class ExtArray {
private:
	int* values;
    bool sorted;

public:
	
	int size;
	ExtArray(int sz);
	void setValue(int place, int value);
	void sort(int);
	void findPlaceByValue(int value);
	void print();
							
};

ExtArray::ExtArray(int sz){
	size = sz;
	values = new int[sz];
    sorted = false;
}

void ExtArray::print(){
	for (int i=0;i<size;i++)
		cout << this->values[i] << " ";
	cout << "\n";
}

void ExtArray::setValue(int place, int value){
	values[place] = value;
}

void ExtArray::sort(int last){
	int* sortedArray = new int[size];
    if(last>0) {
        for (int i = 0; i < last; i++) {
            int temp;
            if (values[i] > values[i + 1]) {
                temp = values[i + 1];
                values[i + 1] = values[i];
                values[i] = temp;
            }
        }

        this->sort(last - 1);
    } else {
        sorted = true;
    }
}

void ExtArray::findPlaceByValue(int value){
	if(sorted){
        int currentIndex = size-1;
        while(true) {
            if (values[currentIndex] != value) {
                if (((values[currentIndex]<value) && (currentIndex == size-1)) ||
                    ((values[currentIndex]>value) && (currentIndex == 0)) ||
                    ((int)floor(currentIndex / 2) == currentIndex)){
                    cout << "Not found";
                    break;
                } else {
                    currentIndex = (int)floor(currentIndex / 2);
                }
            } else {
                cout << "Found at index: " << currentIndex;
                break;
            }
        }
    }
	
}

int main(){
	int sz, place;

	cout << "Enter size: ";
	cin >> sz;

	ExtArray* arr = new ExtArray(sz);

	for (int i = 0; i<sz; i++){
		int value;
		cout << "Enter element no. " << i << ": ";
		cin >> value;
		arr->setValue(i,value);
	};

	arr->sort(sz-1);
	arr->print();

	cout << "Enter value to find: ";
    cin >> place;
	arr->findPlaceByValue(place);

	//system("pause");
	return 0;
}
