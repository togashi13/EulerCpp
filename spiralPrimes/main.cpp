#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;

//
long powerMod(int x, int n, int m)
{
    int k = 0;
    long d = 1;
    while((n>>k) > 0) k++;
    for(int i = k-1; i >= 0; i--)
    {
        d = d*d%m;
        if(((n>>i) & 1) > 0)    d = d*x%m;
    }
    return d;
}
//long powerMod(int a, int b, int n) {
//    long d = 1;
//    int k = 0;
//    while ((b >> k) > 0) k++;
//
//    for (int i = k - 1; i >= 0; i--) {
//        d = d * d % n;
//        if (((b >> i) & 1) > 0) d = d * a % n;
//    }
//
//    return d;
//}
//bool witness(int a, int x) {
//    int t = 0;
//    int u = x - 1;
//    while (u & 1 == 0) {
//        t++;
//        u >>= 1;
//    }
//    int x1 = powerMod(a, u, x);
//    int x2;
//
//    for (int i = 0; i < t; i++)
//    {
//        x2 = x1*x1%x;
//        if((x2==1) && (x1!=1)&&(x1!=(x-1))) return true;
//        x1 = x2;
//
//    }
//    if(x1!=1) return true;
//    return false;
//}
bool witness(int a, int n) {
    int t = 0;
    int u = n - 1;
    while ((u & 1) == 0) {
        t++;
        u >>= 1;
    }

    long xi1 = powerMod(a, u, n);
    long xi2;

    for (int i = 0; i < t; i++) {
        xi2 = xi1 * xi1 % n;
        if ((xi2 == 1) && (xi1 != 1) && (xi1 != (n - 1))) return true;
        xi1 = xi2;
    }
    if (xi1 != 1) return true;
    return false;
}
bool isPseudoPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if (n < 9) return true;
    if (n % 3 == 0) return false;
    if (n % 5 == 0) return false;

    int ar[] = {2, 3};
    for (int i = 0; i < 2; i++) {
        if (witness(ar[i], n)) return false;
    }
    return true;
}
bool isPrime(int x)
{
    int sqrtx = sqrt(x);
    for(int i = 2; i < sqrtx; i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int spiralPrimes()
{
   double primeNum = 3.0;
   int sl = 2, c = 9;
   while(primeNum/(2*sl+1)>0.1)
   {
       sl += 2;
       for (int i = 0; i < 3; i++)
       {
           c += sl;
//           if(isPrime(c)) primeNum++ ;
            if(isPseudoPrime(c)) primeNum++;
       }
       c += sl;
   }
   return sl;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int res = spiralPrimes();
    auto end = chrono::high_resolution_clock::now();
    auto duration =  chrono::duration_cast<chrono::milliseconds>(end-start);
    cout << duration.count() << endl;
//    int res = powerMod(2,9,3);
    cout << res << endl;
//    return 0;
}
