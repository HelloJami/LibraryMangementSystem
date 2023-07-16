#pragma once
#include <string>
using namespace std;

class Book {
    private:
        int BId;
        string title;
        string author;
        string ISBN;
        bool isAvailable;

    public:
        Book(int BId, string title, string author, string ISBN);
        string getTitle() const;
        string getAuthor() const;
        string getISBN() const;
        bool getIsAvailable() const;
        void setIsAvailable(bool value);
        int getBookId() const;
        bool operator==(const Book& book);

};

Book::Book(int BId, string title, string author, string ISBN)
    :BId{BId},title {title}, author{ author }, ISBN{ ISBN }, isAvailable{ true } {
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return ISBN;
}

bool Book::getIsAvailable() const {
    return isAvailable;
}

void Book::setIsAvailable(bool value)
{
    isAvailable = value;
}

int Book::getBookId() const
{
    return BId;
}

bool Book::operator==(const Book& book)
{
    if (this->getAuthor() == book.getAuthor() && book.getTitle() == this->getTitle()) {
        return true;
    }
    return false;
}



