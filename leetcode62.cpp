#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> temp(n);
        vector<vector<int>> res(m,temp);
        for(int i=0;i<n;i++)
        {
            res[0][i]=1;
        }
        for (int j = 0; j < m; j++)
        {
            res[j][0]=1;
        }
        for (int i=1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                res[i][j]=res[i-1][j]+res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};
int main()
{

   Solution s;
    int n=4;
    cout<<s.uniquePaths(3,2);
    system("pause");
    return 0;
}