#ifndef DATA_H
#define DATA_H



//void ReadToKey(ifstream& file, string& container, string key);
void file_read_book(Book B[], int& size);
void file_print_Book(Book B[], const int& size);

void file_print_Borrow(Borrow Bors[], const int& size);
void file_read_borrow(Borrow Bors[], int& size);

void file_print_Detail(Detail Dets[], const int& size);
void file_read_Detail(Detail Dets[], int& size);

void file_print_User(User Us[], const int& size);
void file_read_user(User Us[], int& size);

void file_print_Employee(Employee Em[], const int& size);
void file_read_Employee(Employee Em[], int& size);

#endif // DATA_H
