#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vec)
{
    for (auto element: vec)
    {
        os << element << " ";
    }
    return os;
}
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
bool is_prime(int n) {
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
int concat(int x, int y)
{
    int z = y;
    while(z>0)
    {
        x*=10;
        z/=10;
    }
    return x+y;
}
bool prime_concat(int x, int y)
{
    return is_prime(concat(x,y)) && is_prime(concat(y,x));
}
void makePair(int a, vector<int> const & primes, unordered_map<int,set<int>> &m)
{
    for(int i = a + 1; i < primes.size(); i++)
    {
        if(prime_concat(a,i))
            m[a].insert(primes[i]);
    }

}
vector<int> Esieve(int n)
{
    vector<bool> isPrime((n-1)/2 ,true);
    vector<int> res;
    res.push_back(2);
    for (int i = 3; i <= n; i+=2)
    {
        if(isPrime[i/2-1])
        {
            res.push_back(i);
            for(uint64_t j = i*i; j <= n; j+= 2*i)
            {
               isPrime[j/2-1] = false;

            }
        }
    }

    return res;
}
int main() {
    vector<int> primes = Esieve(50000);
    int result = INT_MAX;
    int n = primes.size();
    for(int i = 0; i < n; i++)
    {
        if( 5* primes[i] > result)  break;


    }
    return 0;

}
