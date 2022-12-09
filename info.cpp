// Copyright (c) 2022 Marshall Demars All rights reserved

// Created by: Marshall Demars
// Created on: Dec 2022
// This program formats someones address using Canada Post format

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

std::string address(std::string fullName,
                    std::string streetNumber,
                    std::string streetName,
                    std::string city,
                    std::string province,
                    std::string postalCode,
                    std::string apartmentNumber = "") {
    // return the address properly formatted
    std::string proper;

    proper = fullName + "\n";
    if (apartmentNumber != "") {
        proper = proper + apartmentNumber + "-";
    }
    proper = proper + streetNumber;
    proper = proper + " " + streetName + "\n";
    proper = proper + city + " ";
    proper = proper + province + "  ";
    proper = proper + postalCode;

    std::for_each(proper.begin(),
                  proper.end(), [](char& c) { c = ::toupper(c); });

    return proper;
}

bool isItaNumber(std::string strOrNum) {
    // Help from Derek Pilat (My Uncle)
    for (int element = 0; element < strOrNum.length(); element++) {
        if (isdigit(strOrNum[element]) == false) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    // gets a users name and prints out their formal name
    std::string fullName;
    std::string question;
    std::string apartmentNumber = "";
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string properAddress;

    // input
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);
    std::cout << "\nDo you live in an apartment? (y/n): ";
    std::getline(std::cin, question);
    std::cout << "" << std::endl;
    if (question == "y") {
        std::cout << "\nEnter your apartment number: ";
        std::getline(std::cin, apartmentNumber);
    }
    std::cout << "\nEnter your street number: ";
    std::getline(std::cin, streetNumber);
    std::cout << "\nEnter your street name and type (Pleasant prkw...): ";
    std::getline(std::cin, streetName);
    std::cout << "\nEnter your city: ";
    std::getline(std::cin, city);
    std::cout << "\nEnter your province (as an abbreviation, ex: ON, BC...): ";
    std::getline(std::cin, province);
    std::cout << "\nEnter your postal code (ABC 123): ";
    std::getline(std::cin, postalCode);

    try {
        if (!(isItaNumber(streetNumber))) {
            std::cout << streetNumber << " is not a valid street number"
                << std::endl;
            throw std::invalid_argument("not a number\n");
        }
        std::cout << "\n"
                  << std::endl;

        if (apartmentNumber != "") {
            if (!(isItaNumber(apartmentNumber))) {
                std::cout << apartmentNumber << ", invalid apartment number"
                    << std::endl;
                throw std::invalid_argument("not a number\n");
            }
            properAddress = address(fullName, streetNumber, streetName, city,
                                    province, postalCode, apartmentNumber);
        } else {
            properAddress = address(fullName, streetNumber, streetName, city,
                                    province, postalCode);
        }
        std::cout << properAddress << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "\nInvalid Input." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
