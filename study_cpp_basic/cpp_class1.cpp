#include <iostream>
//class 및 포인터 기초 복습
//클래스 public, private, 상속
// 포인터 기초 및 참조
using namespace std;

class MyClass {
private:
	int a;
	int b;
	int total;
	int result;

public:
	// 생성자
	MyClass(int a1=0, int b1=1) { 
		a = a1;
		b = b1;
		cout << "a : " << a << " b : " << b << endl;
	}
	~MyClass() {
		cout << "del" << endl;
	}
	void sum() {
		total = a + b;
		cout << "a + b = " << total << endl;
	}
	int minus() {
		result = a - b;
		cout << "result : " << result << endl;
		return result;
	}

	void address(int ch) {
		// pointer 복습
		int* p = &a;
		cout << "&a : " << &a << ", p : " << p << ", *p : " << *p << endl;
		int& ref = a;
		cout << "before ch ref : " << ref;
		ref = ch;
		cout << "after ch ref : " << ref << ", a : " << a << endl;
	}

	void array(int c, int d, int e) {
		int arr[3] = { c, d, e };
		for (int i = 0; i < 3; i++) {
			cout << "arr " << i << " : " << arr[i] << endl;
		}
	}


};

class Math : public MyClass {
private:
	int c;
	int d;
	int result;
public:
	Math(int c1 = 1, int d1 = 1) {
		c = c1;
		d = d1;
	}
	~Math() {
	}

	void divide() {
		if (d == 0) {
			cout << "0으로 나눌 수 없음" << endl;
		} 
		else {
			result = c / d;
			cout << "c/d = " << result << endl;
		}
	}
	void multi() {
		cout << "c*d = " << c * d << endl;
	}
	void all() {
		sum();
		minus();
		divide();
		multi();
	}
};

int main() {

	MyClass num(4, 6);
	num.sum();
	num.minus();

	num.address(7);
	num.array(1,5,2);

	Math num2(18, 9);
	num2.all();
	Math num3(21, 0);
	num3.all();

	return 0;
}