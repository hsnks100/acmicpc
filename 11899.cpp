#include <bits/stdc++.h>
using namespace std; 




int main()
{
     string t; 
     cin >> t; 

     deque<char> second;
     for(auto i : t){
          if(i == '('){
               second.push_back(i); 
          }
          else{
               if(second.empty() == false){
                    char p = second.back();
                    if(p == '('){
                         second.pop_back();
                    } 
                    else{
                         second.push_back(i);
                    }
               } 
               else{
                    second.push_back(i);
               }
          } 
     }
     cout << second.size() << endl;
     // for(auto i : second){
     //      if(step == 1){
     //           if(i == '(')
     //                step = 2;
     //      }

     //      if(step == 1){
     //      }
     //      else{
     //      }
     //      if(i == ')')
     //           top++;
     //      else{
     //           top = 0;
     //      }
          
     // }

     // for(auto i : second){
     //      cout << i << " ";
     // }

     return 0;
}
  
