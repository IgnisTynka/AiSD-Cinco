#include "product.h"
#include "algorithm.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <fstream>

int main() {
    srand(time(NULL));

    story();

    std::string names[] = {
        "Mlot Thor'a",
        "Kostuim Spider-Mana",
        "Tarcza Kapitana Ameryki",
        "Maska Iron Mana",
        "Luk Hawkeye'a",
        "Kamien Czasu",
        "Kamien Mocy",
        "Kamien Rzeczywistosci",
        "Kamien Przestrzeni",
        "Kamien Duszy",
        "Kamien Umyslu",
        "Karta czlonkowska S.H.I.E.L.D.",
        "Karta czlonkowska Avengers",
        "Tesseract",
        "Komunikator Kapitan Marvel",
        "Serum Super-Zolnierza",
        "Kostium Ant-Mana",
        "Opaska na oko Nicka Fury'ego",
        "Goose",
        "Oko Agamotto",
        "Kostium Czarnej Pantery",
        "Vibranium",
        "Super Tajne Notatki Tony'ego Starka",
        "Urzadzenie z Pajeczyna Spider-Mana",
        "Rozerwana koszula Hulka",
        "Czesc zapasowa silnika Helicarriera",
    };


    printf("\t\t\t\t\033[34m -=-=-=-=-=-=-=-=-=-=-=-=-= DANE PROBLEMU =-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m\n\n");

    //choose random backpack weight
    int backPackWeight = (rand() % 1000) + 100;
    std::cout <<"Pojemność plecaka: " << backPackWeight << std::endl;

    //generate products (name from array, random weight and price)
    std::vector<product> products = generateProducts(names, backPackWeight);
    std::cout << "Lista artefaktów: " << std::endl;
    for(product p : products){
        std::cout << "\t" << std::left << std::setw(40) << p.name << " Waga: " << std::setw(10) << p.weight << " Wartosc: " << std::setw(10) << p.price << std::endl;
    }

    //products price and weight to file
    std::fstream file("products.txt", std::ios::out);

    if(file.is_open()){
        file << backPackWeight << std::endl;
        file << products.size() << std::endl;
        for(product p : products){
            file << p.price << " " << p.weight << std::endl;
        }
        file.close();
    }

    printf("\n\t\t\t\t\033[34m -=-=-=-=-=-=-=-=-=-=-=-=-=  PRÓBY ROZWIĄZANIA =-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m\n\n");
    
    std:: cout << "Próba 1. Algorytm zachlanny sortowanie po wadze:" << std::endl;
    greedyWeight(products, backPackWeight);

    std:: cout << "\nPróba 2. Algorytm zachlanny sortowanie po wartosci:" << std::endl;
    greedyPrice(products, backPackWeight);

    std:: cout << "\nPróba 3. Algorytm zachlanny sortowanie po stosunku wartosci do wagi:" << std::endl;
    greedyRatio(products, backPackWeight);

    std:: cout << "\nPróba 4. Algorytm dynamiczny:" << std::endl;
    dynamic(products, backPackWeight);

    endstory();

    return 0;
}