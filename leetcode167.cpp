#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int>res={};
        if(numbers.size()<2)
        {
            
            return res;
        }
        int i=0;
        int j=numbers.size()-1;
        while (i!=j)
        {
            if(numbers[i]+numbers[j]==target)
            {
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if (numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }

        }
    return res;
    }
    
};
int main()
{

   Solution s;
   vector<int>num={2,7,11,15};
   int target=9;
   vector<int>res=s.twoSum(num,target);
   for (int i = 0; i < res.size(); i++)
   {
    cout<<res[i]<<" ";
   }
   cout<<endl;
   

    system("pause");
    return 0;
}