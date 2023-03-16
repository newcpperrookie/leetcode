#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return false;
        int res=0;
        int maxvalue=0;
        for (size_t i = 0; i < n; i++)
        {
            if(nums[i]>maxvalue)
            {
                maxvalue=nums[i];
            }
            res=res+nums[i];
        }
        cout<<res<<endl;
        if((res%2))
        return false;
        int target = res/2;
        if(maxvalue>target)
        return false;
        if(maxvalue==target)
        return true;
        vector<vector<int>> dp(n, vector<int> (target+1,0));
        for (size_t i = 0; i < n; i++)
        {
            dp[i][0]=1;
        }
        dp[0][nums[0]]=1;
        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 1; j <= target; j++)
            {
                if(nums[i]>=j)
                dp[i][j]=dp[i-1][j];
                else 
                dp[i][j]=dp[i-1][j-nums[i]]|dp[i-1][j];
            }
            
        }
        /*for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j <= target; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
            
        }*/

        
        return dp[n-1][target];
    }
};
int main()
{

   Solution s1;
   vector<int> nums={1,5,11,5};
   if(s1.canPartition(nums ))
   {
    cout<<555<<endl;
   }

    system("pause");
    return 0;
}             