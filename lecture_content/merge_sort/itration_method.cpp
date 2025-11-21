// iterative in-place merge sort : find the time complexity

#include <iostream>
#include <vector>
using namespace std;

// --- 辅助函数 1: 标准合并操作 (Merge) ---
// 时间复杂度 O(n), 空间复杂度 O(n)
void merge(vector<int>& arr, int l, int m, int r) {   //time complexuty :O(n)
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
//l is the 1st elem of the first array,and m the 2nd elem of the 1st array,r is the 2nd elem of the 2nd array

// --- 归并排序主函数：迭代实现 (Iterative Merge Sort) ---
// 整体时间复杂度 O(n log n), 空间复杂度 O(n)
void mergeSortIterative(vector<int>& arr) {
    int n = arr.size();
    
    // 外层循环：ws (window size) 控制子数组的长度，从 1, 2, 4, 8... 递增!!!!!!!
    for (int ws = 1; ws < n; ws = ws * 2) {
        
        // 内层循环：i 控制当前合并的子数组对的起始位置
        // 每次步进 2 * ws，跳过已经合并的区间
        for (int l = 0; l < n; l = l + 2 * ws) { // 边界条件 i < n - ws 确保至少有一个完整的子数组
             
            int m = l + ws - 1;     // 中点：第一个子数组的终点

            // 右边界 r：第二个子数组的终点
            // 我们必须使用 min(计算值, n - 1) 来防止 r 越界
            int r = min(l + 2 * ws - 1, n - 1); 
            
            // 确保 m < r，只有当第二个子数组存在时才进行合并
            // 由于 i < n - ws 已经保证了第一个子数组存在，我们只需要检查 m+1 <= r
            if (m < r) {
                merge(arr, l, m, r);
            }
        }
    }
}


int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7, 1, 9, 20, 15};
    int arr_size = arr.size();
    cout << "Given array is  \n";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 调用 O(1) 空间复杂度的 Merge Sort
    mergeSortIterative(arr);

    cout << "sorted array is\n";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}