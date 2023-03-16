#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>res(grid[0].size());
        int left;
        int right; 
        for(int i=0;i<grid[0].size();i++)
        {
            int j=i;
            int k=0;
            while(k<grid.size())
            {

                if(j-1>=0)
                left =grid[k][j-1];
                else
                left=-grid[k][j];
                if(j+1<=grid[0].size()-1)
                {
                    right=grid[k][j+1];
                }

                else
                right=-grid[k][j]; 
                if(grid[k][j]==-1&&grid[k][j]==left)
                {
                    j=j-1;
                    k=k+1;
                }
                else if(grid[k][j]==1&&grid[k][j]==right)
                {
                    j=j+1;
                    k=k+1;
                }
                else
                break;
            }
            if(k==grid.size())
            res[i]=j;
            else
            res[i]=-1;
        }
        return res;

    }
};
int main()
{

   Solution s;
    vector<vector<int>> nums={{-1}};
    vector<int> res=s.findBall(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}