#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size()<1)
        {
            return 0;
        }
        sort(points.begin(),points.end(),[](const auto& u, const auto& v){return u[1]<v[1];});
        int n=points.size();
        int pos=points[0][1];
        int res=1;
        for (int i = 1; i < n; i++)
        {
            if(points[i][0]>pos)
            {
                res++;
                pos=points[i][1];
            }
            
        }
        
        return res;
    }
};

int main()
{

   Solution s;
    vector<int> nums1={0};
    vector<int> nums2={2,5,6};
    s.merge(nums1,3,nums2,3);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    
   

    system("pause");
    return 0;
}