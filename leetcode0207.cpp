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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size_A=0;
        int size_B=0;
        ListNode *p=headA;
        ListNode *q=headB;
        while (p!=NULL)
        {
            size_A++;
            p=p->next;  
        }
        while (q!=NULL)
        {
            size_B++;
            q=q->next;
        }
        if(size_A>=size_B)
        {
            int temp=size_A-size_B;
            p=headA;
            q=headB;
            while (temp--)
            {
                p=p->next;
            }
            while(p!=q)
            {
                p=p->next;
                q=q->next;
            }
            return p;
        }
        else 
        {
            int temp=size_B-size_A;
            p=headA;
            q=headB;
            while (temp--)
            {
                p=p->next;
            }
            while(p!=q)
            {
                p=p->next;
                q=q->next;
            }
            return p;
        }
          
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
    vector<int> nums={1,2,3,4,5,9,8};
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
    Head=s1.removeNthFromEnd(Head,2);
    s1.printlist(Head);
    /*Solution s1;
    s1.printlist(head);
    s1.reverseList(head);
    s1.printlist(head);*/

     
    


    system("pause");
    return 0; 
}   