#include "algorithm.h"

#include <algorithm>

void greedyPrice(std::vector<product> products, int backPackWeight){
    std::vector<product> result;

    //sort by weight
    std::sort(products.begin(), products.end(), [](product a, product b){
        return a.price > b.price;
    });

    //fill the backpack
    int currentWeight = 0;
    int i = 0;
    int backpackValue = 0;
    while(currentWeight < backPackWeight && i < products.size()){
        if(currentWeight + products[i].weight <= backPackWeight){
            result.push_back(products[i]);
            currentWeight += products[i].weight;
            backpackValue += products[i].price;
        }
        i++;
    }
    
    std::cout << "Wartosc plecaka: " << backpackValue << std::endl;
    std::cout << "Zabrane artefakty: " << std::endl;
    for(product p : result){
        std::cout << "\t - " << p.name << std::endl;
    }

}