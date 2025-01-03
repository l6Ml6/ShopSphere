// ============ Start =========== //
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>

using namespace std;
// ============= Dtas ============ //
const  int Max = 100;
//__________ Products data _________//
struct Products {
	int codeProducts;
	string nameProducts;
	double price;
	int inventory;
};

Products product[Max];
int current_p = 0;
//___________ Customers data ____________//
struct Customers {
	int codeCustomer;
	string nameCustomer;
	string number;
};

Customers customer[Max];
int current_c = 0;
//_____________ shopping _________//
struct Shopping {
	int code;
	int customerCode;
	string customername;
	string customerNumber;
	int codeProduct;
	string productName;
	int inventory;
	int price;
};

Shopping shopinng[Max];
int current_sh = 0;
// ============= Set Color ======== //
void setColor(const string& colorCode) {
	cout << "\033[" << colorCode << "m";
}

// _____________ Add Products _____________ //
void AddProduct() {
	int x;
	system("cls");
	system("color 1F");

	setColor("32");
	cout << "===============================\n";
	cout << "\t Add Products section\n";
	cout << "===============================\n\n";

	cout << "Please enter how many products do you add: ";
	cin >> x;

	if (current_p + x > Max) {
		setColor("31");
		cout << "There isn't any space. \n\n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}

	if (current_p + x < Max) {
		for (int i = 0; i < x; i++) {
			cout << "Enter product (" << i + 1 << ") name: ";
			cin.ignore();
			getline(cin, product[current_p + i].nameProducts);

			cout << "Enter product (" << i++ << ") code: ";
			cin >> product[current_p + i].codeProducts;

			cout << "Enter the product (" << i + 1 << ") price: ";
			cin >> product[current_p + i].price;

			cout << "Enter product (" << i + 1 << ") inventory: ";
			cin >> product[current_p + i].inventory;
		}
		current_p += x;
		setColor("32");
		cout << "Successfully added (" << x << ") product.\n";
	}
	else {
		setColor("31");
		cout << "There isn't any space.\n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}
}
// _____________ Products List ____________ //
void ProductList() {
	system("cls");

	system("color 83");
	setColor("32");
	cout << "===============================\n";
	cout << "\t Products list section\n";
	cout << "===============================\n\n";

	if (current_p == 0) {
		setColor("31");
		cout << "There isn't any product. \n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}
	setColor("30");
	for (int i = 0; i < current_p; i++) {
		cout << "Products: \n\n";

		cout << i << "_ Product\n";
		cout << "Name:" << product[i].nameProducts << endl;
		cout << "Code: " << product[i].codeProducts << endl;
		cout << "Price: " << product[i].price << endl;
		cout << "Inventory: " << product[i].inventory << endl;
		cout << "<<< ----------------------------------- >>>\n";
	}

	setColor("37");
	cout << "Press any key to contiue...";
	_getch();
	return;
}
// ________________ Searchpc _______________ //
void Searchpc() {
	int spc;
	system("cls");
	setColor("32");
	cout << "===============================\n";
	cout << "\t Search Products by code\n";
	cout << "===============================\n\n";

	if (current_p == 0) {
		setColor("31");
		cout << "There isn't any product. \n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}

	setColor("35");
	cout << "Please enter the product code: ";
	cin >> spc;

	bool found = false;
	for (int i = 0; i < current_p; i++) {
		if (spc == product[i].codeProducts) {
			found = true;
			setColor("35");
			cout << "Successfully found\n\n";
			setColor("31");
			cout << "Name: " << product[i].nameProducts << endl;
			cout << "Code:" << spc << endl;
			cout << "Price: " << product[i].price << endl;
			cout << "Enventory: " << product[i].inventory << endl;
			break;
		}
	}
	if (!found) {
		setColor("31");
		cout << "The product not found. \n";
	}

	setColor("37");
	cout << "Press any key to continue...";
	_getch();
	return;
}
// ________________ Searchps _______________ //
void Searchps() {
	string sps;
	string temp;
	system("cls");
	setColor("32");
	cout << "===============================\n";
	cout << "\t Search Products by string\n";
	cout << "===============================\n\n";

	if (current_p == 0) {
		setColor("31");
		cout << "There isn't any product. \n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}

	setColor("35");
	cout << "Please enter the string: ";
	cin >> sps;

	bool found = false;

	for (int n = 0; n < current_p; n++) {
		temp = product[n].nameProducts;

		if (temp.find(sps) != string::npos) {
			setColor("31");
			cout << "Product found: " << temp << endl;
			cout << "Code: " << product[n].codeProducts << endl;
			cout << "Price: " << product[n].price << endl;
			cout << "Inventory: " << product[n].inventory << endl;
			found = true;
		}
	}

	if (!found) {
		setColor("31");
		cout << "No matching product found." << endl;
	}

	setColor("37");
	cout << "Press any key to continue...";
	_getch();
	return;
}
// ============= Products Menu ============ //
void ProductMenu() {
	int key;

	while (1) {
		system("cls");
		system("color 0A");
		cout << "====================================\n";
		cout << "\t Product Menu Section\n";
		cout << "====================================\n\n";

		setColor("33");
		cout << "(; ---------------------- ;)\n";
		setColor("31");
		cout << "Add New Products [1]\n";
		cout << "Product list [2]\n";
		setColor("33");
		cout << "(; ---------------------- ;)\n";
		setColor("31");
		cout << "Search Product by code [3]\n";
		cout << "Search Product by string [4]\n";
		cout << "back to main menu [0]\n\n";

		setColor("37");
		cout << "Press a key...";
		key = _getch();

		switch (key) {
		case '0':
			return;
		case '1':
			AddProduct();
			break;
		case '2':
			ProductList();
			break;
		case '3':
			Searchpc();
			break;
		case '4':
			Searchps();
			break;
		}
	}
}
// _____________ Add Customer ____________ //
void AddCustomer() {
	int x;

	system("cls");
	system("color 1F");
	setColor("32");
	cout << "===============================\n";
	cout << " Add Customer section\n";
	cout << "===============================\n\n";
	setColor("37");
	cout << "Please enter how many customer do you want to add: ";
	cin >> x;

	if (current_c + x < Max) {
		for (int i = 0; i < x; i++) {
			cout << "Enter (" << i++ << ") code:";
			cin >> customer[current_c + i].codeCustomer;

			cout << "Enter (" << i++ << ") name";
			cin.ignore();
			getline(cin, customer[current_c + i].nameCustomer);

			cout << "Enter (" << i++ << ") phone number:";
			cin.ignore();
			getline(cin, customer[current_c + i].number);
		}
		current_c += x;
		setColor("37");
		cout << "Successfully added (" << x << ") customer.\n";
	}
	else {
		setColor("31");
		cout << "Tere isn't any space.\n";
	}

	setColor("37");
	cout << "Press any key to continue...";
	_getch();
	return;
}
// ____________ Customer List ____________ //
void CustomerList() {
	system("cls");
	system("color 83");
	setColor("32");
	cout << "===============================\n";
	cout << " Customer list section\n";
	cout << "===============================\n\n";
	if (current_c == 0) {
		setColor("31");
		cout << "There isn't any Customer.\n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}

	setColor("30");
	for (int i = 0; i < current_c; i++) {
		cout << i << "_ Customer:\n";
		cout <<"Code:" << customer[i].codeCustomer;
		cout <<"Name:" << customer[i].nameCustomer;
		cout <<"Phone Number:" << customer[i].number;
		cout << "+-----------------------------------+\n";
	}

	setColor("37");
	cout << "\n Press any key to continue...";
	_getch();
	return;
}
// ___________ Search Costomer ___________ //
void SearchCC() {
	int code;
	system("cls");
	setColor("32");
	cout << "===============================\n";
	cout << "Sreach Customer by code\n";
	cout << "===============================\n\n";
	if (current_c == 0) {
		setColor("31");
		cout << "There isn't any Customer.\n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}

	setColor("31");
	cout << "Please enter the code:";
	cin >> code;

	for (int i = 0; i < current_c; i++) {
		if (customer[i].codeCustomer == code) {
			cout << "Successfully found.\n";
			cout << "Name: " << customer[i].nameCustomer << endl;
			cout << "Phone Number: " << customer[i].number << endl;
			cout << "Code: " << code << endl;
		}
		else {
			setColor("34");
			cout << "Nothig found ;).\n";
		}
	}

	setColor("37");
	cout << "\n Press any key to continue...";
	_getch();
	return;
}
// ============= Customer Menu =========== //
void CustomerMenu() {
	int key;

	while (true) {
		system("cls");
		system("color 0A");

		cout << "============================\n";
		cout << "\t Customer Menu section\n";
		cout << "============================\n\n";

		setColor("34");
		cout << "Register new customer [1]\n";
		cout << "Customer list [2]\n";
		cout << "Search customer by code \n";
		cout << "Back to main menu [0]\n\n";
		setColor("37");
		cout << "Press a key to continue...";
		key = _getch();

		switch (key) {
		case '0':
			return;
		case '1':
			AddCustomer();
			break;
		case '2':
			CustomerList();
			break;
		case '3':
			SearchCC();
			break;
		}
	}
}
// ___________ Add Order __________ //
void AddOrder() {
	int orders;
	int customerOrder;
	string productOrder;
	int ordercount;

	system("cls");
	system("color 1F");
	setColor("32");
	cout << "============================\n";
	cout << "\t Add Order section\n";
	cout << "============================\n\n";

	if (current_c == 0) {
		setColor("31");
		cout << "There isn't any customer in the list.\n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}
	else if (current_p == 0) {
		setColor("31");
		cout << "There isn't any product to buy.\n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}

	setColor("30");
	cout << "Please enter customer code: ";
	cin >> customerOrder;
	bool customerFound = false;
	bool orderSuccess = false;

	for (int i = 0; i < current_c; i++) {
		if (customer[i].codeCustomer == customerOrder) {
			customerFound = true;
			cout << "Please enter how many products do you want to buy: ";
			cin >> orders;

			for (int j = 0; j < orders; j++) {
				cout << "Enter product name: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, productOrder);
				bool productFound = false;

				for (int a = 0; a < current_p; a++) {
					if (product[a].nameProducts.find(productOrder) != string::npos) {
						productFound = true;
						cout << "How many (" << productOrder << ") do you buy? ";
						cin >> ordercount;

						if (ordercount <= product[a].inventory) {
							shopinng[current_sh + j].code = current_sh + j;
							shopinng[current_sh + j].productName = productOrder;
							shopinng[current_sh + j].codeProduct = product[a].codeProducts;
							shopinng[current_sh + j].inventory = ordercount;
							shopinng[current_sh + j].price = ordercount * product[a].price;
							shopinng[current_sh + j].customerCode = customer[i].codeCustomer;
							shopinng[current_sh + j].customername = customer[i].nameCustomer;
							shopinng[current_sh + j].customerNumber = customer[i].number;
							product[a].inventory -= ordercount;

							setColor("32");
							cout << "Successfully added.\n";
							orderSuccess = true;
						}
						else {
							setColor("31");
							cout << "There aren't enough products in stock.\n";
						}
						break;
					}
				}
				if (!productFound) {
					setColor("31");
					cout << "No product found.\n";
				}
			}
			current_sh += orders;
		}
	}
	if (!customerFound) {
		setColor("31");
		cout << "No customer found.\n";
	}
	if (orderSuccess) {
		setColor("32");
		cout << "\nOrders successfully added.\n";
	}

	setColor("37");
	cout << "Press any key to continue...";
	_getch();
	return;
}

// ___________ Order List __________ //
void OrderList() {

	system("cls");
	system("color 83");

	setColor("32");
	cout << "============================\n";
	cout << "\t Order list section\n";
	cout << "============================\n\n";

	if (current_sh == 0) {
		setColor("31");
		cout << "There isn't any order.\n";
		setColor("37");
		cout << "Press any key to continue...";
		_getch();
		return;
	}

	for (int i = 0; i < current_sh; i++) {
		setColor("31");
		cout << "<<-. ===================================== .->>\n";
		setColor("30");
		cout << i << "_ Order:" << shopinng[i].code << endl;
		cout << "Customer Name:" << customer[i].nameCustomer << endl;
		cout << "Custumer code: " << customer[i].codeCustomer << endl;
		cout << "Customer phone number: " << customer[i].number << endl;
		for (int j = 0; j < shopinng[i].code; j++) {
			setColor("35");
			cout << "-----------------------------------\n";
			setColor("30");
			cout << i++ << "_ Product:\n";
			cout << "Product name: " << shopinng[j].productName << endl;
			cout << "Product code: " << shopinng[j].codeProduct << endl;
			cout << "Inventory: " << shopinng[j].inventory << endl;
			cout << "Price: " << shopinng[j].price << endl;
		}

	}
	setColor("32");
	cout << "Successfulyy print the list.\n";
	setColor("37");
	cout << "Press any key to continue...";
	_getch();
	return;
}
// ========= Shopping Menu ======== //
void ShoppingMenu() {
	int key;

	while (true) {
		system("cls");
		system("color 0A");
		cout << "============================\n";
		cout << "\t Shopping Menu section\n";
		cout << "============================\n\n";

		setColor("34");
		cout << "Register a new order [1]\n";
		cout << "Order list [2]\n";
		cout << "Back to Main Menu [0]\n";
		setColor("37");
		cout << "Press a key to continue...";
		key = _getch();

		switch (key)
		{
		case '0':
			return;
		case '1':
			AddOrder();
			break;
		case '2':
			OrderList();
			break;
		}
	}
}
// ============= About Dev ======== //
void AboutDev() {
	system("cls");

	setColor("33");
	cout << "< ======================================================================================== >\n";

	setColor("32");
	cout << "Hello,\nThis program was developed by Mohammadreza\n"
		"in 2024 as part of my university project.\n\n\n";

	setColor("33");
	cout << "<< ======================================================================================= >>\n";

	setColor("31");
	cout << "About Me:\n\n";

	setColor("32");
	cout << "Dev: Mohammadreza\n";
	cout << "Email: twimmati@gmail.com\n";
	cout << "Telegram: @l6Ml6\n\n";

	setColor("37");
	cout << "Press any key to return to the main menu...";
	_getch();
}
// ============= Menu ============ //
void Menu() {
	int key;

	while (1) {
		system("cls");
		system("color 0A");
		cout << "\t\t\t\t========================================\n";
		cout << "\t\t\t\t\tWelcome to online store\n";
		cout << "\t\t\t\t========================================\n\n";

		setColor("33");
		cout << "Products Menu [1]\n";
		cout << "Customers Menu [2]\n";
		cout << "Shopping [3]\n";
		cout << "About Dev [4]\n";
		cout << "Exit [0]\n\n";

		cout << "Press a key to continue...";
		key = _getch();

		switch (key) {
		case '0':
			exit(0);
		case '1':
			ProductMenu();
			break;
		case '2':
			CustomerMenu();
			break;
		case'3':
			ShoppingMenu();
			break;
		case '4':
			AboutDev();
			break;
		}
	}
}
// ============= Main ============ //
int main() {
	Menu();
	return 0;
}
// ====== End Programmming ====== //
// Developed by Mohammadreza