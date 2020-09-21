#include <iostream>
#include <vector>
using namespace std;


int getMaxProfit(vector<int> &stockPrices) {
    int minBuy = stockPrices[0];
    if (stockPrices.size() < 2) {
        throw invalid_argument("need 2")
    }

    int maxProfit = stockPrices[1] - stockPrices[0];
    for (int i = 1; i < stockPrices.size(); i++) {
        int currentPrice = stockPrices[i];
        int profit = currentPrice - minBuy;
        maxProfit =  profit > maxProfit ? profit : maxProfit;
        if (minBuy > currentPrice) {
            minBuy = currentPrice;
        }
    }
    return maxProfit;
}

int main(){

    vector<int> stockPrices{10, 7, 5, 8, 11, 9};
    vector<int> stockPrices2{3, 10, 2, 1, 1, 1};

    int max = getMaxProfit(stockPrices);
    cout << "max profit: " <<  max << "\n";
}

//8, 20, 2, 5