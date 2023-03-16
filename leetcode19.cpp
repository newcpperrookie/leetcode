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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * virtual_head= new ListNode;
        virtual_head->next=head;
        ListNode *fast, *slow;
        n=n+1;
        fast=virtual_head;
        slow=virtual_head;
        while (n--&&fast!=NULL)
        {
           fast=fast->next;
        }
        if(n==-1)
        {
            if(fast==NULL)
            {
                head=head->next;
                delete virtual_head->next;
                delete virtual_head;
                return head;
            }
            else
            {
                while (fast!=NULL)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                ListNode *temp=slow->next;
                slow->next=temp->next;
                delete temp;
                return head;
                
            }
        }
        else
        return NULL;
        

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