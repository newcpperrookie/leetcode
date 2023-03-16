#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
        return 0;
        sort(intervals.begin(),intervals.end(),[](const auto& u, const auto& v){ return u[0]<v[0];});
        int n=intervals.size();
        vector<int> f(n,1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(intervals[i][0]>=intervals[j][1])
                f[i]=max(f[i],f[j]+1);
            }
            
        }
        return n-*max_element(f.begin(),f.end());
        
    
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