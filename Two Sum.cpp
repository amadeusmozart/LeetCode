class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        for(vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); i++)
        {
            vector<int>::iterator j = find(numbers.begin(), numbers.end(), target - *i);
            if(j != numbers.end() && j != i)
            {
                if(j < i)
                {
                    v.push_back(j - numbers.begin() + 1);
                    v.push_back(i - numbers.begin() + 1);
                }
                else
                {
                    v.push_back(i - numbers.begin() + 1);
                    v.push_back(j - numbers.begin() + 1);
                }
            }
        }
        return v;
    }
};
