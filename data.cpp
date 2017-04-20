#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include "Thu_Vien.h"

//using namespace std;

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
        char t;
        file >> t;
        file >> B[size].So_Lan_Muon;
        getline(file, x, '\n');
    }
    file.close();
}
void file_print_Book(Book B[], const int& size){
    fstream file;
    int i;
    file.open("Book.csv", ios::out);
    file << "STT,ID,Title,NameOfAuthor,PublishHouse,NumOfCopies,So luot muon" << endl;
    for (i=1 ; i<=size ; i++){
        file << i << "," << B[i].B_id << "," << B[i].Title << "," << B[i].NameOfAuthor << "," << B[i].PublishHouse << "," << B[i].NumOfCopies << "," << B[i].So_Lan_Muon << endl;
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
    file_in.open("Borrow.csv");
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
        file_in >> t;
        int i;
        file_in >> i;
        if (i)
            Bors[size].BorrowStatus = Chua_Tra_Het;
        else Bors[size].BorrowStatus = Da_Tra_Het;
        getline(file_in, x, '\n');
    }
    file_in.close();
}

void file_print_Detail(Detail Dets[], const int& size){
    ofstream fileOut;
    int i;
    fileOut.open("Detail.csv");
    fileOut << "STT,Borrow_id,Book_id,Status(0:ChuaQuaHan_1:DaTra_2:QuaHan" << endl;
    for (i=1 ; i<=size ; i++){
        fileOut << i << ",";
        fileOut << Dets[i].Borrow_id << ",";
        fileOut << Dets[i].Book_id << ",";
        fileOut << Dets[i].Stt_Det << endl;
    }
    fileOut.close();
}
void file_read_Detail(Detail Dets[], int& size){
    ifstream file_in;
    string x;
    char t;
    file_in.open("Detail.csv");
    getline(file_in, x, '\n');
    while (getline(file_in, x, ',')!=NULL){
        size ++; //cout << "Det " << size << endl;
        //getline(file_in, x, ',');
        file_in >> Dets[size].Borrow_id;
        file_in >> t;
        file_in >> Dets[size].Book_id;
        file_in >> t;
        int i;
        file_in >> i;
        if (i == 0)
            Dets[size].Stt_Det = ChuaQuaHan;
        else if (i == 1)
            Dets[size].Stt_Det = DaTra;
        else Dets[size].Stt_Det = Quahan;
        getline(file_in, x, '\n');
    }
    file_in.close();
}

void file_print_User(User Us[], const int& size){
    int i;
    ofstream fileOut;
    fileOut.open("User.csv");
    fileOut << "STT,u_id,u_name,birthday,Male 0 _ Female 1,Phone,num_book_allow" << endl;
    for (i=1 ; i<=size ; i++){
        fileOut << i << ",";
        fileOut << Us[i].u_id << ",";
        fileOut << Us[i].u_name << ",";
        fileOut << Us[i].birthday.D << "/" << Us[i].birthday.M << "/" << Us[i].birthday.Y << ",";
        fileOut << Us[i].Gen << ",";
        fileOut << "'" << Us[i].Phone << ",";
        fileOut << Us[i].num_book_allow << endl;
    }
    fileOut.close();
}
void file_read_user(User Us[], int& size){
    ifstream file_in;
    string x;
    char t;
    file_in.open("User.csv");
    getline(file_in, x, '\n');
    while (getline(file_in, x, ',')!=NULL){
        size++;
        file_in >> Us[size].u_id;
        file_in >> t;
        getline(file_in, Us[size].u_name, ',');
        file_in >> Us[size].birthday.D;
        file_in >> t;
        file_in >> Us[size].birthday.M;
        file_in >> t;
        file_in >> Us[size].birthday.Y;
        file_in >> t;
        int i;
        file_in >> i;
        if (i)
            Us[size].Gen = FEMALE;
        else Us[size].Gen = MALE;
        file_in >> t;
        getline(file_in, x, ',');
        if (x.substr(0,1) == "'")
            x = x.substr(1, x.size()-1);
        Us[size].Phone = x;
        file_in >> Us[size].num_book_allow;
        getline(file_in, x, '\n');
    }
    file_in.close();
}

void file_print_Employee(Employee Em[], const int& size){
    int i;
    ofstream fileOut;
    fileOut.open("Employee.csv");
    fileOut << "STT,ID,Name,User_Name,Password,Address,Phone,BirthDay,Gender(FeMale: 1; Male: 0)" << endl;
    for (i=1 ; i<=size ; i++){
        fileOut << i << ",";
        fileOut << Em[i].E_id << ",";
        fileOut << Em[i].e_Name << ",";
        fileOut << Em[i].UserName << ",";
        fileOut << Em[i].Pass << ",";
        fileOut << Em[i].Address << ",";
        fileOut << "'" <<  Em[i].Phone << ",";
        fileOut << Em[i].Birthday.D << "/" << Em[i].Birthday.M << "/" << Em[i].Birthday.Y << ",";
        fileOut << Em[i].Gen << endl;
    }
    fileOut.close();
}
void file_read_Employee(Employee Em[], int& size){
    ifstream file_in;
    string x;
    char t;
    file_in.open("Employee.csv");
    getline(file_in, x, '\n');
    while (getline(file_in, x, ',')!=NULL){
        size++;
        file_in >> Em[size].E_id;
        file_in >> t;
        getline(file_in, Em[size].e_Name, ',');
        getline(file_in, Em[size].UserName, ',');
        getline(file_in, Em[size].Pass, ',');
        getline(file_in, Em[size].Address, ',');
        getline(file_in, x, ',');
        if (x.substr(0,1) == "'")
            x = x.substr(1, x.size()-1);
        Em[size].Phone = x;
        file_in >> Em[size].Birthday.D;
        file_in >> t;
        file_in >> Em[size].Birthday.M;
        file_in >> t;
        file_in >> Em[size].Birthday.Y;
        file_in >> t;
        int gen;
        file_in >> gen;
        if (gen)
            Em[size].Gen = FEMALE;
        else Em[size].Gen = MALE;
        getline(file_in, x, '\n');
    }
    file_in.close();
}
#endif // DATA_H
