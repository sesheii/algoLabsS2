#include <iostream>
#include <vector>
#include <algorithm>

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

//    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    long long answer = std::abs(vec1[0] + vec2[0] - x);
    for (long long i : vec1) {

        int L = 0;
        int R = vec2.size()-1;

        while (L <= R) {
            int mid = (L + R) / 2;
            long long sum = i + vec2[mid];
            long long diff = std::abs(sum - x);

            if (diff < answer) {
                answer = diff;
            }

            if (sum == x) {
                std::cout << 0;
                return 0;
            }

            if (sum < x)
                L = mid + 1;
            else
                R = mid - 1;
        }
    }
    std::cout << answer;
}
