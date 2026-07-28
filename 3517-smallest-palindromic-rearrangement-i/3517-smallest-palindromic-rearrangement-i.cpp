class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length()==1)
        return s;
        int n = s.length();
        int mid = s.length()/2;
        sort(begin(s),begin(s)+mid);
        for(int i=0;i<mid;i++){
            s[n-i-1] = s[i];
        }
        return s;
    }
};