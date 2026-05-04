#include <iostream>
using namespace std;
// 오버라이딩 복습

class Shape{
    public :
    virtual double draw(){ // virtual : 가상함수, 자식 클래스에서 재정의 가능
        return 0;
    }
};

class Circle : public Shape{
    
    private :
        double r;


    public : 
        Circle(double r) {
        this->r = r;
    }
        double draw() override{
            return 3.14 * r * r;
        }
};

class Rectangle : public Shape{
    private :
        double w, h;


    public : 
        Rectangle(double w, double h) {
        this->w = w;
        this->h = h;
    }
        double draw() override{
            return w * h;
        }
};

class Calculator { // 오버로딩 복습
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

};

class Point { // 연산자 오버로딩 복습
private:
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}

    // 연산자 오버로딩
    Point operator+(const Point& other) { 
        // operator+(상수 참조) : Point 객체를 상수 참조로 받아서 더하기 연산을 수행
        return Point(x + other.x, y + other.y);
    }

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main(){
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(2, 5);

    cout << "Circle area : " << s1->draw() << endl;
    cout << "Rectangle area : " << s2->draw() << endl;

    delete s1;
    delete s2;

    Calculator calc;
    cout << "add(int, int) : " << calc.add(3, 4) << endl;
    cout << "add(double, double) : " << calc.add(3.5, 4.2) << endl;


    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;
    p3.print();

    return 0;
}