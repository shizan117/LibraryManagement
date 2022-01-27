#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;

void password(void);
void time(void);
void add_books(void);
void delete_books(void);
void search_books(void);
void  view_books(void);
void admin(void);
void main_menu(void);
void computer_bookshelf(void);
void textile_bookshelf(void);
void  electrical_bookshelf(void);
void civil_bookshelf(void);
void mechanical_bookshelf(void);
void architecture_bookshelf(void);
void wrong(void);
void issue_books(void);
void edit_book(void);
void removebooks(void);
void searchbooks(void);
void viewbooks(void);
void issuebooks(void);

int ID = 0;
char a;

class book
{
private:
    char date1[20];
    char student[20];
    char catagory[20];
    int bookid;
    char bookname[20];
    char author[20];
    int quantity;
    int price;
    int rackno;
    char datee[20];
public:
    book()
    {
        strcpy(catagory,"Nothing yet");
        bookid = 0;
        strcpy(bookname,"Nothing yet");
        strcpy(author,"Nothing yet");
        quantity = 0;
        price = 0;
        rackno = 0;
    }
    void get1()
    {
        for(int i=0; i<25; i++)
            cout<<"***";
        cout<<"\n\n\n\t\t\tEnter the student's ID :";
        cin.getline(student, 19);
        cout<<"\n\t\t\tEnter the todays date:";
        cin.getline(date1, 19);
        cin.ignore();
        cout<<"\n\t\t\tEnter the return date:";
        cin.getline(datee, 19);
        cin.ignore();
    }
    void getBookData(int a)
    {
        int c = 0, x = 0;
        if(a == 1)
        {
            findid();
            x = 1;
        }
        cout<<"\n\n\n";
        cin.ignore();
        cout<<"\t\t\t\tCatagory:";
        cin.getline(catagory, 19);
        if(x==1)
        {
            bookid = ID + 1;
            cout<<"\t\t\t\tBook ID: "<<bookid;
        }
        else
        {
            cout<<"\t\t\t\tBook ID: ";
            cin>>bookid;
        }
        cin.ignore();
        cout<<"\t\t\t\tBook Name:";
        cin.getline(bookname, 19);
        cout<<"\t\t\t\tAuthor:";
        cin.getline(author, 19);
        cout<<"\t\t\t\tQuantity:";
        cin>>quantity;
        if (quantity < 0)
        {
            c++;
        }
        cout<<"\t\t\t\tPrice:";
        cin>>price;
        if (price < 0)
        {
            c++;
        }
        cout<<"\t\t\t\tRack No:";
        cin>>rackno;
        if (rackno < 0)
        {
            c++;
        }
        if(c!=0)
        {
            cout<<"\n\n\t\t\t\tWrong Input....\n\n";
            cout<<"\n\n\t\t\t\tTry Again:\n\n";
            getBookData(1);
        }
    }

    void showbookdata()
    {
        cout<<"\n   "<<catagory<<"\t       "<<bookid<<" \t     "<<bookname<<" \t      "<<author<<" \t       "<<quantity<<"  \t    "<<price<<" \t      "<<rackno<<endl;

    }
    void showissuedata()
    {

        cout<<"\t"<<student<<"       "<<catagory<<"           "<<bookid<<"          "<<bookname<<"          "<<author<<"      "<<date1<<"        "<<datee<<endl;
    }
    void storebook();
    void vewallbook();
    int searchbook(int *);
    int deletebook(int *);
    void updatedata(int *);
    void storeissue();
    void vewallissue();
    void searchissue(int *);
    void deleteissue(char *);
    void findid();
} b1;

void book::findid()
{
    fstream filee;
    filee.open("bookshelf.txt", ios::in);
    if(!filee)
        cout<<"file not found"<<endl;
    else
    {
        filee.read((char*)this,sizeof(*this));
        while(!filee.eof())
        {
            ID = bookid;
            filee.read((char*)this,sizeof(*this));
        }
    }
    filee.close();
}

void book::updatedata(int *b_id)
{
    fstream filee;
    filee.open("bookshelf.txt", ios::in | ios::out | ios::ate);
    filee.seekg(0);
    filee.read((char*)this, sizeof(*this));
    while(!filee.eof())
    {
        if(*b_id==bookid)
        {
            getBookData(0);
            filee.seekp(filee.tellp() - sizeof(*this));
            filee.write((char*)this, sizeof(*this));
        }
        filee.read((char*)this, sizeof(*this));
    }
    filee.close();
}

