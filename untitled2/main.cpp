#include <iostream>
#include <vector>
using namespace std;
unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
int groups(vector<int> skills, int minPlayers, int minLevel, int maxlevel)
{
    int numCandidates = 0;
    for ( int i = 0; i < skills.size(); i++)
    {
        if (skills[i] >= minLevel && skills[i] <= maxlevel)
        {
            numCandidates++;
        }

    }
    int res = 0;
    if (numCandidates<minPlayers)   return 0;
    if (numCandidates== minPlayers)  return 1;
    if (numCandidates>minPlayers)
    {
        for (int i = minPlayers; i <= numCandidates; i++)
        {
            res += nChoosek(numCandidates,i);
        }
    }
    return res;
}
int main() {
    int x = 0;

    x = groups(vector<int>{4,8,5,6},1,5,7);
    cout << x << endl;
    return 0;
}
