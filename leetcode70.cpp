#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<0)
        return 0;
        else if(n<=1)
        return 1;
        else 
        return climbStairs(n-1)+climbStairs(n-2);
    }
};
int main()
{

   Solution s;
    int n=4;
    cout<<s.climbStairs(n);
    system("pause");
    return 0;
}