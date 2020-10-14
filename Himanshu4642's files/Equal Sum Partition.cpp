/*The question is similar to subset sum problem.*/

bool EqualSumPartition(int arr[],n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	if((sum/n)%2!=0){
		return false;
	}else{
		return subsetSum(arr,sum/2,n);
	}
}
