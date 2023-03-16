#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 4)
        return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++)
        {
            for(int j = i+1; j < n - 2 ; j++)
            {
                int temp_target = target - nums[i] - nums[j];
                int low = j+1;
                int high = n-1;
                while(low < high)
                {
                    cout<<low<<" "<<high<<endl;
                    int temp_val = nums[low] + nums[high]; 
                    if(temp_val == temp_target)
                    {
                        vector<int> v_temp={nums[i], nums[j], nums[low], nums[high]};
                            res.push_back(v_temp);
                        low ++;
                        high --;
                    }
                    else if (temp_val > temp_target)
                    {
                        high--;
                    }
                    else
                    {
                        low ++;
                    }
                }
            }
        }
        return res;

    }
};
int main()
{

   Solution s;
    vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
    vector<vector<int>> s1=s.fourSum(nums,-11);
    for (auto it:s1)
    {
        for (auto iter : it)
        {
            cout<<iter<<" ";
        }
        cout<<endl;
    }
    
    system("pause");
    return 0;
}