#include <ctime>
#include <stdlib.h>
#include "Test_inp.h"
#include "Thu_Vien.h"


void inp_B(Book B[], int& size){
    int id=123458;
    srand(time(NULL));
    B[++size] = Book(123456, "Harry Potter and the Philosopher's Stone", rand()%200+1, "J.K.Rowling", "Kim Dong");
    B[++size] = Book(123457, "Harry Potter and the Chamber of Secrets ", rand()%200+1, "J.K.Rowling", "Kim Dong");
    B[++size] = Book(123458, "Harry Potter and the Prisoner of Azkaban ", rand()%200+1, "J.K.Rowling", "Kim Dong");
    B[++size] = Book(++id, "Harry Potter and the Goblet of Fire", rand()%200+1, "J.K.Rowling", "Kim Dong");
    B[++size] = Book(++id, "Harry Potter and the Order of the Phoenix ", rand()%200+1, "J.K.Rowling", "Kim Dong");
    B[++size] = Book(++id, "Harry Potter and the Half-Blood Prince ", rand()%200+1, "J.K.Rowling", "Kim Dong");
    B[++size] = Book(++id, "Harry Potter and the Deathly Hallows", rand()%200+1, "J.K.Rowling", "Kim Dong");
    B[++size] = Book(++id, "Doreamon 1", 50, "Fujiko Fujio", "Kim Dong");
    B[++size] = Book(++id, "Doreamon 2", rand()%200+1, "Fujiko Fujio", "Kim Dong");
    B[++size] = Book(++id, "Doreamon 3", 50, "Fujiko Fujio", "Kim Dong");
    B[++size] = Book(++id, "Doreamon 4", rand()%200+1, "Fujiko Fujio", "Kim Dong");
    B[++size] = Book(++id, "Doreamon 5", 0, "Fujiko Fujio", "Kim Dong");
    B[++size] = Book(++id, "Conan 1", rand()%200+1, "Aoyama Gosho", "Kim Dong");
    B[++size] = Book(++id, "Conan 2", rand()%200+1, "Aoyama Gosho", "Kim Dong");
    B[++size] = Book(++id, "Conan 3", rand()%200+1, "Aoyama Gosho", "Kim Dong");
    B[++size] = Book(++id, "Conan 4", rand()%200+1, "Aoyama Gosho", "Kim Dong");
    B[++size] = Book(++id, "Conan 5", rand()%200+1, "Aoyama Gosho", "Kim Dong");
}

void inp_E(Employee Em[], int& size){
    //int i=0;
    int id = 123;
    Em[++size]= Employee(id++, "Nguyen van A", "admin", "admin", "Ha Noi", "019234567", Date(12, 5, 1990), FEMALE);
    Em[++size]= Employee(id++, "Nguyen van B", "admin1", "admin1", "Ha Noi", "019232327", Date(12, 5, 1990), FEMALE);
}

void inp_U(User U[], int& size){
    int id = 16020932;
    srand(time(NULL));
    U[++size] = User(++id, "Nguyen Trong Ha", Date(15, 10, 1998), MALE, "01649044848");
    U[++size] = User(++id, "Le Thi Thanh Hoa", Date(rand()%28+1, rand()%12+1, rand()%5+1994), FEMALE, "01234567891");
    U[++size] = User(++id, "Le Viet Hai", Date(rand()%28+1, rand()%12+1, rand()%5+1994), MALE, "01234567891");
    U[++size] = User(++id, "Nguyen Khac Vu Hiep", Date(rand()%28+1, rand()%12+1, rand()%5+1994), MALE, "01234567891");
    U[++size] = User(++id, "Vu Ngoc Chi", Date(rand()%28+1, rand()%12+1, rand()%5+1994), FEMALE, "01234567891");
    U[++size] = User(++id, "Le Thi Thuy", Date(rand()%28+1, rand()%12+1, rand()%5+1994), FEMALE, "01234567891");
}

void inp_Bor (Borrow Bors[], int& size, Detail Dets[], int& SizeOfDet, const int& SizeOfU, Book Books[], const int& SizeOfBook, User Us[]){
    int i, j, k;
    int num_book;
    Date D_strat, D_finish;
    int U_id;
    User *Ux = NULL;

    srand(time(NULL));
    for (i=1 ; i<=10 ; i++){
        U_id = rand()%SizeOfU + 16020933;

        Ux = search_U_Pro(Us, SizeOfU, U_id);
        int t=(*Ux).num_book_allow;
        if (t>0){
            num_book = rand()%t+1;
        (*Ux).num_book_allow -= num_book;

        D_strat = Date(rand()%28+1, rand()%2+1, 2017);
        D_finish = Cong(D_strat, 20);
        size++;
        Bors[size] = Borrow(size, U_id, num_book, D_strat, D_finish);
        Bors[size].fine = 0;
 //       Bors[size].BorrowStatus = ChuaQuaHan;
        for (j=1 ; j<= num_book ; j++){
            int id_book = rand()%SizeOfBook + 123456;
                  //Sinh ngau nhien idbook, id dau tien la 123456
            Book* B = search_Book_pro(Books, SizeOfBook, id_book);
        (*B).So_Lan_Muon++;
            Dets[++SizeOfDet] = Detail(Bors[size].borrow_id, id_book, ChuaQuaHan);
            for (k=1 ; k<=SizeOfBook ; k++)
                if (id_book == Books[j].B_id){
                    Books[j].NumOfCopies--;
                    break;
                }
        }
        }

    }
}
void inp_Det(){

}


