class Solution {
public: 
   bool repeatedSubstringPattern(string s) {
    string temp = s+s;
    temp = temp.substr(1,temp.size() -2);

    return temp.find(s) != sting::npos;
     
      }
};



