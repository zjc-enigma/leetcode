/* Say you have an array for which the ith element is the price of a given stock on day i. */

/* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit. */
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
    if(!prices || pricesSize == 0 || pricesSize == 1){
        return 0;
    }

}



int main()
{
//    int stock[] = {1,2,-2,1,3,4,-8};
    int stock[] = {4,2,1};
    printf("%d\n",maxProfit(stock, 3));
    return 0;
}
