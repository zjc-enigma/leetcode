/* Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i]. */

/*     Solve it without division and in O(n). */

/* For example, given [1,2,3,4], return [24,12,8,6]. */

/* Follow up: */
/*                                        Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.) */
#include <stdio.h>
#include <stdlib.h>

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// a b c d e   f g h i
int* productExceptSelf2(int* nums, int numsSize, int* returnSize)
{

    int rSize;
    if(numsSize == 2) {
        int *res = (int *)malloc(sizeof(int)*2);
        res[0] = nums[1];
        res[1] = nums[0];
        *returnSize = 2;
        return res;
    }

    int *a = productExceptSelf2(nums, numsSize-1, &rSize);
    int *res = (int *)realloc(a, sizeof(int));
    res[numsSize-1] = a[numsSize-2]*nums[numsSize-2];
    int i;
    for(i=0; i<numsSize-1; i++){
        res[i] *= nums[numsSize-1];
    }

    *returnSize = numsSize;
    return res;
}


int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int i;
    int *res = (int *)malloc(sizeof(int)*numsSize);
    res[0] = 1;

    for(i=1; i<numsSize; i++){
        res[i] = res[i-1]*nums[i-1];
    }

    int tmp = 1;

    for(i=numsSize-2; i>=0; i--){
        tmp *= nums[i+1];
        res[i] *= tmp;
    }
    *returnSize = numsSize;

    return res;

}


int main(void)
{
    int a[] = {1,2,3,4};
    int s = 0;
    int *b = productExceptSelf(a, 4, &s);
    int i;
    for(i=0; i<s; i++){
        printf("%d\t", *(b+i));
    }
    return 0;
}
