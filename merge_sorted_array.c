/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array. */

/*     Note: */
/*     You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively. */

/*         Subscribe to see which companies asked this question */



#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n)
{

    if(!nums1 || !nums2){
        return;
    }
    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    while(i>=0 && j>=0){

        if(nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        } else{
            nums1[k--] = nums2[j--];
        }
    }

    if(i>0){
        while(i>=0){
            nums1[k--] = nums1[i--];
        }
    } else{
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
}




int main()
{

    int arr1[] = {1,0,0,0};
    int arr2[] = {1};

    merge(arr1,1,arr2,1);

    int i;
    for(i=0;i<7;i++){
        printf("%d\t", arr1[i]);
    }

    return 0;
}
