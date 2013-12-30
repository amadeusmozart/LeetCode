class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0;
        int count = 0;
        while(i < n)
        {
            if(i == n - 1)
                return true;
            if(i < n - 1 && A[i] == 0)
                return false;
            i = i + A[i];
        }
        return true;
    }
};
