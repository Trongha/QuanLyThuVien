#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include "Thu_Vien.h"


using namespace std;


bool Yes(const string& ask){
    char Chon;
    do{
        cout << ask << endl;
        cout << " 1. Co\n 2. Khong" << endl;
        cout << " Lua chon: ";
        cin >> Chon;
    }while((Chon!='1') && (Chon!='2'));
    if (Chon == '1') return true;
    else return false;
}
bool check_string(string s1, string s2){
    if (s1.size() > s2.size()){
        string t=s1;
                s1=s2;
                s2=t;
    }
    int i;
    for (i=0 ; i <= (s2.size()-s1.size()) ; i++)
        if (s1 == s2.substr(i, s1.size()))
            return true;
    return false;
}
void search_string(string arr[], const int& size, string x, int vi_tri[], int &num_vitri){
    int i;
    num_vitri  = 0;
    for (i=1 ; i<=size ; i++)
        if (check_string(x, arr[i]))
            vi_tri[++num_vitri] = i;
}
bool check_int(string t){
    int i;
    for (i=0 ; i<t.size() ; i++)
        if ((t[i]<'0') || (t[i]>'9'))
            return false;
    return true;
}
int Convert_Char_Int(char t){
    return int(t-48);
}
int Input_int(string ask){
    string t;
    do{
        cout << ask << "  " ;
        cin >> t;
    }while (!check_int(t));

    int i=0;
    int n=0;
    while (i<=10 && i<t.size()){
        n*=10;
        n+=Convert_Char_Int(t[i]);
        i++;
    }
    return n;
}


string In_Hoa(string s){
    int i;
    for (i=0 ; i<s.size() ; i++)
        if (s[i] <= 'z' && s[i] >= 'a')
            s[i] = s[i] - 32;
    return s;
}
void stop(){
    fflush(stdin);
    cout << "\n            -----> ENTER <-----" << endl;
    cin.get();
}

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
    _Date.D = Input_int("   Ngay:  ");
    _Date.M = Input_int("   Thang: ");
    _Date.Y = Input_int("   Nam:   ");
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

bool check_Employee_UserName(string user, Employee Em[], const int& size){
    int i;
    int n=user.size();
    for (i=0 ; i < n ; i++)
        if ((user[i] < '0')||((user[i]>'9')&&(user[i]<'A'))|| ((user[i]>'Z')&&(user[i]<'a')) || (user[i]>'z'))
            return false;
    for (i=1 ; i<=size ; i++)
        if (user == Em[i].UserName)
            return false;
    return true;
}
Employee add_1_Employee(Employee Em[],const int& size){
    int id = Em[size].E_id + 1;
    Gender gen;
    Date Date_of_birth;
    string user_name, Pass, Name, address, Phone;
    cout << "Name: ";
    fflush(stdin);
    getline(cin, Name);

    do{
        cout << "UserName: ";
        fflush(stdin);
        getline(cin, user_name);
        if (!check_Employee_UserName(user_name, Em, size))
            cout << "UserName bi trung hoac khong hop le (Chi chua chu va so)" << endl;
    }while(!check_Employee_UserName(user_name, Em, size));

    cout << "Password: ";
    fflush(stdin);
    getline(cin, Pass);


    int i;
    do{
        i = Input_int(" 1. Nam\n 2. Nu\n Chon: ");
    }while(i<1 || i>2);

    if (i == 1) gen = MALE;
    else gen = FEMALE;

    cout << "Sinh Ngay? " << endl;
    add_Date(Date_of_birth);
    cout << "Address: ";
    fflush(stdin);
    getline(cin, address);
    cout << "Phone: ";
    fflush(stdin);
    getline(cin, Phone);
    return Employee(id, Name, user_name, Pass, address, Phone, Date_of_birth, gen);
}
void add_Employee(Employee Em[], int& size){
    int n;
    n = Input_int("Them may Employee?  ");
    int i;
    for (i=1 ; i<=n ; i++){
        cout << "-----Employees " << i << "-----" << endl;
        Em[size+1] = add_1_Employee(Em, size);
        size++;
    }
}
void print_Employees(){
    cout << "Vui long mo file Employee.csv xem nhe!!! Met lam roi :(" << endl;
}
void Delete_Employee(Employee Em[], int& size){
    cout << "-----Delete Employee-----" << endl;
    if (Yes("Ham nay chi mang tinh chat minh hoa, khong nen test. Test nua ko?")){
        if (Yes("Nhap id Employee can xoa\n Co 1 id chac chan dung la 124 \n  Co xem danh sach Employee ko?"))
            print_Employees();
        int id;
        id = Input_int("Dung nhap sai nhe, khong check dau. id: ");
        int i=0;
        while ((++i <= size) && (Em[i].E_id != id));
        for ( ; i<size ; i++)
            Em[i] = Em[i+1];
        size--;
        cout << "-----Xong-----" << endl;
    }
}

