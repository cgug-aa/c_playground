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
			cout<<"���A�� ���� ���B�� ���� ���Ұ� �޶� ����� �� ����."<<endl;		
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
            cout<<"���A�� ���B�� ũ�Ⱑ �޶� ����� �� ����."<<endl;
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
			cout<<"���A�� ���B�� ũ�Ⱑ �޶� ����� �� ����."<<endl;
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
            cout<<"���A�� ���B�� ũ�Ⱑ �޶� ����� �� ����."<<endl;
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
            cout<<"���A�� ���B�� ũ�Ⱑ �޶� ����� �� ����."<<endl;
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
            cout<<"0���� �����°� �Ұ����ϴ�."<<endl;
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
		cout<<"��� C"<<endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }
};
// �Ʒ��Լ��� Ŭ���� �ۼ��� �� ����
int main()
{
	int Am,An,Bm,Bn;
	cout<<"��� A�� ũ��(mxn)�� ���� ���ʴ�� �Է��Ͻÿ�."<<endl;
	cin>>Am>>An;
	cout<<"��� B�� ũ��(mxn)�� ���� ���ʴ�� �Է��Ͻÿ�."<<endl;
	cin>>Bm>>Bn;
	Matrix A(Am,An);
	Matrix B(Bm,Bn);

	cout<<"��� A�� ������ ���� �Ҵ��Ͻÿ�."<<endl;
	for(int i=0;i<Am;i++){
		for(int j=0;j<An;j++){
			cin>>A.mat[i][j];
		}
	}
	cout<<"��� B�� ������ ���� �Ҵ��Ͻÿ�."<<endl;
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