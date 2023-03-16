#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> res(n,0);
        if(s[0]=='0')
        {
            res[0]=0;
        }
        else
        {
            res[0]=1;
        }
        if(n==1)
        {
            return res[0];
        }
        if(s[1]=='0')
        {
            res[1]=res[0];
        }
        else
        {
            if(s[0]=='1'||(s[0]=='2'&&s[1]<='6'))
            {
                res[1]=res[0]+1;
            }
            
            else
            {
                res[1]=res[0];
            }
            
        }
        int i=2;
        while(i<n)
        {
            if(s[i]>'0')
            {
               if((s[i-1]=='1')||(s[i-1]=='2'&&s[i]<='6'))
               res[i]=res[i-1]+res[i-2];
               else 
               res[i]=res[i-1];
            }
            else
            {
                if(s[i-1]=='0')
                return 0;
                res[i]=min(res[i-2],res[i-1]);
            }
            i++;
        }
        for (int i = 0; i < n; i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
        
        
        return res[n-1];

    }
};
int main()
{

   Solution s;
    string s1="226";
    cout<<s.numDecodings(s1);
    system("pause");
    return 0;
}