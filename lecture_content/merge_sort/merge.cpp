/*make the sapce compelxity as const , O(1)
which means that we do not need extra space to copy the less elem
so the time complexity will be O(n^2)
// 核心思想：使用插入排序的逻辑进行原地合并。!!!!!
2 5 8   3 4 5  i = 5, j = 3; tmp = 3
2 3 5 8  4 6   i = 5, j = 4; 
2 3 4 5  8 6   i = 5, j = 6
2 3 4 5 6 8    i = 6, j = 8 

*/


#include <iostream>
#include <vector>
using namespace std ;

// 函数 1: 原地合并两个子数组 arr[l..m] 和 arr[m+1..r]

// 空间复杂度 O(1)，但时间复杂度恶化为 O(n^2)。
void mergeInPlace(std::vector<int>& arr, int l, int m, int r) {
    // i 是第一个子数组的当前元素索引 (arr[l...m])
    int i = l; 
    
    // j 是第二个子数组的当前元素索引 (arr[m+1...r])
    int j = m + 1; 

    // 迭代遍历整个要合并的区间
    while (i < j && j <= r) {
        // 1. 如果第一个子数组的元素已经小于等于第二个子数组的元素，
        //    说明 arr[i] 已经就位，我们向前移动 i。
        if (arr[i] <= arr[j]) {
            i++;        /*或者可以是if（a[i] > a[j]{}
                                    else 
                                        i++
                                                    */
        } else {
            // 2. 如果 arr[i] > arr[j]，说明 arr[j] 应该被插入到 arr[i] 之前。
            
            // 存储要移动的元素 arr[j] (第二个子数组的当前元素)
            int tmp = arr[j];
            // 存储 arr[j] 元素的位置，因为后续会被覆盖 到 arr[i] 之前
            int k = j;

            // 将 arr[i] 到 arr[j-1] 的所有元素都向后移动一个位置
            // 这一步就是插入排序的核心移动操作
            while (k > i) {
                arr[k] = arr[k - 1];
                k--;
            }

            // 将 arr[j] 插入到腾出的位置 i 处
            arr[ j] = tmp;

            // 维护指针：
            // 因为 arr[i] 被插入到了第一个子数组，i 应该向前移动。
            i++;
            // 此时 m 也需要增加，因为第一个子数组的范围扩大了。
            m++;
            // j 保持不变，因为 arr[j] 的原始位置上的元素已经被移动到前面，
            // 下一次循环应该继续检查新的 arr[j] (原 arr[j+1])
            j++; 
        }
    }
}


void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        // 找到中点
        int m = l + (r - l) / 2;

        // 递归排序左右两部分
        mergeSort(arr, l, m);        
        mergeSort(arr, m + 1, r);    

        // 调用 O(1) 空间的原地合并函数
        mergeInPlace(arr, l, m, r); 
    }
}


// 示例用法
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7, 1, 9};
    int arr_size = arr.size();
    cout << "Given array is  \n";
    // *** 替换 for (int x : arr) 为标准 for 循环 (使用索引 i) ***
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 调用 O(1) 空间复杂度的 Merge Sort
    mergeSort(arr, 0, arr_size - 1);

    cout << "sorted array is\n";
    // *** 再次使用标准 for 循环打印排序后的数组 ***
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}