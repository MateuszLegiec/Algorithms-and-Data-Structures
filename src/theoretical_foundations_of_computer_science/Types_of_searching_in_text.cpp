#include <vector>
#include <string>

using namespace std;

void  knuth_morris_pratt(string text, string pattern){

   vector<int> indexes;
   vector<int> temp(pattern.size()+1,-1);

   for (int i = 0; i < pattern.size(); i++) {
      int pos = temp[i];
      while (pos != -1 && pattern[pos] != pattern[i])
          pos = temp[pos];
      temp[i+1] = pos + 1;
   }

   for(int i=0,j=0;i < text.size();) {
      while (j != -1 && (j == pattern.size() || pattern[j] != text[i]))
          j = temp[j];
      j++;
      i++;
      if (j == pattern.size())
         indexes.push_back(i - pattern.size());
      }

   return indexes;
}

void naive(string text, string pattern){

   for(int i=text.find(pattern);i!=string::npos;i=text.find(pattern,i+1))
            indexes.push_back(i);
   return indexes;
}


