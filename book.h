#ifndef BOOK_H
#define BOOK_H

#include<vector>
#include<string>
#include<fstream>
#include"coreds.h"

class Book
{
	private:
	std::fstream fileSt;
	std::vector<std::string> dates;
	std::vector<std::string> items;
	std::vector<std::string> cats;
	std::vector<std::string> prices;
	std::vector<std::string> comments;

	public:
	Book();
	void openBook();
	void readBook();
	void writeBook(std::vector<struct expData> expenses);
	void closeBook();
	std::vector<std::string> getDates();
	std::vector<std::string> getItems();
	std::vector<std::string> getCats();
	std::vector<std::string> getPrices();
	std::vector<std::string> getComments();
};

#endif  /* BOOK_H */

