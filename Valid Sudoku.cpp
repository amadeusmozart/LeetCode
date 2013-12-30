class Solution {
public:
    
    bool notUsedInRow(vector<vector<char> >& v, int row,int col, char val){
    	for(int i = 0; i < 9; i++) {
    		if(i != col && v[row][i] == val)
    			return false;
    	}
    	return true;
    }
    
    bool notUsedInColumn(vector<vector<char> >& v,int row, int col, char val){
    	for(int i = 0; i < 9; i++) {
    		if(i != row && v[i][col] == val)
    			return false;
    	}
    	return true;
    }
    
    bool notUsedInGrid(vector<vector<char> >& v, int row, int col, char val){
    	int sr = (row / 3) * 3, er = ((row / 3) * 3 + 2), sc = ((col / 3) * 3), ec= ((col / 3) * 3 + 2);
    	for(int i = sr; i <= er; i++) {
    		for(int j = sc; j <= ec; j++ ){
    			if(i != row && j != col && v[i][j] == val)
    				return false;
    		}
    	}
    	return true;
    }
    bool isValid(vector<vector<char> >& v, int row, int col, char val) {
    	return notUsedInRow(v, row,col, val) && notUsedInColumn(v,row, col, val) && notUsedInGrid(v, row, col,val);
    }
    
    bool isValidSudoku(vector<vector<char> > &board){
    	
    	for(int i = 0; i < 9; i++){
    		for(int j = 0; j < 9; j++) {
    		    if(board[i][j] == '.' || (board[i][j] != '.'  && isValid(board, i, j, board[i][j])))
    		        continue;
    		    else
    		        return false;
    		}
    	}
    	return true;
    }
};
