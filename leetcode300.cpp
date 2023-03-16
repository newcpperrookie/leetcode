#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        if(nums[1]>nums[0])
        res[1]=2;
        int i=2;
        int tempmax=0;
        while(i<n)
        {
            tempmax=1;
            for(int j=i;j>=0;j--)
            {
                if(nums[j]<nums[i]&&(tempmax-1)<res[j])
                {
                    tempmax=res[j]+1;
                }
            }
            res[i]=tempmax;
            i++;
        }
        int maxres=0;
        for(int i=0;i<n;i++)
        {
            cout<<res[i]<<" ";
            if(maxres<res[i])
            maxres=res[i];
        }
        cout<<endl;
        return maxres;

    }
};
int main()
{

   Solution s;
    vector<int> nums={7,7,7,7,7};
    cout<<s.lengthOfLIS(nums)<<endl;
    system("pause");
    return 0;
}