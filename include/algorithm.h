#include "product.h"

#include <iostream>
#include <vector>

void story();
void endstory();
std::vector<product> generateProducts(std::string names[], int backpacSsize);

//greedy weight
void greedyWeight(std::vector<product> products, int backPackWeight);

//greedy price
void greedyPrice(std::vector<product> products, int backPackWeight);

//greedy ratio
void greedyRatio(std::vector<product> products, int backPackWeight);

//dynamic
void dynamic(std::vector<product> products, const int backPackWeight);
