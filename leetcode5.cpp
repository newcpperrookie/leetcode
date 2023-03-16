#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1)
        return s;
        int res_i=0;
        int res_j=0;
        int maxlen=1;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (size_t i = 0; i < n; i++)
        {
            dp[i][i]=1;
        }
        for (size_t L =2; L <= n; L++)
        {
            for (size_t i = 0; i < n; i++)
            {
                int j=i+L-1;
                if(j>=n)
                {
                    break;
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        if(dp[i+1][j-1]||L<=3)
                        {
                            dp[i][j]=1;
                            if(L>maxlen)
                            {
                                maxlen=L;
                                res_i=i;
                                res_j=j;
                            }
                        }
                    }
                }
            }
        }
        string s1=s.substr(res_i,maxlen);
        return s1;
    }
};
int main()
{
    Solution sl;
  string s="babad";
   string res=sl.longestPalindrome(s);
   cout<<res<<endl;
    system("pause");
    return 0;
}