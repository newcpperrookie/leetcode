#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
struct fNode
{
    int value;
    int frequency;
    fNode(int a)
    {
        value=a;
        frequency=1;
    }
};

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int flag=0;
        vector<fNode> res={};
        vector<int> up={};
        for (int i = 0; i < nums.size(); i++)
        {
            flag=0;
           for (int j = 0; j < res.size(); j++)
           {
                if(res[j].value==nums[i])
                {
                    flag=1;
                    res[j].frequency++;
                }
           }
           if(flag==0)
           res.push_back(fNode(nums[i]));
        }
        quicksort(res,0,res.size()-1);
        int n=res.size()-k;
        for (int i = 0; i < k; i++)
        {
            up.push_back(res[n].value);
            n++;
        }
        return up;
    }
    int partition(vector<fNode> &nums1, int low, int high)
    {
        int i=low;
        int j=high+1;
        while (i<j)
        {
           while(nums1[++i].frequency<=nums1[low].frequency&&i<high);
            while (nums1[--j].frequency>nums1[low].frequency&&j>low);
            if(i<j)
            swap(nums1[i],nums1[j]);
        }
        swap(nums1[low],nums1[j]);
        return j;
    }

    void quicksort(vector<fNode> &nums1, int low, int high)
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
    vector<int> nums1={1,1,1,2,2,3};
    vector<int> res={};
    res=s.topKFrequent(nums1,2);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<endl;
    }
    
    system("pause");
    return 0;
}