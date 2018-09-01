#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string a){
    char prev=a[0];
    string k;
    int j=0;
    k.push_back(prev);
    for(int i=1; i<a.size(); i++)
    {
      if(k.size()!=0&&k[k.size()-1]==a[i])
      {
        k.pop_back();
        //i++;
        prev=a[i];
      }
      else
      {
        k.push_back(a[i]);
      }
      prev=a[i];
    }
    return k;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
