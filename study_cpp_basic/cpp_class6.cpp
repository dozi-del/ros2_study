// 큐 만들기 예제

#include <iostream>
#include <vector>

using namespace std;

template<typename T>

class Queue{
    private:
        vector<T> items;

    public:
        void enqueue(T item);
        void dequeue();
        T front();
        bool empty();
        void print(){
            for(auto x : items){
                cout << x <<" ";
            }
            cout<<endl;
        }
};

template<typename T>
void Queue<T>::enqueue(T item){
    items.push_back(item);
}

template<typename T>
void Queue<T>::dequeue(){
    items.erase(items.begin());
}

template<typename T>
T Queue<T>::front(){
    return items.front();
}

template<typename T>
bool Queue<T>::empty(){
    return items.empty();
}


int main()
{
    // cout<<"Hello World";
    vector<int> v = {1,2,3};
    // Queue test();
    // std::cout << v << std::endl;
    
    for(auto x : v){ //.begin()부터 .end()까지 반복하면서 원소 하나씩 x에 복사
    //iterable한 객체에서 원소 하나씩 x에 복사 -> v값을 바꾸려면 참조 활용
    // auto& x :v -> x값이 변하면 실제 원소값 변경됨
    // 파이썬에서의 for x in v와 유사
        cout << x << " ";
    }
    cout<<endl;
    
    Queue<int> q;
    
    for(int i=10; i<100; i=i*2){
        q.enqueue(i);
    }
    q.print();
    
    q.dequeue();
    
    q.print();
    
    q.empty();
    
    q.front();
    

    return 0;
}