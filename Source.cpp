
#include <iostream>
#include <fstream>
#include "Administrator.h"
//#include "Readers.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <ctime>



int main()
{
	Administrator admin;
	std::cout << "Create publishers (1) or load existing from file (2): ";
	int choice{};
	std::string name{};
	int n{};
	std::ifstream inf{};
	do
	{
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Enter num of publishers to add: ";
			std::cin >> n;
			admin.createPublishers(n, "Publishers.dat");  
			break;
		case 2:
			std::cout << "Enter name of file: ";
			std::cin >> name;
			admin.createPublishers(name);
			break;
		default:
			std::cout << "Enter 1 for first choice or 2 for second.";
			break;
		}
	} while (choice != 1 && choice != 2);
	system("cls");
	std::cout << "Recreate publishers (1)\nCreate first reader(2)\nAdd existing readers from the file (3)\n";
	do
	{
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Enter num of publishers to add: ";
			std::cin >> n;
			admin.createPublishers(n, "Publishers.dat");
			break;
		case 2:
			admin.createReaders();
			break;
		case 3:
			std::cout << "Enter name of file: ";
			std::cin >> name;
			admin.createReaders(name);
			break;
		default:
			std::cout << "Enter 1 for first choice or 2 for second.";
			break;
		}
	} while (choice != 1 && choice != 2 && choice != 3);
	system("cls");
	do
	{
		std::cout << "Recreate publishers (1)\nAdd new reader (2)\nMake a purchase (3)\nGet reader info (4)\nSave current readers (5)\nExit (6)\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Enter num of publishers to add: ";
			std::cin >> n;
			admin.createPublishers(n, "Publishers.dat");
			break;
		case 2:
			admin.addNewReaders();
			break;
		case 3:
			std::cout << "Enter index of reader: ";
			std::cin >> n;
			admin.makePurchase(n);
			break;
		case 4:
			std::cout << "Enter index of reader: ";
			std::cin >> n;
			admin.getReaderInfo(n);
			break;
		case 5:
			std::cout << "Enter name of file: ";
			std::cin >> name;
			admin.saveCurrentReaders(name);
			break;
		case 6:
			return 0;
		default:
			std::cout << "Enter valid choice.";
			break;
		}
		std::cout << "In switch" << std::endl;
		system("cls");
	} while (1);
	return 0;
}