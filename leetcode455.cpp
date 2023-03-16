#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include<map>
#include <cmath>
using namespace std;



class Solution {
public:
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        quicksort(g,0,g.size()-1);
        quicksort(s,0,s.size()-1);
        int i=0;
        int j=0;
        while (i<g.size()&&j<s.size())
        {
            while (s[j]<g[i]&&j<s.size())
            {
                j++;
            }
            if(j<s.size())
            {
                i++;
                j++;
            }
        }
        return i;
        

    }

        int partition(vector<int> &nums1, int low, int high)
    {
        int i=low;
        int j=high+1;
        while (i<j)
        {
           while(nums1[++i]<=nums1[low]&&i<high);
            while (nums1[--j]>nums1[low]&&j>low);
            if(i<j)
            swap(nums1[i],nums1[j]);
        }
        swap(nums1[low],nums1[j]);
        return j;
    }

    void quicksort(vector<int> &nums1, int low, int high)
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
    vector<int> nums1={1,2,3};
    vector<int> nums2={1,1};
    int res=s.findContentChildren(nums1,nums2);
    cout<<res<<endl;
    
    system("pause");
    return 0;
}