// Time = O(n)
// Space = O(n)
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        
        unordered_map<int,int> m;
        
        for(auto i=0;i<nums.size();++i)
            m[nums[i]]=i;
        
        
        for(auto i=0;i<nums.size();++i)
        {
            const auto n = nums[i];
            const auto left = target - n;
            if(!m.count(left)) continue;
            
            if(n==left && i != m[left] || n!=left)
            {
                auto l = min(m[left], i);
                auto h = max(m[left], i);
                return vector<int>{l+1, h+1};
            }
        }
        
        return vector<int>{-1,-1};
    }
};

