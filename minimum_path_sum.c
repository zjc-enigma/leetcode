/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path. */

/*     Note: You can only move either down or right at any point in time. */

/*     Subscribe to see which companies asked this question */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(A,B) ((A) < (B) ? (A) : (B))
#define ROW 20
#define COL 20

int minPathSum(int **grid, int gridRowSize, int gridColSize)
{
    int i, j;
    int *t  = (int *)malloc(sizeof(int)*gridRowSize*gridColSize);
    memset(t, 65535, sizeof(int)*gridRowSize*gridColSize);

    int minSum = 0;
    t[0] = grid[0][0];
    for(i=1; i<gridColSize; i++){
        t[i] =  t[i-1] + grid[0][i];
    }

    t[gridColSize] = grid[0][0] + grid[1][0];


    for(i=1; i<gridRowSize; i++) {
        for(j=0; j<gridColSize; j++){
            int goRight = 65535;
            int goDown = 65535;

            if(j > 0) {
                goRight = t[i*gridColSize + (j-1)];
            }
            goDown = t[(i-1)*gridColSize + j];

            minSum = grid[i][j] + MIN(goDown, goRight);
            t[i*gridColSize + j] = minSum;
        }
    }

    return t[gridRowSize*gridColSize-1];
}



int minPathSumREC(int **grid, int gridRowSize, int gridColSize)
{

//    printf("%d\n", **(grid + gridColSize - 1));
//    printf("%d\n", *(*grid + 1));

    if(!grid){
        return 0;
    }
    if(gridRowSize == 1 && gridColSize == 1){
        return grid[0][0];
    }
    int moveDownSum;
    int moveRightSum;

    if(gridRowSize > 1){
        int *p = &grid[1][0];
        int **n = &p;
        moveDownSum = minPathSum(n,
                                 gridRowSize - 1,
                                 gridColSize);
    } else {
        moveDownSum = 65535;
    }

    if(gridColSize > 1){
        int *p = &grid[0][1];
        int **n = &p;
        moveRightSum = minPathSum(n,
                                  gridRowSize,
                                  gridColSize - 1);
    } else {
        moveRightSum = 65535;
    }

    int minSum = grid[0][0] + ((moveDownSum < moveRightSum)? moveDownSum : moveRightSum);
    return minSum;

}


int main()
{
    int **a;
    a = malloc(ROW * sizeof(*a));
    int k = 0;

    int i;
    for(i=0; i<ROW; i++){
        a[i] = malloc(COL*sizeof(*a[i]));
        int j;
        for(j=0; j<COL; j++){
            a[i][j] = k;
            k++;
        }
    }

    printf("%d\n", minPathSum(a, ROW, COL));
    return 0;
}