int book::deletebook(int *b_id)
{
    int c = 0;
    fstream fin;
    fstream fout;
    fin.open("bookshelf.txt", ios::in);
    if(!fin)
        cout<<"file not found"<<endl;
    else
    {
        fout.open("temp.txt", ios::out);
        fin.read((char*)this, sizeof(*this));
        while(!fin.eof())
        {
            if(*b_id!=bookid)
            {
                fout.write((char*)this, sizeof(*this));
            }
            else
                c++;
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("bookshelf.txt");
        rename("temp.txt","bookshelf.txt");
    }
    if(c==0)
        return 0;
    else
        return 1;
}

int book::searchbook(int *b_id)
{
    int c = 0;
    fstream filee;
    filee.open("bookshelf.txt", ios::in);
    if(!filee)
        cout<<"file not found"<<endl;
    else
    {
        filee.read((char*)this,sizeof(*this));
        while(!filee.eof())
        {
            if(*b_id==bookid)
            {
                cout<<endl<<"\n\n\t\t\t    \xB2\xB2\xB2\xB2 Book Found \xB2\xB2\xB2\xB2\n\n"<<endl<<endl;
                c++;
                for(int i=0; i<33; i++)
                    cout<<"***";
                cout<<"\n";

                cout<<"\n CATEGORY \t ID   \t    BOOK NAME  \t     AUTHOR \t       QTY \t    PRICE \t   RackNo\n\n";



                showbookdata();
                return 1;
                break;
            }
            filee.read((char*)this,sizeof(*this));
        }
        if(c==0)
        {
            cout<<"\n\n\n\t\t\t\tRecord not found!!!!\n";
        }
    }
    filee.close();

}

void book::vewallbook()
{
    fstream filee;
    filee.open("bookshelf.txt", ios::in);
    if(!filee)
        cout<<"file not found"<<endl;
    else
    {
        filee.read((char*)this,sizeof(*this));
        for(int i=0; i<33; i++)
            cout<<"***";
        cout<<"\n";
        cout<<"\n CATEGORY \t ID   \t    BOOK NAME  \t     AUTHOR \t       QTY \t    PRICE \t   RackNo\n\n";
        while(!filee.eof())
        {
            cout<<"\n\n";

            showbookdata();
            filee.read((char*)this,sizeof(*this));
        }
    }
    filee.close();
}

void book::storebook()
{
    if(bookid == 0 && quantity == 0 && price == 0)
    {
        cout<<"Nothing added to store"<<endl;
    }
    else
    {
        fstream filee;
        filee.open("bookshelf.txt", ios::app);
        filee.write((char*)this,sizeof(*this));
        filee.close();
    }
}
void book::storeissue()
{

    fstream filee;
    filee.open("issue.txt", ios::app);
    filee.write((char*)this,sizeof(*this));
    filee.close();

}
void book::vewallissue()
{
    fstream filee;
    filee.open("issue.txt", ios::in);
    if(!filee)
        cout<<"file not found"<<endl;
    else
    {
        filee.read((char*)this,sizeof(*this));
        while(!filee.eof())
        {
            showissuedata();
            filee.read((char*)this,sizeof(*this));
        }
    }
    filee.close();
}
void book::searchissue(int *b_id)
{
    int c = 0;
    fstream filee;
    filee.open("issue.txt", ios::in);
    if(!filee)
        cout<<"file not found"<<endl;
    else
    {
        filee.read((char*)this,sizeof(*this));
        while(!filee.eof())
        {
            if(*b_id==bookid)
            {
                c++;
                showissuedata();
            }
            filee.read((char*)this,sizeof(*this));
        }
        if(c==0)
        {
            cout<<"\n\n\n\t\t\t\tRecord not found!!!!";
        }
    }
    filee.close();
}

void book::deleteissue(char *stID)
{
    fstream fin;
    fstream fout;
    fin.open("issue.txt", ios::in);
    if(!fin)
        cout<<"file not found"<<endl;
    else
    {
        fout.open("temp.txt", ios::out);
        fin.read((char*)this, sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(student, stID))
            {
                fout.write((char*)this, sizeof(*this));
            }
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("issue.txt");
        rename("temp.txt","issue.txt");
    }
}

void time()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    cout <<"\n\t\t\t\t\t\t\t      Current Date: "<<tm.tm_mday<< "-"<<tm.tm_mon+1<<"-"<< tm.tm_year+1900<<"\n\n";
}

