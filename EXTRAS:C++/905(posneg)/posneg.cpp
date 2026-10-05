#include <iostream>
using namespace std;

void partitionNegative(int arr[], int n) {

    int left = 0;
    int right = n - 1;

    while (left < right) {

        // Left side ko negative chahiye
        if (arr[left] < 0) {
            left++;
        }

        // Right side ko positive/zero chahiye
        else if (arr[right] >= 0) {
            right--;
        }

        // Left par positive/zero aur right par negative
        // Dono wrong side par hain → swap
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }
}

int main() {

    int arr[] = {1, -2, 3, -4, -5, 6, -7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    partitionNegative(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}