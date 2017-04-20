#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "View.h"
#include "Thu_Vien.h"


using namespace std;

string  Link = "";

void Set_console(){
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1300, 780, TRUE);
}

void stop1(){
    cout << "       -----> ENTER <-----" << endl;
    cin.get();
}
void clean(){
    system("cls");
    cout << "\n " ;
    print_Date(ToDay());
    cout << "   Link: " << Link << endl << endl;
}
void next_page(const string& Name_page){
    Link += " > " + Name_page;
}
void Out_page(const string& Name_page){
    Link = Link.erase((Link.size()-Name_page.size() - 3), Name_page.size() + 3);
}
void next_and_clean(const string& Name_page){
    next_page(Name_page);
    clean();
}
void Out(const string& Name_page){
    stop();
    Out_page(Name_page);
}

void login(Employee Em[], const int& size){
    int i = 1;
    string user;
    bool check = false;
    do{
        do{
            cout << "   User Name: ";
            cin >> user;
            i=0;
            while ((i<=size) && (Em[i].UserName != user))
                i++;
            if (i>size)
                cout << "   Sai Ten Dang Nhap" << endl;
        } while (i>size);
        cout << "   Password: ";
        string pass;
        cin >> pass;
        if (pass == Em[i].Pass) {
            cout << "   Dang nhap thanh cong " << endl;
            check = true;
        }else cout << "    Sai mat khau" << endl;
    }while (!check);
    Link = Em[i].e_Name;
    stop();
}

void Start(Employee Em[], const int& size){
    char chon;
    do{
        cout << endl;
        cout << "   1. Login" << endl;
        cout << "   2. Review" << endl;
        cout << "  Lua chon: ";
        cin >> chon;
    }while (chon != '1' && chon != '2');

    if (chon == '1')
        login(Em, size);
    else Link = "Review";
}


void Quan_ly_sach(Borrow Bors[],int& SizeOfBor, Detail Dets[],int& SizeOfDet, Book B[],int& SizeOfBook, User Us[], int& SizeOfU){
    char Chon;
    string Name_page = "Quan_ly_sach";
    next_page(Name_page);
    do{
    clean();
    cout << "        ___________________________Quan_Ly_Sach_________________________" << endl;
    cout << "       |                  1. Tat ca sach trong thu vien                 |" << endl;
    cout << "       |                  2. Tim sach (hay)                             |" << endl;
    cout << "       |                  3. Them sach                                  |" << endl;
    cout << "       |                  4. Sua thong tin sach                         |" << endl;
    cout << "       |                  5. Xoa Dau Sach                               |" << endl;
    cout << "       |                  6. Cac sach chua tra                          |" << endl;
    cout << "       |                  7. TOP sach duoc muon nhieu nhat              |" << endl;
    cout << "       |                  8. Thoat                                      |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |________________________________________________________________|" << endl;
    cout << "                           Lua chon: " ;
        cin >> Chon;
        switch(Chon){
            case '1':{
                string Name_page = "Sach_Trong_Thu_Vien";
                next_and_clean(Name_page);
                printf_all_book(B, SizeOfBook);
                Out(Name_page);
                break;
            }
            case '2':{
                string Name_page = "Tim_sach";
                next_and_clean(Name_page);
                Search_Book_test(B, SizeOfBook);
                Out(Name_page);
                break;
            }
            case '3':{
                string Name_page = "Them_sach";
                next_and_clean(Name_page);
                add_Book(B, SizeOfBook);
                stop1();
                Out_page(Name_page);
                break;
            }
            case '4':{
                string Name_page = "Sua_thong_tin_sach";
                next_and_clean(Name_page);
                Edit_Book(B, SizeOfBook);
                stop1();
                Out_page(Name_page);
                break;
            }
            case '5':{
                string Name_page = "Top_Sach_Co_Luot_Muon_Nhieu";
                next_and_clean(Name_page);
                Delete_Book(B, SizeOfBook);
                Out(Name_page);
                break;
            }
            case '6':{
                string Name_page = "Cac_sach_chua_tra";
                next_and_clean(Name_page);
                Sach_Chua_Tra(B, SizeOfBook, Dets, SizeOfDet);
                Out(Name_page);
                break;
            }
            case '7':{
                string Name_page = "Top_Sach_Co_Luot_Muon_Nhieu";
                next_and_clean(Name_page);
                Top_Sach_muon_nhieu(B, SizeOfBook);
                Out(Name_page);
                break;
            }
            case '8':{
                Out_page(Name_page);
                break;
            }
        }
    }while (Chon != '8');
}

