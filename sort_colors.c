/* Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue. */

/*     Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. */

/*     Note: */
/*     You are not suppose to use the library's sort function for this problem. */

/* click to show follow up. */

/* Follow up: */
/* A rather straight forward solution is a two-pass algorithm using counting sort. */
/* First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's. */

/* Could you come up with an one-pass algorithm using only constant space? */



#include <stdio.h>
#define SWAP(A, B) \
    do{            \
        int t;     \
        t = (A);   \
        (A) = (B); \
        (B) = t;   \
    }while(0)      \



void sortColors(int* nums, int numsSize)
{
    int left = -1;
    int right = numsSize;
    int mid_left = numsSize/2;
    int mid_right = numsSize/2;

    while(left < right){
        while(nums[++left] == 0);
        while(nums[--right] == 2);

        if(nums[left] == 1 && nums[right] == 1){
            SWAP(nums[left++], nums[--mid_left]);
            SWAP(nums[right++], nums[++mid_right]);

        } else if(nums[left] == 2 && nums[right] == 1){
            SWAP(nums[left++], nums[right]);

        } else if(nums[left] == 2 && nums[right] == 0){
            SWAP(nums[left], nums[right]);

        } else if(nums[left] == 1 && nums[right] == 0) {
            SWAP(nums[left], nums[right]);
        }
            // 1. nums[left] == 1 nums[right] == 1
            // 2. nums[left] == 2 nums[right] == 1
            // 3. nums[left] == 2 nums[right] == 0 : swap
            // 4. nums[left] == 1 nums[right] == 0 : swap
    }
}

void sortColors_(int* nums, int numsSize)
{

    if(!nums || numsSize <= 0){
        return ;
    }

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    int i;
    for(i=0; i<numsSize; i++){
        switch(nums[i]){
            case 0:
                count0++;
                break;

            case 1:
                count1++;
                break;

            case 2:
                count2++;
                break;
            default:
                break;
        }
    }
    for(i=0;i<numsSize; i++){
        if(count0) {
            nums[i] = 0;
            count0--;

        } else if(count1){
            nums[i] = 1;
            count1--;
        } else {
            nums[i] = 2;
            count2--;
        }
    }
}


int main()
{
    int arr[] = { 0,2,1,2,1,1,0,0,1};
    sortColors(arr, 9);
    int i;
    for(i=0;i<9;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
