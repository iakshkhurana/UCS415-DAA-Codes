#include <iostream>
using namespace std;

void merge(int arr[], int s, int e, int mid) {
    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    // Create temporary arrays
    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    // Copy data to temp arrays
    for (int i = 0; i < leftLength; i++) {
        leftArr[i] = arr[s + i];
    }
    for (int i = 0; i < rightLength; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge logic
    int leftIndex = 0, rightIndex = 0;
    int mainArrayIndex = s;
    while (leftIndex < leftLength && rightIndex < rightLength) {
        if (leftArr[leftIndex] <= rightArr[rightIndex]) {
            arr[mainArrayIndex] = leftArr[leftIndex];
            leftIndex++;
        } else {
            arr[mainArrayIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mainArrayIndex++;
    }

    // Copy remaining elements of leftArr
    while (leftIndex < leftLength) {
        arr[mainArrayIndex] = leftArr[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }

    // Copy remaining elements of rightArr
    while (rightIndex < rightLength) {
        arr[mainArrayIndex] = rightArr[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int s, int e) {
    // Base case
    if (s >= e) return;
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e, mid);
}

int main() {
    int arr[] = {50, 20, 10, 40, 30};
    int sizeArr = 5;

    cout << "Original array: ";
    for (int i = 0; i < sizeArr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, sizeArr - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < sizeArr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}