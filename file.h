#ifndef DATA_H
#define DATA_H



//void ReadToKey(ifstream& file, string& container, string key);
void file_read_book(Book B[], int& size);

void file_print_Book(Book B[], const int& size);

void file_print_Borrow(Borrow Bors[], const int& size);
void file_read_borrow(Borrow Bors[], int& size);
#endif // DATA_H

