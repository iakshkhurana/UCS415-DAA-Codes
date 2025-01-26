#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(int arr[], int sizeArr, int brr[], int sizeBrr, vector<int> &ans) { // Pass ans by reference
    int i = 0;
    int j = 0;

    while (i < sizeArr && j < sizeBrr) {
        if (arr[i] < brr[j]) {
            ans.push_back(arr[i]); // Insert the smaller value
            i++;
        } else {
            ans.push_back(brr[j]); // Insert the smaller value
            j++;
        }
    }

    // Add remaining elements from arr
    while (i < sizeArr) {
        ans.push_back(arr[i]);
        i++;
    }

    // Add remaining elements from brr
    while (j < sizeBrr) {
        ans.push_back(brr[j]);
        j++;
    }
}

int main() {
    int arr[] = {10, 30, 50, 70};
    int sizeArr = 4;
    int brr[] = {20, 40, 60, 80, 90, 100};
    int sizeBrr = 6;

    vector<int> ans;
    mergeSortedArrays(arr, sizeArr, brr, sizeBrr, ans);

    for (int num : ans) {
        cout << num << " ";
    }
    return 0;
}
