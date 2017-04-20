#include <iostream>
#include <iomanip>
#include <ctime>
#include "Thu_Vien.h"

using namespace std;

int NamNhuan (int y){
	if(y%400==0 || (y%4==0 && y%100!=0))
		return 1;
	return 0;
};
Date Cong(Date _Date, int num){
   int Thang[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
   _Date.D += num;
   while (_Date.D > Thang[_Date.M]){
        if (NamNhuan(_Date.Y)) Thang[2]=29;
            else Thang[2]=28;
        _Date.D -= Thang[_Date.M];
        if (_Date.M < 12)
                _Date.M++;
            else {
                _Date.M = 1;
                _Date.Y++;
            }
   }
   return _Date;
}
void add_Date(Date& _Date){
    cout << "Ngay: ";
    cin >> _Date.D;
    cout << "Thang: ";
    cin >> _Date.M;
    cout << "Nam: ";
    cin >> _Date.Y;
}
void print_Date (const Date& _Date){
    cout << " " << _Date.D << "/" << _Date.M << "/" << _Date.Y << endl;
}
Date ToDay(){
    tm* today;
    time_t ltime;
    time(&ltime);
    today = localtime(&ltime);
    return (Date(today->tm_mday, today->tm_mon+1, today->tm_year+1900));
}
int WTF_MAGIC(Date _Date){           // Tinh so ngay tu 31/12/1899
    if (_Date.M < 3){
        _Date.Y--;
        _Date.M +=12;
    }
    return 365*_Date.Y + _Date.Y/4 - _Date.Y/100 + _Date.Y/400 + (153*_Date.M - 457)/5 + _Date.D - 306;
}
int Num_Date(Date start, Date finish){
    return (WTF_MAGIC(finish) - WTF_MAGIC(start));
}

void print_u(User u){
    cout << setw(10) << left  << setfill('_') << u.u_id << setw(25) << left << u.u_name << u.birthday.D << "/" << u.birthday.M << endl;
}
void print_u_id(User Us[], const int& size, const int& id){
    int i;
    for (i=1 ; i<=size ; i++)
        if (id == Us[i].u_id){
            print_u(Us[i]);
            break;
        }
}
void print_all_u(User u[],const int& size){
	int i;
	cout << "----------------------------" << endl;
	cout << "    Danh sach nguoi dung: " << endl;
	for (i=1 ; i<=size ; i++)
		print_u(u[i]);
    cout << "----------end---------------" << endl;
}
void insert_u(User us[], int& size, User u){
	us[++size] = u;
}


void print_book( Book B){
    cout << "   " << B.B_id << " | " << setw(45) << left << setfill('_')<< B.Title << "x" << B.NumOfCopies << endl;
}
void printf_all_book(Book B[], const int& size){
    int i;
    cout << "   Tat ca sach trong thu vien: " << endl;
    for (i=1 ; i<=size ; i++)
        print_book(B[i]);
    cout << endl;
}
void print_book_id(Book B[], const int& size, const int& id){
    int i;
    for (i=1 ; i<=size ; i++)
        if (id == B[i].B_id){
            print_book(B[i]);
            break;
        }
}
void check_out(Book B[],const int& size, const int& id, Status_book &check){
    int i;
    for (i=1 ; i<=size ; i++)
        if (id == B[i].B_id){
            if (0 == B[i].NumOfCopies){
                cout << "Quyen " << B[i].Title << " da bi muon het" << endl;
                check = het;
            }else{
                B[i].NumOfCopies--;
                check = con;
            }
            break;
        }
}
int search_Book_id(Book B[], const int& size, const int& id){
    int i=0;
    while ((i++ <= size) && (id != B[i].B_id));
    if (id != B[i].B_id){
        cout << "  Ko tim thay  ";
        return 0;
    }
    return i;
}

int search_Borrow_id(Borrow Bors[], const int& SizeOfBor, const int& id){
    int i=0;
    while ((++i <= SizeOfBor) && (Bors[i].borrow_id != id));
    return i;
}
void add_Borrow(Borrow Bors[],int& size, Detail Dets[], int& SizeOfDet, Book Books[],const int& SizeOfBook){
    int num_book, id_book;
    int i;
    Status_book Check;
    Date D_strat, D_finish;
    int U_id;

    cout << "\n\n\nNgay muon: ";
    print_Date(ToDay());
    D_strat = ToDay();
    D_finish = Cong(D_strat, 20);
    cout << "Id sinh vien: ";
    cin >> U_id;
    cout << "So' sach muon: ";
    cin >> num_book;

    size++;
    Bors[size] = Borrow(size, U_id, num_book, D_strat, D_finish);
    Bors[size].fine = 0;
//    Bors[size].BorrowStatus = ChuaQuaHan;

    for (i=1 ; i<= num_book; i++){
        do {
            cout << "-----Quyen " << i << "-----" << endl;
            cout << "Ma sach: ";
            cin >> id_book;
            check_out(Books, SizeOfBook, id_book, Check);
        } while(Check == het);
        Dets[++SizeOfDet] = Detail(size, id_book, ChuaQuaHan);
    }
}

int search_Detail(Detail Dets[], const int& SizeOfDets, const Detail& Det){
    int i=0;
    while ((++i <= SizeOfDets) && (Det.Book_id == Dets[i].Book_id) && (Det.Borrow_id) == Dets[i].Borrow_id);
    return i;
}
void print_Det(Detail Det, Book B[], const int& SizeOfBook, Borrow Bors[], const int& SizeOfBor){
    int i;
    for (i=1 ; i<= SizeOfBook ; i++)
        if (Det.Book_id == B[i].B_id){
            cout << setw(45) << left << setfill('_') << B[i].Title << setw(10) << B[i].B_id;
            if (Det.Stt_Det == ChuaQuaHan){
                cout << "  Chua tra, chua qua han  ";
                int j=0;
                while ((++j <= SizeOfBor) && (Bors[j].borrow_id != Det.Borrow_id));
                print_Date(Bors[j].due_Date);
            }
            else if (Det.Stt_Det == Quahan){
                cout << " Chua tra, qua han cmnr!!!" ;
                int j=0;
                while ((++j <= SizeOfBor) && (Bors[j].borrow_id != Det.Borrow_id));
                print_Date(Bors[j].due_Date);
            }
            else cout << " Tra lau roi." << endl;
        }
}

void print_Borrow(Borrow Bor, Detail Dets[], const int& SizeOfDet, Book B[], const int& SizeOfB, User Us[], const int& SizeOfU){
    int i, j;
    cout << "-----------------ID Borrow: " << Bor.borrow_id << "-----------------" << endl;
    cout << "Nguoi muon: " ;
    print_u_id(Us, SizeOfU, Bor.User_id);
    cout << "Ngay muon: ";      print_Date(Bor.start_Date);
    cout << "Han tra: ";        print_Date(Bor.due_Date);
    for (i=1 ; i<= SizeOfDet ; i++)
        if (Bor.borrow_id == Dets[i].Borrow_id)
                break;
    cout << "Muon " << Bor.num << " quyen gom: " << endl;
    for (j=1 ; j<=Bor.num ; j++){
        if (Dets[i+j-1].Stt_Det != DaTra){
            cout << " Quyen thu " << j << " la: ";
            print_book_id(B, SizeOfB, Dets[i+j-1].Book_id);
            if (Dets[i+j-1].Stt_Det == ChuaQuaHan)
                cout << "_________Chua qua han" << endl;
                else cout << "________Qua han cmnr!!!" << endl;
        }
    }
}

void Sach_Dang_Muon_id_U(const int& id_U, Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    int i, j=1, k;
    for (i=1 ; i<=SizeOfBor ; i++)
        if (id_U == Bors[i].User_id){
            for ( ; j<=SizeOfDet ; j++){
                if (Bors[i].borrow_id == Dets[j].Borrow_id)
                    for (k=1 ; k<= Bors[i].num ; k++)
                        if (Dets[j].Stt_Det != DaTra)
                            print_Det(Dets[j++], Books, SizeOfBook, Bors, SizeOfBor);
                break;
            }
        }
}
void Sach_Dang_Muon(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    int id_U;
    cout << "Ma Sinh Vien: ";
    cin >> id_U;
    Sach_Dang_Muon_id_U(id_U, Bors, SizeOfBor, Dets, SizeOfDet, Books, SizeOfBook, Us, SizeOfU);
}

void Sach_Dang_Muon_id_U(Detail DetOfU[], int& SizedetsOfU, const int& id_U, Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    int i, j=1, k;
    SizedetsOfU = 0;
    for (i=1 ; i<=SizeOfBor ; i++)
        if (id_U == Bors[i].User_id){
            for ( ; j<=SizeOfDet ; j++){
                if (Bors[i].borrow_id == Dets[j].Borrow_id)
                    for (k=1 ; k<= Bors[i].num ; k++)
                        if (Dets[j].Stt_Det != DaTra){
                            cout << ++SizedetsOfU << " : ";
                            print_Det(Dets[j], Books, SizeOfBook, Bors, SizeOfBor);
                            DetOfU[SizedetsOfU] = Dets[j];
                            j++;
                        }
                break;
            }
        }
}

void Check_in(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    int id_U, stt;
    int i_book, i_Det, i_bor;
    int ask;
    Detail DetOfU[10];
    int SizeDetOfU;
    cout << "//-----------Tra_Sach-----------//" << endl;
    cout << "Ma Sinh Vien: ";
    cin >> id_U;
    do{
        cout << "  Cac sach chua tra: " << endl;
        Sach_Dang_Muon_id_U(DetOfU, SizeDetOfU, id_U, Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);

        cout << "\n" << " Muon tra quyen thu may? Chon so sach tu 1 den " << SizeDetOfU << " :";
        cin >> stt;
        i_book = search_Book_id(B, SizeOfBook, DetOfU[stt].Book_id);
        i_bor = search_Borrow_id(Bors, SizeOfBor, DetOfU[stt].Borrow_id);
        i_Det = search_Detail(Dets, SizeOfDet, DetOfU[stt]);

        cout << "\n   ";
        print_book_id(B, SizeOfBook, i_book);
        cout << "Han tra la: ";
        print_Date(Bors[i_bor].due_Date);
        cout << "Hom nay la: ";
        print_Date(ToDay());
        cout << "Qua han hay chua thi tu tinh di" << endl;
        do{
            cout << "Nhap  1  de xac nhan tra sach" << endl;
            cin >> ask;
            if (ask) {
                B[i_book].NumOfCopies++;
                Dets[i_Det].Stt_Det = DaTra;
                cout << "Tra sach thanh cong!" << endl;
            }
        }while (ask != 1);
    cout << "Tra nua ko? " << endl;
    cout << "    1. Co" << endl;
    cout << "    2. Ko" << endl;
    cin >> ask;
    }while (ask == 1);
}





