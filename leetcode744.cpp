#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0;
        int r=letters.size()-1;
        int mid=(l+r)/2;
        while(l<=r)
        {
            if(letters[mid]==target)
            return letters[mid+1];
            else if(letters[mid]>target)
            {
                r=mid-1;
                if(letters[r]<=target)
                return letters[mid];
             mid=(l+r)/2;
            }
            else
            {
                l=mid+1;
                if(letters[l]>target)
                return letters[l];
                mid=(l+r)/2;
            }
        }

        return ' ';
    }
};
int main()
{

   Solution s;
    vector<char> nums={'c', 'f', 'j'};
    char target='c';
    cout<<s.nextGreatestLetter(nums,target);
    system("pause");
    return 0;
}