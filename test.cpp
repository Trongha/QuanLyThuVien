#include <iostream>
#include <string>
#include <fstream>
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

int main(){
	int size=0;
	Borrow Bors[100];
	fstream a;
	ifstream file_in;
    string x;
    char t;
    file_in.open("Borrow.csv");
    getline(file_in, x, '\n');
    while (getline(file_in, x, ',')!=NULL){
        size++;
        cout << size << endl;
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
    cout << "xong";
    file_in.close();
    
	return 0;
}
