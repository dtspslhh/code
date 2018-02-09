/*
[1, 6, 3, 2, 5, 4, 7] return 4, because 1 3 5 7
DP solution. dp stores an array of hash_map. Every hash map stores the current position number's every differentiation with prior ones longest path.


*/

int longestArithmeticArray(vector<int> nums){
	int longest = 0, size = nums.size();
	if(size < 3) return size;
	vector<unordered_map<int,int>> dp(size);
	for(int i = 1; i < size; i++){
		for(int j = 0; j < i; j++){
			int diff = nums[i] - nums[j];
			dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
			//or dp[i][diff] = dp[j][diff] + 1; since later dp[j][diff] will be larger
			longest = max(longest, dp[i][diff]);
		}
	}
	return longest + 1;
}