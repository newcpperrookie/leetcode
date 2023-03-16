#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include<algorithm>
#include <cmath>
#include<utility>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
            return mid;
            else
            {
                if(nums[i]>target)
                i=mid+1;
                else if(nums[i<target])
                j=mid-1;
                else
                return i;
            }
        }
        return -1;
    }
};
class object
{
    public:
        object(int _nums,int val)
        {
            p=new int(val);
            num=_nums;
            cout<<"vaule constructer"<<endl;
        }
        object(const object& ob)
        {
            this->p=new int(*(ob.p));
            this->num=ob.num;
            cout<<"copy constructer"<<endl;
        }
        object(object&& oj)
        {
            this->p=oj.p;
            oj.p=nullptr;
            this->num=oj.num;
            cout<<"move constructer"<<endl;
        }
        object  operator+(const object &o1)
        {
            object temp(o1.num+this->num,*(o1.p)+*(this->p));
            return temp;
        }
        void show()
        {
            if(p!=NULL)
            cout<<*p<<ends<<num<<endl;
            else 
            cout<<"p is NULL"<<ends<<num<<endl;;
        }
        ~object()
        {
            cout<<"destory function"<<endl;
            if(p!=nullptr)
            {
                delete p;
                p=NULL;
            }

        }

    private:
        int *p;
        int num;
};
object  test(const object& ot)
{
    object temp=ot;
    return temp;
}
void test01()
{
    object o_1(6,5);
    object o_2(o_1);
    object o_3(test(o_1));
    cout<<"o_1:"<<endl;
    o_1.show();
    cout<<"o_2:"<<endl;
    o_2.show();
    cout<<"o_3:"<<endl;
    o_3.show();
}
int main()
{

    test01();
    system("pause");
    return 0;
}