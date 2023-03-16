#include <iostream>
#include<stdlib.h>
#include<vector>
#include <string>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head!=NULL && head->val == val)
        {
            ListNode * temp= head;
            head = head->next;
            delete temp;
            temp=NULL;
        }
        ListNode *cur=head;

        while(cur!=NULL && cur->next!=NULL)
        {
            if (cur->next->val==val)
            {
                ListNode * temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else
            cur=cur->next;

        }
        return head;
    }
};

int main()
{
    vector<int> nums = {1,2,6,3,4,5,6};
    int target=6;
    ListNode * Head = new ListNode();
    ListNode * p;
    p=Head;
    if (nums.size()!=0)
    {
        Head->val = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
        
            ListNode * node = new ListNode(nums[i]);
            p->next=node;
            p=node;
        
        }
    }
    
    
    Solution s1;
    Head=s1.removeElements(Head, target);
    p=Head;
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    

    system("pause");
    return 0;
}