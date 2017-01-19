/*
 * book.cpp:
 *
 * St: 2016-12-02 Fri 01:40 PM
 * Up: 2016-12-02 Fri 01:40 PM
 *
 * Author: SPS
 */


#include<fstream>
#include<iostream> // DEBUG
#include<string>
#include"book.h"

Book::Book()
{
	;
}

void Book::openBook()
{
	fileSt.open("/home/cursive/Documents/exp/exp.exp");
	if (!fileSt.is_open()) {
		// DEBUG
		std::cout << "File open error\n";
	}
}

void Book::readBook()
{
	std::string line;

	// Read details for ONE contact
	while (getline(fileSt, line)) {
		dates.push_back(line);
		getline(fileSt, line);
		items.push_back(line);
		getline(fileSt, line);
		cats.push_back(line);
		getline(fileSt, line);
		prices.push_back(line);
		getline(fileSt, line);
		comments.push_back(line);
	}
}

void Book::writeBook(std::vector<struct expData> expenses)
{
	int i;

	for (i = 0; i < expenses.size(); i++) {
		fileSt << expenses[i].date << "\n";
		fileSt << expenses[i].item << "\n";
		fileSt << expenses[i].cat << "\n";
		fileSt << expenses[i].price << "\n";
		fileSt << expenses[i].comment << "\n";
	}
}

void Book::closeBook()
{
	fileSt.close();
}

std::vector<std::string> Book::getDates()
{
	return dates;
}

std::vector<std::string> Book::getComments()
{
	return comments;
}

std::vector<std::string> Book::getItems()
{
	return items;
}

std::vector<std::string> Book::getCats()
{
	return cats;
}

std::vector<std::string> Book::getPrices()
{
	return prices;
}

