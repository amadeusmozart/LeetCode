class Solution {
    vector<vector<int> > set;
    vector<int> v;
public:
    vector<vector<int> > permute(vector<int> &num) {
        perm(num, 0);
        return set;
    }
    void swap(vector<int>::iterator i, vector<int>::iterator j)
    {
        vector<int>::iterator tmp;
        tmp = i;
        i = j;
        j = tmp;
    }
    
    void perm(vector<int> &num,unsigned int i)
    {
        if(i == num.size() - 1)
        {
    		set.push_back(num);
    		return;
        }
    	else
    	{
    		unsigned int n = num.size();
    		for(unsigned int j = i; j < n; j++)
    		{
    			vector<int> tmp = num;
    			swap(num.begin() + i, num.begin() + j);
    			swap_ranges(num.begin() + j, num.end(), num.begin() + i);
    			perm(num, i + 1);
    			num = tmp;
    		}
    	}
    }
    
};
