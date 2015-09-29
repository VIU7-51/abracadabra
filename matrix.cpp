#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
int n;
class matrix{
	int **a;
public:	
	matrix::matrix(){a=new int*[n];
	for(int i=0;i<n;i++){
		a[i]=new int[n];
	}
	}
	//friend int& operator +( matrix& r,matrix & k);
	friend ostream & operator <<(ostream & is, matrix & r);
	friend istream & operator >>(istream & is, matrix& r);

matrix operator +( matrix r){
	matrix z;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			z.a[i][j]=a[i][j]+r.a[i][j];
		}
	}
	return z;

}
matrix operator *( matrix r){
	matrix z;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			z.a[i][j]=0;
			for(int y=0;y<n;y++){
				z.a[i][j]+=a[i][y]*r.a[y][j];
			}
		}
	}
	return z;

}
};
ostream & operator <<(ostream & is, matrix & r)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
		cout<<r.a[i][j]<<" ";
		if(j==n-1){cout<<endl;}
		}
	}
	return is;
}
	
istream & operator >>(istream & is, matrix & r)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		cin>>r.a[i][j];
		}
	}
			return is;
}

void main(){
	cout<<"size massiv"<<endl;
	cin>>n;
	system("cls");
	matrix l;
	cout<<"1 matrix:"<<endl;
	cin>>l;
	system("cls");
	cout<<"ok! 2 matrix"<<endl;
	matrix k;
	cin>>k;
	system("cls");
	cout<<"*"<<endl<<l*k<<endl;
	cout<<"+"<<endl<<l+k;
	system("pause");
}
