#ifndef VIEW_H
#define VIEW_H



#include "Thu_Vien.h"

void Set_console();

void stop1();
void clean();
void next_page(const string& Name_page);
void Out_page(const string& Name_page);
void next_and_clean(const string& Name_page);
void Out(const string& Name_page);

void login(Employee Em[], const int& size);
void Start(Employee Em[], const int& size);

void Quan_ly_sach(Borrow Bors[],int& SizeOfBor, Detail Dets[],int& SizeOfDet, Book B[],int& SizeOfBook, User Us[], int& SizeOfU);
void Quan_ly_User(Borrow Bors[],int& SizeOfBor, Detail Dets[],int& SizeOfDet, Book B[],int& SizeOfBook, User Us[], int& SizeOfU);
void Quan_ly_Borrow(Borrow Bors[],int& SizeOfBor, Detail Dets[],int& SizeOfDet, Book B[],int& SizeOfBook, User Us[], int& SizeOfU);

void Home(Borrow Bors[],int& SizeOfBor, Detail Dets[],int& SizeOfDet, Book B[],int& SizeOfBook, User Us[], int& SizeOfU, Employee Em[], int& SizeOfEm);
#endif // VIEW_H
