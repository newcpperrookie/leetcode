#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include<map>
#include <cmath>
using namespace std;
struct node
{
   char c;
   int fre;
   node(char c1)
   {
        c=c1;
        fre=1;
   }
};


class Solution {
public:
    string frequencySort(string s) {
        vector<node> num1;
        int flag=1;
        for (int i = 0; i < s.length(); i++)
        {
            flag=1;
            for (auto iter =num1.begin(); iter != num1.end(); iter++)
            {
                if(iter->c==s[i])
                {
                    flag=0;
                    iter->fre++;
                }
            }
            if(flag==1)
            {
                num1.push_back(node(s[i]));
            }
            
        }
        quicksort(num1,0,num1.size()-1);
        int temp=0;
        for (int i = num1.size()-1; i > -1; i--)
        {
            for(int j=0; j<num1[i].fre;j++)
            {
                s[temp+j]=num1[i].c;
            }
            temp=temp+num1[i].fre;
        }
        return s;
        
        

    }
        int partition(vector<node> &nums1, int low, int high)
    {
        int i=low;
        int j=high+1;
        while (i<j)
        {
           while(nums1[++i].fre<=nums1[low].fre&&i<high);
            while (nums1[--j].fre>nums1[low].fre&&j>low);
            if(i<j)
            swap(nums1[i],nums1[j]);
        }
        swap(nums1[low],nums1[j]);
        return j;
    }

    void quicksort(vector<node> &nums1, int low, int high)
    {
        if (low>=high)
        {
            return;
        }
        int mid=partition(nums1,low,high);
        quicksort(nums1,low,mid-1);
        quicksort(nums1,mid+1,high);

    }
};

int main()
{   
    Solution s;
    string nums1="aaabbbbe";
    nums1=s.frequencySort(nums1);
    cout<<nums1<<endl;
    
    system("pause");
    return 0;
}