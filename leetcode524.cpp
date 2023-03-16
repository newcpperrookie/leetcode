#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string> res={};
        int res_length=0;
        for (int i = 0; i < dictionary.size(); i++)
        {
            cout<<111<<endl;
            int j=0;
            int k=0;
            while(k<s.length())
            {
                if(s[k]==dictionary[i][j])
                {
                    k++;
                    j++;
                }
                else
                k++;
            }
            if(j==dictionary[i].length()&&j>res_length)
            {
                cout<<555<<endl;
                res.push_back(dictionary[i]);
                res_length=j;
            }
            else if (j==dictionary[i].length()&&j==res_length)
            {
                                cout<<666<<endl;
                int m=0;
                while (m<j)
                {
                    if(dictionary[i][m]>res[res.size()-1][m])
                        break;
                    else if(dictionary[i][m]==res[res.size()-1][m])
                    {
                        m++;
                    }
                    else
                    {
                        res.push_back(dictionary[i]);
                    }
                }
            }
            
        }
        if(res.size()>0)
        return res[res.size()-1];
        else
        return "";
    }
};

int main()
{

   Solution s;
   string s1 = "apple";
   vector<string> dictionary = {"zxc","vbn"};
   string res= s.findLongestWord(s1,dictionary);
   cout<<res<<endl;
    system("pause");
    return 0;
}