void wrong()
{
    system("cls");
    cout<<"\n\n\n\t    ";
    for(int j=0; j<18; j++)
    {
        Sleep(50);
        cout<<"xx";
    }
    cout<<"\a\n\t\t       Wrong Entry \n\t      Please re-entered correct option";
    cout<< "\n\t\t    Enter any key again";

}

void main_menu()
{
    system("cls");
    time();

    cout<<"\n\n\t\t\t";
    char d[25]="  MAIN MENU";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<13; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n\n";

    cout<<"\n\n\n\t\t  1. Add Books";
    cout<<"\n\n\t\t  2. Delete books";
    cout<<"\n\n\t\t  3. Search Books";
    cout<<"\n\n\t\t  4. Issue Books";
    cout<<"\n\n\t\t  5. View Book list";
    cout<<"\n\n\t\t  6. Edit book's Record";
    cout<<"\n\n\t\t  7. Close Application";
    cout<<"  \n\n\t\t  Enter your choice: ";

    switch (getch())
    {

    case '1':                ///  Add Books
        system("cls");
        add_books();
        break;
    case '2':              ///  Delete books
        system("cls");
        delete_books();
        break;
    case '3':             ///  Search Books
        system("cls");
        search_books();
        break;
    case '4':            ///  issue Book list
        system("cls");
        issue_books();
        break;
    case '5':            ///  View Book list
        system("cls");
        view_books();
        break;
    case '6':            ///  edit
        system("cls");
        edit_book();
        break;
    case '7':            ///  close
    {
        system("cls");
        cout<<"\n\n\t\t\t";
        char d[25]="  Exiting";
        int j;
        for(j=0; j<8; j++)
        {
            Sleep(40);
            cout<<"\xDB";
        }
        for(j=0; j<10; j++)
        {
            Sleep(50);
            cout<<d[j];
        }
        for(j=0; j<8; j++)
        {
            Sleep(40);
            cout<<"\xDB";
        }
        cout<<"\n\n\t\t\t";
        cout<<"Exiting in 2 second"<<"\n\t\t\t";
        cout<<"*******************\n\n\n";
        Sleep(2000);
        exit(0);
        break;
    }
    default:
    {
        wrong();
        if(getch())
            main_menu();
    }
    }
}


void architecture_bookshelf()
{
    time();
    cout<<"\t\t\t  Architecture Bookshelf"<<endl;
    b1.getBookData(1);
    b1.storebook();
    cout<<endl<<"\t\t\t\tSaved Successfully......."<<endl<<endl;
    cout<<"\t\t\t\tAdd any more ? (Y / N):";
    if(getch()=='n')
        main_menu();
    else
    {
        system("cls");
        add_books();
    }
}
void mechanical_bookshelf()
{
    time();
    cout<<"\t\t\t  Mechanical Bookshelf"<<endl;
    b1.getBookData(1);
    b1.storebook();
    cout<<endl<<"\t\t\t\tSaved Successfully......."<<endl<<endl;
    cout<<"\t\t\t\tAdd any more ? (Y / N):";
    if(getch()=='n')
        main_menu();
    else
    {
        system("cls");
        add_books();
    }
}

void civil_bookshelf()
{
    time();
    cout<<"\t\t\t  Civil Bookshelf"<<endl;
    b1.getBookData(1);
    b1.storebook();
    cout<<endl<<"\t\t\t\tSaved Successfully......."<<endl<<endl;
    cout<<"\t\t\t\tAdd any more ? (Y / N):";
    if(getch()=='n')
        main_menu();
    else
    {
        system("cls");
        add_books();
    }
}
void  electrical_bookshelf()
{
    time();
    cout<<"\t\t\t  Electrical Bookshelf"<<endl;
    b1.getBookData(1);
    b1.storebook();
    cout<<endl<<"\t\t\t\tSaved Successfully......."<<endl<<endl;
    cout<<"\t\t\t\tAdd any more ? (Y / N):";
    if(getch()=='n')
        main_menu();
    else
    {
        system("cls");
        add_books();
    }
}
void textile_bookshelf()
{
    time();
    cout<<"\t\t\t  Textile Bookshelf"<<endl;
    b1.getBookData(1);
    b1.storebook();
    cout<<endl<<"\t\t\t\tSaved Successfully......."<<endl<<endl;
    cout<<"\t\t\t\tAdd any more ? (Y / N):";
    if(getch()=='n')
        main_menu();
    else
    {
        system("cls");
        add_books();
    }
}
void computer_bookshelf()
{
    time();

    cout<<"\t\t\t  Computer Bookshelf"<<endl;
    b1.getBookData(1);
    b1.storebook();
    cout<<endl<<"\t\t\t\tSaved Successfully......."<<endl<<endl;
    cout<<"\t\t\t\tAdd any more ? (Y / N):";
    if(getch()=='n')
        main_menu();
    else
    {
        system("cls");
        add_books();
    }
}

