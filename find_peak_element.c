/* A peak element is an element that is greater than its neighbors. */

/* Given an input array where num[i] ≠ num[i+1], find a peak element and return its index. */

/*     The array may contain multiple peaks, in that case return the index to any one of the peaks is fine. */

/*     You may imagine that num[-1] = num[n] = -∞. */

/*     For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2. */

/*     click to show spoilers. */

/*     Note: */
/*     Your solution should be in logarithmic complexity. */

/*     Credits: */
/*     Special thanks to @ts for adding this problem and creating all test cases. */

/*     Subscribe to see which companies asked this question */

/*     Show Tags */

#include<stdio.h>

int findPeakElement(int* nums, int numsSize)
{

    if(!nums || numsSize <= 0){
        return -1;
    }

    int left = 0;
    int right = numsSize-1;

    while(left < right){
        int mid = (left + right)/2;
            //peak in left - mid
        if(nums[mid] > nums[mid+1]){
            right = mid - 1;
        }
            //peak in mid + 1 - right
        else {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    int array[] = {1, 2, 3, 1};
    int ret = findPeakElement(array, 4);
    printf("%d\n", ret);
    return 0;
}
