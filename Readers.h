//#pragma once
//#include <string.h>
//#include <iostream>
//
//struct Date {
//	unsigned short day{};
//	unsigned short month{};
//	unsigned year{};
//};
//struct Publishers {
//	double price{};
//	short index{};
//	std::string Name;
//};
//struct PubsNode {
//	Publishers publisher;
//	PubsNode* next{ nullptr };
//	PubsNode* prev{ nullptr };
//};
//
//struct Reader
//{
//	std::string Name;
//	std::string Surname;
//	bool isInBlackList = false;
//	Date regDate;
//	Date lastPurchase{};
//	int* subsPubs;
//	int numOfSubs;
//	double fee;
//	short index;
//};
//struct node {
//	Reader r;
//	node* next{ nullptr };
//};
//
//class Readers
//{
//	PubsNode* publis;
//	node* head{ nullptr };
//	node* curr{ nullptr };
//	node* temp{ nullptr };
//public:
//	Readers(/*std::string Name, std::string Surname, Publishers* pubs, int day, int month, int year*/);
//	Readers(std::string Name, std::string Surname, Date regDay, Date purchaseDay, int numOfSubs, double fee, short index);
//	void printName(int i);
//	void printSurname(int i);
//	Date getRegdate(int i);
//	int calcFee(int i);
//	void readPublishers(std::string name);
//	double getFee(int i);
//	void isBlacklisted(int i);
//	void checkFee(int i);
//	void addNewReader();
//	void removeReader(int i);
//};
//
