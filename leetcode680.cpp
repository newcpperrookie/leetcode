#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        int flag=2;
        while (i<=j&&s[i]==s[j])
        {
                ++i;
                --j;
        }
        if(i>j)
        return true;
        if(s[i+1]==s[j])
        {
            int temp_1_i=i+2;
            int temp_1_j=j-1;
            while (temp_1_i<=temp_1_j&&s[temp_1_i]==s[temp_1_j])
            {
                ++temp_1_i;
                --temp_1_j;
            }
            if(temp_1_i>temp_1_j)
            return true;    
        }
        if(s[i]==s[j-1])
        {
            int temp_2_i=i+1;
            int temp_2_j=j-2;
            while (temp_2_i<=temp_2_j&&s[temp_2_i]==s[temp_2_j])
            {
                ++temp_2_i;
                --temp_2_j;
            }
            if(temp_2_i>temp_2_j)
            return true;
        }
        return false;
        
    }
};

int main()
{

   Solution s;
   if(s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"))
   {
    cout<<555<<endl;
   }
   else
   {
    cout<<598<<endl;
   }

    system("pause");
    return 0;
}