#include "product.h"
#include "algorithm.h"

#include <iostream>
#include <vector>
#include <ctime>

int main() {
    srand(time(NULL));

    story();

    std::string names[] = {
        "Młot Thor'a",
        "Kostuim Spider-Mana",
        "Tarcza Kapitana Ameryki",
        "Maska  Iron Mana",
        "Łuk Hawkeye'a",
        "Kamień Czasu",
        "Kamień Mocy",
        "Kamień Rzeczywistości",
        "Kamień Przestrzeni",
        "Kamień Duszy",
        "Kamień Umysłu",
        "Karta członkowska S.H.I.E.L.D.",
        "Karta członkowska Avengers",
        "Tesseract",
        "Komunikator Kapitan Marvel",
        "Serum Super-Żołnierz",
        "Kostium Ant-Mana",
        "Opaska na oko Nicka Fury'ego",
        "Goose",
        "Oko Agamotto",
        "Kostium Czarnej Pantery",
        "Vibranium",
        "Super Tajne Notatki Tony'ego Starka",
        "Urządzenie z Pajęczyną Spider-Mana",
        "Rozerwana koszula Hulka",
        "Część zapasowa silnika Helicarriera",
    };


    printf("\t\t\t\t\033[34m -=-=-=-=-=-=-=-=-=-=-=-=-= DANE PROBLEMU =-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m\n\n");

    int backPackWeight = (rand() % 1000) + 100;
    std::cout <<"Pojemność plecaka: " << backPackWeight << std::endl;

    std::vector<product> products = generateProducts(names, backPackWeight);
    std::cout << "Lista artefaktów: " << std::endl;
    for(int i = 0; i < products.size(); i++){
        std::cout << products[i].name << " - wartość: " << products[i].price << ", waga: " << products[i].weight << std::endl;
    }


    printf("\n\t\t\t\t\033[34m -=-=-=-=-=-=-=-=-=-=-=-=-=  PRÓBY ROZWIĄZANIA =-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m\n\n");
    
    std:: cout << "Próba 1. Algorytm zachłanny sotowanie po wadze:" << std::endl;
    greedyWeight(products, backPackWeight);

    std:: cout << "\nPróba 2. Algorytm zachłanny sotowanie po wartosci:" << std::endl;
    greedyPrice(products, backPackWeight);

    std:: cout << "\nPróba 3. Algorytm zachłanny sotowanie po stosunku wartosci do wagi:" << std::endl;
    greedyRatio(products, backPackWeight);

    std:: cout << "\nPróba 4. Algorytm dynamiczny:" << std::endl;
    dynamic(products, backPackWeight);

    endstory();

    return 0;
}