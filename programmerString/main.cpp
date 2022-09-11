#include <iostream>
#include <vector>
#include <string>
using namespace std;

int programmerString(string s)
{
    vector<char> progS{'p','r','o','g','r','a','m','m','e','r'};
    int i = 0;//length of first progS;
    int j = s.size() -1 ;//index of second progS;
    while(!progS.empty())
    {
        for (int k = 0; k < progS.size(); k++)
        {
            if (progS[k] == s[i])
            {
                progS.erase(progS.begin()+k);
                break;
            }
        }
        i++;
    }
    vector<char> proglS{'p','r','o','g','r','a','m','m','e','r'};
    while(!proglS.empty())
    {
        for (int k = 0; k < proglS.size(); k++) {
            if (proglS[k] == s[j])
            {
                proglS.erase(proglS.begin()+k);
            }
        }
        j--;
    }
    return j-i+1;
}
int main() {
    string progS{"programmerxxxxxxprozmerqgram"};
    int res = 0;
    res = programmerString(progS);
    cout << res << endl;
    return 0;
}
