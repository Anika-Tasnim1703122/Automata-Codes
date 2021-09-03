#include<bits/stdc++.h>
#include<cstring>
#include <set>
#include <cstdlib>
using namespace std;
class nfa
{
public:

    string state;
    string inp0;
    string inp1;
};
int main()
{
    int n;
    //ofstream fout;
    //fout.open("nfa_dfa.txt");
    string powset[8][3];
    int k = 0;
    cout <<  "Enter number of states : ";
    cin >> n;
    nfa *ob;
    ob = new nfa[n];
    cout << "Enter states and transitions :\n";
    for(int i = 0;i < n; i++)
    {
        char ch;
        cin >> ob[i].state >> ob[i].inp0 >> ob[i].inp1;
    }
    cout << "state\tinput0\tinput1\n";
    for(int i = 0; i<n ;i++)
    {
        cout << ob[i].state << "\t" << ob[i].inp0 << "\t" << ob[i].inp1 << endl;
    }
    for(int  i = 0;i<8;i++)
    {
        for(int j =0,m = 0 ;j<3; j++)
        {
            if(i&(1<<j))
            {
               powset[i][m] = ob[j].state;
               m++;
            }
        }
    }

    int subsetflag[8][3];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            subsetflag[i][j] = 0;
        }
    }
    int x = 0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k = 0 ; k < n ; k++)
            {
                if(powset[i][j]==ob[k].state)
                {
                    subsetflag[i][k]=1;
                }
            }
        }
    }
    cout << endl;
    cout << "DFA table:\n";
    for(int i=0,m=0;i<8,m<8;i++,m++)
    {
        set <char> st0, st1;
        set <char> :: iterator itr;
        string strin, str0, str1;

        for(int j=0,n=0;j<3,n<3;j++,n++)
        {
            if(subsetflag[i][j]==1)
            {
                for(int k = 0; k < (ob[j].inp0).length(); k++)
                {
                    st0.insert((ob[j].inp0)[k]);
                    st1.insert((ob[j].inp1)[k]);
                }
                strin += ob[j].state;
            }
        }
        for(itr = st0.begin(); itr != st0.end(); itr++)
        {
            str0 += *itr;
        }

        for(itr = st1.begin(); itr != st1.end(); itr++)
        {
            str1 += *itr;
        }
        cout << "{" << strin << "}" << "\t" << "{" << str0 << "}" << "\t" << "{" << str1 << "}" << endl;
    }
}

