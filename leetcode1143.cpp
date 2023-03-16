#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int  find_next_position(string s, int pos,char target)
    {
        int n=s.length();
        if(pos<0||pos>=n-1)
        return -1;
        pos=pos+1;
        while (pos<n)
        {
            if(s[pos]==target)
            {
                return pos;
            }
            pos++;
        }
        return -1;
    }
    vector<int> & find_all_pos(string s,char target)
    {
        vector<int> res;
        int position=0;
        while((position=s.find(target,position))!=string::npos)
        {
            res.push_back(position);
            position++;
        }
        return res;
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        int i=0;
        vector<int> resarray;
        vector<vector<int>> res(m,resarray);
        vector<int> posarray;
        vector<vector<int>> pos(m,posarray); 
        int position=0;
        while((position=text2.find(text1[0],position))!=string::npos)
        {
            pos[0].push_back(position);
            position++;
        }
        pos[0]=text2.find(text1[0]);
        for (int i = 0; i < pos[0].size(); i++)
        {
            res[0].push_back(1);
        }
        
        res[0]=(is_empty(pos[0])?0:1);
        int maxres_temp=0;
        int temp_pos_res;
        int temp_pos;
        for (int i = 1; i < m; i++)
        {
            vector<int> temp_pos_res=find_all_pos(text2,text1[0]);

            if(!is_empty(temp_pos_res))
            {
                vector<int>maxres_temp=;
                for (int j = 0; j < i; j++)
                {
                    for(int k=0;k<pos[j].size();k++)
                    {
                        if(pos[j][k]>=0&&maxres_temp-1<res[j])
                        {

                            temp_pos=find_next_position(text2,pos[j],text1[i]);
                            if(temp_pos>0)
                            {
                                maxres_temp=res[j]+1;
                                temp_pos_res=temp_pos;
                            }
                        }
                    }
                    res[i]=maxres_temp;
                    pos[i]=temp_pos_res;
                }
            }
            else
            {
                res[i].push_back({0});
                pos[i].push_back({-1});
            }
        }
        int max_res=0;
        for (int i = 0; i < m; i++)
        {
           cout<<res[i]<<"   "<<pos[i]<<endl;
            if(res[i]>max_res)
            max_res=res[i];
        }
        return max_res;
        } 
};
int main()
{

   Solution s;
    string s1="pmjghexybyrgzczy";

    string s2= "hafcdqbgncrcbihkd";
    cout<<s.longestCommonSubsequence(s1,s2)<<endl;
    system("pause");
    return 0;
}