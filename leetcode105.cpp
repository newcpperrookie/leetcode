#include <iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> myqueue;
        vector<vector<int>> res;
        myqueue.push(root);
        int flag=1;
        while (!myqueue.empty())
        {
            int size=myqueue.size();
            vector<int> temp;
            while (size>0)
            {
                TreeNode* p=myqueue.front();
                temp.push_back(p->val);
                myqueue.pop();
                size--;
            }
            if(!flag)
            {
                reverse(temp.begin(),temp.end());
            }
            flag=-flag;
            res.push_back(temp);
        }
        return res;

    }
};
int main()
{

   const int i=10;
   int *p=(int* )&i;
   *p=9;
   cout<<*p<<endl;
   cout<<i<<endl;
    system("pause");
    return 0;
}