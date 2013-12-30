class Solution {
public:

    bool GetUnassignedCell(vector<vector<char> > & v, int& row, int& col) {
    	for (row = 0; row < 9; row++)
            for (col = 0; col < 9; col++)
                if (v[row][col] == '.') return true;
        return false;
    }
    
    bool notUsedInRow(vector<vector<char> >& v, int row, char val){
    	for(int i = 0; i < 9; i++) {
    		if(v[row][i] == val)
    			return false;
    	}
    	return true;
    }
    
    bool notUsedInColumn(vector<vector<char> >& v, int col, char val){
    	for(int i = 0; i < 9; i++) {
    		if(v[i][col] == val)
    			return false;
    	}
    	return true;
    }
    
    bool notUsedInGrid(vector<vector<char> >& v, int row, int col, char val){
    	int sr = (row / 3) * 3, er = ((row / 3) * 3 + 2), sc = ((col / 3) * 3), ec= ((col / 3) * 3 + 2);
    	for(int i = sr; i <= er; i++) {
    		for(int j = sc; j <= ec; j++ ){
    			if(v[i][j] == val)
    				return false;
    		}
    	}
    	return true;
    }
    bool isValid(vector<vector<char> >& v, int row, int col, char val) {
    	return notUsedInRow(v, row, val) && notUsedInColumn(v, col, val) && notUsedInGrid(v, row, col,val);
    }
    
    bool ss(vector<vector<char> > &board){
        int row, col;
    	
    	if(!GetUnassignedCell(board, row, col))	return true;
    	
    	for(int i = 1; i <= 9; i++){
    		if(isValid(board, row, col, '0' + i)){
    			board[row][col] = '0' + i;
    			if(ss(board))	return true;
    			board[row][col] = '.';
    		}
    	}
    	return false;
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        ss(board);
    }
};
