#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
ostream& operator<<(ostream& os, const vector<int>& vec)
{
    for (auto element: vec)
    {
        os << element << " ";
    }
    return os;
}
int main() {
    int rep = 100, length = 100000;
    vector<vector<int>> record(rep, vector<int>(length));
    vector<vector<int>> walk(rep, vector<int>(length));

    for (int i = 0; i < rep ; i++)//omega
    {
        int S = 0, Y = 0;

        srand(time(NULL));
        for (int j = 1; j < length; j++)
        {
            S += ( rand() % 2 ) ? 1 : -1;
//            Y = pow((1/2),S);
//            record[i][j] = Y;
            walk[i][j] = S;
        }
    }
    vector<int> average(length);
    for ( int i = 0; i < rep; i++)
    {
        for ( int j = 0; j < length; j++)
        {
            average[j] += walk[i][j];
        }
    }
    for ( int i = 0; i < length; i++)
    {
        average[i] /= rep;
    }
    for ( int i =length -10; i < length; i++) {
        cout << average[i] << endl;
    }
    return 0;
}
