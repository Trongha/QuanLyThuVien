#ifndef THU_VIEN_H
#define THU_VIEN_H

#include <iostream>
using namespace std;


int Create_id();
bool Yes(const string& ask);
bool check_string(string s1, string s2);
void search_string(string arr[], const int& size, string x, int vi_tri[], int &num_vitri);
bool check_int(string t);
int Convert_Char_Int(char t);
int Input_int(string ask);
string In_Hoa(string s);
void stop();

const int max_borrow = 10;
//SO sach toi da 1 nguoi duoc muon
const int everyday = 10;
//So tien no /1quyen/1ngay
const int max_num_day = 20;

enum Gender {
	MALE,
	FEMALE
};

enum Status_book{
    con,
    het
};

enum Status_Detail{
    ChuaQuaHan,
	DaTra,
	Quahan
};

enum Status_Borrow{
    Da_Tra_Het,
    Chua_Tra_Het
};
struct Date{
	int D;
	int M;
	int Y;
	Date(){}
	Date(int _D, int _M, int _Y){
		D= _D;
		M= _M;
		Y= _Y;
	}
};

int NamNhuan (int y);
Date Cong(Date _Date, int num);
void add_Date(Date& _Date);
void print_Date (const Date& _Date);
Date ToDay();
int WTF_MAGIC(Date _Date);      // Tinh so ngay tu 31/12/1899
int Num_Date(Date start, Date finish);


struct Employee{
	int E_id;
	string e_Name;
	string UserName;
	string Pass;
	string Address;
	string Phone;
	Date Birthday;
	Gender Gen;
	Employee(){	}
	Employee(int _E_id, string _e_Name, string _UserName, 	string _Pass, string _Address, string _Phone, Date _Birthday, Gender _Gen){
		E_id = _E_id;
		e_Name = _e_Name;
		UserName = _UserName;
        Pass = _Pass;
		Address = _Address;
		Phone = _Phone;
		Birthday = _Birthday;
		Gen = _Gen;
	}
};

bool check_Employee_UserName(string user, Employee Em[], const int& size);
Employee add_1_Employee(Employee Em[],const int& size);
void add_Employee(Employee Em[], int& size);
void print_Employees();
void Delete_Employee(Employee Em[], int& size);

struct User{
	int u_id;
	string u_name;
	Date birthday;
	Gender Gen;
	string Phone;
	int num_book_allow;
	User(){}
	User(int _u_id, string _u_name, Date _birthday, Gender _Gen, string _Phone){
		u_id = _u_id;
        u_name = _u_name;
        birthday = _birthday;
		Gen = _Gen;
		Phone = _Phone;
		num_book_allow = max_borrow;
	}
};

void print_u_fast(User u);
void print_u_fast(User Us[], const int& size, const int& id);
void print_user(User u);
void print_User_array(User u[], const int& size);
void print_all_u(User u[],const int& size);
User add_1_user(const int& id);
void add_user(User Us[], int& size);
void Delete_User(User Us[], int& size);
void insert_u(User us[], int& size, User u);
User* search_U_Pro(User us[], const int& size, const int& id);
void search_U(User*& u, User us[], const int& size, const int& id);
int search_U(User us[], const int& size, const int& id);
bool check_U(User us[], const int& size, const int& id);
int input_U_id(User Us[], const int& size);
//void Delete_u(User us[], int& size, int u_id);

struct Book{
	int B_id;
	string CallNumber;
	string Title;
	int NumOfCopies;
	string NameOfAuthor;
	string PublishHouse;
	int So_Lan_Muon;

	Book(){	}
	Book(int _B_id, string _Title, int _NumOfCopies, string _NameOfAuthor, string _PublishHouse){
		B_id = _B_id;
		Title = _Title;
		NumOfCopies = _NumOfCopies;
		NameOfAuthor = _NameOfAuthor;
		PublishHouse = _PublishHouse;
		So_Lan_Muon = 0;
	}
};

