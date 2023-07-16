#pragma once
#include <vector>
#include "Student.h"
#include "Book.h"
#include <iostream>
using namespace std;
class Library
{
private:
	vector<Student> students;
	vector<Book> books;
	vector<pair<string, string>> bookAssignment;
	int getIndex(pair<string, string> obj);
public:
	void addBook(Book book);
	void addStudent(Student student);
	bool searchBook(string title);
	bool searchBook(Book book);
	bool searchStudent(string name);
	bool assignBookToStudent(string stdName, string bookName);
	bool returnBook(string title);
	int getBookIdByTitle(string title);
	void occupyBook(string title);
	void printStudentNames();
	void printBooksNames();
};

int Library::getIndex(pair<string, string> obj)
{
	for (int i = 0; i < bookAssignment.size(); i++) {
	
		if (bookAssignment.at(i).first == obj.first && bookAssignment.at(i).second == obj.second) {
			return i;
		}
	}
	return -1;
}

void Library::addBook(Book book)
{
	books.push_back(book);
}

void Library::addStudent(Student student)
{
	students.push_back(student);
}

bool Library::searchBook(string title)
{
	for (Book& book : books) {
		if (book.getTitle() == title && book.getIsAvailable()) {
			return true;
		}
	}

	return false;
}

bool Library::searchBook(Book book)
{
	for (Book& b : books) {
		if (book == b) {
			return true;
		}
		return false;
	}
	return false;
}

bool Library::searchStudent(string name)
{
	for (Student s : students) {
		if (s.getName() == name) {
			return true;
		}
	}
	return false;
}

bool Library::assignBookToStudent(string stdName, string bookName)
{
	if (searchBook(bookName) && searchStudent(stdName) && getBookIdByTitle(bookName) ){
		occupyBook(bookName);
		bookAssignment.push_back(make_pair(stdName, bookName));
		return true;
	}
	return false;
}


bool Library::returnBook(string title)
{
	for (auto pair : bookAssignment) {
		if (pair.second == title) {
			for (Book& book : books) {
				if (title == book.getTitle()) {
					book.setIsAvailable(true);
					bookAssignment.erase(bookAssignment.begin() + getIndex(pair));
					return true;
				}
			}
		}
	}
	return false;
}

int Library::getBookIdByTitle(string title)
{
	for (Book& b : books) {
		if (b.getTitle() == title) {
			return b.getBookId();
		}
	}
	return -1;
}

void Library::occupyBook(string title)
{
	for (Book& book : books) {
		if (book.getTitle() == title) {
			book.setIsAvailable(false);
		}
	}
}

void Library::printStudentNames()
{
	cout << "test" << endl;
	for (auto s : students) {
		cout << s.getName() << endl;
	}
}

void Library::printBooksNames()
{
	cout << "test2" << endl;
	for (auto book : books) {
		cout << book.getTitle() << endl;
	}
}
