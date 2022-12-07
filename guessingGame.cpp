// Copyright (c) 2022 Marshall Demars All rights reserved

// Created by: Marshall Demars
// Created on: Nov 2022
// This program sees if you guess the right number using while true

#include <iostream>
#include <random>
#include <string>

int main() {
    // This program sees if you guess the right number using while true
    int guessAsInt;
    int randomNumber;
    std::string guessAsString;

    while (true) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(0, 9);
        randomNumber = idist(rgen);

        // Input
        std::cout << "\nEnter the number between 0-9: ";
        std::cin >> guessAsString;
        std::cout << std::endl;

        // Process and Output
        try {
            guessAsInt = std::stoi(guessAsString);
            if (guessAsInt == randomNumber) {
                std::cout << "\nYou guessed right." << std::endl;
                break;
            } else {
                std::cout << "\nYou guessed wrong, try again." << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "\nPlease enter a valid number." << std::endl;
        }
    }
    std::cout << "\nDone.";
}
