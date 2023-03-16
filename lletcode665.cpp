#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()==1)
        return true;
        int flag=1;
        int i=0;
        int maxtemp=nums[0];
        while(i<nums.size()-1)
        {
            if(nums[i+1]>=nums[i]&&nums[i]>=maxtemp)
            {
                i++;
                maxtemp=nums[i];
            }
            else
            {
                if(flag)
                {
                    if(i==0)
                    {
                        maxtemp=nums[i+1];
                    }
                    else if(nums[i+1]>=nums[i-1])
                    {
                        maxtemp=nums[i+1];
                        nums[i]=maxtemp;
                    }
                    else
                    {
                        nums[i+1]=maxtemp;
                    }
                    
                    i++;
                    flag--;

                }
                
                else
                return false;
            }
        }
        if(nums[i]>=nums[i-1]&&nums[i]>=maxtemp)
        return true;
        else
        {
            if(flag)
            return true;
            else
            return false;
        }
    }
};
int main()
{

   Solution s;
    vector<int> nums={5,7,1,8};
  if(s.checkPossibility(nums))
  {
    cout<<"true"<<endl;
  }
  else
  {
        cout<<"false"<<endl;
  }
    system("pause");
    return 0;
}