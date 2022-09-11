#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//bool isin_map(unordered_map<char,int> m1,unordered_map<char,int> m2)
//{
//    for(auto z:m1)
//    {
//        if(m2[z.first] < z.second) return false;
//    }
//    return true;
//}
//
//string minWindow(string s, string t) {
//    int m = s.size();
//    int n = t.size();
//    bool match_flag = false;
////    bool match_flag2 = false;
//    if(m<n) return "";
//    unordered_map<char,int> count;
//    unordered_map<char,int> countt;
//    string res = s;
//    for (int i = 0; i < n; i++)
//    {
//        countt[t[i]] ++;
//
//    }
//    int start = 0;
//    int end = 0;
//    for(; end<m; end++)
//    {
//        count[s[end]] ++;
//        if (isin_map(countt,count))
//        {
//            match_flag = true;
////            if (end - start + 1 < res.size())   res = s.substr(start,end-start+1);
//
//            while(isin_map(countt,count))
//            {
//
//                count[s[start]] --;
//                start ++;
////                res = (end - start + 2 < res.size()) ? s.substr(start-1,end-start+2): res;
//
//            }
//            res = (end - start + 2 < res.size()) ? s.substr(start-1,end-start+2): res;
//
//
//        }
//
//    }
//    if(match_flag)  return (end - start + 2 < res.size()) ? s.substr(start-1,end-start+1): res;
//    else    return "";
//}
//

string minWindow(string s, string t) {
    vector<int> map(128,0);
    for(auto c: t) map[c]++;
    int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
    while(end<s.size()){
        if(map[s[end++]]-->0) counter--; //in t
        while(counter==0){ //valid
            if(end-begin<d)  d=end-(head=begin);
            if(map[s[begin++]]++==0) counter++;  //make it invalid
        }
    }
    return d==INT_MAX? "":s.substr(head, d);
}


int main() {
    string xd("ADOBECODEBANC");
    string bruh("ABC");
    string res = minWindow(xd,bruh);
    cout << res << endl;
    return 0;
}
