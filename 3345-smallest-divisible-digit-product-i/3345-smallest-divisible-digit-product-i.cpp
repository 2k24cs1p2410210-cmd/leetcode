class Solution {
public:
    int smallestNumber(int n, int t) {
        // int p = n;
        for(int i=n; ;i++){
             int prod = 1;
             int p = i;
            while(p!=0){
                int rem = p%10;
                prod = prod*rem;
                p = p/10;
            }
            if(prod%t==0){
            return i;
            }
        }
        return 0;
    }
};