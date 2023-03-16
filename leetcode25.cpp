#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
void    AddatListTail(ListNode* head,int val)
{
    ListNode* p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    ListNode *node=new ListNode(val);
    p->next=node;
}
class Solution {
public:
    int flag=1;
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
        return head;
        vector<ListNode*> catchk=catchknodes(head,k);
        if(catchk[1]==nullptr&&flag)
        return head;
        
        ListNode* temphead=catchk[0];
        ListNode* nexthead=catchk[1];
        vector<ListNode*> reverse_k=reverseK(temphead);
        ListNode* temptail=reverse_k[1];
        head=reverse_k[0];
        while(1)
        {
            if(nexthead==nullptr)
            {
                break;
            }
            catchk=catchknodes(nexthead,k);
            if(catchk[1]==nullptr&&flag)
            {
                temptail->next=catchk[0];
                break;
            }
            temphead=catchk[0];
            nexthead=catchk[1];
            reverse_k=reverseK(temphead);
            temptail->next=reverse_k[0];
            temptail=reverse_k[1];
        }
        return head;

    }
    vector<ListNode*> catchknodes(ListNode* head, int k)
    {
        vector<ListNode*> res(2,nullptr);
        res[0]=head;
        ListNode *p=head;
        int count=0;
        while(p!=nullptr)
        {
            
            ++count;
            if(count==k)
            break;
            p=p->next;
        }
        if(count==k)
        {
            ListNode *temp=p->next;
            if(temp==NULL) flag=0;
            else p->next=nullptr;
            res[1]=temp;
            

        }
        /*for (size_t i = 0; i < res.size(); i++)
        {
            cout<<res[i]->val<<endl;
        }*/
        
        return res;
    }

    vector<ListNode*> reverseK(ListNode* head)
    {
        vector<ListNode*> res(2,nullptr);
        ListNode * dummy_head=new ListNode;
        ListNode* left=dummy_head;
        ListNode* mid=head;
        ListNode* right=head->next;

        dummy_head->next=NULL;
        while(right!=nullptr)
        {
            mid->next=left;
            left=mid;
            mid=right;
            right=right->next;
        }
        mid->next=left;
        res[0]=mid;
        res[1]=head;
        head->next=NULL;
        delete dummy_head;
        dummy_head=nullptr;
        return res;
    }
};
void showlist(ListNode* head)
{
    ListNode *p=head;
    while (p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    
}
int main()
{

   Solution s;
   vector<int> nums={1,2};
    ListNode *head=new ListNode(nums[0]);
   for (size_t i = 1; i < nums.size(); i++)
    {
        AddatListTail(head,nums[i]);
    }
    head=s.reverseKGroup(head,2);
    /*vector<ListNode*> res=s.catchknodes(head,2);
    cout<<res[0]->val<<endl;*/
   showlist(head);
    
    system("pause");
    return 0;
}