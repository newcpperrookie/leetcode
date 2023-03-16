#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)
        return n-1;
        int max_k=n/2;
        int i=2;
        int res=0;
        int temp;
        while (i<=max_k)
        {
            temp=searchbiggest(n,i);
            if(temp>res)
            {
                res=temp;
            }
            i++;
        }
        return res;
        

    }
    int searchbiggest(int n, int k)
    {
        vector<int> nums(k,n/k);
        for (int i = 0; i < n%k; i++)
        {
            nums[i]++;
        }
        int res=1;
        for (int i = 0; i < k; i++)
        {
            res=res*nums[i];
        }
        return res;
        
    }
};
int main()
{

   Solution s;
    int n=4;
    cout<<s.integerBreak(2);
    system("pause");
    return 0;
}