void print_u_fast(User u){
    cout << setw(10) << left  << setfill('_') << u.u_id << setw(25) << left << u.u_name ;
    cout << setw(2) << right << u.birthday.D << "/" << setw(2) << left << u.birthday.M ;
    cout << setw(17) << right << "Dang muon: " << max_borrow - u.num_book_allow << " quyen" << endl;
}
void print_u_fast(User Us[], const int& size, const int& id){
    int i;
    for (i=1 ; i<=size ; i++)
        if (id == Us[i].u_id){
            print_u_fast(Us[i]);
            break;
        }
}
void print_user(User u){
    cout << setfill(' ') << setw(10) << left << u.u_id << " | " << setw(25) << left << u.u_name << " | ";
    cout << setw(2) << right << u.birthday.D << "/" << setw(2) << right << u.birthday.M << "/" << setw(4) << u.birthday.Y << " | ";
    if (u.Gen == MALE)
        cout << setw(6) << "Male" << " | ";
    else
        cout << setw(6) << "FeMale" << " | ";
    cout << setw(12) << u.Phone << " | ";
    cout << setw(3) << u.num_book_allow << endl;
}
void print_User_array(User u[], const int& size){
    int i;
    cout << "_STT_|_____ID_____|___________Name____________|__BirthDay__|_Gender_|_Number_Phone_|_NumAllow" << endl;
    for (i=1 ; i<=size ; i++){
        cout << " " << setw(3) << left << setfill(' ') << i << " | ";
        print_user(u[i]);
    }
    cout << endl;
}
void print_all_u(User u[], const int& size){
    cout << "\n                                   DANH SACH BAN DOC" << endl;
    print_User_array(u, size);
}
User add_1_user(const int& id){
    string Name, phone;
    Date Date_of_birth;
    Gender gen;
    cout << "Name: ";
    fflush(stdin);
    getline(cin, Name);
    int i;
    do{
        i = Input_int(" 1. Nam\n 2. Nu\n Chon: ");
    }while(i<1 || i>2);
    if (i == 1) gen = MALE;
    else gen = FEMALE;

    cout << "Sinh Ngay? " << endl;
    add_Date(Date_of_birth);

    cout << "Phone: ";
    fflush(stdin);
    getline(cin, phone);
    return User(id, Name, Date_of_birth, gen, phone);
}
void add_user(User Us[], int& size){
    int n;
    n = Input_int("Them may nguoi?  ");
    for (int i=1 ; i<=n ; i++){
        cout << "----- User " << i << " -----" << endl;
        int id = Us[size].u_id + 1;
        size++;
        Us[size] = add_1_user(id);
    }
}
void Delete_User(User Us[], int& size){
    do{
        cout << "-----Delete User-----" << endl;
        int id;
        if (Yes("Nhap id can xoa. Ban muon xem danh sach User ko?"))
            print_all_u(Us, size);
        id = input_U_id(Us, size);
        cout << endl;
        print_u_fast(Us, size, id);
        if (Yes("Ban co chac muon xoa ko?")){
            int i = search_U(Us, size, id);
            for ( ; i<size ; i++)
                Us[i] = Us[i+1];
                size--;
            cout << "-----Done!-----" << endl;
        }
    }while (Yes("Xoa nua ko?"));
}
void insert_u(User us[], int& size, User u){
	us[++size] = u;
}
int search_U(User us[], const int& size, const int& id){
    int i=0;
    while ((++i <= size) && (us[i].u_id != id));
    return i;
}
User* search_U_Pro(User us[], const int& size, const int& id){
    int i=0;
    while ((++i <= size) && (us[i].u_id != id));
    return &us[i];
}
bool check_U(User us[], const int& size, const int& id){
    int i;
    for (i=1 ; i<=size ; i++)
        if (us[i].u_id == id)
            return true;
    return false;
}
int input_U_id(User Us[], const int& size){
    int U_id;
    bool check = true;
        do{
        U_id = Input_int("Id User: ");
        //cout << U_id;
        check = check_U(Us, size, U_id);
        if (!check)
            cout << "id sai cmnr!!!" << endl;
    }while (!check);
    return U_id;
}


