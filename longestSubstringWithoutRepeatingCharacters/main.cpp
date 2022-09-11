#include <iostream>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> bro(128,0);
    int res = 0, start = 0, end = 0, n = s.size();
    while(end<n)
    {
        if(bro[s[end++]]++ == 1)
        {
            res = max(end - start - 1,res);

            while(bro[s[end-1]]!=1)
            {
                bro[s[start++]]--;
            }
        }

    }
    return max(res,end-start);
}
int main() {
    string target("pwwkew");
    int res;
    res = lengthOfLongestSubstring(target);
    cout << res << endl;
    return 0;
}
