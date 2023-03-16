#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1||(n==2&&nums[0]==nums[1]))
        return 1;
        if(n==2)
        return 2;
        vector<int> symbol(n,0);
        vector<int>  res(n,1);

        if(nums[0]>nums[1])
        {
            symbol[1]=-1;
            res[1]=2;
        }
        else if(nums[0]<nums[1])
        {
            symbol[1]=1;
            res[1]=2;
        }
        else
        {
            symbol[1]=0;
            res[1]=1;
        }
        int i=2;
        int maxtemp=1;
        int tempsymbol=0;
        while (i<n)
        {
            maxtemp=1;
            tempsymbol=0;
            for (int j = 0; j < i; j++)
            {
                if((nums[i]>nums[j]&&symbol[j]<=0&&(maxtemp-1)<res[j])||(nums[i]<nums[j]&&(symbol[j]>=0)&&(maxtemp-1)<res[j]))
                {
                    maxtemp=res[j]+1;
                    if(symbol[j]!=0)
                    tempsymbol=-symbol[j];
                    else
                    {
                        tempsymbol=(nums[i]>nums[j]?1:-1);
                    }
                }
                else if (nums[i]==nums[j]&&maxtemp<res[j])
                {
                    maxtemp=res[j];
                    tempsymbol=symbol[j];
                }
                
            }
            res[i]=maxtemp;
            symbol[i]=tempsymbol;
            i++;
        }
        
        int res_value=1;
        for (int i = 0; i < n; i++)
        {
  //         cout<<res[i]<<"     "<<symbol[i]<<endl;
            if(res[i]>res_value)
            res_value=res[i];
        }
        return res_value;
        

    }
};
int main()
{

   Solution s;
    vector<int> nums={3,3,3,2,5};
    cout<<s.wiggleMaxLength(nums)<<endl;
    system("pause");
    return 0;
}