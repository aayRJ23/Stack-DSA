// https://leetcode.com/problems/next-greater-element-i/description

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans;
        unordered_map<int, int> mp;

        stack<int> stk;
        stk.push(INT_MAX);

        for (int i = n2 - 1; i >= 0; i--) {
            while (stk.size() > 1 && nums2[i] > stk.top()) {
                stk.pop();
            }

            if (stk.top() == INT_MAX) {
                //    ans[i]=-1;
                mp[nums2[i]] = -1;
                stk.push(nums2[i]);
                continue;
            }

            //    ans[i]=stk.top();
            mp[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }

        // printing the ans array
        //    for(auto it:ans)
        //     cout<<it<<" ";

        //     return ans;

        for (int i = 0; i < n1; i++) {
            int curr = nums1[i];
            ans.push_back(mp[curr]);
        }
        return ans;
    }
};
