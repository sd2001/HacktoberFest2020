vector<int> SubsetSum(int arr[],int range,int n){
	int dp[n+1][range+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=range;j++){
			if(i==0 && j==0)
			dp[i][j]=true;
			else if(i==0)
			dp[i][j]=false;
			else if(j==0)
			dp[i][j]=true;
			else{
				if(arr[i-1]<=j)
				dp[i][j]=(dp[i-1][j-arr[i-1]])||(dp[i-1][j]);
				else
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	vector<int> ans;
	for(int j=0;j<=range/2;j++){
		if(dp[n][j])
		ans.push_back(j);
	}
	return ans;
}

int minimumSubsetSumDiff(int arr[],int n){
	int range=0;
	for(int i=0;i<n;i++) range+=arr[i];
	vector<int> req=SubsetSum(arr,range,n);
	int ans=INT_MAX;
	for(int i=0;i<req.size();i++){
		ans=min(ans,range-2*req[i]);
	}
	return ans;
}

