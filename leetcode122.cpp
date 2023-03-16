#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
        return 0;
        int i=0;
        int res=0;
        int minprice=prices[0];
        while(i<prices.size()-1)
        {
            if(prices[i+1]>=prices[i])
            {
                i=i+1;
                cout<<i<<" "<<555<<endl;
            }
            else
            {
                if(prices[i]>=minprice)
                {
                    res=res+prices[i]-minprice;
                    cout<<"res:"<<res<<endl;
                    minprice=prices[i+1];
                    i=i+1;
                }
                else
                {
                    minprice=prices[i+1];
                    i=i+1;
                }
            }
        cout<<"minprice"<<minprice<<endl;
        }

        if(prices[i]>=prices[i-1])
        {
            cout<<i<<endl;
            res=res+prices[i]-minprice;
        }
        return res;

    }
};

int main()
{

   Solution s;
    vector<int> nums={1,9,6,9,1,7,1,1,5,9,9,9};
   cout<<s.maxProfit(nums);
    system("pause");
    return 0;
}