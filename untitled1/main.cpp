#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string fname;
    ofstream outFile;

    for ( int i = 1; i < 3; i ++ )
    {
        if ( i == 1 )
        {
            fname = "out1.txt";
        }
        if ( i == 2)
        {
            fname = "out2.txt";
        }
        outFile.open( fname.c_str() );
        outFile << i << endl;

    }

    return 0;
}