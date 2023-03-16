#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        res[0]=nums[0];
        if(n==1)
        return res[0];
        res[1]=max(nums[0],nums[1]);
        int i=2;
        while(i<n)
        {
            res[i]=max(res[i-1],res[i-2]+nums[i]);
            i++;
        }
        return res[n-1];

    }
};
int main()
{

   Solution s;
    vector<int> nums={2,7,9,3,1};     
    cout<<s.rob(nums);
    system("pause");
    return 0;
}