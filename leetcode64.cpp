#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size();
        int n=grid[0].size();
        if(n==1)
        {
            int i=0;
            while(i<m)
            {
                res=res+grid[i][0];
                i++;
            }
            return res;
        }
        if(m==1)
        {
            int i=0;
            while(i<n)
            {
                res=res+grid[0][i];
                i++;
            }
            return res;
        }
        vector<vector<int>> temp;
        for(int i=0;i<m;i++)
        {
            vector<int> temp_d(n);
            temp.push_back(temp_d);
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            temp[0][i]=grid[0][i];
            else
            temp[0][i]=temp[0][i-1]+grid[0][i];
        }
        for(int i=0;i<m;i++)
        {
            if(i==0)
            temp[i][0]=grid[i][0];
            else
            temp[i][0]=temp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                temp[i][j]=min(temp[i][j-1],temp[i-1][j])+grid[i][j];
            }
        }
        
        return temp[m-1][n-1];
}

};

int main()
{

   Solution s;
    vector<vector<int>> nums={{1,2},{5,6},{1,1}};     
    cout<<s.minPathSum(nums);
    system("pause");
    return 0;
}