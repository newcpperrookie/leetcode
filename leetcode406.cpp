#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
   void reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const auto& u, const auto& v){ return u[0]<v[0]||(u[0]==v[0]&&u[1]<v[1]);});
        vector<vector<int>> res(people.size());
        int n=people.size();
        for (auto iter = people.begin(); iter != people.end(); iter++)
        {
            int space=iter[1]+1;
            for (int i = 0; i < n; i++)
            {
                if(empty(res[i]))
                space--;
                if (space==0)
                {
                    res[i]=iter;
                    break;
                }
            }
            
        }
        return res;
    }
};

int main()
{

    Solution s;
    vector<vector<int>> nums1={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    s.reconstructQueue(nums1);
    
   

    system("pause");
    return 0;
}