int input_Book_id(Book B[], const int& size);
void print_book( Book B);
void printf_book_array(Book B[], const int& size);
void printf_all_book(Book B[], const int& size);
void print_book(Book B[], const int& size, const int& id);
void print_book_detail(Book B);
Book add_1_book(const int& id);
void Edit_Book(Book B[], int& size);
void Delete_Book(Book B[], int& size);
void add_Book(Book B[], int& size);
bool check_book(Book B[], const int& size, const int& id);
void check_num_book(Book B[],const int& size, const int& id, Status_book &check);
int search_Book(Book B[], const int& size, const int& id);
int search_Book(Book B[], const int& size, const int& id);
Book* search_Book_pro(Book B[], const int& size, const int& id);
void Top_Sach_muon_nhieu(Book B[], const int& size);
Book add_1_book(const int& id);
void Search_Book(Book B[], const int& size);
void Search_Book_test(Book B[], const int& size);




struct Borrow{
	int borrow_id;
	int User_id;
	int num;
	Date start_Date;
	Date due_Date;
	int fine;
	Status_Borrow BorrowStatus;
	Borrow(){}
	Borrow(int _borrow_id, int _User_id, int _num, Date _start_Date, Date _due_Date){
		borrow_id = _borrow_id;
		User_id = _User_id;
		num = _num;
		start_Date = _start_Date;
		due_Date = _due_Date;
        fine = 0;
        BorrowStatus = Chua_Tra_Het;
	}
};

int search_Borrow(Borrow Bors[], const int& SizeOfBor, const int& id);
Borrow* search_Borrow_Pro(Borrow Bors[], const int& SizeOfBor, const int& id);
void add_Borrow(Borrow Borrows[],int& size);

struct Detail{

    int Borrow_id;
    int Book_id;
    Status_Detail Stt_Det;

    Detail(){}
    Detail(int _Borrow_id, int _Book_id, Status_Detail _Stt_Det){
        Borrow_id = _Borrow_id;
        Book_id = _Book_id;
        Stt_Det = _Stt_Det;
    }
};
void print_Det(Detail Det, Book B[], const int& SizeOfBook, Borrow Bors[], const int& SizeOfBor);
int search_Detail(Detail Dets[], const int& SizeOfDets, const Detail& Det);
int search_Detail(Detail Dets[], const int& SizeOfDets, const int& id_borrow);
Detail* search_Detail_Pro(Detail Dets[], const int& SizeOfDets, const int& id_borrow);
void check_detail(Detail& det, Borrow Bors[], const int& SizeOfBor);
int So_Ngay_Qua_Han(const Detail& det, Borrow Bors[], const int& SizeOfBor);

void Check_out(Borrow Bors[],int& size, Detail Dets[], int& SizeOfDet, Book Books[],const int& SizeOfBook, User us[], const int& SizeOfU);
void print_Borrow(Borrow Bor, Detail Dets[], const int& SizeOfDet, Book B[], const int& SizeOfB, User Us[], const int& SizeOfU);
void print_all_borrow(Borrow Bors[], const int& SizeOfBors, Detail Dets[], const int& SizeOfDet, Book B[], const int& SizeOfB, User Us[], const int& SizeOfU);
void check_borrow(Borrow& Bor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU);
void check_all_borrow(Borrow Bors[], const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU);

void Sach_Dang_Muon_id_U(const int& id_U, Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook, User Us[], const int& SizeOfU);
void Sach_Dang_Muon(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook, User Us[], const int& SizeOfU);
void Sach_Dang_Muon_id_U(Detail* DetOfU[], int& SizedetsOfU, const int& id_U, Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook);

void Check_in(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU);

void Don_Qua_Han(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU);
void In_Don_Theo_Ngay(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU);
void User_qua_han(Borrow Bors[],const int& SizeOfBor, User Us[], const int& SizeOfU);
void Sach_Chua_Tra(Book B[],const int& SizeOfBook, Detail Det[], const int& SizeOfDet);
#endif // THU_VIEN_H
