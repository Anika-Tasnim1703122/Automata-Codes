#include<bits/stdc++.h>
using namespace std;
class DfaToRe
{
    public:
        string inputTable[4][4];
        string reTable1[4][4];
        string reTable2[4][4];
        string reTable3[4][4];
        char inpTranTable[4][2];
        int acceptindi;
        int acceptindj;
        string stateFinder(int from, int to)
        {
            string str = "";
            for(int i = 0; i < 4; i++)
            {
                if(inpTranTable[from][i] == to + '0')
                {
                    if(str != "")
                        str = str + "+" + char(i + '0');
                    else
                        str += (i + '0');
                }
            }
            if(str == "")
                return "x";
            return str;
        }
        void input()
        {
            for(int i=0; i<4; i++)
            {
                for(int j = 0; j<3 ;j++)
                {
                    cin >> inpTranTable[i][j];
                }
            }
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                if(i == j)
                    inputTable[i][j] += 'e';
                if(inputTable[i][j] != "")
                    inputTable[i][j] = inputTable[i][j] + "+" + stateFinder(i, j);
                else
                    inputTable[i][j] += stateFinder(i, j);
                }
            }
        }

        void inputPrinter()
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    cout << "R" <<i+1 << j+1 << " : " << inputTable[i][j] << "\n";
                }
                //cout << endl;
            }
        }
        void reTabletran1()
        {
            int k=0;
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        reTable1[i][j] = inputTable[i][j] + "+(" + inputTable[i][k] + ") (" + inputTable[k][k] + ")*(" + inputTable[k][j]+")";
                    }
                }
        }

        void printerReTable1()
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    cout << "R" << i+1 << j+1 << " : " << reTable1[i][j] << "\n";
                }
                //cout << endl;
            }
        }
        void reTabletran2()
        {
            int k=1;
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        reTable2[i][j] = reTable1[i][j] + "+(" + reTable1[i][k] + ") (" + reTable1[k][k] + ")*(" + reTable1[k][j]+")";
                    }
                }
        }

        void printerReTable2()
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    cout << "R" << i+1 << j+1 << " : " << reTable2[i][j] << "\n";
                }
                //cout << endl;
            }
        }
        void reTabletran3()
        {
            int k=1;
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        reTable3[i][j] = reTable2[i][j] + "+(" + reTable2[i][k] + ") (" + reTable2[k][k] + ")*(" + reTable2[k][j]+")";
                    }
                }
        }

        void printerReTable3()
        {
            int i=0,j=0;
            /*for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    cout << "R" << i+1 << j+1 << " : " << reTable3[i][j] << "\n";
                }
                //cout << endl;
            }*/
            cout << "R" << i+1 << j+1 << " : " << reTable3[acceptindi][acceptindj] << "\n";
        }
};
int main()
{
    DfaToRe ob;
    ob.input();
    //cout << "Regular Expression for 0th iteration :\n";
    //ob.inputPrinter();
    //cout << endl;

    ob.reTabletran1();
    //ob.printerReTable1();
   // cout << endl;
    //
    ob.reTabletran2();
    //ob.printerReTable2();
   // cout << endl;
    //
    ob.reTabletran3();
    cout << "Regular Expression for 0th iteration :\n";
    ob.inputPrinter();
    cout << "Regular Expression for 1st iteration :\n";
    ob.printerReTable1();
    cout << endl;
    cout << "Regular Expression for 2nd iteration :\n";
    ob.printerReTable2();
    cout << "Enter accepting states indx : ";
    cin >> ob.acceptindi >> ob.acceptindj;
    cout << "Required RE: " << ob.reTable2[ob.acceptindi-1][ob.acceptindj-1];
}

