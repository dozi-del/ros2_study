//STL과 템플릿을 활용한 스택 구현 연습

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack{
    private:
        vector<T> items;
    public:
        void push(T item){
            items.push_back(item);
        }
        void pop(){
            if (!items.empty()){
                items.pop_back();
            }
        }
        T top(){
            return items.back();
        }
        bool empty(){
            return items.empty();
        }
};


int main(){
    Stack<int> s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.top()<<endl;
    s.pop();
    cout << "Top after pop : "<< s.top()<<endl;
    
    return 0;
}