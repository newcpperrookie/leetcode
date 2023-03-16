#include <iostream>
#include<stdlib.h>
#include<vector>
#include <string>
using namespace std;


class MyLinkedList {
public:
    
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr){}
    };
    ListNode *virtual_header;
    int List_Size;
    
    MyLinkedList() {
       virtual_header =new ListNode(0);
       List_Size=0;
    }
    
    int get(int index) {
        if(index<0|| index>List_Size-1)
        {
            return -1;
        }
        ListNode *p=virtual_header;
        while (index--)
        {
            p=p->next;
        }
        return p->next->val;

    }
    
    void addAtHead(int val) {
        ListNode *temp= new ListNode(val);
        temp->next=virtual_header->next;  
        virtual_header->next=temp;
        
        List_Size++;
    }
    
    void addAtTail(int val) {
        ListNode *p=virtual_header;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        ListNode *temp= new ListNode(val);
        temp->next=p->next;
        p->next=temp;
        List_Size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<=0)
        {
            addAtHead(val);
            return;
        }
        if(index>List_Size)
        {
            return;
        }
        if(index==List_Size)
        {
            addAtTail(val);
            return;
        }
        ListNode *p=virtual_header;
        while(index--)
        {
            p=p->next;
        }   
    
        ListNode *temp= new ListNode(val);
        temp->next=p->next;
        p->next=temp;
        List_Size++;
        return;
    }
    
    void deleteAtIndex(int index) {
         if(index<0|| index> List_Size-1)
        {
            return ;
        }
        ListNode *p=virtual_header;
        while(index--)
        {
            p=p->next;
        }
        ListNode *temp=p->next;
        p->next=temp->next;
        delete temp;
        temp=NULL;
        List_Size--;
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

    
    
    MyLinkedList ml1;
    ml1.ListPrint();
    ml1.addAtIndex(1,0);
    ml1.ListPrint();
    cout<<ml1.get(0);




    system("pause");
    return 0;
}