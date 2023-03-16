#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        if (exp.size() == 0) return {};
        for (int i = 0; i < exp.size(); i++) {
            char act = exp[i];
            if (act == '+' || act == '-' || act == '*') {
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1, exp.size() - i - 1));
                for (int l_num : left) {
                    for (int r_num : right) {
                        if (act == '+') {
                            ans.push_back(l_num + r_num);
                        }
                        if (act == '-') {
                            ans.push_back(l_num - r_num);
                        }
                        if (act == '*') {
                            ans.push_back(l_num * r_num);
                        }
                    }
                }
            }
        }
        if (ans.size() == 0) ans.push_back(stoi(exp));
        return ans;
    }
};
int main()
{

   Solution s;
   string s1="2*3-4*5";
   vector<int> nums=s.diffWaysToCompute(s1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}