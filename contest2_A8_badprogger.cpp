#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for (int& i: v) {
        cin >> i;
    }

    long long bro = 0, me = 0;
    int i = 0, j = N-1;

    bool queue = true;

    while (i < j) {

        if (j - i == 1) {
            if (queue)
                bro += std::max(v[i],v[j]);
            else
                me += std::max(v[i],v[j]);

            queue = !queue;

            if (queue)
                bro += std::min(v[i],v[j]);
            else
                me += std::min(v[i],v[j]);

            break;
        }

        int mid = (i + j)/2;
        long long left_sum = sum(i, mid, v);
        long long right_sum = sum(mid + 1, j, v);
        std::cout << "L: " << i << " R: " << j << " M: " << mid << " left_sum: " << left_sum << " right_sum: " << right_sum << '\n';

        if (right_sum > left_sum) {

            if (queue)
                bro += right_sum;
            else
                me += right_sum;

            j = mid;

        } else {

            if (queue)
                bro += right_sum;
            else
                me += right_sum;

            i = mid;

        }

        queue = !queue;
    }

    std::cout << std::min(bro, me) << ' ' << std::max(bro, me);

}
