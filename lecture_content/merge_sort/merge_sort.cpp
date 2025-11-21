#include <iostream>
#include <vector>
using namespace std;

// so for merge-sort : TC:O(n long n), SP:O(n)
// Function 1: Merges two sorted subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]                     // space complexity : O(n)
void merge(vector<int>& arr, int l, int m, int r) {   // time complexuty :O(n)
    // two temporary subarrays
    vector<int> a1(m - l + 1);
    vector<int> a2(r - m);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < a1.size(); i++)
        a1[i] = arr[l + i];
    for (int j = 0; j < a2.size(); j++)
        a2[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray a1
    int j = 0; // Initial index of second subarray a2
    int k = l; // Initial index of merged subarray

    while (i < a1.size() && j < a2.size()) {
        if (a1[i] > a2[j]) { // 比较两个数组当前元素
            arr[k] = a2[j]; //swap them
            j++;
        } else {        
            arr[k] = a1[i];//将较小的元素写入到 arr[k] 中
            i++;
        }
        k++;
    }

    /* Copy the remaining elements of a1[], if any 
    如果 a1 中有剩余元素（说明 a2 已用尽），
    将其全部复制到 arr 的末尾
    */
    while (i < a1.size()) {
        arr[k] = a1[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of a2[], if any
    如果 a2 中有剩余元素（说明 a1 已用尽），
    将其全部复制到 arr 的末尾
    */
    while (j < a2.size()) {
        arr[k] = a2[j];
        j++;
        k++;
    }
}

// Function 2: split the oridinary array
void mergeSort(vector<int>& arr, int l, int r) { // time complexity : O(log n)
    // Base case: only proceed if the low index (l) is less than the high index (r)
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m);        // Sort left half : arr[l..m]
        mergeSort(arr, m + 1, r);    // Sort right half: arr[m+1..r]

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}


int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }    
    cout << endl;
    
    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
   

    return 0;
}