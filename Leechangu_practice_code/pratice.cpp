#include<iostream>
#include<string.h>
using namespace std;

/*
template<class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize){
    int count=0;
    T ret[];
    for(int i=0;i<sizeSrc;i++){
        for(int j=0;j<sizeMinus;j++){
            if(src[i]!=minus[j])
                ref[count]=src[i];
                count++;
        }
    }
}
int main() {
// remove() �Լ��� int�� ��üȭ�ϴ� ���
    cout << "���� �迭 {1,2,3,4}���� ���� �迭 {-3,5,10,1,2,3}�� ���ϴ�" << endl;
    int x[]={1,2,3,4};
    int y[]={-3,5,10,1,2,3};
    int retSize;
    int* p = remove(x, 4, y, 6, retSize);
    if(retSize == 0) {
        cout << "��� ���ŵǾ� �����ϴ� �迭�� �����ϴ�." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // �迭�� ��� ���� ���
            cout << ________________ << ' ';
        cout << endl;
        delete [] p; // �Ҵ���� �迭 ��ȯ
    }
// remove() �Լ��� double�� ��üȭ�ϴ� ���
// �̰��� �ۼ�
}
*/
////////////////////////////////////////////////////////////
template <class T>
bool CheckItem(T item, T minus[], int sizeMinus){
    for(int i=0;i<sizeMinus;i++){
        if(minus[i]==item)//���� ���Ұ� ����
            return true;
    }
    return false; //���� ���Ұ� ����
}
template <class T>
T* remove(T* src, int sizeSrc, T minus[], int sizeMinus, int& retSize)
{   //�ּҸ� ��������
    T* C=new T[sizeSrc];  //�迭�� ����� ���ڰ� ���ߵ� ���� �����Ҵ� �ع�����.
    int count=0;

    for(int i=0;i<sizeSrc;i++){
        if(false==CheckItem(src[i],minus, sizeMinus)){
            C[count]=src[i];
            count++;
        }
    }
    retSize=count;   //c�迭�� ������ ������ �˷���
    return C;        //�迭 ����
};
int main() {
    // remove() �Լ��� int�� ��üȭ�ϴ� ���

    cout << "���� �迭 {1,2,3,4}���� ���� �迭 {-3,5,10,1,2}�� ���ϴ�" << endl;
    int x[]={1,2,3,4};
    int y[]={-3,5,10,1,2};
    int retSize;
    
    int* p = remove<int>(x, 4, y, 5, retSize);  //remove�Լ��� �ּҸ� ��ȯ�ϹǷ� p�� �������� �ּҷ��Ѵ�.
    
    if(retSize == 0) {
        cout << "��� ���ŵǾ� �����ϴ� �迭�� �����ϴ�." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // c �迭�� ��� ���� ���
            cout << p[i] << ' ';
        cout << endl;
        delete [] p; // �Ҵ���� �迭 ��ȯ
    }
}
int main_1() {
    // remove() �Լ��� double�� ��üȭ�ϴ� ���

    cout << "�Ǽ� �迭 {1,2,3,4}���� �Ǽ� �迭 {-3,5,10,1,2}�� ���ϴ�" << endl;
    double x[]={1.0,2.0,3.0,4.0};
    double y[]={-3.0,5.0,10.0,1.0,2.0};
    int retSize;
    
    double* p = remove<double>(x, 4, y, 5, retSize);  //remove�Լ��� �ּҸ� ��ȯ�ϹǷ� p�� �������� �ּҷ��Ѵ�.
    
    if(retSize == 0) {
        cout << "��� ���ŵǾ� �����ϴ� �迭�� �����ϴ�." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // c �迭�� ��� ���� ���
            cout << p[i] << ' ';
        cout << endl;
        delete [] p; // �Ҵ���� �迭 ��ȯ
    }
}