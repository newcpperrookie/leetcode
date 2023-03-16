#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res = nums[n - 1] + nums[n - 2] + nums[n - 3] - target;
        int ret = nums[n - 1] + nums[n - 2] + nums[n - 3];
        if (res <= 0 )
        return ret; 
        for(int i = 0; i < n; i++)
        {
                int low = 0;
                int high = n - 1;
                while(low < high)
                {
                    if(low == i) ++low;
                    if(high == i) --high;
                    int temp = nums[low] + nums[high] + nums[i];
                    if( temp < target)
                    {
                        if( target - temp < res)
                        {
                             res = target -temp;
                             ret = temp;
                        }  
                        low = low + 1;
                    } 
                    else if(temp > target)
                    {
                        if( temp - target < res)
                        {
                            res = temp - target;
                            ret = temp;
                        }
                        high = high - 1;
                    }
                    else 
                    return temp;
                }
        }
        return ret;
    }
};
int main()
{

   Solution s;
    vector<int> nums = {1 , 2 , -1 , -4};
    cout<<s.threeSumClosest(nums,1);
    system("pause");
    return 0;
}