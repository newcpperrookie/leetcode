#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==1)
        return 1;
        sort(pairs.begin(),pairs.end(),[](const auto &u, const auto &v){return u[0]<v[0]||(u[0]==v[0]&&u[1]<v[1]);});
        vector<int> res(n,1);
        int maxres=1;
        for (int i = 1; i < n; i++)
        {
            maxres=1;
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1]&&maxres-1<res[j])
                {
                    maxres=res[j]+1;
                }
            }
            res[i]=maxres;
        }
        int res_value=1;
        for (int i = 0; i < n; i++)
        {
            if(res[i]>res_value)
            res_value=res[i];
        }
        return res_value;
    }
};
int main()
{

   Solution s;
    vector<vector<int>> nums={{1,2}, {2,3}, {3,4}};
    cout<<s.findLongestChain(nums)<<endl;
    system("pause");
    return 0;
}