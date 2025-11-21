#include <iostream>
#include <deque>
using namespace std;

/*If she tired she shows the character ’!’ ,
Zhansaya wants to find the sum of first and the last number of her deque.  
if she wants to add a number to the begin she shows ’+’, 
and if she wants to add to the back , shows character ’-’ 
and if she shows ’*’, you have to find the sum of first and last elements and delete elements. 
Note that if deque is empty print "error".
*/
int main() {
    char c;  // c is the character : + - * ! 
    int a;
    deque<int> dq;
    
    while(true){
        cin >> c;
        if(c == '+') {
            cin >> a;
            dq.push_front(a);
        }
        else if(c == '-'){
            cin >> a;
            dq.push_back(a);
        }
        else if(c == '*'){
            if(dq.size() == 0) cout << "error\n"; // if the deque is empty ,print error
            else {
                cout << dq.front() + dq.back() << endl;
                if(dq.size() >= 2){
                    dq.pop_front(); dq.pop_back(); // is there are at least 2 elems on deque,delete the first and last elems 
                } else dq.pop_front(); // if there is only one elem on deque ,just remove it
            }
        }
        else break;
        
    }
    
    return 0;
}


    /*
    + 1 the first element
    - 9 the last element
    + 2 the new first element  （2 1 9）
    *  2+9 and delete 2 and 9，left 1

    + 2 the first elem   2 1
    - 6 the last         2 1 6
    + 3 the new first    3 2 1 6
    - 9 the new last     3 2 1 6 9 
    * 3+9 and delete 3 and 9  2 1 6
    * 2+6 and delete 2 and 6   1
    * 1
    * empty
    ! error
    2 1 9 -> 11
    3 2 1 6 9
    12
    8
    */

/*
+ 1  1
+ 2  2 1
- 9  2 1 9
- 2  2 1 9 2
*    2+2=4
!    4
*/