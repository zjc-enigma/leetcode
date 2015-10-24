/* given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. */

/*     You may assume no duplicates in the array. */

/*     Here are few examples. */
/*     [1,3,5,6], 5 → 2 */
/*     [1,3,5,6], 2 → 1 */
/*     [1,3,5,6], 7 → 4 */
/*     [1,3,5,6], 0 → 0 */

#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target)
{
    if(!nums){
        return 0;
    }

    int left = 0;
    int right = numsSize - 1;
    while(left < right){

        int mid = (left + right)/2;

        if(target < nums[mid]){
            right = mid - 1;
        }
        else if(target > nums[mid]){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }
        // target between left & right
    if(target > nums[left]){
        return left + 1;
    }
    else {
        return left;
    }
}



int main()
{
    int arr[] = {1,3,5,6};
//    printf("%d\n", searchInsert(arr, 1, 2));
   printf("%d\n", searchInsert(arr, 4, 2));
   printf("%d\n", searchInsert(arr, 4, 7));
   printf("%d\n", searchInsert(arr, 4, 0));

    return 0;
}
