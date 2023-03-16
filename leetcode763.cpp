#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> length;
        int i=0;
        int flag=1;
        vector<vector<char>> charlabel;
        vector<char> temp;
        while(i<s.length())
        {
            flag=1;
            for(int m=0;m<charlabel.size();m++)
            {
                for(int n=0;n<=charlabel[m].size();n++)
                {
                    if(charlabel[m][n]==s[i])
                    {
                        flag=0;
                        if(m==charlabel.size()-1)
                        length[m]++;
                        else 
                        {
                            int k=charlabel.size()-1;
                            while(k>m)
                            {
                                length[m]=length[m]+length[k];
                                length.pop_back();
                                charlabel[m].insert(charlabel[m].end(),charlabel[k].begin(),charlabel[k].end());
                                charlabel.pop_back();
                                k--;
                            }
                            length[m]++;
                            
                        }
                    goto here;
                        
                    }
                }
            }
            if(flag)
            {
                temp.clear();
                temp.push_back(s[i]);
                length.push_back(1);
                charlabel.push_back(temp);
            }
            here:i++;
            
        }
        return length;
    }
};
int main()
{

   Solution s;
    string s1="ababcbacadefegdehijhklij";
    vector<int> res=s.partitionLabels(s1);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}