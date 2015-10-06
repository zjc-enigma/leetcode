/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. */

/* For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. */

/* Note: */
/* You must do this in-place without making a copy of the array. */
/* Minimize the total number of operations. */

#include <stdio.h>
#include <string.h>

void moveZeroes(int *nums, int numsSize) {
  int count = 0;
  int i, j;

  for(i=0; i<numsSize-count-1; i++){

    if(nums[i]==0){

      for(j=i; j<numsSize-count-1; j++){
        nums[j] = nums[j+1];
      }
      count++;
      i--;
    }
  }
  memset(nums+numsSize-count, 0, count*sizeof(int));
}

int main(void){

  //  int a[] = {0,1,0,3,5};

  //int a[]={4,2,4,0,0,3,0,5,1,0};
  int a[] = {0,1,0,3,12};
  moveZeroes(a, 5);
  for(int i=0; i<5; i++){printf("%d\n", a[i]);}
  return 0;
}
