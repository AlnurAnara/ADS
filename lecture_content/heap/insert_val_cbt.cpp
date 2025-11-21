#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Element {
    int value;
    int priority;
    Element (int v,int p ) : value(v), priority(p) {}
};

class MaxHeapPriorityQueue {
private:
    vector<Element> arr; // 底层数组存储堆元素

    void _heapify_down(int i) {
        int n = arr.size();
        int idxMax = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // 1. 检查左子节点：是否在界内 且 优先级是否大于当前最大值
        if (left < n && arr[left].priority > arr[idxMax].priority) {
            idxMax = left;
        }

        // 2. 检查右子节点：是否在界内 且 优先级是否大于当前最大值
        if (right < n && arr[right].priority > arr[idxMax].priority) {
            idxMax = right;
        }

        // 3. 如果最大元素不是当前节点，则交换并递归下沉
        if (idxMax != i) {
            std::swap(arr[i], arr[idxMax]);
            _heapify_down(idxMax); // 递归对被影响的子树进行下沉
        }
    }

public:
    // 检查堆是否为空
    bool isEmpty() const {
        return arr.empty();
    }

    void insert(int val, int p) { //o(log n )
        // 1. 将新元素添加到数组末尾 (保持完全二叉树结构)
        Element new_element(val, p);
        arr.push_back(new_element);
        int i = arr.size() - 1; // 新元素的索引
        
        // 2. 上浮操作：只要 i > 0 且当前优先级大于父节点优先级
        // 时间复杂度 O(log n)
        while (i > 0 && arr[i].priority > arr[(i-1) /2].priority) {
           
            // 交换当前节点和父节点
            swap(arr[i], arr[(i-1) /2]);
            i = (i-1) /2;
        }
    }


    int extractMax() { // O(log n)
        if(arr.size() == 0){
        return 0;
    }
        // 1. 保存根元素（最大值）的值
        int max_val = arr[0].value;
        
        // 2. 将最后一个元素移动到根部
        arr[0] = arr.back(); 
        
        // 3. 删除最后一个元素 (缩小堆的大小)
        arr.pop_back();

        // 4. 对新的根元素执行下沉操作，恢复最大堆属性
        // 时间复杂度 O(log n)
        if (!arr.empty()) {
            _heapify_down(0); 
        }

        return max_val;
    }

    // 辅助函数：打印堆的内容
    void printHeap() const {
        if (arr.empty()) {
            cout << "Heap: []" << endl;
            return;
        }
        cout << "Heap (Value, Priority): [";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << "(" << arr[i].value << ", " << arr[i].priority << ")" << (i < arr.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }
};

// --- 演示主程序 ---
int main() {
    MaxHeapPriorityQueue pq;
    
     cout << "--- Max Heap 优先队列演示 ---" << endl;
    
    // 插入操作：(值, 优先级)
    pq.insert(10, 5);
    pq.printHeap();
    
    pq.insert(50, 15); // 优先级 15 最高，将浮到根部
    pq.printHeap();
    
    pq.insert(20, 10); // 优先级 10 位于 15 和 5 之间
    pq.printHeap(); // Expected: (50, 15), (10, 5), (20, 10)
    
    pq.insert(30, 25); // 优先级 25 再次成为最大，浮到根部
    cout << "--- 插入 (30, 25) ---" << endl;
    pq.printHeap(); // Expected: (30, 25), (50, 15), (20, 10), (10, 5)

    cout << "\n--- 提取最大值 (Extract Max) ---" << endl;
    
    // 第一次提取：25
    cout << "提取最大值 (Priority 25): " << pq.extractMax() << endl;
    cout << "堆状态：";
    pq.printHeap(); 
    
    // 第二次提取：15
    cout << "提取最大值 (Priority 15): " << pq.extractMax() << endl;
    cout << "堆状态：";
    pq.printHeap();

    // 第三次提取：10
    cout << "提取最大值 (Priority 10): " << pq.extractMax() << endl;
    cout << "堆状态：";
    pq.printHeap();
    
    return 0;
}