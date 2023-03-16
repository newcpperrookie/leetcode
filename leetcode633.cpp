#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int j=floor(sqrt(c));
        int i=0;
        while (i!=j)
        {
            
            if(i*i==c-j*j)
            return true;
            else if (i*i>c-j*j)
            {
                j--;
            }
            else
            i++;
            
        }
        if(i*i==c-j*j)
        return true;
        else
        return false;
    }
};

int main()
{

   Solution s;
   if(s.judgeSquareSum(2147482647))
   {
    cout<<555<<endl;
   }
   

    system("pause");
    return 0;
}