#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include "Thu_Vien.h"

//using namespace std;

/*void ReadToKey(ifstream& file, string& container, string key){    //doc file den khi gap "key"
	string test;
	file >> container;
	while (file >> test, test != key){
		container += " ";
		container += test;
	}
}*/

void file_read_book(Book B[], int& size){
    string x;
    ifstream file;
    file.open("Book.csv");

    file >> x;          //Doc phan tieu de

     while (getline(file, x, ',')!=NULL){
		size ++;
        file >> B[size].B_id;
        getline(file, x, ',');   //doc 1 ky tu ',' sau id
        getline(file, B[size].Title, ',');
        getline(file, B[size].NameOfAuthor, ',');
        getline(file, B[size].PublishHouse, ',');
        file >> B[size].NumOfCopies;
        getline(file, x, '\n');
    }
    file.close();
}
void file_print_Book(Book B[], const int& size){
    fstream file;
    int i;
    file.open("Book.csv", ios::out);
    file << "STT,ID,Title,NameOfAuthor,PublishHouse,NumOfCopies" << endl;
    for (i=1 ; i<=size ; i++){
        file << i << "," << B[i].B_id << "," << B[i].Title << "," << B[i].NameOfAuthor << "," << B[i].PublishHouse << "," << B[i].NumOfCopies << endl;
    }
    //file << "--end--";
    file.close();
}

void file_print_Borrow(Borrow Bors[], const int& size){
    ofstream file_out;
    int i;
    file_out.open("Borrow.csv");
    file_out << "STT,ID,User_id,num,Start_Date,Due_Date,Fine,Status(1:ChuaTraHet_0:DaTraHet)" << endl;
    for (i=1 ; i<=size ; i++){
        file_out << i << "," << Bors[i].borrow_id << "," << Bors[i].User_id << "," << Bors[i].num << ",";
        file_out << Bors[i].start_Date.D << "/" << Bors[i].start_Date.M << "-" << Bors[i].start_Date.Y << ",";
        file_out << Bors[i].due_Date.D << "/" << Bors[i].due_Date.M << "-" << Bors[i].due_Date.Y << ",";
        file_out << Bors[i].fine << "," << Bors[i].BorrowStatus << endl;
    }
    file_out.close();
}
void file_read_borrow(Borrow Bors[], int& size){
    ifstream file_in;
    string x;
    char t;
    file_in.open("Borrow.csv", ios :: app);
    getline(file_in, x, '\n');
    while (getline(file_in, x, ',')!=NULL){
        size++;
        file_in >> Bors[size].borrow_id;
        getline(file_in, x, ',');   //doc 1 ky tu ',' sau id
        file_in >> Bors[size].User_id;
        getline(file_in, x, ',');
        file_in >> Bors[size].num;
        getline(file_in, x, ',');
        file_in >> Bors[size].start_Date.D ;
        file_in >> t;
        file_in >> Bors[size].start_Date.M ;
        file_in >> t;
        file_in >> Bors[size].start_Date.Y ;
        file_in >> t;
        file_in >> Bors[size].due_Date.D ;
        file_in >> t;
        file_in >> Bors[size].due_Date.M ;
        file_in >> t;
        file_in >> Bors[size].due_Date.Y;
        file_in >> t;
        file_in >> Bors[size].fine;
        int i;
        file_in >> i;
        if (i)
            Bors[size].BorrowStatus = Chua_Tra_Het;
        else Bors[size].BorrowStatus = Da_Tra_Het;
        getline(file_in, x, '\n');
    }
    file_in.close();

}
#endif // DATA_H

