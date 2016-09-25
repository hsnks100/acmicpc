#include <bits/stdc++.h>
using namespace std;

#define LIMIT(X, cmd) {static int __ = 0; if(__++ >= (X)) cmd;}


vector<int> computeLPSArray(string pat);

bool KMPSearch(string txt, string pat)
{
  int M = pat.size();
  int N = txt.size();

  int j  = 0;  // index for pat[]
  auto lps = computeLPSArray(pat);

  int i = 0;  // index for txt[]
  while (i < N)
  {
    if (pat[j] == txt[i])
    {
      j++;
      i++;
    }

    if (j == M)
    {
      //printf("Found pattern at index %d \n", i-j);
      j = lps[j-1];
      return true;
    }

    // mismatch after j matches
    else if (i < N && pat[j] != txt[i])
    {
      // Do not match lps[0..lps[j-1]] characters,
      // they will match anyway
      if (j != 0)
        j = lps[j-1];
      else
        i = i+1;
    }
  }
  return false;
}

vector<int> computeLPSArray(string pat)
{
  int M = pat.size();
  vector<int> pi(M, 0);
  int len = 0;  // length of the previous longest prefix suffix
  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      pi[i] = len;
      i++;
    }
    else {
      if (len != 0) {
        len = pi[len-1];
      }
      else {
        pi[i] = 0;
        i++;
      }
    }
  }
  return pi;
}

// Driver program to test above function
int main()
{
  //char *txt = (char*)"abracadabra";
  //char *pat = (char*)"dabr";
  //KMPSearch(pat, txt);

  //getline(cin, h);
  //getline(cin, n);
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int minBound = 0;
    int maxBound;
    int jumper = 1;

    do{
      jumper = 1;
      while(KMPSearch(a, string(b.begin(), b.begin() + minBound + jumper + 1))){
        jumper *= 2;
      }
      minBound = minBound + jumper / 2;
      maxBound = minBound + jumper - 1; 
      //printf("%d ~ %d\n", minBound, maxBound);
    }
    while(maxBound - minBound > 100);
    //printf("-----------\n");
    //return 0; 

    int firstWrongIndex = 0;
    for(int i=minBound; i<=maxBound; i++){
      if(KMPSearch(a, string(b.begin(), b.begin() + i + 1)) == false){
        firstWrongIndex = i;
        break;
      } 
    }
    string result = string(b.begin() + firstWrongIndex, b.end()) + 
      string(b.begin(), b.begin() + firstWrongIndex);
    firstWrongIndex %= b.size();
    if(result == a){
      printf("%d\n", firstWrongIndex);
    }
    else{
      printf("-1\n");
    }
    //cout << firstWrongIndex << endl; 
  }
  return 0;
}
