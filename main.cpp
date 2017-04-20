//Trong HA
#include <iostream>

#include "Thu_Vien.h"
#include "Test_inp.h"
#include "View.h"
#include "data.h"

using namespace std;


int main()
{
    User Us[1000];
	User Test;
	Employee Employees[20];
	Book Books[10000];
	Borrow Bors[10000];
	Detail Dets[100000];
	int Size_User = 0, Size_Bors = 0, Size_Dets = 0, Size_Books = 0, Size_employee = 0;

    Set_console();
    file_read_Employee(Employees, Size_employee);
    Start(Employees, Size_employee);

    file_read_user(Us, Size_User);
    file_read_book(Books, Size_Books);
    file_read_borrow(Bors, Size_Bors);
    file_read_Detail(Dets, Size_Dets);
    //inp_Bor(Bors, Size_Bors, Dets, Size_Dets, Size_User, Books, Size_Books, Us);
    //Search_Book(Books, Size_Books);

    Home(Bors, Size_Bors, Dets, Size_Dets, Books, Size_Books, Us, Size_User, Employees, Size_employee);

    file_print_Book(Books, Size_Books);
    file_print_User(Us, Size_User);
    file_print_Borrow(Bors, Size_Bors);
    file_print_Detail(Dets, Size_Dets);
    file_print_Employee(Employees, Size_employee);

    return 0;
}
