#include <bits/stdc++.h>

using namespace std;
/*string presentChars;
string mulOccurence;
vector<int> charCount;
int Count(char c)
{
    int len=presentChars.length();
    int i;
    for(i=0; i<len; i++)
    {
      if(presentChars[i]==c)
      {
          charCount[i]++;
          break;
      }
    }
    if(i==len)
    {
        presentChars.push_back(c);
        charCount.push_back(1);
    }
    return 0;
}
int MulOc(char c)
{
    int len=mulOccurence.length();
    int i;
    for(i=0; i<len; i++)
    {
      if(mulOccurence[i]==c)
      {
          break;
      }
    }
    if(i==len)
    {
        mulOccurence.push_back(c);
    }
    return 0;
}
bool isPresentTwice(char c)
{
  for(int i=0; i<mulOccurence.length(); i++)
  {
    if(mulOccurence[i]==c)return 1;
  }
  return 0;
}
int twoCharaters(string s) {
    int i;
    int l=s.length();
    for(i=0; i<l; i++)
    {
        Count(s[i]);
        if(i!=l-1)
        {
           if(s[i]==s[i+1])
           {
               MulOc(s[i]);
           }
        }
    }
    for(i=0; i<presentChars.length(); i++)
    {
        cout<<presentChars[i]<<":"<<charCount[i]<<" ";
    }
    cout<<endl;
    for(i=0; i<mulOccurence.length(); i++)
    {
        cout<<mulOccurence[i]<<" ";
    }
    cout<<"removing mo "<<endl;
    string noTwice;
    for(i=0; i<l; i++)
    {
      if(!isPresentTwice(s[i]))
      {
        noTwice.push_back(s[i]);
      }
    }
    cout<<noTwice<<endl;
    return 0;
}*/
int twoChars(string s);
int main() {
    int l;
    //cin >> l;
    string s;
    cin >> s;
    int result = twoChars(s);
    //cout << result << endl;
    return 0;
}
int UnWantedPush(string *s,char c)
{
  int i;
  for(i=0; i<s->length(); i++)
  {
    if(c==(*s)[i])
    {
      return 1;
    }
  }
  if(i==s->length())
  {
    s->push_back(c);
  }
}
bool isPresentString(string s,char c)
{
  for(int i=0; i<s.length(); i++)
  {
    if(c==s[i])return 1;
  }
  return 0;
}
int twoChars(string s)
{
  vector<char>finalm1;
  string unWanted;
  int l=s.length();
  int i;
  finalm1.push_back(s[0]);
  bool unWantedFalg;
  do{for(i=1; i<l; i++)
  {
    unWantedFalg=0;
    if(isPresentString(unWanted,s[i]))
    {
      unWantedFalg=1;
      continue;
    }
    if(s[i]==finalm1[finalm1.size()-1])
    {
      unWantedFalg=1;
      finalm1.pop_back();
      UnWantedPush(&unWanted,s[i]);
    }
    else
    {
      finalm1.push_back(s[i]);
    }
    
  }}while(unWantedFalg);
  for(i=0; i<finalm1.size(); i++)
  {
    cout<<finalm1[i];
  }
}
