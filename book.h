#ifdef BOOK_H
#define BOOK_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class book
{
public:
	book();
	~book();

private:
	string title;
	string author;


};

class book: public {
}

book::~book()
{
};
#endif