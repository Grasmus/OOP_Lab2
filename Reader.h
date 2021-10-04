#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include <math.h>

struct Date {
	int day{};
	int month{};
	int year{};
};
struct Publishers {
	double price{};
	short index{};
	std::string Name;
};
struct PubsNode {
	Publishers publisher;
	PubsNode* next{ nullptr };
	PubsNode* prev{ nullptr };
};

struct Data
{
	std::string Name;
	std::string Surname;
	bool isInBlackList = false;
	Date regDate;
	Date lastPurchase{};
	Date paidFor{};
	int numOfSubs;
	double fee;
	short index;
};

class Reader
{
	Data r;
public:
	int* subsPubs{ nullptr };
	PubsNode* publis{ nullptr };
	Reader* next{ nullptr };
	Reader(PubsNode* pp);
	Reader(Data r, PubsNode* pp);
	void calcFee();
	void isBlacklisted();
	void checkFee();
	void setNode(Reader* next);
	void setLastPurchase(Date d);
	void setPaidFor(Date d);
	std::string printName();
	std::string printSurname();
	Date getLastPurchase();
	Date getRegDate();
	double getFee();
	Reader* getNode();
	short getIndex();
	Date getPaidFor();
	Data getData();
};

