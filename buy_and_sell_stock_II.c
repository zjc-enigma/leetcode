/* Say you have an array for which the ith element is the price of a given stock on day i. */

/* Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). */

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int maxProfit(int* prices, int pricesSize) {

  int hasStock = FALSE;
  int prevPrice = prices[0];
  int profit = 0;
  int i;

  for(i=1; i<pricesSize; i++){
    if(hasStock) {

      if(prices[i] < prevPrice) {
        hasStock = FALSE;
      }
      else{
        profit += prices[i] - prevPrice;
      }
    } else {

      if(prices[i] > prevPrice) {
        hasStock = TRUE;
        profit += prices[i] - prevPrice;
      }
      else {

      }
    }
    prevPrice = prices[i];
  }
  return profit;
}

int main(void) {

  int stockPrice[] = { 1, 5, 3, 2, 8};
  int p = maxProfit(stockPrice, 5);
  printf("%d\n", p);
  return 0;
}
