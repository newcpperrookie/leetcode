#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> res;
        if(m==1)
        {
            res=matrix[0];
            return res;
        }
        if(n==1)
        {
            for(int i=0;i<matrix.size();i++)
            res.push_back(matrix[i][0]);
            return res;
        }
        int i=0;
        int j=0;
        int flag=1;
        int num1=0;
        int num2=0;
        while(flag)
        {
            while(j<=(n-flag))
            {
                res.push_back(matrix[i][j]);
                j++;
            }
            num1++;
            j--;
            i++;
            if(num1==m)
            break;
            while(i<=(m-flag))
            {
                res.push_back(matrix[i][j]);
                i++;

            }
            num2++;
            i--;
            j--;
            if(num2==n)
            break;
            while(j+1>=flag)
            {
                res.push_back(matrix[i][j]);
                j--;
            }
            num1++;
            if(num1==m)
            break;
            j++;
            i--;
            while(i>=flag)
            {
                res.push_back(matrix[i][j]);
                i--;
            }
            num2++;
            if(num2==n)
            break;
            flag++;
            i++;
            j++;
        }
        return res;

    }
};
int main()
{

   Solution s;
    vector<vector<int>> nums={{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    vector<int> res=s.spiralOrder(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}