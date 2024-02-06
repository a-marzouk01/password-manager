// Copyright 2024 emka

#include <iostream>
#include <fstream>
#include <string>

void findpass(std::string websiteName) {
  std::ifstream file;

  std::string password, mail;

  file.open("storage.txt");

  std::string input;
  while (std::getline(file, input)) {
    int pos = input.find(':');

    std::string foundWebsite = input.substr(0, pos);

    int pos2 = input.find(',');

    if (foundWebsite == websiteName) {
      password = input.substr(pos + 1, pos2 - pos - 1);
      mail = input.substr(pos2 + 1);
      break;
    }
  }
  file.close();
  std::cout << "Password for " << websiteName
    <<" is " << password
    <<" email is " << mail <<  std::endl;
}

void addpass(std::string websiteName, std::string password, std::string mail) {
  std::ofstream file;
  file.open("storage.txt", std::ios::app);

  file << websiteName << ":" << password << "," << mail << std::endl;
}

int main() {
  std::string choice;
  std::cout << "Do you want to find a password or add a new one or exit? (find/add/exit): ";
  std::cin >> choice;

  while (choice != "exit") {
    if (choice == "find") {
      std::string websiteName;
      std::cout << "Enter the website name: ";
      std::cin >> websiteName;
      findpass(websiteName);
    } else if (choice == "add") {
      std::string websiteName, password, mail;
      std::cout << "Enter the website name: ";
      std::cin >> websiteName;
      std::cout << "Enter the password: ";
      std::cin >> password;
      std::cout << "Enter the email: ";
      std::cin >> mail;
      addpass(websiteName, password, mail);
    } else if (choice == "exit") {
      std::cout << "cya later!" << std::endl;
      break;
    }
    std::cout << "Do you want to find a password or add a new one or exit? (find/add/exit): ";
    std::cin >> choice;
  }

  return 0;
}
