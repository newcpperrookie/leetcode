#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
#include<unordered_map>
using namespace std;
struct DLinkNode
{
    int key;
    int val;
    DLinkNode* prev;
    DLinkNode* next;
    DLinkNode():key(0),val(0),prev(NULL),next(NULL){};
};
class LRUCache {
private:
int size; //键值对数目
int _capacity;//最大容量
DLinkNode* vir_head;
DLinkNode* vir_tail;
unordered_map<int, DLinkNode*> cache;
public:
    LRUCache(int capacity) {
        size=0;
        vir_head=new DLinkNode;
        vir_tail=new DLinkNode;
        vir_head->next=vir_tail;
        vir_tail->prev=vir_head;
        _capacity=capacity;
    }
    
    int get(int key) {
        if(!cache.count(key))
        {
            cout<<8888<<endl;
            return -1;
        }
        else
        {
            MoveToHead(key);
            return cache[key]->val;
        }

    }
    
    void put(int key, int value) {
        if(!cache.count(key))
        {
            
            AddAtHead(key,value);
            size++;
            if(size>_capacity)
            {
                int res_key=DeleteAtTail();
                cache.erase(res_key);
            }
        }
        else
        {
            DLinkNode* p=cache[key];
            p->val=value;
            MoveToHead(p->key);
        }


    }
    void AddAtHead(int key,int val)
    {
        DLinkNode *p=new DLinkNode;
        p->key=key;
        p->val=val;
        vir_head->next->prev=p;
        p->next=vir_head->next;
        vir_head->next=p;
        p->prev=vir_head;
        cache.emplace(p->key,p);
        
    }
    void MoveToHead(int key)
    {
        DLinkNode* p=cache[key];
        p->prev->next=p->next;
        p->next->prev=p->prev;
        p->next=vir_head->next;
        vir_head->next->prev=p;
        p->prev=vir_head;
        vir_head->next=p;
    }

    int DeleteAtTail()
    {
        if(vir_tail->prev==vir_head)
        return -1;
        int res_key;
        DLinkNode* p=vir_tail->prev;
        res_key=p->key;
        p->prev->next=vir_tail;
        vir_tail->prev=p->prev;
        delete p;
        p=NULL;
        return res_key;
    }
};
int main()
{

    LRUCache* obj = new LRUCache(2);
    int res=obj->get(1);
    obj->put(2,1);
    obj->put(1,1);
    res=obj->get(2);
    cout<<res<<endl;
    obj->put(4,1);
    res=obj->get(2);
    cout<<res<<endl;


    system("pause");
    return 0;
}