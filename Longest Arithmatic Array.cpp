int longestArithmaticArray(vector<int> nums){
	int longest = 0, size = nums.size();
	if(size < 3) return size;
	vector<unordered_map<int,int>> dp(size);
	for(int i = 1; i < size; i++){
		for(int j = 0; j < i; j++){
			int diff = nums[i] - nums[j];
			dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
			longest = max(longest, dp[i][diff]);
		}
	}
	return longest + 1;
}