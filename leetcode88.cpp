#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num=0;
        int i=m-1;
        int j=n-1;
        while (i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[m+n-1-num]=nums1[i];
                num++;
                i--;
            }
            else
            {
                nums1[m+n-1-num]=nums2[j];
                num++;
                j--;
            }
        }
        if (j>=0)
        {
            for (int m = 0; m <= j; m++)
            {
                nums1[m]=nums2[m];
            }
        }
        
        

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