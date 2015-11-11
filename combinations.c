/* Total Accepted: 58442 Total Submissions: 182729 Difficulty: Medium */
/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. */

/*     For example, */
/*     If n = 4 and k = 2, a solution is: */

/*     [ */
/*         [2,4], */
/*         [3,4], */
/*         [2,3], */
/*         [1,2], */
/*         [1,3], */
/*         [1,4], */
/*         ] */
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int calcFactorial(int x)
{
    if(x==1){
        return x;
    }

    return x*calcFactorial(x-1);
}



int calcReturnSize(int k, int n)
{
    return calcFactorial(n)/(calcFactorial(k)*calcFactorial(n-k));

}


int calcColumnSize()
{

//    return columnSize;
}

int** combine(int n, int k, int** columnSizes, int* returnSize)
{
    if(n < k || n < 0 || k < 0){
        *returnSize = 0;
        **columnSizes = 0;
        return NULL;
    }

    *returnSize = calcReturnSize(k, n);
    int** resMatrix = (int **)malloc(sizeof(*int)*(*returnSize));
    **columnSizes = k;

    int i;
    for(i=0; i<*resturnSize; i++){
        *resMatrix = (int *)malloc(sizeof(int)*(**columnSizes));
    }
    int e = 0;

    while(e < k){
        for(i=0; i<n; i++){

        }
        e++;
    }

    return resMatrix;
}

int main()
{

//    printf("%d\n", calcReturnSize(1,10));

    return 0;
}
