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
// remove() 함수를 int로 구체화하는 경우
    cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2,3}을 뺍니다" << endl;
    int x[]={1,2,3,4};
    int y[]={-3,5,10,1,2,3};
    int retSize;
    int* p = remove(x, 4, y, 6, retSize);
    if(retSize == 0) {
        cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // 배열의 모든 원소 출력
            cout << ________________ << ' ';
        cout << endl;
        delete [] p; // 할당받은 배열 반환
    }
// remove() 함수를 double로 구체화하는 경우
// 이곳에 작성
}
*/
////////////////////////////////////////////////////////////
template <class T>
bool CheckItem(T item, T minus[], int sizeMinus){
    for(int i=0;i<sizeMinus;i++){
        if(minus[i]==item)//같은 원소가 있음
            return true;
    }
    return false; //같은 원소가 없음
}
template <class T>
T* remove(T* src, int sizeSrc, T minus[], int sizeMinus, int& retSize)
{   //주소를 리턴해줘
    T* C=new T[sizeSrc];  //배열의 사이즈엔 숫자가 들어가야돼 따라서 동적할당 해버리자.
    int count=0;

    for(int i=0;i<sizeSrc;i++){
        if(false==CheckItem(src[i],minus, sizeMinus)){
            C[count]=src[i];
            count++;
        }
    }
    retSize=count;   //c배열의 원소의 개수를 알려줘
    return C;        //배열 리턴
};
int main() {
    // remove() 함수를 int로 구체화하는 경우

    cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2}을 뺍니다" << endl;
    int x[]={1,2,3,4};
    int y[]={-3,5,10,1,2};
    int retSize;
    
    int* p = remove<int>(x, 4, y, 5, retSize);  //remove함수가 주소를 반환하므로 p의 변수형도 주소로한다.
    
    if(retSize == 0) {
        cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // c 배열의 모든 원소 출력
            cout << p[i] << ' ';
        cout << endl;
        delete [] p; // 할당받은 배열 반환
    }
}
int main_1() {
    // remove() 함수를 double로 구체화하는 경우

    cout << "실수 배열 {1,2,3,4}에서 실수 배열 {-3,5,10,1,2}을 뺍니다" << endl;
    double x[]={1.0,2.0,3.0,4.0};
    double y[]={-3.0,5.0,10.0,1.0,2.0};
    int retSize;
    
    double* p = remove<double>(x, 4, y, 5, retSize);  //remove함수가 주소를 반환하므로 p의 변수형도 주소로한다.
    
    if(retSize == 0) {
        cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // c 배열의 모든 원소 출력
            cout << p[i] << ' ';
        cout << endl;
        delete [] p; // 할당받은 배열 반환
    }
}