void Quan_ly_User(Borrow Bors[],int& SizeOfBor, Detail Dets[],int& SizeOfDet, Book B[],int& SizeOfBook, User Us[], int& SizeOfU){
    string Name_page = "Quan_ly_ban_doc";
    next_page(Name_page);
    char Chon;
    do{
    clean();
    cout << "        ______________________________USER______________________________" << endl;
    cout << "       |                  1. Tat ca ban doc                             |" << endl;
    cout << "       |                  2. Them ban doc                               |" << endl;
    cout << "       |                  3. Xoa thong tin ban doc                      |" << endl;
    cout << "       |                  4. Nhung ban muon sach qua han                |" << endl;
    cout << "       |                  5. Tra cuu sach dang muon                     |" << endl;
    cout << "       |                  6. Nhung ban dang muon sach                   |" << endl;
    cout << "       |                  7. Thoat                                      |" << endl;
    cout << "       |                                                                | " << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |________________________________________________________________|" << endl;
    cout << "                        Lua chon: " ;
        cin >> Chon;
        switch(Chon){
            case '1':{
                string Name_page = "Tat_ca_ban_doc";
                next_and_clean(Name_page);
                print_all_u(Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '2':{
                string Name_page = "Them_ban_doc";
                next_and_clean(Name_page);
                add_user(Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '3':{
                string Name_page = "Xoa_thong_tin_ban_doc";
                next_and_clean(Name_page);
                Delete_User(Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '4':{
                string Name_page = "Nhung_ban_muon_qua_han";
                next_and_clean(Name_page);
                User_qua_han(Bors, SizeOfBor, Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '5':{
                string Name_page = "Tra_cuu_sach_dang_muon";
                next_and_clean(Name_page);
                Sach_Dang_Muon(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '6':{
                string Name_page = "Nhung_ban_dang_muon_sach";
                next_and_clean(Name_page);
                cout << "\n   updating system...... .  .   .    .     .      :)  \n\n" << endl;
                Out(Name_page);
                break;
            }
            case '7':{
                Out_page(Name_page);
                break;
            }
        }
    }while (Chon != '7');

}

void Quan_ly_Borrow(Borrow Bors[],int& SizeOfBor, Detail Dets[],int& SizeOfDet, Book B[],int& SizeOfBook, User Us[], int& SizeOfU){
    string Name_page = "Quan_ly_phieu_muon";
    next_page(Name_page);
    char Chon;
    do{
    clean();
    cout << "        _____________________________BORROW_____________________________" << endl;
    cout << "       |                  1. Tat ca phieu muon                          |" << endl;
    cout << "       |                  2. Them phieu muon                            |" << endl;
    cout << "       |                  3. Tra sach                                   |" << endl;
    cout << "       |                  4. Xem don theo ngay                          |" << endl;
    cout << "       |                  5. Xem don qua han                            |" << endl;
    cout << "       |                  6. Thoat                                      |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |________________________________________________________________|" << endl;
    cout << "                        Lua chon: " ;
        cin >> Chon;
        switch(Chon){
            case '1':{
                string Name_page = "Tat_ca_phieu_muon";
                next_and_clean(Name_page);
                print_all_borrow(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '2':{
                string Name_page = "Them_phieu_muon";
                next_and_clean(Name_page);
                Check_out(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '3':{
                string Name_page = "Tra_sach";
                next_and_clean(Name_page);
                Check_in(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '4':{
                string Name_page = "Xem_don_theo_ngay";
                next_and_clean(Name_page);
                In_Don_Theo_Ngay(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '5':{
                string Name_page = "Don_qua_han";
                next_and_clean(Name_page);
                Don_Qua_Han(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                Out(Name_page);
                break;
            }
            case '6':{
                Out_page(Name_page);
                break;
            }
        }
    }while (Chon != '6');
}

void Quan_ly_Employee(Employee Em[], int& size){
    string Name_page = "Quan_ly_nhan_vien";
    next_page(Name_page);
    char Chon;
    do{
    clean();
    cout << "        ____________________________Employee____________________________" << endl;
    cout << "       |                  1. Tat ca nhan vien                           |" << endl;
    cout << "       |                  2. Them nhan vien                             |" << endl;
    cout << "       |                  3. Xoa Nhan Vien                              |" << endl;
    cout << "       |                  4. Sua thong tin nhan vien                    |" << endl;
    cout << "       |                  5. Thoat                                      |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |________________________________________________________________|" << endl;
    cout << "                         Lua chon: " ;
        cin >> Chon;
        switch(Chon){
            case '1':{
                string Name_page = "Tat_ca_nhan_vien";
                next_and_clean(Name_page);
                print_Employees();
                Out(Name_page);
                break;
            }
            case '2':{
                string Name_page = "Them_nhan_vien";
                next_and_clean(Name_page);
                add_Employee(Em, size);
                Out(Name_page);
                break;
            }
            case '3':{
                string Name_page = "Xoa_nhan_vien";
                next_and_clean(Name_page);
                Delete_Employee(Em, size);
                Out(Name_page);
                break;
            }
            case '4':{
                string Name_page = "Sua_thong_tin_nhan_vien";
                next_and_clean(Name_page);
                cout << "\n   updating system...... .  .   .    .     .      :) \n\n " << endl;
                Out(Name_page);
                break;
            }
            case '5': {
                Out_page(Name_page);
                break;
            }
        }
    }while(Chon != '5');
}

void Home(Borrow Bors[],int& SizeOfBor, Detail Dets[],int& SizeOfDet, Book B[],int& SizeOfBook, User Us[], int& SizeOfU, Employee Em[], int& SizeOfEm){
    string Name_page = "Home";
    next_page(Name_page);
    char Chon;
    do{
    clean();
    cout << "        ______________________________Home______________________________" << endl;
    cout << "       |                  1. Quan ly sach                               |" << endl;
    cout << "       |                  2. Quan ly ban doc (User)                     |" << endl;
    cout << "       |                  3. Quan ly phieu muon                         |" << endl;
    cout << "       |                  4. Quan ly nhan vien (Employee)               |" << endl;
    cout << "       |                  5. Thoat + Save                               |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |                                                                | " << endl;
    cout << "       |                                                                |" << endl;
    cout << "       |________________________________________________________________|" << endl;
    cout << "                         Lua chon: ";
        cin >> Chon;
        switch(Chon){
            case '1':{
                Quan_ly_sach(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                break;
            }
            case '2':{
                Quan_ly_User(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                break;
            }
            case '3':{
                Quan_ly_Borrow(Bors, SizeOfBor, Dets, SizeOfDet, B, SizeOfBook, Us, SizeOfU);
                break;
            }
            case '4':{
                if (Link.substr(0,5) != "ADMIN"){
                    cout << "Chi ADMIN moi duoc quyen truy cap" << endl;
                    if (Yes("Co Login lai ko? (username = password = admin)"))
                        login(Em, SizeOfEm);;
                }else
                    Quan_ly_Employee(Em, SizeOfEm);
                break;
            }
            case '5':{
                Out_page(Name_page);
                break;
            }
        }
    }while (Chon != '5');
}

#endif // VIEW_H