void add_books()
{
    system("cls");
    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" SELECT CATEGORIES";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<19; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n";
    cout<<"\n\n\n\t\t  1. Computer Bookshelf";
    cout<<"\n\n\t\t  2. Textile Bookshelf";
    cout<<"\n\n\t\t  3. Electrical Bookshelf";
    cout<<"\n\n\t\t  4. Civil Bookshelf";
    cout<<"\n\n\t\t  5. Mechanical Bookshelf";
    cout<<"\n\n\t\t  6. Architecture Bookshelf";
    cout<<"\n\n\t\t  7. Back";
    cout<<"  \n\n\t\t  Enter your choice: ";
    //cin >> select;

    switch (getch())
    {
    case '1':                ///  Computer Bookshelf
        system("cls");
        computer_bookshelf();
        break;
    case '2':              ///  Textile Bookshelf
        system("cls");
        textile_bookshelf();
        break;
    case '3':             ///  Electrical Bookshelf
        system("cls");
        electrical_bookshelf();
        break;
    case '4':            ///  Civil Bookshelf
        system("cls");
        civil_bookshelf();
        break;
    case '5':            ///  Mechanical Bookshelf
        system("cls");
        mechanical_bookshelf();
        break;
    case '6':          ///Architecture Bookshelf
        system("cls");
        architecture_bookshelf();
        break;
    case '7':          ///back
        system("cls");
        main_menu();
        break;

    default:
    {

        wrong();
        if(getch())
            add_books();
    }
    }
}

void delete_books()
{
    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" DELETE BOOKS";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<14; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n";
    int x,*p;
    cout<<"\n\n\n\t\t  Enter the Book ID to delete: ";
    cin>>x;
    p = &x;
    if(b1.deletebook(p)==1)
    {
        cout<<endl<<"\n\n\t\t Deleted Successfully"<<endl<<endl;
        cout<<"\n\n\n\t\t\t Delete any more ? (Y / N):";
        if(getch()=='n')
            main_menu();
        else
        {
            system("cls");
            delete_books();
        }
    }
    else
    {
        cout<<endl<<"\n\n\t\t Book Not Found"<<endl<<endl;
        cout<<"\n\n\n\t\t\t Try again ? (Y / N):";
        if(getch()=='n')
            main_menu();
        else
        {
            system("cls");
            delete_books();
        }
    }

}
void search_books()
{
    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" SEARCH BOOKS";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<14; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n";

    int x,*p;
    cout<<"\n\n\n\t\t\t  Enter the Book ID to search: ";
    cin>>x;
    p = &x;
    b1.searchbook(p);
    for(int i=0; i<33; i++)
        cout<<"***";
    cout<<"\n";
    cout<<endl<<endl<<"\t\t\t\tSearch any more ? (Y / N):";
    if(getch()=='n')
        main_menu();
    else
    {
        system("cls");
        search_books();
    }
}

void  view_books()
{
    system("cls");
    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" VIEW BOOKS";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<12; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n";
    cout<<endl;
    b1.vewallbook();

    for(int i=0; i<33; i++)
        cout<<"***";

    cout<<endl<<"\n\n\n\t\t\t\tAll Books Showed......."<<endl<<endl;
    cout<<"\n\t\t\t   Press any key to return"<<endl;
    getch();
    main_menu();
}

void edit_book()
{
    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" EDIT BOOKS";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<12; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n";


    int x,*p;
    cout<<"\n\n\n\t\t\t Enter the Book ID to Edit: ";
    cin>>x;
    p = &x;
    b1.updatedata(p);
    cout<<endl<<"\t\t\t\tAll Book Updated......."<<endl<<endl;
    cout<<"\t\t\t\tPress any key to return"<<endl;
    getch();
    main_menu();

}

