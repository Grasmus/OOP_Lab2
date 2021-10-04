#define _CRT_SECURE_NO_WARNINGS
#include "Reader.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include <math.h>

Reader::Reader(PubsNode* pp)
{
	this->publis = pp;
	std::cout << "Enter name of reader: ";
	std::cin >> this->r.Name;
	std::cout << "Enter surnamename of reader: ";
	std::cin >> this->r.Surname;
	std::cout << "Enter index of reader: ";
	std::cin >> this->r.index;
	std::time_t t = std::time(0);
	std::tm* now = localtime(&t);
	int day = now->tm_wday + 3;
	Date today{  day, now->tm_mon + 1, now->tm_year + 1900 };
	this->r.regDate = today;
	this->r.paidFor = today;
	PubsNode* current = this->publis;
	int iter{};
	int n{};
	while (current)
	{
		current = current->next;
		iter++;
	}
	while (n <= 0 || n >= iter)
	{
		std::cout << "Enter number of subscriptions: ";
		std::cin >> n;
		if (n <= 0 || n >= iter) std::cout << "Enter valid number!" << std::endl;
	}
	this->r.numOfSubs = n;
	this->subsPubs = new int[n];
	current = this->publis;
	int j{};
	int* tmp = new int[iter];
	while (current)
	{
		tmp[j] = current->publisher.index;
		j++;
		current = current->next;
		
	}
	/*for (int k{}; k < j; k++)
	{
		std::cout << tmp[k] << '\t';
	}*/
	int p{};
	bool isValid{false};
	for (int i{}; i < n; i++)
	{
		isValid = false;
		PubsNode* current = this->publis;
		std::cout << "Available publishers: \n";
		while (current)
		{
			std::cout << current->publisher.Name << " = " << current->publisher.index << '\t' << "price: " << current->publisher.price << std::endl;
			current = current->next;
		}
		while (!isValid)
		{
			std::cout << "Enter the index of publisher: ";
			std::cin >> p;
			for (int k{}; k < j; k++)
			{
				if (p == -1){std::cout << "Enter valid number!" << std::endl; break;}
				else if (tmp[k] == p) { tmp[k] = -1;  isValid = true; break;
				}
			}
			if (isValid) break;
			else
				std::cout << "Enter valid number!" << std::endl;
		}
			
		
		this->subsPubs[i] = p;
		system("cls");
	}
	calcFee();
}

Reader::Reader(Data r, PubsNode* pp)
{
	this->r = r;
	this->publis = pp;
}


void Reader::calcFee()
{
	this->r.fee = 0.0;
	PubsNode* current = this->publis;
	for (int i{}; i < this->r.numOfSubs && current; i++)
	{
		if (current->publisher.index == this->subsPubs[i])
		{
			this->r.fee += current->publisher.price;
		}
		current = current->next;
	}
}

std::string Reader::printName()
{
	return this->r.Name;
}

std::string Reader::printSurname()
{
	return this->r.Surname;
}

Date Reader::getRegDate()
{
	return this->r.regDate;
}

Data Reader::getData()
{
	return this->r;
}

//void Reader::readPublishers(PubsNode* pp)
//{
//	//std::ifstream inf{};
//	//inf.open(name);
//	//this->publis = new PubsNode;
//	//this->publis->prev = NULL;
//	//PubsNode* current = this->publis;
//	//PubsNode* temp{};
//	//Publishers tmp;
//	//if (inf.is_open())
//	//{
//	//	while (!inf.eof())
//	//	{
//	//		//inf.read((char*)&current->publisher, sizeof(Publishers));
//	//		inf >> current->publisher.Name;
//	//		inf >> current->publisher.index;
//	//		inf >> current->publisher.price;
//	//		if (!inf.eof()) {
//	//			temp = current;
//	//			current->next = new PubsNode;
//	//			current = current->next;
//	//			current->prev = temp;
//	//		}
//	//	}
//	//	inf.close();
//	//	delete current->next;
//	//	current->next = nullptr;
//	//}
//	//else std::cout << "Error reading file!";
//	this->publis = pp;
//}

double Reader::getFee()
{
	return this->r.fee;
}

void Reader::isBlacklisted()
{
	switch (this->r.isInBlackList)
	{
	case true:
		std::cout << "User " << this->r.Name << " " << this->r.Surname << " " << "is in blacklist.";
		break;
	case false:
		std::cout << "User " << this->r.Name << " " << this->r.Surname << " " << "is NOT in blacklist.";
		break;
	default:
		break;
	}
}

void Reader::checkFee()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	int day = now->tm_wday;
	Date today{ day, now->tm_mon + 1, now->tm_year + 1900 };
	Date nextPurchase = this->r.paidFor;
	Date overdue{};
	if (nextPurchase.year > today.year || nextPurchase.month > today.month)
	{
		overdue = { 0, 0, 0 };
		this->r.isInBlackList = false;
		std::cout << this->r.Name << " " << this->r.Surname << " doesn`t have overdue" << std::endl;
	}
	else if (nextPurchase.year < today.year) {
		overdue.year = today.year - nextPurchase.year;
		overdue.month = fabs(today.month - nextPurchase.month);
		if (today.day < nextPurchase.day)
		{
			overdue.day = nextPurchase.day - today.day;
		}
		else
		{
			overdue.day = today.day - nextPurchase.day;
		}
		this->r.isInBlackList = true;
		std::cout << this->r.Name << " " << this->r.Surname
			<< " has an ovedue for: " << overdue.day << " days " << overdue.month
			<< " month " << overdue.year << " years " << std::endl;
	}
	else if (nextPurchase.year == today.year)
	{
		overdue.year = 0;
		if (today.month > nextPurchase.month)
		{
			overdue.month = today.month - nextPurchase.month;
		}
		if (today.day < nextPurchase.day)
		{
			overdue.day = nextPurchase.day - today.day;
		}
		else
		{
			overdue.day = today.day - nextPurchase.day;
		}
		this->r.isInBlackList = true;
		std::cout << this->r.Name << " " << this->r.Surname
			<< " has an ovedue for: " << overdue.day << " days " << overdue.month
			<< " month " << overdue.year << " years " << std::endl;
	}
}

void Reader::setNode(Reader* next)
{
	this->next = next;
}

Reader* Reader::getNode()
{
	return this->next;
}
short Reader::getIndex()
{
	return this->r.index;
}

void Reader::setLastPurchase(Date d) 
{
	this->r.lastPurchase = d;
}

Date Reader::getLastPurchase()
{
	return this->r.lastPurchase;
}

Date Reader::getPaidFor()
{
	return this->r.paidFor;
}

void Reader::setPaidFor(Date d)
{
	this->r.paidFor = d;
}