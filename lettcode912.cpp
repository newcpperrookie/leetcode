#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
            //vector<int> res=nums;
            quicksort(nums, 0, nums.size()-1);

            return nums;
    }
    void quicksort(vector<int>& nums, int low, int high)
    {
        if(low>=high)
        return;
        int mid=partition(nums,low,high);
        quicksort(nums,low, mid-1);
        quicksort(nums, mid+1, high);
    }
    int partition(vector<int>& nums, int low, int high)
    {
        int i=low;
        int j=high+1;
        while(i<j)
        {
            while(nums[++i]<=nums[low]&&i<high);
            while(nums[--j]>nums[low]&&j>low);
            if(i<j)
            swap(nums,i,j);
        }
        swap(nums,low,j);
        return j;
    }
    void swap(vector<int>& nums, int i, int j)
    {
        if(i==j)
        return ;
        int temp= nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
int main()
{

   Solution s;
    vector<int> nums={5,2,3,1};
    s.quicksort(nums,0,3);
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
    system("pause");
    return 0;
}