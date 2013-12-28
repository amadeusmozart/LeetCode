class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        unsigned int i = 0;
        
        int arrsize = matrix[0].size();
        while(i < matrix.size())
        {
            if(matrix[i][arrsize - 1] < target)
                i++;
            else
                break;
            
        }
        if(i == matrix.size())
			return false;
			
        int low = 0, high = arrsize - 1, mid;
        
        while(low <= high){
            mid = ( low + (high - low) / 2) ;
            if(matrix[i][mid] > target)
                high = mid - 1;
            else if(matrix[i][mid] < target)
                low = mid + 1;
            else
                return true;
        }
        
        return false;
    }
};
