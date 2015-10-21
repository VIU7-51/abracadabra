#include <iostream>
using namespace std;
class BinSearch
{
public:
	BinSearch();
	void binSearch(int num) {
		count++;
		int mid = (start+end)/2;
		if (end-start == 1) {cout<<num<<" is not Found; "<<count<<" iterations\n"; return;}
		if (num<arr[mid]) {
		    end = mid; 
		    binSearch(num);
		}
		else if (num>arr[mid]) {
		    start = mid;
		    binSearch(num);
		}
		else if(num==arr[mid]) {
		    cout<<num<<" is found in "<<count<<" iterations; index = "<<mid<<"\n";
		    start = 0;
		    end = size;
		    count = 0;
		}
		
	}
	void printArr() {
		for (int i = 0; i<size; i++) {
			cout<<arr[i]<<"\t";
		}
		cout<<"\n";
	}
	
	private:
	const int size = 100;
	int count = 0;
	int arr[100];
	int start = 0;
	int end = size;

	int Fill(int arr[]) {
		for (int i = 0; i<size; i++) {
			arr[i] = rand()%100 + 1;
		}
		return *arr;
	}

	int BubSort(int arr[]) {
		for (int i = 0; i<size; i++) {
			for (int j = 0; j<size; j++) {
				if (arr[i]<arr[j]) {
					swap(arr[i], arr[j]);
				}
				
			}
		}
		return *arr;
	}
};
BinSearch::BinSearch() {
	Fill(arr);
	BubSort(arr);
}

int main() {
	BinSearch b;
	b.printArr();
	b.binSearch(28);
	b.binSearch(64);
	b.binSearch(11);
	cout<<"\n";
	system("pause");
	return 0;
}
