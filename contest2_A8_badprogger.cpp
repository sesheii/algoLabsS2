#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long sum(vector<int>::iterator first, vector<int>::iterator second) {
    long long result = 0;
    for (auto i = first; i <= second; ++i){
        result += *i;
        std::cout << *i << ' ';
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for (int& i: v) {
        cin >> i;
    }

    long long bro = 0, me = 0;

    auto i = v.begin();
    auto j = v.end();

    vector<int>::iterator mid = (v.begin() + (distance(i,j)/2 + distance(i,j)%2 - 1));
    sum(i,mid);
    std::cout << '\n';
    sum(mid,j);

//    cout << *mid << '\n';
//    cout << accumulate(i,mid,0) << ' ' << accumulate(mid + 1, j, 0);

//    while (i != j) {
//        vector<int>::iterator mid = (v.begin() + (distance(i,j)/2 + distance(i,j)%2 - 1));
//
//    }

//    std::cout << std::min(bro, me) << ' ' << std::max(bro, me);

}
