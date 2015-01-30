class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        const auto n = triangle.size();
        if(n==0) return 0;
        const auto m = triangle[0].size();
        
        for(auto i=1;i<n;++i)
            for(auto j=0;j<=i;++j)
            {
                if(j==0) triangle[i][j] += triangle[i-1][j];
                else if(j==i) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        
        return *std::min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};

