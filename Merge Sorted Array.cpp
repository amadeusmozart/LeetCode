class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(m == 0 && n == 0)
            return;
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while(i >= 0 && j >= 0)
        {
            if(A[i] > B[j])
            {
                A[k] = A[i];
                i--;
            }
            else if(B[j] >= A[i])
            {
                A[k] = B[j];
                j--;
            }
            k--;
        }
        
        while(i >= 0)
        {
            A[k--] = A[i--];
        }
        while(j >= 0)
            A[k--] = B[j--];
        
        
    }
};
