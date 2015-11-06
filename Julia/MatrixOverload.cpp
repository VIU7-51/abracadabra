#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

class Matrix{
public:
    Matrix();
    Matrix(int);
    void randFill();
    int getSize();
    Matrix operator+(Matrix);
    Matrix operator*(Matrix);
    Matrix operator=(Matrix);
    friend ostream& operator<<(ostream&, Matrix);
    //friend ostream& operator>>(ostream&, Matrix);
private:
    int **matrix;
    int size;
};

Matrix::Matrix(){
    size = 1+rand()%10;
    matrix = new int*[size];
    for(int i = 0; i<size; i++) matrix[i] = new int[size];
}
Matrix::Matrix(int num){
    size = num;
    matrix = new int*[size];
    for(int i = 0; i<size; i++) matrix[i] = new int[size];
}

void Matrix::randFill(){
    for(int i = 0; i<size; i++)
        for(int j = 0; j<size; j++){
            matrix[i][j] = rand()%5;
        }
}

int Matrix::getSize(){
    return size;
}

Matrix Matrix::operator+(Matrix that){
    assert(getSize()==that.getSize());
    Matrix temp(size);
    for(int i = 0; i<size; i++)
        for(int j = 0; j<size; j++){
            temp.matrix[i][j] = matrix[i][j]+that.matrix[i][j];
        }
    return temp;
}

Matrix Matrix::operator*(Matrix that){
    assert(getSize()==that.getSize());
    Matrix temp(size);
    for(int i = 0; i<size; i++)
        for(int j = 0; j<size; j++){
            temp.matrix[i][j] = 0;
            for(int r = 0; r<size; r++){
                temp.matrix[i][j] += matrix[i][r]*that.matrix[r][j];
            }
        }
    return temp;
}
Matrix Matrix::operator=(Matrix that){
    assert(getSize()==that.getSize());
    for(int i = 0; i<size; i++)
        for(int j = 0; j<size; j++){
            matrix[i][j] = that.matrix[i][j];
        }
    return *this;
}

ostream& operator<<(ostream &os, Matrix m){
    for(int i = 0; i<m.getSize(); i++){
        for(int j = 0; j<m.getSize(); j++){
            os<<m.matrix[i][j]<<" ";
        }
        os<<endl;
    }
    return os;
}

int main(){
    Matrix m(2);
    Matrix n(2);
    Matrix d(2);
    m.randFill();
    n.randFill();
    cout<<"Matrix m:"<<endl<<m<<endl;
    cout<<"Matrix n:"<<endl<<n<<endl;
    d = m+n;
    cout<<"Matrix d=m+n:"<<endl<<d<<endl;
    cout<<"m*n:"<<endl<<m*n<<endl;
    return 0;
}
