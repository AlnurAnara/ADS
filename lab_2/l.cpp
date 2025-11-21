# include <iostream>
# include <algorithm>
# include <cassert>
using namespace std;

/*找到最大子数组和：问题要求从一个给定的整数序列（或数组/列表）中，
找到一个连续的子序列（子数组），使得这个子序列中所有元素的和是最大的。
i.e. 5
     1 2 -1 4 5
子数组：（1，2）；（-1，4，5）。。。。
     output：11

*/
struct Node {
  int val;
  Node *next;
  Node(): val(0),next(NULL){}

};


int findMaxSum(int n, Node *head) {
    int max_sum = head->val;
    int cur_sum = head->val;
    Node* cur = head->next;
    while(cur != NULL){
        cur_sum = max(cur->val, cur_sum + cur->val);
        max_sum = max(max_sum, cur_sum);
        cur = cur->next;
    }
    return max_sum;
	
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
