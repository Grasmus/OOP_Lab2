//#define _CRT_SECURE_NO_WARNINGS
//#include "Readers.h"
//#include <iostream>
//#include <string.h>
//#include <fstream>
//#include <ctime>
//#include <math.h>
//
//
//
//Readers::Readers(/*std::string Name, std::string Surname, int day, int month, int year*/)
//{
//	this->head = new node;
//	this->curr = this->head;
//	std::cout << "Enter name of reader: ";
//	std::cin >> this->head->r.Name;
//	std::cout << "Enter surnamename of reader: ";
//	std::cin >> this->head->r.Surname;
//	std::cout << "Enter index of reader: ";
//	std::cin >> this->head->r.index;
//	/*std::cout << "Enter day of registration: ";
//	std::cin >> this->regDate.day;
//	std::cout << "Enter month of registration: ";
//	std::cin >> this->regDate.month;
//	std::cout << "Enter year of registration: ";
//	std::cin >> this->regDate.year;*/
//	std::time_t t = std::time(0);
//	std::tm* now = localtime(&t);
//	Date today{ now->tm_wday, now->tm_mon + 1, now->tm_year + 1900 };
//	this->head->r.regDate = today;
//	std::cout << "Enter number of subscriptions: ";
//	int n{};
//	std::cin >> n;
//	this->head->r.numOfSubs = n;
//	this->head->r.subsPubs = new int[n];
//	for (int i{}; i < n; i++)
//	{
//		/*std::cout << "Available publishers: \n"
//			"Enchanted Lion Books = 0\n"
//			"Soho Teen = 1\n"
//			"Farshore Books = 2\n"
//			"Joffe Books = 3\n"
//			"Berkley = 4\n"
//			"Seven Stories Press = 5\n"
//			"Puffin Books = 6\n"
//			"Page Street Publishing = 7\n"
//			"Drawnand Quarterly = 8\n";*/
//		readPublishers("Publishers.dat");
//		PubsNode* current = this->publis;
//		std::cout << "Available publishers: \n";
//		while (current)
//		{
//			std::cout << current->publisher.Name << " = " << current->publisher.index << std::endl;
//			current = current->next;
//		}
//		int p{};
//		std::cout << "Enter the index of publisher: ";
//		std::cin >> p;
//		this->head->r.subsPubs[i] = p;
//		system("cls");
//	}
//	calcFee(this->head->r.index);
//};
//
//void Readers::printName(int i)
//{
//	this->curr = this->head;
//	while (this->curr->next)
//	{
//		if (this->curr->r.index == i)
//		{
//			std::cout << this->curr->r.Name;
//			return;
//		}
//		else this->curr = this->curr->next;
//	}
//	std::cout << "There is no such user with index " << i << std::endl;
//}
//
//void Readers::printSurname(int i)
//{
//	this->curr = this->head;
//	while (this->curr->next)
//	{
//		if (this->curr->r.index == i)
//		{
//			std::cout << this->curr->r.Surname;
//			return;
//		}
//		else this->curr = this->curr->next;
//	}
//	std::cout << "There is no such user with index " << i << std::endl;
//}
//
//Date Readers::getRegdate(int i)
//{
//	this->curr = this->head;
//	while (this->curr->next)
//	{
//		if (this->curr->r.index == i)
//		{
//			return this->curr->r.regDate;
//		}
//		else this->curr = this->curr->next;
//	}
//	return { 0,0,0 };
//}
//
//void Readers::readPublishers(std::string name)
//{
//	PubsNode* current = this->publis;
//	PubsNode* temp;
//	Publishers tmp;
//	std::ifstream inf;
//	inf.open(name, std::ios::binary);
//	this->publis = new PubsNode;
//	current = this->publis;
//	if (inf.is_open())
//	{
//		while (!inf.eof())
//		{
//			inf >> tmp.index;
//			inf >> tmp.Name;
//			inf >> tmp.price;
//			current->publisher = tmp;
//			temp = current;
//			current->next = new PubsNode;
//			current = current->next;
//			current->prev = temp;
//		}
//		temp = current;
//		current = current->prev;
//		if (current) current->next = NULL;
//		delete(temp);
//		inf.close();
//	}
//	else std::cout << "Error reading file!";
//}
//
//int Readers::calcFee(int i)
//{
//	this->curr = this->head;
//	while (this->curr)
//	{
//		if (this->curr->r.index == i)
//		{
//			this->curr->r.fee = 0.0;
//			readPublishers("Publishers.dat");
//			PubsNode* current = this->publis;
//			for (int i{}; i < this->curr->r.numOfSubs && current; i++)
//			{
//				if (current->publisher.index == this->curr->r.subsPubs[i])
//				{
//					this->curr->r.fee += current->publisher.price;
//				}
//				current = current->next;
//			}
//			return 1;
//		}
//		else this->curr = this->curr->next;
//	}
//	std::cout << "There is no such user with index " << i << " in calcFee."<< std::endl;
//	return 0;
//}
//
//double Readers::getFee(int i)
//{
//	this->curr = this->head;
//	while (this->curr->next)
//	{
//		if (this->curr->r.index == i)
//		{
//			return this->curr->r.fee;
//		}
//		else this->curr = this->curr->next;
//	}
//	return 0;
//}
//
//void Readers::isBlacklisted(int i)
//{
//	this->curr = this->head;
//	while (this->curr->next)
//	{
//		if (this->curr->r.index == i)
//		{
//			switch (this->curr->r.isInBlackList)
//			{
//			case true:
//				std::cout << "User " << this->curr->r.Name << " " << this->curr->r.Surname << " " << "is in blacklist.";
//				break;
//			case false:
//				std::cout << "User " << this->curr->r.Name << " " << this->curr->r.Surname << " " << "is NOT in blacklist.";
//				break;
//			default:
//				break;
//			}
//			return;
//		}
//		else this->curr = this->curr->next;
//	}
//	std::cout << "There is no such user with index " << i << std::endl;
//}
//
//void Readers::checkFee(int i)
//{
//	this->curr = this->head;
//	while (this->curr->next)
//	{
//		if (this->curr->r.index == i)
//		{
//			std::time_t t = std::time(0);
//			std::tm* now = std::localtime(&t);
//			Date today{ now->tm_wday, now->tm_mon + 1, now->tm_year + 1900 };
//			Date nextPurchase = this->curr->r.lastPurchase;
//			Date overdue{};
//			nextPurchase.month++;
//			if (nextPurchase.year < today.year) {
//				overdue.year = today.year - nextPurchase.year;
//				overdue.month = fabs(today.month - nextPurchase.month);
//				if (today.day < nextPurchase.day)
//				{
//					overdue.day = nextPurchase.day - today.day;
//					overdue.month--;
//				}
//				else
//				{
//					overdue.day = today.day - nextPurchase.day;
//				}
//				this->curr->r.isInBlackList = true;
//				std::cout << this->curr->r.Name << " " << this->curr->r.Surname
//					<< " has an ovedue for: " << overdue.day << " days " << overdue.month
//					<< " month " << overdue.year << " years " << std::endl;
//			}
//			else if (nextPurchase.year == today.year)
//			{
//				overdue.year = 0;
//				if (today.month > nextPurchase.month)
//				{
//					overdue.month = today.month - nextPurchase.month;
//				}
//				if (today.day < nextPurchase.day)
//				{
//					overdue.day = nextPurchase.day - today.day;
//					overdue.month--;
//				}
//				else
//				{
//					overdue.day = today.day - nextPurchase.day;
//				}
//				this->curr->r.isInBlackList = true;
//				std::cout << this->curr->r.Name << " " << this->curr->r.Surname
//					<< " has an ovedue for: " << overdue.day << " days " << overdue.month
//					<< " month " << overdue.year << " years " << std::endl;
//			}
//			else
//			{
//				overdue = { 0, 0, 0 };
//				this->curr->r.isInBlackList = false;
//				std::cout << this->curr->r.Name << " " << this->curr->r.Surname << " doesn`t have ovedue" << std::endl;
//			}
//			return;
//		}
//		else this->curr = this->curr->next;
//	}
//	std::cout << "There is no such user with index " << i << std::endl;
//}
//
//void Readers::addNewReader()
//{
//	this->temp = new node;
//	std::cout << "Enter name of reader: ";
//	std::cin >> this->temp->r.Name;
//	std::cout << "Enter surnamename of reader: ";
//	std::cin >> this->temp->r.Surname;
//	std::cout << "Enter index of reader: ";
//	std::cin >> this->temp->r.index;
//	std::time_t t = std::time(0);
//	std::tm* now = std::localtime(&t);
//	Date today{ now->tm_wday, now->tm_mon + 1, now->tm_year + 1900 };
//	this->temp->r.regDate = today;
//	std::cout << "Enter number of subscriptions: ";
//	int n{};
//	std::cin >> n;
//	this->temp->r.numOfSubs = n;
//	this->temp->r.subsPubs = new int[n];
//	for (int i{}; i < n; i++)
//	{
//		PubsNode* current = this->publis;
//		std::cout << "Available publishers: \n";
//		while (current)
//		{
//			std::cout << current->publisher.Name << " = " << current->publisher.index << std::endl;
//			current = current->next;
//		}
//		current = this->publis;
//		int p{};
//		std::cout << "Enter the index of publisher: ";
//		std::cin >> p;
//		this->temp->r.subsPubs[i] = p;
//		system("cls");
//	}
//	calcFee(this->temp->r.index);
//	while (this->curr->next)
//	{
//		this->curr = this->curr->next;
//	}
//	this->curr->next = this->temp;
//	this->temp->next = NULL;
//	this->temp = NULL;
//}
//
//void Readers::removeReader(int i)
//{
//	this->curr = this->head;
//	while (this->curr->next)
//	{
//		if (this->curr->next->r.index == i)
//		{
//			this->temp = this->curr->next;
//			this->curr->next = this->curr->next->next;
//			delete(temp);
//			return;
//		}
//		else this->curr = this->curr->next;
//	}
//	std::cout << "There is no such user with index " << i << std::endl;
//}