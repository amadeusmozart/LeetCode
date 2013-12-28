/* Not the optimised solution, can be better, in single pass */

class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0, blue = 0, white = 0, i = 0;
        
        while(i < n) {
            if(A[i] == 0)
                red++;
            else if(A[i] == 1)
                white++;
            else
                blue++;
            i++;
        }
        i = 0;
        while(i < n) {
            if(i < red)
            {
                A[i] = 0;
            }
            else if(i >= red && i < white + red)
            {
                A[i] = 1;
            }
            else
                A[i] = 2;
            i++;
        }
    }
};
