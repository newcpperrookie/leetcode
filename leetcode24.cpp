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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode *lastnode,*next_lastnode,*lnode, *rnode,*nextlnode,*nextrnode;
        ListNode *virtual_header= new ListNode;
        virtual_header->next=head;
        lastnode=virtual_header;
        lnode=head;
        rnode=head->next;
        while (lnode!=NULL&&rnode!=NULL)
        {
            nextlnode=lnode->next->next;
            nextrnode=rnode->next->next;
            lnode->next=rnode->next;
            rnode->next=lnode;
            lastnode->next=rnode;
            next_lastnode=lnode;
            lnode=nextlnode;
            rnode=nextrnode;
            lastnode=next_lastnode;
        }
        return virtual_header->next;
    }


    void printlist(ListNode * head)
    {
        ListNode *p=head;
        while (p!=NULL)
        {
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
        
    }
};


int main()
{
    vector<int> nums={1,2,3,4,5};
    Solution s1;
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
    s1.printlist(Head);
    Head=s1.swapPairs(Head);
    s1.printlist(Head);
    /*Solution s1;
    s1.printlist(head);
    s1.reverseList(head);
    s1.printlist(head);*/

     
    


    system("pause");
    return 0;
}