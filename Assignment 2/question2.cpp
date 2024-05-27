#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<double> > data;

public:
    
    Matrix(int m, int n){
        rows = m;
        cols = n;
        data = vector<vector<double> >(m,vector<double>(n));
    }

    void input() {
        cout << "Enter " << rows * cols << " elements for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    Matrix operator*(const Matrix& other) const {
        

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {                
                double sum = 0.0;
                for (int k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;            
            }
        }
        
        return result;
    }

    void print() const {
        cout << "Matrix " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    Matrix matA(m, n), matB(n, m), matC(m, m);

    matA.input();
    matB.input();

    matC = matA * matB;

    cout << "Matrix matA:"<<endl;
    matA.print();
    cout << "Matrix matB:\n";
    matB.print();
    cout << "Result of multiplication (Matrix matC):\n";
    matC.print();

    return 0;
}
