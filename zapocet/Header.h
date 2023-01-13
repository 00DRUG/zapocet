#pragma once
#include<iostream>
#include<string>
//#include<map>
using namespace std;

typedef enum
{
    Fantasy = 1,
    Graphic_novel,
    Historical_fiction ,
    Horror ,
    Romance ,
    Thriller ,
    Science_fiction  ,
    Children_s ,
    Mystery = 9,
    Unknown_GENRE =10

} GENRE;
using T = int;
const T NULA = T();
void print_endl() {
    cout << endl;
}
inline const char* ToString(GENRE v)
{
    switch (v)
    {
    case Fantasy:   return "Fantasy";
    case Graphic_novel:   return "Graphic_novel";
    case Historical_fiction: return "Historical_fiction";
    case Horror: return "Horror";
    case Romance: return "Romance";
    case Thriller: return "Thriller";
    case Science_fiction: return "Science_fiction";
    case Children_s: return "Children’s";
    case Mystery: return "Mystery";
    default:      return "[Unknown GENRE]";
    }
}
struct items {
    string autor;
    string titul;
    GENRE book_GENRE;
    T pages;
    items() {
        autor = "";
        titul = "";
        book_GENRE = Unknown_GENRE;
        pages = 0;

    }
    void print(int i) {
        cout << "Book #" << i << endl;
        cout << "Author: " << autor << endl;
        cout << "Titul: " << titul << endl;
        cout << "Book GENRE: " << ToString(book_GENRE) << endl;
        cout << "Pages: " << pages << endl;
        cout << endl;
    }
};

void ToGenre(string str, items* b)
{
    if (str == "Fantasy") { b->book_GENRE = Fantasy; }
    else if (str == "Graphic novel") { b->book_GENRE = Graphic_novel; }
    else if (str == "Historical fiction") { b->book_GENRE = Historical_fiction; }
    else if (str == "Horror") { b->book_GENRE = Horror; }
    else if (str == "Romance") { b->book_GENRE = Romance; }
    else if (str == "Thriller") { b->book_GENRE = Thriller; }
    else if ( str == "Science fiction") { b->book_GENRE = Science_fiction; }
    else if (str == "Children's") { b->book_GENRE = Children_s; }
    else if (str == "Mystery") { b->book_GENRE = Mystery; }
    else { b->book_GENRE = Unknown_GENRE; }

}
struct book {
    items* item;
    book* next;
    book() {
        item = new items;
        item->autor = NULA;
        item->titul = NULA;
        //item->book_GENRE = 
        item->pages = NULA;
        next = nullptr;
    }
    void enter() {
        cout << "Book enter" << endl;
        cout << "Author: ";
        getline(cin >> ws, item->autor);
        cout << "Titul: ";
        getline(cin >> ws,item->titul);
        string helper;
        string string_GENRE;
        cout << "Book GENRE: ";
        getline(cin >> ws, string_GENRE);
        string_GENRE[0] = toupper(string_GENRE[0]);
       /* map<string, GENRE> nodeMap;
        nodeMap["Fantasy"] = GENRE::Fantasy;*/
        ToGenre(string_GENRE, item);
        cout << "Pages: ";
        cin >> item->pages;
    }
};

struct Spojovi_seznam {
    book* head;
    book* gethead()
    {
        return head;
    }
};
void create_list(Spojovi_seznam* s) {
    if (s != nullptr) {
        cout << "List is already created\n";
    }
    else {
        s = new Spojovi_seznam();
    }
}
void del_list(book** head_ref)
{
    book* current = *head_ref;
    book* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}
void vypis(Spojovi_seznam* s) {
    if (s->head == nullptr) {
        cout << "List is empty\n";
    }
    else {
        book* pom = s->head;
        if (pom == nullptr && pom->next == nullptr) {
            cout << "List is empty\n";
        }
        else {
            cout << "List of books : \n"; int i = 1;
            for (book* pom=s->head; pom != nullptr; pom = pom->next) {
               pom->item->print(i++); 

            }
        }
        delete pom;
    }
}
void deleteAllNodes(Spojovi_seznam* s) {
    if (s->head == NULL) {
        cout << "List is empty\n";
    }
    else {
        book* temp = new book();
        while (s->head != NULL) {
            temp = s->head;
            s->head = s->head->next;
            delete temp;
        }

        cout << "All nodes are deleted successfully.\n";
    }
}
void deleteNode(book* node, Spojovi_seznam* s)
{
    if (node == nullptr) {
        cout << "Book not found" << endl;
    }
    else {
        book* pom = s->gethead();
        for (pom; pom->next != node; pom = pom->next) {}
        book* temp;
        temp = pom->next;
        pom->next = temp->next;
        delete temp;
    }
}
void delete_List(Spojovi_seznam*s) {
        deleteAllNodes(s);
}
void vlozit(Spojovi_seznam* s) {
    auto new_book = new book();
    new_book->next = s->head;
    s->head = new_book;
    new_book->enter();
}
void najdi_velicost(Spojovi_seznam* s) {
    book* pom = s->head;
    if (pom == nullptr) {
        cout << "List is empty" << endl;
    }
    else {
        int n = 0;
        for (pom; pom != nullptr; pom = pom->next) {
            n++;
        }
        cout << "List size is :" << n << endl;
    }
    
}
int najdi_velicost_int(Spojovi_seznam* s) {
    book* pom = s->head;
    if (pom == nullptr) {
        return 0;
    }
    else {
        int n = 0;
        for (pom; pom != nullptr; pom = pom->next) {
            n++;
        }
        return n;
    }

}
void author_find(Spojovi_seznam* s) {
    cout << "Enter the author's name: ";
    string name;
    cin >> name;
    int i = 1;
    for (book* pom = s->head; pom != nullptr; pom = pom->next) {
 
        if (name.compare(pom->item->autor) == 0) { pom->item->print(i); i++;}
        
    }
}
book* author_find(Spojovi_seznam* s,int* a) {
    cout << "Enter the author's name: ";
    string name;
    cin >> name;
    int i = 1;
        for (book* pom = s->head; pom != nullptr; pom = pom->next) {

            if (name.compare(pom->item->autor) == 0) { return pom; };
            i++;
        }
    return nullptr;
}
void titul_find(Spojovi_seznam* s) {
    cout << "Enter the titul: ";
    string titul;
    cin >> titul;
    int i = 1;
    for (book* pom = s->head; pom != nullptr; pom = pom->next) {
        if (titul.compare(pom->item->titul) == 0)pom->item->print(i);
        i++;
    }
}
book* titul_find(Spojovi_seznam* s,int* a) {
    cout << "Enter the titul: ";
    string titul;
    cin >> titul;
    int i = 1;
    for (book* pom = s->head; pom != nullptr; pom = pom->next) {
        if (titul.compare(pom->item->titul) == 0)return pom;
        i++;
    }
    return nullptr;
}
void odstran_prvni(Spojovi_seznam* s) {
    if ((najdi_velicost_int(s) > 0)) {
        auto pom = s->head;
        s->head = s->head->next;
        delete pom;
    }
    else cout << "seznam je prazdny" << endl;
}