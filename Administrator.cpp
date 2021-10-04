#define _CRT_SECURE_NO_WARNINGS
#include "Administrator.h"
#include <iostream>
#include <fstream>



PubsNode* Administrator::pubs = NULL;


void Administrator::createReaders()
{
	this->head = new Reader(this->pubs);
}

void Administrator::createReaders(std::string name)
{
	std::ifstream inf{};
	inf.open(name);
	Data r{};
	if (inf.is_open())
	{
		while (!inf.eof())
		{
			//inf.read((char*)&r, sizeof(Data));
			inf >> r.Name;
			inf >> r.Surname;
			inf >> r.fee;
			inf >> r.index;
			inf >> r.isInBlackList;
			inf >> r.lastPurchase.day;
			inf >> r.lastPurchase.month;
			inf >> r.lastPurchase.year;
			inf >> r.numOfSubs;
			inf >> r.paidFor.day;
			inf >> r.paidFor.month;
			inf >> r.paidFor.year;
			inf >> r.regDate.day;
			inf >> r.regDate.month;
			inf >> r.regDate.year;
			
			if (this->head)
			{
				this->temp = new Reader(r, pubs);
				this->curr = this->temp;
				this->curr->subsPubs = new int[r.numOfSubs];
				for (int i{}; i < r.numOfSubs; i++)
				{
					inf >> this->curr->subsPubs[i];
				}
				this->curr->setNode(this->head);
				this->head = this->curr;
			}
			else
			{
				this->head = new Reader(r, pubs);
				this->head->subsPubs = new int[r.numOfSubs];
				for (int i{}; i < r.numOfSubs; i++)
				{
					inf >> this->head->subsPubs[i];
				}
			}
		}
		inf.close();
		//std::cout << "Closed" << std::endl;
	}
	else std::cout << "Error reading file!";
	//std::cout << "Ended" << std::endl;
	getchar();
	getchar();
}

void Administrator::createPublishers(std::string name)
{
	std::ifstream inf{};
	inf.open(name);
	this->pubs = new PubsNode;
	this->pubs->prev = NULL;
	PubsNode* current = this->pubs;
	PubsNode* temp{};
	Publishers tmp;
	if (inf.is_open())
	{
		while (!inf.eof())
		{
			//inf.read((char*)&current->publisher, sizeof(Publishers));
			inf >> current->publisher.Name;
			inf >> current->publisher.index;
			inf >> current->publisher.price;
			if (!inf.eof()) {
				temp = current;
				current->next = new PubsNode;
				current = current->next;
				current->prev = temp;
			}
		}
		inf.close();
		current->prev = temp;
		delete current;
		if (temp) temp->next = nullptr;
	}
	else std::cout << "Error reading file!";
	getchar();
	getchar();
}

void Administrator::saveCurrentReaders(std::string name)
{
	std::ofstream outf{};
	outf.open(name);
	if (outf.is_open())
	{
		this->curr = this->head;
		while(this->curr)
		{
			Data r{ this->curr->getData() };
			//outf.write((char*)&r, sizeof(Data));
			outf << r.Name << '\t' << r.Surname << '\t' << r.fee << '\t' << r.index << '\t' << r.isInBlackList << '\t' << 
				r.lastPurchase.day << '\t' << r.lastPurchase.month << '\t' << r.lastPurchase.year << '\t' << r.numOfSubs << '\t' <<
				r.paidFor.day << '\t' << r.paidFor.month << '\t' << r.paidFor.year << '\t' << r.regDate.day << '\t' << r.regDate.month 
				<< '\t' << r.regDate.year << '\t';
			for (int i{}; i < r.numOfSubs; i++)
			{
				outf << this->curr->subsPubs[i] << '\t';
			}
			outf << std::endl;
			this->curr = this->curr->getNode();
		}
		outf.close();
	}
	else std::cout << "Error writing file!";
	getchar();
	getchar();
}

void Administrator::createPublishers(int n, std::string name)
{
	int p{ n };
	this->pubs = new PubsNode;
	this->pubs->prev = NULL;
	PubsNode* current = this->pubs;
	std::ofstream outf{};
	outf.open(name);
	PubsNode* tmp{};
	if (outf.is_open())
	{
		for (int i{}; i < p; i++)
		{
			std::cout << "Enter name of publisher: ";
			std::cin >> current->publisher.Name;
			std::cout << "Enter index of publisher: ";
			int k{};
			while (k <= 0)
			{
				std::cin >> k;
				if (k <= 0) std::cout << "Enter Valid index!";
			}
			current->publisher.index = k;
			std::cout << "Enter price of publisher: ";
			std::cin >> current->publisher.price;
			Publishers temp{ current->publisher };
			//outf.write((char*)&current->publisher, sizeof(Publishers));
			outf << current->publisher.Name << '\t' << current->publisher.index << '\t' << current->publisher.price << std::endl;
			if (i != p - 2)
			{
				tmp = current;
				current->next = new PubsNode;
				current = current->next;
				current->prev = tmp;
			}
			
		}
		if (current) current->next = NULL;
		outf.close();
	}
	else std::cout << "Error writing file!";
	getchar();
	getchar();
}

void Administrator::addNewReaders()
{
	if (this->head)
	{
		this->temp = new Reader(this->pubs);
		this->curr = this->temp;
		this->curr->setNode(this->head);
		this->head = this->curr;
	}
	else this->createReaders();
}

void Administrator::getReaderInfo(short i)
{
	this->curr = this->head;
	while (this->curr)
	{
		if (this->curr->getIndex() == i)
		{
			std::cout << "Reader name: " << this->curr->printName();
			std::cout << std::endl;
			std::cout << "Reader surname: " << this->curr->printSurname();
			std::cout << std::endl;
			Date d{ this->curr->getRegDate() };
			std::cout << "Registration date: " << d.day << "." << d.month << "."
				<< d.year << std::endl;
			if (this->curr->getLastPurchase().year != 0)
			{
				d = this->curr->getLastPurchase();
				std::cout << "Last purchase date: "  << d.day << "." << d.month << "."
					<< d.year << std::endl;
				d = this->curr->getPaidFor();
				std::cout << "Paid for: " << d.day << "." << d.month << "."
					<< d.year << std::endl;
				std::cout << "Fee: " << this->curr->getFee() << std::endl;
			}
			this->curr->isBlacklisted();
			std::cout << std::endl;
			this->curr->checkFee();
			std::cout << std::endl;
			getchar();
			getchar();
			return;
		}
		else this->curr = this->curr->getNode();
	}
	std::cout << "There is no such user with index " << i << std::endl;
	getchar();
	getchar();
}

void Administrator::makePurchase(short i)
{
	this->curr = this->head;
	while (this->curr)
	{
		if (this->curr->getIndex() == i)
		{
			int month{};
			std::cout << "Enter num of paid months: ";
			std::cin >> month;
			std::time_t t = std::time(0);
			std::tm* now = std::localtime(&t);
			int day = now->tm_wday + 3;
			Date today{ day, now->tm_mon + 1, now->tm_year + 1900 };
			if (!this->curr->getLastPurchase().year)
			{
				this->curr->setLastPurchase(today);
			}
				Date d = this->curr->getPaidFor();
				for (int i{}; i < month; i++)
				{
					if (d.month < 12)
					{
						d.month++;
					}
					else
					{
						d.year++;
						d.month = 0;
					}
				}
				this->curr->setPaidFor(d);

				getchar();
				getchar();
			return;
		}
		else this->curr = this->curr->getNode();
	}
	std::cout << "There is no such user with index " << i << std::endl;
	getchar();
	getchar();
}
