#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
         if(nums.size()<3)
            return 0;
        int i=1;
        int n=nums.size();
        int sequen_length=0;
        int distance=-1;
        int res=0;
        while (i<n)
        {
            if((nums[i]-nums[i-1])==distance)
            {
                sequen_length++;
            }
            else
            {
                if(sequen_length>=1)
                {
                    res=res+(sequen_length+1)*(sequen_length)/2;
                    distance=nums[i]-nums[i-1];
                    sequen_length=0;
                }

                else
                {
                    distance=nums[i]-nums[i-1];
                }
            }
            i++;
            
        }
        if(sequen_length>=1)
        {
            res=res+(sequen_length+1)*(sequen_length)/2;
        }
        return res;

    }
};
int main()
{

   Solution s;
    vector<int> nums={1};
    cout<<s.numberOfArithmeticSlices(nums)<<endl;
    system("pause");
    return 0;
}