//Dobrý den,
//
//
//zde jsou požadavky na zápočtový spojový seznam :
//
//
//spojový seznam o přečtených knihách by měl obsahovat důležité informace o těchto knihách.Součástí záznamu budou následující údaje :
//Autor
//Titul
//Žánr - zde použijte výčtový typ
//Rok vydáníф
//Počet stran
//Uživatel bude moci :
//Vytvářet nový deník
//Deník ukládat do souboru
//Deník načítat ze souboru
//Vkládat jednotlivé záznamy
//Vyhledávat záznamy podle autora a titulu(stačí použít funkci strcmp)
//Mazat záznamy podle autora a titulu
//Vymazat všechny záznamy
//Zcela zrušit deník
//Do programu doplňte jednoduchou řádkově orientovanou nabídku a tu využijte v jednoduché smyčce událostí.Program vhodně rozdělte do modulů a moduly dále do funkcí.Navrhněte a použijte vhodnou datovou strukturu pro uchovávání informací o jednotlivé knize.
//
//S pozdravem Tran
#include"Header.h"
void menu(Spojovi_seznam* s) {
	int menu_switcher;
	do {
		cout << "Menu of the list of Books:\n";
		cout << "Create list  - 1\n";
		cout << "Add a book to list - 2\n";\
		cout << "Print a list of books - 3\n";
		cout << "The size of the list - 4\n";
		cout << "Delete first of the list - 5\n";
		cout << "Find a book(*books) by author - 6\n";
		cout << "Find a book(*books) by titul - 7\n";
		cout << "Delete all list elements - 8\n";
		cout << "Delete list - 9\n";
		cout << "Delete a book(*books) by author - 10\n";
		cout << "Delete a book(*books) by titul - 11\n";
		cout << "Exit - 0\n";
		cout << "Command: ";
		cin >> menu_switcher;
		system("cls");
		if (&s == nullptr) {
			cout << "List is deleted\n";
			menu_switcher = 0;
		}
		else {
			switch (menu_switcher) {
			case(1): { create_list(s); break; }
			case(2): { vlozit(s); break; }
			case(3): { vypis(s); break; }
			case(4): { najdi_velicost(s); break; }
			case(5): { odstran_prvni(s); break; }
			case(6): { author_find(s); break; }
			case(7): { titul_find(s); break; }
			case(8): { deleteAllNodes(s); break; }
			case(9): {  delete_List(s); delete& s; break; }
			case(10): {  int a = -1; int* ptr = &a; deleteNode(author_find(s,ptr),s); break; }
			case(11): {  int a = -1; int* ptr = &a; deleteNode(titul_find(s, ptr),s); break; }
			}
		}
		print_endl();
	} while (menu_switcher != 0);
}
int main() {
  Spojovi_seznam *s;
  s = new Spojovi_seznam();
  menu(s);

  return 0;
}
// clear the console
// file imput + export