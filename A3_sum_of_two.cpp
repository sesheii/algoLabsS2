#include <iostream>
#include <vector>

int main() {
    int n, m;
    long long x;
    std::cin >> n >> m >> x;

    std::vector<long long> vec1(n);
    std::vector<long long> vec2(m);

    for (long long& i : vec1) {
        std::cin >> i;
    }
    for (long long& i : vec2) {
        std::cin >> i;
    }

    std::sort(vec1.begin(), vec1.end());

    long long answer = 10e+18;
    for (long long i : vec2) {

        int L = 0;
        int R = vec1.size()-1;

        while (L <= R) {
            int mid = (L + R) / 2;
            long long diff = std::abs((i + vec2[mid]) - x);

            if (diff < answer) {
                answer = diff;
            }

            if ((vec1[mid] + i) < x)
                R = mid - 1;
            else
                L = mid + 1;
        }
    }
    std::cout << answer;
}
