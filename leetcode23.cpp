#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include<algorithm>
#include <cmath>
using namespace std;
  struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
void Addattail(ListNode* head, ListNode *element)
{   
        ListNode* p=head;
        while(p->next!=nullptr)
        {
            p=p->next;
        }
        p->next=element;
        element->next=NULL;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<2)
            return lists[0];
        ListNode* reshead=new ListNode;
        ListNode* tail;
        ListNode* node;
        tail=reshead;
        int min_i=-1;
        while(1)
        {
            ListNode *p =nullptr;
            for(int i=0;i<lists.size();i++)
            {
                if(lists[i]!=nullptr)
                {
                    p=lists[i];
                    min_i=i;
                    break;
                }
            }
            if(p==nullptr)
                break;
            for(int i=0;i<lists.size();i++)
            {
                 
                if(lists[i]!=nullptr&&lists[i]->val<p->val)
                {
                   
                    p=lists[i];
                    min_i=i;
                }
            }
            //cout<<min_i<<" "<<endl;
            lists[min_i]=lists[min_i]->next;
            cout<<p->val<<ends<<min_i<<endl;
            Addattail(reshead,p);
        }
        ListNode* head=reshead->next;
        delete reshead;
        reshead=nullptr;
        return head;
}

};
void listprint(ListNode* head)
{
    ListNode* p=head;
    while (p!=nullptr)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
     
}
int main()
{
    Solution s;
    vector<vector<int>> nums={{1,4,5},{1,3,4},{2,6}};
   vector<ListNode*> list;
   for (size_t i = 0; i < nums.size(); i++)
   {
        ListNode *p=new ListNode(nums[i][0]);
        list.push_back(p);
   }
   
   for (size_t i = 0; i < nums.size(); i++)
   {
    for (size_t j = 1; j < nums[i].size(); j++)
    {
       ListNode *p=new ListNode(nums[i][j]);
       Addattail(list[i],p);
    }
   }
   ListNode* head= s.mergeKLists(list);
   listprint(head);
   
    system("pause");
    return 0;
}