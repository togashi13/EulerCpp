#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int ct = 0;
    for ( int i = 2; i < 100; i++)
    {
        int limit = floor( sqrt( i ) );

        int a = limit, m = 0, d = 1, period = 0;
        if ( limit * limit == i )   continue;
        do
        {
            m = d * a - m;
            d = ( i - m * m ) / d;
            a = ( limit + m ) / d;
            period ++;
        }
        while ( a != 2 * limit );
        if ( period % 2 == 1)   ct ++;
    }
    cout << ct << endl;
    return 0;
}
