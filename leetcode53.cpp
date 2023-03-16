#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int maxres=nums[0];
        int tempres=0;
        while(i<nums.size())
        {
            if(nums[i]>=0&&tempres<0)
            {
                tempres=0;
            }
            tempres=nums[i]+tempres;
            maxres=max(max(maxres, tempres),nums[i]);
            i++;
        }
        return maxres;

    }
};
int main()
{

   Solution s;
    vector<int> nums={-2,-1};
    cout<<s.maxSubArray(nums);
    system("pause");
    return 0;
}