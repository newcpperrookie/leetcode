#include <iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        cout<<s[i]<<s[j]<<endl;
        while (i!=j)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U')
                {
                    char temp;
                    temp=s[i];
                    s[i]=s[j];
                    s[j]=temp;
                    ++i;
                    --j;
                }
                else
                --j;
            }
            else
            ++i;
        }
        return s;
        

    }
};

int main()
{

   Solution s;
   string s1;
   s1=s.reverseVowels("ai");
   cout<<s1;

    system("pause");
    return 0;
}