int input_Book_id(Book B[], const int& size){
    int B_id;
    bool check = false;
        do{
        B_id = Input_int("Id book: ");
        check = check_book(B, size, B_id);
        if (!check)
            cout << "id sai cmnr!!!" << endl;
    }while (!check);
    return B_id;
}
void print_book( Book B){
    cout << "   " << B.B_id << " | " << B.Title << endl;
}
void printf_book_array(Book B[], const int& size){
    int i;
    cout << "_STT_|____ID____|_________________Title_______________________|_Name_Of_Author_|_Publish_House_|_Copies_|_Luot_Muon" << endl;
    for (i=1 ; i<=size ; i++){
        cout << setw(4) << left << setfill(' ') << i << " | ";
        print_book_detail(B[i]);
    }

    cout << endl;
}
void printf_all_book(Book B[], const int& size){
    cout << "                                       TAT CA SACH TRONG THU VIEN " << endl;
    printf_book_array(B, size);
}
void print_book(Book B[], const int& size, const int& id){
    int i;
    for (i=1 ; i<=size ; i++)
        if (id == B[i].B_id){
            print_book(B[i]);
            break;
        }
}
void print_book_detail(Book B){
    cout << setw(8) << B.B_id << " | ";
    cout << setw(43) << B.Title << " | ";
    cout << setw(14) << B.NameOfAuthor << " | ";
    cout << setw(13) << B.PublishHouse << " | ";
    cout << setw(6) << B.NumOfCopies << " | ";
    cout << setw(5) << B.So_Lan_Muon << endl;
}
Book add_1_book(const int& id){
    Book B;
    B.B_id = id;
    cout << "       Title: ";
    fflush(stdin);
    getline(cin , B.Title);
    cout << "       NumOfCopies: " ;
    cin >> B.NumOfCopies;
    cout << "       NameOfAuthor: ";
    fflush(stdin);
    getline(cin , B.NameOfAuthor);
    cout << "       PublishHouse: ";
    fflush(stdin);
    getline(cin , B.PublishHouse);
    return Book(id, B.Title, B.NumOfCopies,  B.NameOfAuthor, B.PublishHouse);
}
void add_Book(Book B[], int& size){
    int i, n;
    n = Input_int("   Them may quyen?     ");
    for (i=1 ; i<=n ; i++){
        size++;
        B[size].B_id = B[size-1].B_id + 1;
        cout << "----------Quyen " << i << "----------" << endl;
        B[size] = add_1_book(B[size].B_id);
    }
}
void Edit_Book(Book B[], int& size){

    int id;
    id = input_Book_id(B, size);

    int i = search_Book(B, size, id);
    print_book_detail(B[i]);
    int So_luot_muon = B[i].So_Lan_Muon;
    B[i] = add_1_book(id);
    B[i].So_Lan_Muon = So_luot_muon;
}
void Delete_Book(Book B[], int& size){
    do{
        int id;
        int rep;
        if (Yes("Nhap id sach can xoa, ban co muon tim sach ko?"))
            Search_Book_test(B, size);
        cout << "Xoa quyen nao?   ";
        id = input_Book_id(B, size);
        int i_b = search_Book(B, size, id);
        print_book(B[i_b]);
        if (Yes("Ban muon xoa quyen nay???")){
            cout << "------------------------------" << endl;
            print_book(B[i_b]);
            if (Yes("    Delete???")){
                do{
                    cout << "------------------------------" << endl;
                    print_book(B[i_b]);
                    rep = Input_int("Nhap 1 de xac nhan xoa \n");
                }while (rep != 1);
                cout << "------------------------------" << endl;
                print_book(B[i_b]);
                if (Yes("    Xoa?")){
                    while (i_b<size){
                        B[i_b] = B[i_b + 1];
                        i_b++;
                    }
                    size--;
                }
                cout << "-----------XONG-------------" << endl;
            }
        }
    }while (Yes("Xoa nua ko?"));
}
bool check_book(Book B[], const int& size, const int& id){
    int i;
    for (i=1 ; i<=size ; i++)
        if (B[i].B_id == id)
            return true;
    return false;
}
void check_num_book(Book B[],const int& size, const int& id, Status_book &check){
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
int search_Book(Book B[], const int& size, const int& id){
    int i=0;
    while ((i++ <= size) && (id != B[i].B_id));
    if (id != B[i].B_id){
        cout << "  Ko tim thay  ";
        return 0;
    }
    return i;
}
Book* search_Book_pro(Book B[], const int& size, const int& id){
    int i=0;
    while ((++i <= size) && (id != B[i].B_id));
    return &B[i];
}
void Top_Sach_muon_nhieu(Book B[], const int& size){
    int n;
    Book a[50];
    do{
        n = Input_int("Top may?\n     n = ");
        if (n>size) cout << "Chi co " << size << " dau sach" << endl;
    }while ((n<=0) || (n>size));
    int i, j;
    for (i=1 ; i<=n ; i++)
        a[i].So_Lan_Muon = 0;
    for (i=1 ; i<=size ; i++){
        j=1;
        while ((j<=n) && (a[j].So_Lan_Muon > B[i].So_Lan_Muon))
            j++;
        if (j<=n) {
            for (int k=n ; k>j ; k--)
                a[k] = a[k-1];
            a[j] = B[i];
        }

    }
    cout << "                              TOP " << n << " SACH CO LUOT MUON NHIEU NHAT" << endl;
        printf_book_array((a), n);

}
void Search_Book(Book B[], const int& size){
    do{
        int Vitri[1000];
        string arr[10000];
        int SizeOfVitri = 0;
        char t;
        string x;
        int i;
        do{
            cout << "1. Tim theo ten" << endl;
            cout << "2. Tim theo tac gia" << endl;
            cout << "3. Tim theo NXB" << endl;
            cin >> t;
        }while ((t != '1') && (t!= '2') && (t!='3'));
        if (t == '1'){
            for (i=1 ; i<=size ; i++)
                arr[i] = In_Hoa(B[i].Title);
            cout << "   Tim theo ten sach " << endl;
        }
        else if(t == '2'){
             for (i=1 ; i<=size ; i++)
                arr[i] = In_Hoa(B[i].NameOfAuthor);
            cout << "   Tim theo ten tac gia " << endl;
        }
        else if (t == '3'){
            for (i=1 ; i<=size ; i++)
                arr[i] = In_Hoa(B[i].PublishHouse);
            cout << "   Tim theo ten NXB " << endl;
        }
        cout << "String Search: " ;
        fflush(stdin);
        getline(cin, x);
        x=In_Hoa(x);

            cout << "\n   Searching.... .  .   .    .     .      ." << endl;
        search_string(arr, size, x, Vitri, SizeOfVitri);
        if (SizeOfVitri == 0)
            cout << " Khong tim thay" << endl;
        else{
            Book Bx[1000];
            for (i=1 ; i<=SizeOfVitri ; i++)
                Bx[i] = B[Vitri[i]];
            cout << "Cac sach tim thay:  " << endl;
            printf_book_array(Bx, SizeOfVitri);
        }
    }while (Yes("Co tim nua ko?"));
}

void Search_Book_test(Book book[], const int& size){
    do{
        int Vitri[1000];
        string arr[10000];
        int SizeOfVitri = 0;
        Book B[1000];
        char t, chon;
        string x="", tim="";
        int i, sodongbandau;
        bool kt_landau = true;
        do{
            cout << "1. Tim theo ten" << endl;
            cout << "2. Tim theo tac gia" << endl;
            cout << "3. Tim theo NXB" << endl;
            cin >> chon;
        }while ((chon != '1') && (chon!= '2') && (chon!='3'));
        system("cls");
        if (chon == '1')
            cout << "   Tim theo ten sach " << endl;
        if (chon == '2')
            cout << "   Tim theo ten tac gia " << endl;
        if (chon == '3')
            cout << "   Tim theo ten NXB" << endl;
        cout << "\n     String Search: ";
        for (i=1 ; i<=size ; i++)
            B[i] = book[i];
        int SizeOfB = size;
        x="";
        while(t = getche() , t != '\r'){
            system("cls");
            if (chon == '1'){
                for (i=1 ; i<=SizeOfB ; i++)
                    arr[i] = In_Hoa(B[i].Title);
                cout << "   Tim theo ten sach " << endl;
            }
            else if(chon == '2'){
                 for (i=1 ; i<=SizeOfB ; i++)
                    arr[i] = In_Hoa(B[i].NameOfAuthor);
                cout << "   Tim theo ten tac gia " << endl;
            }
            else if (chon == '3'){
                for (i=1 ; i<=SizeOfB ; i++)
                    arr[i] = In_Hoa(B[i].PublishHouse);
                cout << "   Tim theo ten NXB " << endl;
            }
            cout << "\n   Enter de ket thuc tim kiem :)" << endl;
            tim+=t;
            x=In_Hoa(tim);

            search_string(arr, SizeOfB, x, Vitri, SizeOfVitri);

            if (SizeOfVitri == 0)
                cout << "\n Khong tim thay" << endl;
            else{
                for (i=1 ; i<=SizeOfVitri ; i++)
                    B[i] = B[Vitri[i]];
                SizeOfB = i-1;
                cout << "Cac sach tim thay:  " << endl;
                printf_book_array(B, SizeOfB);

                if (kt_landau){
                    kt_landau = false;
                    cout << "\n     String Search: " ;
                    sodongbandau = SizeOfB;
                }else{
                    for (int i=1 ; i<=(sodongbandau - SizeOfB); i++)
                        cout << endl;
                    cout << "\n     String Search: " ;
                }
                cout << tim << endl;

            }

            fflush(stdin);
        }
    cout << endl;
    }while (Yes("Co tim nua ko?"));
}


int search_Borrow(Borrow Bors[], const int& SizeOfBor, const int& id){
    int i=0;
    while ((++i <= SizeOfBor) && (Bors[i].borrow_id != id));
    return i;
}
Borrow* search_Borrow_Pro(Borrow Bors[], const int& SizeOfBor, const int& id){
    int i=0;
    while ((++i <= SizeOfBor) && (Bors[i].borrow_id != id));
    return &Bors[i];
}
void Check_out(Borrow Bors[],int& size, Detail Dets[], int& SizeOfDet, Book Books[],const int& SizeOfBook, User us[], const int& SizeOfU){
    int num_book, id_book;
    int i;
    int U_id;
    bool check = false;
    Detail* DetailOfU[11] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int SizeDetailOfU;
    User *UserX = NULL;
    Status_book Check = het;
    Date D_strat, D_finish;
    Date a;

    U_id = input_U_id(us, SizeOfU);
    UserX = search_U_Pro(us, SizeOfU, U_id);

    do{
        cout << "\nNgay muon: " << endl;
        cout << "   1. Hom nay" << endl;
        cout << "   2. Nhap ngay" << endl;
        int lua_chon = Input_int("");
        if (lua_chon >=1 && lua_chon <=2){
            check = true;
            if (lua_chon == 1)
                D_strat = ToDay();
            else add_Date(D_strat);
        }
    }while (!check);
    cout << "Ngay muon: ";
    print_Date(D_strat);
    D_finish = Cong(D_strat, 20);

    print_u_fast(*UserX);
    cout << "Cac sach dang muon: " << endl;
    Sach_Dang_Muon_id_U(DetailOfU, SizeDetailOfU, U_id, Bors, size, Dets, SizeOfDet, Books, SizeOfBook);
    do{
        num_book = Input_int("\nSo' sach muon: ");
        if (num_book >= (*UserX).num_book_allow)
            cout << "Ko duoc muon qua " << (*UserX).num_book_allow << " quyen" << endl;
    }while(num_book >= (*UserX).num_book_allow);

    size++;
    Bors[size] = Borrow(size, U_id, num_book, D_strat, D_finish);

    for (i=1 ; i<= num_book; i++){
        do {
            do{
                cout << "-----Quyen " << i << "-----" << endl;
                id_book = Input_int("Ma sach: ");
                check = check_book(Books, SizeOfBook, id_book);
                if (!check)
                    cout << "  id sai cmnr!!!"<< endl;
            }while (!check);

            for (int j=1 ; j<=SizeDetailOfU ; j++)
                if ((*DetailOfU[j]).Book_id == id_book){
                    check = false;
                    print_book(Books, SizeOfBook, id_book);
                    cout << "Ban dang muon quyen nay roi!" << endl;
                }

            if (check) check_num_book(Books, SizeOfBook, id_book, Check);
        } while(Check == het);
        (*UserX).num_book_allow--;
        Dets[++SizeOfDet] = Detail(size, id_book, ChuaQuaHan);
        cout << "   Muon thanh cong Quyen " << i << " : ";
        print_book(Books, SizeOfBook, id_book);
        Book* B = search_Book_pro(Books, SizeOfBook, id_book);
        (*B).So_Lan_Muon++;
    }
    cout << "\nXong!!!" << endl;
    if (Yes(" Co xem phieu muon ko?"))
        print_Borrow(Bors[size], Dets, SizeOfDet, Books, SizeOfBook, us, SizeOfU);
}

int search_Detail(Detail Dets[], const int& SizeOfDets, const Detail& Det){
    int i=0;
    while ((++i <= SizeOfDets) && (Det.Book_id != Dets[i].Book_id) && (Det.Borrow_id) != Dets[i].Borrow_id);
    return i;
}
int search_Detail(Detail Dets[], const int& SizeOfDets, const int& id_borrow){
    int i=0;
    while ((++i <= SizeOfDets) && (Dets[i].Borrow_id != id_borrow));
    return i;
}
Detail* search_Detail_Pro(Detail Dets[], const int& SizeOfDets, const int& id_borrow){
    int i=0;
    while ((++i <= SizeOfDets) && (Dets[i].Borrow_id != id_borrow));
    return &Dets[i];
}
void print_Det(Detail Det, Book B[], const int& SizeOfBook, Borrow Bors[], const int& SizeOfBor){
    int i;
    check_detail(Det, Bors, SizeOfBor);
    for (i=1 ; i<= SizeOfBook ; i++)
        if (Det.Book_id == B[i].B_id){
            cout << setw(45) << left << setfill('_') << B[i].Title << setw(10) << B[i].B_id;
            if (Det.Stt_Det == ChuaQuaHan){
                cout << " Chua tra, chua qua han    ";
                int j=0;
                //int j=search_Borrow(Bors, SizeOfBor, Det.Borrow_id);
         while ((++j <= SizeOfBor) && (Bors[j].borrow_id != Det.Borrow_id));
                print_Date(Bors[j].due_Date);
            }
            else if (Det.Stt_Det == Quahan){
               // int j=search_Borrow(Bors, SizeOfBor, Det.Borrow_id);
               int j=0;
               while ((++j <= SizeOfBor) && (Bors[j].borrow_id != Det.Borrow_id));
                cout << " Chua tra, qua han " << Num_Date(Bors[j].due_Date, ToDay()) << " ngay ";

                print_Date(Bors[j].due_Date);
            }
            else cout << " Tra lau roi." << endl;
        }
}

void check_borrow(Borrow& Bor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    if (Bor.BorrowStatus == Chua_Tra_Het){
        int n_day = Num_Date(Bor.due_Date, ToDay());
        if (n_day > 0){
            Bor.fine = 0;
            int i0 = 0;
            while (Dets[++i0].Borrow_id != Bor.borrow_id);
            for (int i=i0 ; i < i0 + Bor.num ; i++)
                if (Dets[i].Stt_Det != DaTra){
                    if (Dets[i].Stt_Det == ChuaQuaHan)
                        Dets[i].Stt_Det = Quahan;
                    Bor.fine += n_day * everyday;
                }
            if (Bor.fine == 0)
                Bor.BorrowStatus = Da_Tra_Het;
        }
    }
}
void check_all_borrow(Borrow Bors[], const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    int i;
    for (i=1 ; i<=SizeOfBor ; i++)
        check_borrow(Bors[i], Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
}

void print_Borrow(Borrow Bor, Detail Dets[], const int& SizeOfDet, Book B[], const int& SizeOfB, User Us[], const int& SizeOfU){
    int i, j;
    cout << "\n---------------------------ID Borrow: " << Bor.borrow_id << "---------------------------" << endl;
    cout << "Nguoi muon: " ;
    print_u_fast(Us, SizeOfU, Bor.User_id);
    cout << "-------------" << endl;
    cout << "Ngay muon: ";      print_Date(Bor.start_Date);
    cout << "Han tra:   ";        print_Date(Bor.due_Date);
    cout << "-------------" << endl;
    i = 0;
    while (Bor.borrow_id != Dets[++i].Borrow_id);
    cout << "  Muon " << Bor.num << " quyen gom: " << endl;
    for (j=1 ; j<=Bor.num ; j++){
        cout << " Quyen thu " << j << " la: ";
        print_book(B, SizeOfB, Dets[i+j-1].Book_id);
        if (Dets[i+j-1].Stt_Det == DaTra)
            cout << "                       Da Tra" << endl;
        else if (Dets[i+j-1].Stt_Det == ChuaQuaHan)
            cout << "                      Chua qua han" << endl;
        else cout << "                     Qua han cmnr!!!" << endl;
    }
    cout << "\n                    Tien no: " << Bor.fine << " cent" <<endl;
    cout << "__________________________________________________________________" << endl << endl;
}
void print_all_borrow(Borrow Bors[], const int& SizeOfBors, Detail Dets[], const int& SizeOfDet, Book B[], const int& SizeOfB, User Us[], const int& SizeOfU){
    int i;
    check_all_borrow(Bors, SizeOfBors, Dets, SizeOfDet, B, SizeOfB, Us, SizeOfU);
    for (i=1 ; i<=SizeOfBors ; i++)
        print_Borrow(Bors[i], Dets, SizeOfDet, B, SizeOfB, Us, SizeOfU);
}

void Sach_Dang_Muon_id_U(const int& id_U, Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook){
    int i, j, Dem=0;
    for (i=1 ; i<=SizeOfBor ; i++)
        if (id_U == Bors[i].User_id){
            j=search_Detail(Dets, SizeOfDet, Bors[i].borrow_id);
            while (Bors[i].borrow_id == Dets[j].Borrow_id){
                check_detail(Dets[j], Bors, SizeOfBor);
                if (Dets[j].Stt_Det != DaTra){
                    Dem++;
                    cout << Dem << " : ";
                    print_Det(Dets[j], Books, SizeOfBook, Bors, SizeOfBor);
                }
                j++;
            }
        }
}
void Sach_Dang_Muon(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    int id_U;
    if (Yes("Phai nhap id ban doc. Co xem danh sach ban doc ko?"))
        print_all_u(Us, SizeOfU);
    id_U = input_U_id(Us, SizeOfU);
    Sach_Dang_Muon_id_U(id_U, Bors, SizeOfBor, Dets, SizeOfDet, Books, SizeOfBook);
}

void Sach_Dang_Muon_id_U(Detail* DetOfU[], int& SizedetsOfU, const int& id_U, Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book Books[],const int& SizeOfBook){
    // Ham nay cho cac Detail vao array;
    int i, j;
    SizedetsOfU = 0;
    for (i=1 ; i<=SizeOfBor ; i++)
        if (id_U == Bors[i].User_id){
            j=search_Detail(Dets, SizeOfDet, Bors[i].borrow_id);
            while (Bors[i].borrow_id == Dets[j].Borrow_id){
                check_detail(Dets[j], Bors, SizeOfBor);
                if (Dets[j].Stt_Det != DaTra){
                    SizedetsOfU++;
                    cout << SizedetsOfU << " : ";
                    print_Det(Dets[j], Books, SizeOfBook, Bors, SizeOfBor);
                    DetOfU[SizedetsOfU] = &Dets[j];
                }
                j++;
            }
        }
}

void Check_in(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    int id_U, stt; //So thu tu;
    User* U = NULL;
    Book* BookX = NULL;
    Borrow* BorrowX = NULL;
    int ask;
    Detail* DetOfU[11] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int SizeDetOfU;
    cout << "//-----------Tra_Sach-----------//" << endl;
    id_U = input_U_id(Us, SizeOfU);
    U = search_U_Pro(Us, SizeOfU, id_U);
    do{
        print_u_fast(*U);
        cout << "  Cac sach chua tra: " << endl;
        Sach_Dang_Muon_id_U(DetOfU, SizeDetOfU, id_U, Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook);
        if (SizeDetOfU == 0)
            cout << "Chua muon quyen nao.";
        else{
        cout << "\n" << " Muon tra quyen thu may? Chon so sach tu 1 den " << SizeDetOfU << " :";
        stt = Input_int("");

        BookX = search_Book_pro(B, SizeOfBook, (*DetOfU[stt]).Book_id);
        BorrowX = search_Borrow_Pro(Bors, SizeOfBor, (*DetOfU[stt]).Borrow_id);

        print_book(*BookX);
        cout << "   Han tra la: ";

        print_Date((*BorrowX).due_Date);
        cout << "   Hom nay la: ";
        print_Date(ToDay());
        if ((*DetOfU[stt]).Stt_Det == Quahan){
            int Qua_Han = Num_Date((*BorrowX).due_Date, ToDay());
            cout << "Qua han " << Qua_Han << " ngay, thanh toan: " << Qua_Han*everyday << " cent." << endl;
        }
        else
            cout << "Chua qua han" << endl;
        do{
            ask = Input_int("Nhap  1  de xac nhan tra sach (va xac nhan da thanh toa'n) \n");
            if (ask) {
                (*BookX).NumOfCopies++;
                (*U).num_book_allow++;
                (*DetOfU[stt]).Stt_Det = DaTra;
                cout << "Tra sach thanh cong!" << endl;
            }
        }while (ask != 1);
    }
    cout << "Tra nua ko? " << endl;
    cout << "    1. Co" << endl;
    cout << "    2. Ko" << endl;
    ask = Input_int("");
    }while (ask == 1);
}

void check_detail(Detail& det, Borrow Bors[], const int& SizeOfBor){
    if (det.Stt_Det != DaTra){
        int i_bors = search_Borrow(Bors, SizeOfBor, det.Borrow_id);
        int num_day = Num_Date(Bors[i_bors].due_Date, ToDay());
        if (num_day <= 0)
            det.Stt_Det = ChuaQuaHan;
        else det.Stt_Det = Quahan;
    }

}
void Don_Qua_Han(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    int i;
   // check_all_borrow(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
    for (i=1 ; i<=SizeOfBor ; i++){
        check_borrow(Bors[i], Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
        if (Bors[i].fine > 0)
            print_Borrow(Bors[i], Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
    }
}
void In_Don_Theo_Ngay(Borrow Bors[],const int& SizeOfBor, Detail Dets[],const int& SizeOfDet, Book B[],const int& SizeOfBook, User Us[], const int& SizeOfU){
    Date Ngay_Can_in;
    int num_day;
    do{
        cout << "Nhap Ngay: " << endl;
        add_Date(Ngay_Can_in);
        num_day = Num_Date(ToDay(), Ngay_Can_in);
        if (num_day > 0)
            cout << "Chua den ngay nay." << endl;
    }while (num_day > 0);

    int i=1;
    while ((i<=SizeOfBor) && (Num_Date(Ngay_Can_in, Bors[i].start_Date) != 0))
        i++;
    if (Num_Date(Ngay_Can_in, Bors[i].start_Date) == 0){
        while ((i<=SizeOfBor) && (Num_Date(Ngay_Can_in, Bors[i].start_Date) == 0)){
            check_borrow(Bors[i], Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
            print_Borrow(Bors[i], Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
            i++;
        }
    }
    else{
        cout << "Ngay " ;
        print_Date(Ngay_Can_in);
        cout << " ko co ai muon sach." << endl;
    }
}

void User_qua_han(Borrow Bors[],const int& SizeOfBor, User Us[], const int& SizeOfU){
    bool Danh_Dau[1000] = {false};
    int i;
    for (i=1 ; i<=SizeOfBor ; i++){
        if (Bors[i].BorrowStatus == Chua_Tra_Het){
            if (Num_Date(Bors[i].due_Date, ToDay()) > 0){
                int Vi_tri=search_U(Us, SizeOfU, Bors[i].User_id);
                Danh_Dau[Vi_tri] = true;
            }
        }
    }
    User U[1000];
    int j=0;
    for (i=1 ; i<=SizeOfU ; i++)
        if (Danh_Dau[i])
            U[++j] = Us[i];
    cout << "                              DANH SACH QUA HAN" << endl;
    print_User_array(U, j);
}
void Sach_Chua_Tra(Book B[],const int& SizeOfBook, Detail Det[], const int& SizeOfDet){
    int i;
    bool Danh_dau[1000] = {false};
    int Dem[1000] = {0};
    for (i=1 ; i<=SizeOfDet ; i++)
        if (Det[i].Stt_Det != DaTra){
            int Vi_tri = search_Book(B, SizeOfBook, Det[i].Book_id);
            Danh_dau[Vi_tri] = true;
            Dem[Vi_tri]++;
        }
    cout << "Cac sach chua tra la: " << endl;
    int j=0;
    for (i=1 ; i<=SizeOfBook ; i++)
        if (Danh_dau[i]){
            cout << setw(3) << setfill(' ') << right << ++j << ": " ;
            cout << B[i].B_id << " | " << setw(50) << left << B[i].Title ;
            cout << "x" << Dem[i] << " quyen chua tra" << endl;
        }
}

//void Status_Borrow(Borrow Bor )



