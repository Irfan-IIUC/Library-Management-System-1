#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class bookEntry
{
public:

    int copies;
    char name[50], author[50];
};

class library
{
public:

    int numBooks;
    bookEntry database[MAX];

    library()
    {
        numBooks = 0;
    }

    void insertBook(char bookName[], char author[], int c);
    void deleteBook(char bookName[]);
    bookEntry *Search(char bookName[]);
};

void library::insertBook(char bookName[], char author[], int c)
{
    strcpy(database[numBooks].name, bookName);
    strcpy(database[numBooks].author, author);
    database[numBooks].copies = c;

    cout << "\n\nBook Inserted Successfully\n\n";
    ++numBooks;
}

void library::deleteBook(char bookName[])
{
    for(int i=0; i<numBooks; i++)
    {
        if(strcmp(database[i].name, bookName) == 0)
        {
            database[i].copies--;
            cout << "\n\nBook deleted Successfully\n\n";
            return;
        }
    }

    cout << "\n\nBook not found\n\n";
}

bookEntry *library::Search(char bookName[])
{
    for(int i=0; i<numBooks; i++)
    {
        if(strcmp(database[i].name, bookName) == 0)
        {
            return &database[i];
        }
    }

    return NULL;
}

int main()
{
    library ob1;
    char option[5], name[50], author[50], copies[25];

    while(1)
    {
        cout << "\nEnter your option : i for insert";
        cout << "\n                    d for delete";
        cout << "\n                    s for search";
        cout << "\n                    e for Exit\n\n";

        gets(option);

        if(option[0] == 'i')
        {
            cout << "\n\nEnter name of book, author and number of copies per line : ";

            gets(name);
            gets(author);
            gets(copies);

            ob1.insertBook(name, author, atoi(copies));
        }

        else if(option[0] == 'd')
        {
            cout << "\n\nEnter name of book : ";

            gets(name);
            ob1.deleteBook(name);
        }

        else if(option[0] == 's')
        {
            cout << "\n\nEnter name of book : ";

            gets(name);
            bookEntry *item;
            item = ob1.Search(name);

            if(item != NULL)
            {
                cout << "\n\nBook found !!\n\n";
                cout << "Name   : " << item->name << endl;
                cout << "Author : " << item->author << endl;
                cout << "Copies : " << item->copies << endl;
            }

            else
            {
                cout << "\n\nBook not found";
            }
        }

        else if(option[0] == 'e')
        {
            cout << "\n\nThanks for using our service\n\n";
            exit(0);
        }

        else
        {
            cout << "\n\nPlease Enter correct code\n\n";
        }
    }

    return 0;
}

