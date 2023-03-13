#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <random>
#include <map>
#include <deque>
using namespace std;

#include <iostream>
#include <deque>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::deque<int> dq(arr, arr + n);

    // Reverse the deque
    std::reverse(dq.begin(), dq.end());

    // Print the reversed deque
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
