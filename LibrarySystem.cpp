// LibrarySystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Library.h"
#include <limits>
using namespace std;

void menu() {
	cout << "\tLibrary" << endl;
	cout << "1. Add student" << endl;
	cout << "2. Add book" << endl;
	cout << "3. search book" << endl;
	cout << "4. search student" << endl;
	cout << "5. assign book to student" << endl;
	cout << "6. return book" << endl;
	cout << "7. exit" << endl;
	cout << "8. print students" << endl;
	cout << "9. print books" << endl;
}

Book inputBookInfo() {
	cout << "Enter title : ";
	string title;
	getline(cin, title);
	cout << "Enter author : ";
	string author;
	getline(cin, author);
	cout << "enter ISBN : ";
	string isbn;
	getline(cin, isbn);
	cout << "Enter Book id : ";
	int id;
	cin >> id;

	Book b(id, title, author, isbn);
	return b;
}

Student inputStudentInfo() {
	string name;
	string roll;
	int id;

	cout << "Enter name : ";
	getline(cin, name);
	cout << "Enter rollNo : ";
	getline(cin, roll);
	cout << "Enter student id : ";
	cin >> id;
	Student s(name, roll, id);
	return s;
}

void searchBook(Library& library) {
	string title;
	cout << "Enter book title : ";
	getline(cin, title);
	if (library.searchBook(title)) {
		cout << "Book found!" << endl;
	}
	else {
		cout << "Book not found" << endl;
	}
}

void searchStudent(Library& library) {
	string name;
	cout << "Enter student name : ";
	getline(cin, name);
	if (library.searchStudent(name)) {
		cout << "student found!" << endl;
	}
	else {
		cout << "student not found" << endl;
	}
}

void assignBookToStudent(Library &library) {
	string stdName;
	string bName;

	cout << "Enter student name : ";
	getline(cin, stdName);

	cout << "Enter book title : ";
	getline(cin, bName);

	if (library.assignBookToStudent(stdName, bName)) {
		cout << "Book assigned to student successfully";
	}
	else {
		cout << "Failed to assign book" << endl;
	}
}

void returnBook(Library& library) {
	string title;
	cout << "Enter title : ";
	getline(cin, title);
	if (library.returnBook(title)) {
		cout << "Book returned successfully" << endl;
	}
	else {
		cout << "Failed to return" << endl;
	}
}

int main()
{
	Library library;
	
	while (true) {
		menu();
			int choice = 0;
			cout << "Enter your choice : ";
			cin >> choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			switch (choice) {
			case 1:
				library.addStudent(inputStudentInfo());
				cout << "Student added" << endl;
				break;
			case 2:
				library.addBook(inputBookInfo());
				cout << "Book added" << endl;
				break;
			case 3:
				searchBook(library);
				break;
			case 4:
				searchStudent(library);
				break;
			case 5:
				assignBookToStudent(library);
				break;
			case 6:
				returnBook(library);
				break;
			case 7:
				return EXIT_SUCCESS;
				break;
			case 8:
				library.printStudentNames();
				break;
			case 9:
				library.printBooksNames();
				break;
			default:
				cout << "Input invalid!" << endl;
			}
	}
	
}

