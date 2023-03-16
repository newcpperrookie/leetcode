#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        int mid;
        int low=0;
        int high=nums.size()-1;
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(nums[mid-1]==nums[mid])
            {
                if((mid-low)%2==0)
                {
                    high=mid;
                }
                else
                {
                    if((high-mid)==1)
                    {
                        mid=high;
                        break;
                    }
                    else
                    low=mid+1;
                }
            }
            else if(nums[mid+1]==nums[mid])
            {
                if((mid-low)%2==0)
                {
                    low=mid;
                }
                else 
                {
                    if((mid-low)==1)
                    {
                        mid=low;
                        break;
                    }
                    else
                    high=mid-1;
                }
            }
            else
            break;
        }
        return nums[mid];


    }
};
int main()
{

   Solution s;
    vector<int> nums={3,3,7,7,10,11,11};
    cout<<s.singleNonDuplicate(nums);
    system("pause");
    return 0;
}