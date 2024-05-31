#include "algorithm.h"

void dynamic(std::vector<product> products, int backPackWeight){
    int n = products.size();
    std::vector<std::vector<int>> K(n+1, std::vector<int>(backPackWeight+1));
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= backPackWeight; w++){
            if(i == 0 || w == 0){
                K[i][w] = 0;
            } else if(products[i-1].weight <= w){
                K[i][w] = std::max(products[i-1].price + K[i-1][w-products[i-1].weight], K[i-1][w]);
            } else {
                K[i][w] = K[i-1][w];
            }
        }
    }

    int res = K[n][backPackWeight];
    std::cout << "Wartość plecaka: " << res << std::endl;
    std::cout << "Zabrane artefakty: " << std::endl;
    int w = backPackWeight;
    for(int i = n; i > 0 && res > 0; i--){
        if(res == K[i-1][w]){
            continue;
        } else {
            std::cout << "\t - " << products[i-1].name << std::endl;
            res -= products[i-1].price;
            w -= products[i-1].weight;
        }
    }
}