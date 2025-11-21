#include <iostream>
#include <vector>
using namespace std;

// remember the heapify and heapsort functions

// heapify 堆化函数
void heapify(vector<int>& arr, int n, int i) { //O(log n)
    int largest = i;        // 初始化最大值为根节点
    int left = 2 * i + 1;   // 左子节点
    int right = 2 * i + 2;  // 右子节点
    
    // 如果左子节点大于根节点,更新最大值的索引为左子节点
    if (left < n && arr[left] > arr[largest]) {  //left < n 检查左子节点索引是否在有效范围内
        largest = left;
    }
    
    // 如果右子节点大于当前最大值的索引,更新最大值的索引为右子节点
    if (right < n && arr[right] > arr[largest]) { //right < n 检查右子节点索引是否在有效范围内
        largest = right;
    }
    
    // 如果最大值不是根节点,需要交换根节点与最大值的索引
    if (largest != i) {
        swap(arr[i], arr[largest]);
        //如果 largest 仍然是 i，说明当前节点已经大于等于它的子节点，不需要调整
        //如果 largest 不是 i，说明需要交换
        heapify(arr, n, largest);
    }
}

// 堆排序主函数
void heapSort(vector<int>& arr) { // O(n log n)
    int n = arr.size();
    
    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {//这是数组中最后一个非叶子节点的索引
        heapify(arr, n, i);
    }
    
    // 逐个提取元素
    for (int i = n - 1; i > 0; i--) {
        // 将当前最大值移动到末尾
        swap(arr[0], arr[i]);
        // 对剩余堆进行堆化
        heapify(arr, i, 0); // 这里的i表示每进行一次heapify cut the biggest value and consider it as a separable value in a new array
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    
    cout << "排序前: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    heapSort(arr);
    
    cout << "排序后: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}