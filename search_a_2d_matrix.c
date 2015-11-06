/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties: */

/* Integers in each row are sorted from left to right. */
/* The first integer of each row is greater than the last integer of the previous row. */
/* For example, */

/*     Consider the following matrix: */

/*     [ */
/*         [1,   3,  5,  7], */
/*         [10, 11, 16, 20], */
/*         [23, 30, 34, 50] */
/*         ] */
/*     Given target = 3, return true. */


#include<stdio.h>
#define TRUE 1
#define FALSE 0

bool searchMatrix(int **matrix,
                  int matrixRowSize,
                  int matrixColSize,
                  int target)
{
    if(!matrix || !*matrix){
        return FALSE;
    }
    int rowBegin = 0;
    int rowEnd = matrixRowSize - 1;

    while(rowBegin < rowEnd){

        int rowMid = (rowBegin + rowEnd)/2;

        if(matrix[rowMid][0] < target){
            rowBegin = rowMid + 1;

        } else if(matrix[rowMid][0] > target){
            rowEnd = rowMid - 1;

        } else {
            return TRUE;
        }
    }

    int colBegin = 0;
    int colEnd = matrixColSize - 1;
    while(colBegin < colEnd){
        int colMid = (colBegin + colEnd)/2;

        if(matrix[rowBegin][colMid] < target){
            colBegin = colMid + 1;

        } else if(matrix[rowBegin][colMid] > target){
            colEnd = colMid - 1;
        } else {
            return TRUE;
        }
    }
    return FALSE;
}

int main()
{


}
