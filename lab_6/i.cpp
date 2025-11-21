#include <iostream>
#include <algorithm>
using namespace std;

/* sort letters alphabetically. 
Input
asdzxchfg
Output
acdfghsxz
*/
int main() {
    string arr;
    cin >> arr;
    
    int n = arr.length();  //这三行是针对输入是没有空格的字符串
    
    // 冒泡排序
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        /*for J from 0 to n-i-1, 每完成一轮外层循环（i 增加 1），
        就有一个最大的元素被“冒泡”到了数组的末尾正确的位置上，
        所以内层循环的比较范围可以缩小，无需再比较已经排好序的部分。*/
        if (arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);

    for (int i = 0; i < n; i++) cout << arr[i];
    return 0;
}


/*如果输入是有空格的字符串，
    int n;
    cin >> n;
    
    char arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // 读取每个字符
    }

*/