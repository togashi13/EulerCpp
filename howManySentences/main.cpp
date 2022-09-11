#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

int countSentences(vector<string> wordSet,vector<string> sentences)
{
    int res = 1;
    unordered_map<string, int> maps;
    for (int i = 0; i< wordSet.size(); i++)
    {
        string s = wordSet[i];
        sort(s.begin(),s.end());
        maps[s] ++;
    }
    for(int i = 0; i < sentences.size(); i++)
    {
        istringstream iss(sentences[i]);
        do
        {
            string subs;
            iss >> subs;
            sort(subs.begin(),subs.end());
            if(maps.find(subs) != maps.end())
            {
                res *= maps[subs];

            }
        }
        while(iss);
    }

    return res;

}
int main() {
    vector<string> words {"listen","silent","it","is"};
    vector<string> sent {{"listen it is silent silent"},{"listen"}};
    int x = 0;
    x = countSentences(words,sent);
    cout << x << endl;
    return 0;
}