void issue_books()
{
    system("cls");
    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" ISSUE BOOKS";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<13; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n";

    cout<<"\n\n\n\t\t  1. Issue a Book";
    cout<<"\n\n\t\t  2. View Issued Book";
    cout<<"\n\n\t\t  3. Search Issued Book";
    cout<<"\n\n\t\t  4. Remove Issued Book";
    cout<<"\n\n\t\t  5. Back";

    cout<<"  \n\n\t\t  Enter your choice: ";
    switch (getch())
    {
    case '1':                ///  Issue a Book
        system("cls");
        issuebooks();
        break;
    case '2':              ///  View Issued Book
        system("cls");
        viewbooks();
        break;
    case '3':             ///  Search Issued Book
        system("cls");
        searchbooks();
        break;
    case '4':            ///  Remove Issued Book
        system("cls");
        removebooks();
        break;
    case '5':            ///  Back
        system("cls");
        main_menu();
        break;


    default:
    {

        wrong();
        if(getch())
            add_books();
    }
    }
}
void  issuebooks()
{
    system("cls");

    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" ISSUE BOOKS";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<13; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n\n\n";
    int x, *p;
    cout<<"\n\t\t\tEnter the book Id to issue: ";
    cin>>x;
    cin.ignore();
    p = &x;

    if(b1.searchbook(p)==1)
    {
        b1.get1();
        b1.storeissue();
        cout<<"\t\t\tIssue anymore ? (Y/N)";
        if(getch()=='n')
            issue_books();
        else
            issuebooks();
    }
    else
    {
        cout<<"\n\t\t\tRecord not found!!!!";
        cout<<"\n\t\t\tTry Again ? (Y/N)";
        if(getch()=='n')
            issue_books();
        else
            issue_books();
    }


}

void viewbooks()
{
    system("cls");
    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" VIEW ISSUED BOOKS";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<19; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n\n\n\t";
    for(int i=0; i<33; i++)
        cout<<"***";
    cout<<"\n";
    cout<<"\n\tSTUDENT-ID      CATEGORY      BOOK-ID     BOOK NAME     AUTHOR      ISSUED DATE       REFUND DATE\n\n";
    b1.vewallissue();
    cout<<endl<<"\t";
    for(int i=0; i<33; i++)
        cout<<"***";
    cout<<"\n";
    cout<<"\t\t  Enter any key to return.....";
    getch();
    issue_books();

}

void searchbooks()
{
    system("cls");
    time();
    cout<<"\n\n\t\t\t";
    char d[25]=" SEARCH BOOKS";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<15; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n\n";
    int x, *p;
    cout<<"\n\n\t\t  Enter the book Id to issue: ";
    cin>>x;
    cout<<"\n\n\t";
    cin.ignore();
    p = &x;
    for(int i=0; i<33; i++)
        cout<<"***";
    cout<<"\n";
    cout<<"\n\tSTUDENT-ID      CATEGORY      BOOK-ID     BOOK NAME     AUTHOR      ISSUED DATE       REFUND DATE\n\n";
    b1.searchissue(p);
    cout<<endl<<"\t";
    for(int i=0; i<33; i++)
        cout<<"***";
    cout<<"\n";
    cout<<"\n\n\t\t  Enter any key to return.....";
    getch();
    issue_books();
}

void removebooks()
{
    system("cls");
    time();
    cout<<"\n\n\t\t\t";
    char d[40]=" REMOVE BOOKS FROM ISSUE LIST";
    int j;
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    for(j=0; j<30; j++)
    {
        Sleep(50);
        cout<<d[j];
    }
    for(j=0; j<8; j++)
    {
        Sleep(40);
        cout<<"\xDB";
    }
    cout<<"\n";
    char x[20];
    cout<<"\n\n\n\t\t  Enter the Student ID: ";
    cin.getline(x, 20);
    b1.deleteissue(x);
    cout<<"\n\n\n\t\t  Enter any key to return.....";
    getch();
    issue_books();


}

void welcome_Message()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t         \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<"\n\t\t\t         \xB2                                           \xB2";
    cout<<"\n\t\t\t         \xB2                  WELCOME                  \xB2";
    cout<<"\n\t\t\t         \xB2                    TO                     \xB2";
    cout<<"\n\t\t\t         \xB2           LIBRARY MANAGEMENT SYSTEM       \xB2";
    cout<<"\n\t\t\t         \xB2                                           \xB2";
    cout<<"\n\t\t\t         \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<"\n\n\n\t\t\t         Enter any key to continue\n\n";

    getch();
    main_menu();
}
int main()
{
    welcome_Message();
}
