#include "algorithm.h"

#include <iostream>

std::vector<product> generateProducts(std::string names[], int backpacSsize){
    std::vector<product> products;

    //because you are not worthy to lift the hammer
    products.push_back(product{names[0], (rand() % (backpacSsize - 100)) , backpacSsize + 1});

    for(int i = 1; i < 25; i++){
        product p;
        p.name = names[i];
        p.price = rand() % (backpacSsize / 5) + 1;
        p.weight = rand() % (backpacSsize / 5) + 1;
        products.push_back(p);
    }
    return products;
}