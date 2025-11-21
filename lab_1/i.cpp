#include <iostream>
#include <queue>
using namespace std;

/*
In class A, students want to establish a class leader. The class splitted into two fractions: Sakayanagi and Katsuragi. They decided to decide the leader by the following procedure:

1. Each of  students makes a statement. They make statements one by one starting from student 1 and finishing with student n  
If student were kicked from the procedure, he/she is skipped.

2. When student makes a statement, he/she can kick any other student from procedure. If someone is kicked from procedure he no longer participates in the procedure till the very end.

3. When the round is finished, i.e. all students are done with their statements, the procedure repeats from step 1.

4. The process repeats until there is only one student eligible to participate and this student becomes the group leader.

Determine the fraction of the group leader, if both fractions play optimally (i.e. both fractions act best they can to make the group leader from their fraction).
学生按顺序发言，每轮可以踢掉一人。

游戏进行多轮，直到只剩一人。

两派都采取最优策略（即每次踢人时，都会选择踢掉对方派系的人，以最大化己方获胜概率）*/
int main() {
    int n;
    string s;
    cin >> n >> s;

    queue<int> S, K;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') S.push(i); // according to the S or K, add it to the correspoding fraction
        else K.push(i);
    }

    while (!S.empty() && !K.empty()) {
        int idS = S.front(); S.pop(); // the first mumber of this fraction will make statement
        int idK = K.front(); K.pop();

        if (idS < idK) S.push(idS + n);
         /*if the index of the first member of S fraction is less then the counterpart in K fraction
         This means that in the initial arrangement, the 'S' player has an earlier position. According to the rule, this 'S' player wins."
         
         for idS+n : means this player is allowd to join the next round, and is placed at the end of the queue
         */ 
        else K.push(idK + n);
    }

    if (S.empty()) cout << "KATSURAGI";
    else cout << "SAKAYANAGI";
    return 0;
}