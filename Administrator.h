#pragma once
#include <iostream>
#include <string.h>
#include "Reader.h"



class Administrator
{
	Reader* head{ nullptr };
	Reader* curr{ nullptr };
	Reader* temp{ nullptr };
	//Reader* rPtr{};
	

public:
	static PubsNode* pubs;
	void createPublishers(std::string name);
	void createPublishers(int n, std::string name);
	void createReaders();
	void createReaders(std::string name);
	void saveCurrentReaders(std::string name);
	void addNewReaders();
	void getReaderInfo(short i);
	void makePurchase(short i);
};


