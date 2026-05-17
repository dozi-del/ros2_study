// 스마트 포인터 예제: unique_ptr과 shared_ptr 사용법

/*
스마트 포인터
- 동적 메모리 관리를 자동으로 처리하는 클래스 템플릿, <memory> 헤더에서 제공
- new, delete 직접 쓰지 않고도 메모리 자동 해제
- 메모리 누수 방지, 예외 안전성 제공

(1) unique_ptr
- 하나의 객체에 하나의 포인터만 소유(단독 소유권)
- 소유권 이전(move semantics) 가능, 복사 불가
- 객체가 범위를 벗어나면 자동으로 메모리 해제

(2) shared_ptr
- 여러 포인터가 하나의 같은 객체를 공유(참조 카운트)
- 참조 카운트가 0이 되면 객체 자동 해제
- 복사 가능, 참조 카운트 증가

(3) weak_ptr
- shared_ptr이 관리하는 객체에 대한 약한 참조 (소유하지 않음)
- 참조 카운트 증가시키지 않음, 순환 참조 방지
- 객체가 이미 소멸되었는지 확인 가능 (expired(), lock() 메서드)
- 스마트 포인터 사용 시 주의사항
  - 순환 참조: shared_ptr이 서로를 참조하는 경우 메모리 누수 발생 가능, weak_ptr로 해결
  - 성능: 스마트 포인터는 일반 포인터보다 약간의 오버헤드가 있을 수 있음, 하지만 안전성 향상으로 보완

*/

#include <iostream>
#include <memory>
using namespace std;

class Student { //학생 객체를 unique_ptr로 관리
public:
    string name;
    Student(string n) : name(n) {
        cout << name << " 생성" << endl;
    }
    ~Student() {
        cout << name << " 소멸" << endl;
    }
};

class Data {
public:
    Data() { cout << "Data 생성" << endl; }
    ~Data() { cout << "Data 소멸" << endl; }
};


int main() {
    unique_ptr<Student> s1 = make_unique<Student>("Jisu");
    cout << s1->name << endl;

    // shared_ptr 참조 카운트 확인
    // 같은 객체를 가리키는 shared_ptr이 몇 개 있는지 확인
    shared_ptr<Data> d1 = make_shared<Data>();
    {
        shared_ptr<Data> d2 = d1;
        cout << "참조 카운트: " << d1.use_count() << endl;
    }
    cout << "블록 종료 후 카운트: " << d1.use_count() << endl;

    return 0;
}
