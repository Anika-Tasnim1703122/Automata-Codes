#include<bits/stdc++.h>
using namespace std;
class DfaToRe
{
    public:
        string inputTable[2][2];
        string reTable1[2][2];
        string reTable2[2][2];
        void input()
        {
            for(int i=0; i<2; i++)
            {
                for(int j = 0; j<2 ;j++)
                {
                    cin >> inputTable[i][j];
                }
            }
        }

        void inputPrinter()
        {
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    cout << "R" <<i+1 << j+1 << " : " << inputTable[i][j] << "\n";
                }
                //cout << endl;
            }
        }
        void reTabletran1()
        {
            int k=0;
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        reTable1[i][j] = inputTable[i][j] + "+(" + inputTable[i][k] + ") (" + inputTable[k][k] + ")*(" + inputTable[k][j]+")";
                    }
                }
        }

        void printerReTable1()
        {
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    cout << "R" << i+1 << j+1 << " : " << reTable1[i][j] << "\n";
                }
                //cout << endl;
            }
        }
        void reTabletran2()
        {
            int k=1;
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        reTable2[i][j] = reTable1[i][j] + "+(" + reTable1[i][k] + ") (" + reTable1[k][k] + ")*(" + reTable1[k][j]+")";
                    }
                }
        }

        void printerReTable2()
        {
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    cout << "R" << i+1 << j+1 << " : " << reTable2[i][j] << "\n";
                }
                //cout << endl;
            }
        }
};
int main()
{
    DfaToRe ob;
    ob.input();
    cout << "Regular Expression for 0th iteration :\n";
    ob.inputPrinter();
    cout << endl;
    cout << "Regular Expression for 1st iteration :\n";
    ob.reTabletran1();
    ob.printerReTable1();
    cout << endl;
    cout << "Regular Expression for 2nd iteration :\n";
    ob.reTabletran2();
    ob.printerReTable2();
}
