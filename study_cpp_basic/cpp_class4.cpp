// STL과 템플릿을 활용한 벡터 정렬 및 이진 검색 연습

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums;
    int n, target;

    cout << "정수 5개를 입력하세요: ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    cout << "검색할 수: ";
    cin >> target;

    if (binary_search(nums.begin(), nums.end(), target)) {
        cout << target << " 존재!" << endl;
    } else {
        cout << target << " 없음!" << endl;
    }

    cout << "정렬된 벡터: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}