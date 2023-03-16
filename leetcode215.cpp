#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int temp=0;
        int i=0;
        int j=nums.size()-1;
        k=nums.size()-k;
        cout<<k<<endl;
        while(i<j)
        {
            for (size_t i = 0; i < nums.size(); i++)
            {
                cout<<" "<<nums[i];
            }
            cout<<" i: "<<i<<" j: "<<j<<" temp:"<<temp<<endl;
            temp=partition_k(nums,i,j);

            
            if(temp==k)
            break;
            else if(temp<k)
            {
                i=temp+1;
            }
            else
            {
                j=temp-1;
            }
        }
        return nums[k];
    }
    int partition_k(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i=low;
        int j=high+1;
        while(i<j)
        {
            while(nums[++i]<=pivot&&i<high) ;
            while(nums[--j]>pivot&&j>low) ;
            if(i<j) swap_elements(nums,i,j);
            else  break;
        }
        swap_elements(nums, low, j);
        return j;
    }
    void swap_elements(vector<int> &nums, int i, int j)
    {
        if(i==j)
        return ;
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};

int main()
{

   Solution s;
    vector<int> nums2={7,6,5,4,3,2,1};
    int k=5;
    
    cout<<s.findKthLargest(nums2,k)<<endl;
    
   

    system("pause");
    return 0;
}