#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct BookData{
    char title[200];
    char ISBN[10];
    char author[40];
    char language[30];
    unsigned int year;
    double price;
    int stock_level;

    void inputData();

};

struct Book{
    BookData data;
    Book *next;
};

Book* makeBook(BookData data);

void addNewBook(Book *&book, BookData data);
bool compareBook(BookData data1, BookData data2);

void sellOneBook(Book *&book, BookData data, char ISBN[]);

void findOneBook(Book *book, char name[]);

void deleteAllBookLessK(Book *&book, int k);

bool checkFile();

void writeIntoFile(Book *book);

int main(){
    Book *book = nullptr; BookData data;
    int sl;
    while(sl != 0){
        cout << "-----------------------\n";
        cout << "1. Add new book\n";
        cout << "2. Sell one book\n";
        cout << "3. Find one book\n";
        cout << "4. Delete all book if less than k book\n";
        cout << "0. Thoat\n";
        cout << "-----------------------\n";
        cin >> sl;

        if(sl == 1){
            cout << "Enter in4 of book: \n";
            data.inputData();
            addNewBook(book, data);
        } else if(sl == 2){
            cout << "Enter ISBN";
            char ISBN[10];
            cin.ignore(1, '\n');
            cin.getline(ISBN,10);
            sellOneBook(book, data, ISBN);
        } else if(sl == 3){
            char name[40];
            cout << "Enter name: ";
            cin.ignore(1, '\n');
            cin.getline(name, 40);
            findOneBook(book, name);
        } else if(sl == 4){
            int k;
            do{
                cout << "Enter k: ";
                cin >> k;
            } while(k <= 0);

            deleteAllBookLessK(book, k);
        } else break;
        
    }
    return 0;
}

void BookData::inputData(){
    cout << "Enter title: ";
    cin.ignore(1,'\n');
    cin.getline(title, 200);

    cout << "Enter ISBN: ";
    cin.ignore(1,'\n');
    cin.getline(ISBN, 10);

    cout << "Enter author: ";
    cin.getline(author, 40);

    cout << "Enter language: ";
    cin.getline(language, 30);

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter price: ";
    cin >> price;

    stock_level = 1;
}

Book* makeBook(BookData data){
    Book *newBook = new Book;
    newBook->data = data;
    newBook->next = nullptr;
    return newBook;
}

bool compareBook(BookData data1, BookData data2){
    if(strcmp(data1.title, data2.title) != 0) return false;
    if(strcmp(data1.ISBN, data2.ISBN) != 0) return false;
    if(strcmp(data1.author, data2.author) != 0) return false;
    if(strcmp(data1.language, data2.language) != 0) return false;
    if(data1.year != data2.year) return false;
    if(data1.price != data2.price) return false;
    return true; 
}

void addNewBook(Book *&book, BookData data){
    Book *newBook = makeBook(data);
    if(book == nullptr){
        book = newBook;
        return;
    }

    Book *tmp = book;
    //tang so luong ton kho
    while(tmp){
        if(compareBook(data, tmp->data)){
            tmp->data.stock_level ++;
            return;
        } 
            else tmp = tmp->next;
    }  
    
    tmp = book;
    //them sach moi
    while (tmp->next != nullptr) tmp = tmp->next;
    tmp->next = newBook;
}

void sellOneBook(Book *&book, BookData data, char ISBN[]){
    Book *tmp = book;
    while(tmp){
        if(strcmp(tmp->data.ISBN, ISBN) == 0){
            tmp->data.stock_level --;
            return;
        } else tmp = tmp->next;
    }

    if(tmp == NULL) cout << "Sold out";
}

void findOneBook(Book *book, char name[]){
    while(book){
        if(strcmp(name, book->data.author) == 0){
            cout << "ISBN: " << book->data.ISBN << " Title: " << book->data.title << endl;
            cout << "-----------\n"; 
        }
        book = book->next;
    }
}

void deleteAllBookLessK(Book *&book, int k){
    Book *tmp = book, *prev = nullptr;

    if(book == nullptr) {
        cout << "No book else";
        return;
    }
    while(tmp){
        if(tmp->data.stock_level < k){
            Book *toDelete = tmp;
            if(prev == nullptr) {
                book = tmp->next;
            } else {
                prev->next = toDelete->next;
            }
            delete toDelete;
            return;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

bool checkFile(){
    ifstream output("output.txt");
    if (!output.is_open()){
        cout << "Cannot open file";
        return false;
    }

    output.seekg(0, std::ios::end);
    if (output.tellg() == 0) return false;
        else return true;
}

void writeIntoFile(Book *book){
    ofstream output("output.txt", ios::out | ios::app);

    if(!output.is_open()){
        cout << "Cannot open this file";
        return;
    }

    if(checkFile()){
        output << "Title\tISBN\tAuthor\tLanguage\tYear\tPrice\tStock Level\n";
        output << book->data.title << "\t" << book->data.ISBN << "\t" << book->data.author << "\t" << book->data.language << "\t";
        output << book->data.year << "\t" << book->data.price << "\t" << book->data.stock_level << "\n";
    } else {
        output << book->data.title << "\t" << book->data.ISBN << "\t" << book->data.author << "\t" << book->data.language << "\t";
        output << book->data.year << "\t" << book->data.price << "\t" << book->data.stock_level << "\n";
    }

    output.close();
}