/* Find the contiguous subarray within an array (containing at least one number) which has the largest sum. */

/*     For example, given the array [−2,1,−3,4,−1,2,1,−5,4], */
/*     the contiguous subarray [4,−1,2,1] has the largest sum = 6. */

/*     click to show more practice. */

/*     More practice: */
/*                                                                                If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle. */
#include<stdio.h>
int maxSubArray(int* nums, int numsSize)
{
    if(!nums || numsSize == 0)
        return 0;

    int i;
    int maxLeft = 0;
    int maxRight = numsSize - 1;
    int sum = 0;

    for(i=0;i<numsSize;i++){
        sum += nums[i];
    }
    int max = sum;
    for(i=0;i<numsSize;i++){
        sum -= nums[i];
        if(sum > max){
            maxLeft = i + 1;
            max = sum;
        }
    }
    sum = max;

    for(i=numsSize-1;i>=0;i--){
        sum -= nums[i];
        if(sum > max){
            maxRight = i - 1;
            max = sum;
        }
    }
    sum = 0;

    for(i=maxLeft;i<=maxRight;i++){
        sum += nums[i];
    }

    return sum;
}

int main()
{
//    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int a[]={-1};


    printf("%d\n", maxSubArray(a, 1));


    return 0;
}
