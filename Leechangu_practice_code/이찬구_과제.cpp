#include<iostream>
#include<vector>
using namespace std;

class Matrix {
public:
    int row, column;
	vector<vector<int>> mat;
	Matrix() {row=column=1;}
	Matrix(int m, int n) {
		mat.resize(m);
        for (int i = 0; i < m; i++) {
            mat[i].resize(n, 0);
        }
        row = m;
        column = n;
    }
	~Matrix() {
        for (int i = 0; i < row; i++) {
            mat[i].clear();
        }
        mat.clear();
    }

	Matrix operator*(Matrix &mat_B){
        Matrix result(this->row, mat_B.column);
        if (this->column != mat_B.row) {
			cout<<"행렬A의 열과 행렬B의 행의 원소가 달라 계산할 수 없다."<<endl;		
		}
		else{
            for (int i = 0; i < this->row; i++) {
                for (int j = 0; j < mat_B.column; j++) {
                    for (int k = 0; k < this->column; k++) {
                        result.mat[i][j] += this->mat[i][k] * mat_B.mat[k][j];
                    }
                }
            }
		}
        return result;
    }

    Matrix operator+(Matrix &mat_B) {
        Matrix result(row, column);
        if (this->column != mat_B.column || this->row != mat_B.row) {
            cout<<"행렬A와 행렬B의 크기가 달라 계산할 수 없다."<<endl;
        }
		else{
            for (int i = 0; i < this->row; i++) {
                for (int j = 0; j < this->column; j++) {
                    result.mat[i][j] = this->mat[i][j] + mat_B.mat[i][j];
                }
            }
		}
        return result;
    }

	Matrix operator-(Matrix &mat_B) {
        Matrix result(row, column);

        if (this->column != mat_B.column || this->row != mat_B.row) {
			cout<<"행렬A와 행렬B의 크기가 달라 계산할 수 없다."<<endl;
        }
		else{
            for (int i = 0; i < this->row; i++) {
                for (int j = 0; j < this->column; j++) {
                    result.mat[i][j] = this->mat[i][j] - mat_B.mat[i][j];
                }
            }
		}
        return result;
    }
	Matrix &operator+=(Matrix &mat_A) {
        if (this->column != mat_A.column || this->row != mat_A.row) {
            cout<<"행렬A와 행렬B의 크기가 달라 계산할 수 없다."<<endl;
        }
		else{
            for (int i = 0; i < this->row; i++) {
                for (int j = 0; j < this->column; j++) {
                    this->mat[i][j] += mat_A.mat[i][j];
                }
            }
		}
        return *this;
    }
	Matrix &operator-=(Matrix &mat_B) {
        if (this->column != mat_B.column || this->row != mat_B.row) {
            cout<<"행렬A와 행렬B의 크기가 달라 계산할 수 없다."<<endl;
        }
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->column; j++) {
                this->mat[i][j] -= mat_B.mat[i][j];
            }
        }
        return *this;
    }
	Matrix operator*(int integer) {
        Matrix result(row, column);
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->column; j++) {
                result.mat[i][j] = this->mat[i][j] * integer;
            }
        }
        return result;
    }
    Matrix operator+(int integer) {
        Matrix result(row, column);
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->column; j++) {
                result.mat[i][j] = this->mat[i][j] + integer;
            }
        }
        return result;
    }
    Matrix operator-(int integer) {
        Matrix result(row, column);
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->column; j++) {
                result.mat[i][j] = this->mat[i][j] - integer;
            }
        }
        return result;
    }
    Matrix operator/(int integer) {
        Matrix result(row, column);
        if (integer == 0) {
            cout<<"0으로 나누는건 불가능하다."<<endl;
        }
		else{
            for (int i = 0; i < this->row; i++) {
                for (int j = 0; j < this->column; j++) {
                    result.mat[i][j] = this->mat[i][j] / integer;
                }
            }
		}
        return result;
    }
	void print() {
		cout<<"행렬 C"<<endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }
};
// 아래함수는 클래스 작성할 때 참고
int main()
{
	int Am,An,Bm,Bn;
	cout<<"행렬 A의 크기(mxn)의 값을 차례대로 입력하시오."<<endl;
	cin>>Am>>An;
	cout<<"행렬 B의 크기(mxn)의 값을 차례대로 입력하시오."<<endl;
	cin>>Bm>>Bn;
	Matrix A(Am,An);
	Matrix B(Bm,Bn);

	cout<<"행렬 A의 원소의 값을 할당하시오."<<endl;
	for(int i=0;i<Am;i++){
		for(int j=0;j<An;j++){
			cin>>A.mat[i][j];
		}
	}
	cout<<"행렬 B의 원소의 값을 할당하시오."<<endl;
	for(int i=0;i<Bm;i++){
		for(int j=0;j<Bn;j++){
			cin>>B.mat[i][j];
		}
	}
	cout<<endl;

	Matrix C = A * B;
	cout<<"<<C = A * B>>"<<endl;
	C.print();
    
	C = A + B;
    cout<<"<<C = A + B>>"<<endl;
	C.print();

    C = A - B;
	cout<<"<<C = A - B>>"<<endl;
	C.print();

    C = A += B;
	cout<<"<<C = A += B>>"<<endl;
	C.print();

    C = A -= B;
	cout<<"<<C = A -= B>>"<<endl;
	C.print();

    C = A * 2;
	cout<<"<<C = A * 2>>"<<endl;
	C.print();

	C = A + 1;
	cout<<"<<C = A + 1>>"<<endl;
	C.print();

    C = A - 1;
	cout<<"<<C = A - 1>>"<<endl;
	C.print();

    C = A / 3;
	cout<<"<<C = A / 3>>"<<endl;
	C.print();

	return 0;
}