int dominantIndex(int* nums, int numsSize) {
    int n=numsSize;
    int max=nums[0],maxIndex=0;
    for(int i=0;i<n;i++){
        if(nums[i]>max){
            max=nums[i];
            maxIndex=i;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=maxIndex && nums[i]*2 > max){
            return -1;
        }
    }
    return maxIndex;
}