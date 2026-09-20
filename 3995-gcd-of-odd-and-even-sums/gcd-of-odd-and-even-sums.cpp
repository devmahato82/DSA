class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=1;
        int evenSum=2;
        int odd=1;
        int even =2;
        for(int i=1;i<n;i++) {
            odd = odd+2;
            sumOdd += odd;
            even = even+2;
            evenSum +=even;
        }

        while(evenSum != 0) {
            int temp = evenSum;
            evenSum = sumOdd%evenSum;
            sumOdd = temp;
        }
        return sumOdd;
    }
};