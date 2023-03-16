#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        int flag=0;
        if (nums.size()==0)
        {
            return res;
        }
        if(nums.size()==1&&target==nums[0])
        {
            res[0]=0;
            res[1]=0;
            return res;
        }
    
        int low=0;
        int high=nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            cout<<mid<<endl;
            if(nums[mid]>target)
            high=mid-1;
            else if(nums[mid]<target)
            low=mid+1;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<555<<endl;
        return res;
        }

        int i=mid;
        int j=mid;
        while(nums[i]==nums[mid]&&i>=0)
        {
            i--;
        }
        while(nums[j]==nums[mid]&&j<nums.size())
        {
            j++;
        }
        res[0]=i+1;
        res[1]=j-1;
        return res;

    }
};
int main()
{

   Solution s;
    vector<int> nums={1,4};
    
    vector<int> res=s.searchRange(nums,4);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
   system("pause");
    return 0;
}