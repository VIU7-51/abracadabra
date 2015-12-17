#include <iostream>

using namespace std;

class Matrix {
public:
    int width, height;
    Matrix(int, int);
    void randomFill();
    Matrix operator+(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix* operator=(Matrix*);
    void print();

private:
    int **values;
};

Matrix::Matrix(int w, int h){
    width = w;
    height = h;
    values = new int*[height];
    for (int i=0; i<height; i++){
        values[i] = new int[width];
    }
}

void Matrix::randomFill(){
    srand(std::time(0));
    for (int i = 0; i<height; i++)
        for (int j = 0; j < width; j++)
            values[i][j] = rand() % 10;
}

void Matrix::print(){
    for (int i = 0; i<height; i++) {
        for (int j = 0; j < width; j++) {
            cout << values[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

Matrix Matrix::operator+(const Matrix& rhs) {
    Matrix result(width, height);
    if((width == rhs.width) && (height == rhs.height)){
        for (int i=0; i< height; i++)
            for (int j=0; j<width; j++)
                result.values[i][j] = values[i][j]+rhs.values[i][j];
    } else {
        //Здесь должно вылететь исключение
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& rhs) {
    Matrix result(max(width, height), max(width, height));
    if((width == rhs.height) && (height == rhs.width)){
        for (int i=0; i< result.width; i++)
            for (int j=0; j<result.width; j++){
                int value = 0;
                for(int r = 0; r<width; r++)
                    value = value + values[i][r]*rhs.values[r][j];

                result.values[i][j] = value;
            }

    } else {
        //Здесь должно вылететь исключение
    }
    return result;
}

Matrix* Matrix::operator=(Matrix* rhs) {
    if((width == rhs->width) && (height == rhs->height)){
        for (int i=0; i< height; i++)
            for (int j=0; j<width; j++)
                values[i][j] = rhs->values[i][j];
        return this;
    } else {
        return nullptr;
    }
}

int main() {

    Matrix m1(5,7);
    Matrix m2(5,7);
    Matrix m3(7,5);
    m1.randomFill();
    m2.randomFill();
    m3.randomFill();

    Matrix sum(5,7);
    Matrix prod(7,7);
    sum = m1 + m2;
    prod = m1 * m3;
    cout << "Matrix 1:\n";
    m1.print();
    cout << "Matrix 2:\n";
    m2.print();
    cout << "Matrix 3:\n";
    m3.print();
    cout << "Matrix 1 + 2:\n";
    sum.print();
    cout << "Matrix 1 * 3:\n";
    prod.print();




    return 0;
}