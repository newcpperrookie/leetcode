#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1)
        {
            if((nums[0]==target)||(nums[0]+target)==0)
            return 1;
            else
            return 0;
        }
        int sum=0;
        for (size_t i = 0; i < n; i++)
        {
            sum=sum+nums[i];
        }
        if(sum<target)
        return 0;
        if((sum-target)%2)
        return 0;
        int temp=(sum-target)/2;
        target=target+temp;

        vector<vector<int>> res(n+1,vector<int> (target+1,0));
        res[0][0]=1;
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 0; j <= target; j++)
            {
                if(nums[i]>j)
                res[i][j]=res[i-1][j];
                else
                res[i][j]=res[i-1][j]+res[i-1][j-nums[i]];
            }
            
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j <= target; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
            
        }
        return res[n][target];

    }
};
int main()
{

   Solution s;
   vector<int> nums={0,0,0,0,0,0,0,0,1};
    cout<<s.findTargetSumWays(nums,1);
    system("pause");
    return 0;
}