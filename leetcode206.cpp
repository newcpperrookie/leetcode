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
    ListNode* reverseList(ListNode* head) {
        ListNode *Virtual_header= new ListNode;
        ListNode *p= head;
        ListNode *temp;
        while (p !=NULL)
        {
            temp=p;
            p=p->next;
            Virtual_header=Addathead(Virtual_header,temp);
            
        }
        head=Virtual_header->next;
        Virtual_header->next=NULL;
        delete Virtual_header;
        Virtual_header=NULL;
        return head;
        
    }
    ListNode * Addathead(ListNode* head, ListNode * node)
    {
        node->next=head->next;
        head->next=node;
        return head;
    }
    void printlist(ListNode * head)
    {
        ListNode *p=head;
        while (p!=NULL)
        {
            cout<<p->val<<endl;
            p=p->next;
        }
        
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
    Head=s1.reverseList(Head);
    s1.printlist(Head);
    /*Solution s1;
    s1.printlist(head);
    s1.reverseList(head);
    s1.printlist(head);*/

     
    


    system("pause");
    return 0;
}