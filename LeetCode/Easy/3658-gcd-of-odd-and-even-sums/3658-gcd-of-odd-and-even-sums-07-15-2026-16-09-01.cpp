class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long  oddSum=0;
        long long evenSum=0;
        long long i=1;
        int  n1 = n;
        int  n2 = n;
        while(n1>0){
            if(i%2!=0){
                oddSum = oddSum+i;
                i=i+2;
            }
            n1--;
            
        }
        long long j = 2;
          while(n2>0){
            if(j%2==0){
                evenSum = evenSum+j;
                j=j+2;
            }
            n2--;
            
        }
        long long gcd =  __gcd(evenSum,oddSum);
        return gcd;
    }
};