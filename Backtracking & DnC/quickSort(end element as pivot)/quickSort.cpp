#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void quickSort(int arr[], int start, int end) {
        if (start >= end)
            return;
        int pivot = end;
        int i = start - 1;
        int j = start;
        while (j < pivot) {
            if (arr[j] < arr[pivot]) {
                ++i;
                swap(arr[i], arr[j]);
            }
            ++j;
        }
        ++i;
        swap(arr[i], arr[pivot]);
        quickSort(arr, start, i - 1);
        quickSort(arr, i + 1, end);
    }

    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    int arr[] = {7, 2, 1, 8, 6, 3, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = size - 1;
    
    cout << "Original array: ";
    s.printArray(arr, size);

    s.quickSort(arr, start, end);

    cout << "Sorted array: ";
    s.printArray(arr, size);

    return 0;
}
