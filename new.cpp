#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <cctype>
#include <climits>
#include <Windows.h> //set timer
#include <cstdio>
using namespace std;

//prototype
void logo();
void staff_login();

void admin();
void admin_login();
void check_profit();
void staff_mag();
void customer_det();
char vc_user(string v_user_type);
char vc_admin(string v_admin_c);
char vc_admin_login(string v_admin_c_l);
void change_pass();

void order_menu();
void package();
void a_la_carte();
void beverage();
void personal();
void family();
void burger();
void fried_chicken();
void side();
int num_order();
void check_cart();
void checkout();
void bill();

//void get_price();
void det_fill();
string validatePhone(string);
char validateGender(string);
string validateDescript(string);

//delivery
void delivery();
void state();
void postcode();
void confirm_address();


//staff management prototype
void staff_mag();
void addStaff();
void delStaff();
void mag_staffList();
void disp_staffList();
void nextStaffChoice();
string valid_staffChoice(string);
string valid_Name(string);
string valid_staffIC(string);
char valid_staffGender(string);
int calc_staffAge(string);
void staffMenu();

//food and beverage management
void FoodnBeverageMngmt();
void packageCat();
void alacarteCat();
void PersonalSubCat();
void FamilySubCat();
void chooseService(string, string);
void UPDService(string, string);
void INSService(string, string);
void DELService(string, string);
string validateChoice(string, int);

//insert map
void insertMapFunc();
void insertMap(string, string, int* i);
void displayMenu3(string, string, string, string, string, string, string);
void displayMenu2(string, string, string, string, string);
void displayMenu1(string, string);

//global variable vd = validated
bool order_complete = false;
string sName[50], sGender[50], sICnumber[50], sAge[50];
char vdc_user_c, vdc_admin_c, valid_login_admin, valid_login_staff, vdc_admin_c_l;
string choice = "0", order = "1", description, fname, IptName, UPDname, name, price, code;
double UPDprice, IptPrice, fprice;
string confirmation;
int user_state;
string address;
string user_postcode;
string userstate;
string date, line,foodcode,foodname,amount;
double chk_price;
double chk_profit = 0;
map <string, int> order_map; //store user orders (code and amount ordered)
map < string, double> price_map; //store product prices (code and price)
map < string, double> itemMap;
map <string, double> ::iterator itemMapitr;
map <string, string> food_map;
map <string, string> ::iterator it_food;

//sorting
void sortStaff(string* array1, string* array2, string* array3, string* array4, int); 
void swapping(string& a, string& b);
void store(int);



int main() {
	while (vdc_user_c != '0'){
		system("cls");
		logo();
		cout << "\n\t\t\t\t1. Staff Login\n";
		cout << "\t\t\t\t2. Admin Login";
		cout << "\n\t\t\t\t0. Close Program\n";
		cout << "\n\t\t\t\tEnter your choice : ";
		cin >> choice;
		vdc_user_c = vc_user(choice);
		if (vdc_user_c == '1') {
			staff_login();
		}
		else if (vdc_user_c == '2') {
			admin_login();
		}
		else {
			logo();
			cout << "\n\t\t\t\t\tHave a nice day!" << endl;
			cout << "\t\t";
			system("PAUSE");
			system("cls");
			return 0;
		}
	}

}

//valid choice user
char vc_user(string v_user_type) {
	char validated_one;
	while (v_user_type != "0" && v_user_type != "1" && v_user_type != "2") {
		cout << "\n\t\t\t\tPlease choose a proper selection!";
		cout << "\n\t\t\t\tEnter your choice : ";
		cin >> v_user_type;
	}
	validated_one = v_user_type[0];
	return validated_one;
}


//validate admin login choice
char vc_admin_login(string v_admin_c_l) {
	char validated_two;
	while (v_admin_c_l != "0" && v_admin_c_l != "L" && v_admin_c_l != "l") {
		cout << "\n\t\tPlease choose a proper selection!";
		cout << "\n\t\tEnter your choice : ";
		cin >> v_admin_c_l;
	}
	validated_two = v_admin_c_l[0];
	return validated_two;
}

//validate admin login choice
char vc_admin(string v_admin_c) {
	char validated_three;
	while (v_admin_c != "0" && v_admin_c != "1" && v_admin_c != "2" && v_admin_c != "3" && v_admin_c != "4" && v_admin_c != "5") {
		cout << "\n\t\tPlease choose a proper selection!";
		cout << "\n\n\t\tEnter your choice : ";
		cin >> v_admin_c;
	}
	validated_three = v_admin_c[0];
	return validated_three;
}

void admin_login() {
	string adminId, adminPassword;
	string data;
	system("CLS");
	cout << "\n\t\t   Do You Want To Login?" << endl;
	cout << "\t----------------------------------------------" << endl;
	cout << "\n\t\tPress 0 return to previous page.";
	cout << "\n\t\tPress L or l to login.";
	cin >> choice;
	vdc_admin_c_l = vc_admin_login(choice);
	if (vdc_admin_c_l == 'L' || vdc_admin_c_l == 'l') {
		cout << "\n\n\n\n\n\t----------------------------------------------" << endl;
		cout << "\t\t\tAdmin Login" << endl;
		cout << "\t----------------------------------------------" << endl;

		string psw;
		// Read from the text file
		ifstream readpass("admin.txt");

		// Use a while loop together with the getline() function to read the file line by line
		getline(readpass, psw);
		// Close the file
		readpass.close();

		string password;
		while (password != psw) {
			cout << "\n\n\t\tAdmin Password: ";
			cin >> password;
			if (password == psw) {
				break;
			}
			else {
				cout << "\n\t\tYour password is incorrect!";
			}
		}
		admin();
	}
	else {
		main();
	}
}

void admin() {
	system("CLS");
	cout << "\n\t------------------------------------------" << endl;
	cout << "\t\t\tWelcome!" << endl;
	cout << "\t------------------------------------------" << endl;
	cout << "\n\t\t1. Food & Beverage Management" << endl;
	cout << "\t\t2. Check profit" << endl;
	cout << "\t\t3. Staff management" << endl;
	cout << "\t\t4. Customer details" << endl;
	cout << "\t\t5. Change Password" << endl;
	cout << "\n\t\t0. Back to login page" << endl;
	cout << "\n\t\tEnter your choice : ";
	cin >> choice;
	vdc_admin_c = vc_admin(choice); //validate choice

	if (vdc_admin_c == '1') {
		cin.get();
		FoodnBeverageMngmt();
	}
	else if (vdc_admin_c == '2') {
		check_profit();
	}
	else if (vdc_admin_c == '3') {
		staff_mag();
	}
	else if (vdc_admin_c == '4') {
		customer_det();
	}
	else if (vdc_admin_c == '5') {
		change_pass();
	}
	else {
		admin_login();
	}
}

//Module of food and beverage management
void FoodnBeverageMngmt() {
	cout << "\t\t==============Category Menu==============" << endl;
	cout << "\t\t1. Package" << endl;
	cout << "\t\t2. A la cart" << endl;
	cout << "\t\t3. Beverage" << endl;
	cout << "\t\t0. Exit" << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tEnter the category: ";
	getline(cin, choice);
	choice = validateChoice(choice, 4);

	if (choice == "1") {
		system("CLS");
		packageCat();
	}
	else if (choice == "2") {
		system("CLS");
		alacarteCat();
	}
	else if (choice == "3") {
		system("CLS");
		chooseService("Beverage", "Beverage");
	}
	else {
		//exit to admin menu
	}
}



//Module of package module
void packageCat() {
	cout << "\t\t==============Package Menu==============" << endl;
	cout << "\t\t1. Personal" << endl;
	cout << "\t\t2. Family" << endl;
	cout << "\t\t0. Exit" << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tEnter the pakage: ";
	getline(cin, choice);
	choice = validateChoice(choice, 3);
	if (choice == "1") {
		system("CLS");
		PersonalSubCat();
	}
	else if (choice == "2") {
		system("CLS");
		FamilySubCat();
	}
	else {
		FoodnBeverageMngmt();
	}
}


//Module of personal subcategory 
void PersonalSubCat() {
	cout << "\t\t==============Type Menu==============" << endl;
	cout << "\t\t1. Fried Chicken" << endl;
	cout << "\t\t2. Chicken Burger" << endl;
	cout << "\t\t3. Fish Burger" << endl;
	cout << "\t\t0. Exit" << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tEnter the type: ";
	getline(cin, choice);
	choice = validateChoice(choice, 4);
	//determine the filename and item name then go to chooseservice module
	if (choice == "1") {
		system("CLS");
		chooseService("PersonalFriedChicken", "Fried Chicken");
	}
	else if (choice == "2") {
		system("CLS");
		chooseService("PersonalChickenBurger", "Chicken Burger");
	}
	else if (choice == "3") {
		system("CLS");
		chooseService("PersonalFishBurger", "Fish Burger");
	}
	else {
		system("CLS");
		packageCat();
	}
}

//Module of family subcategory
void FamilySubCat() {
	cout << "\t\t==============Type Menu==============" << endl;
	cout << "\t\t1. Fried Chicken" << endl;
	cout << "\t\t2. Chicken Burger" << endl;
	cout << "\t\t3. Fish Burger" << endl;
	cout << "\t\t0. Exit" << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tEnter the type: ";
	getline(cin, choice);
	choice = validateChoice(choice, 4);
	//determine the filename and item name then go to chooseservice module
	if (choice == "1") {
		system("CLS");
		chooseService("FamilyFriedChicken", "Fried Chicken");
	}
	else if (choice == "2") {
		system("CLS");
		chooseService("FamilyChickenBurger", "Chicken Burger");
	}
	else if (choice == "3") {
		system("CLS");
		chooseService("FamilyFishBurger", "Fish Burger");
	}
	else {
		system("CLS");
		packageCat();
	}
}

//Module of a la carte category
void alacarteCat() {
	cout << "\t\t==============Type Menu==============" << endl;
	cout << "\t\t1. Fried Chicken" << endl;
	cout << "\t\t2. Chicken Burger" << endl;
	cout << "\t\t3. Fish Burger" << endl;
	cout << "\t\t4. Side" << endl;
	cout << "\t\t0. Exit" << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tEnter the type: ";
	getline(cin, choice);
	choice = validateChoice(choice, 5);
	//determine the filename and item name then go to chooseservice module
	if (choice == "1") {
		system("CLS");
		chooseService("AlacarteFriedCchicken", "Fried Chicken");
	}
	else if (choice == "2") {
		system("CLS");
		chooseService("AlacarteChickenBurger", "Chicken Burger");
	}
	else if (choice == "3") {
		system("CLS");
		chooseService("AlacarteFishBurger", "Fish Burger");
	}
	else if (choice == "4") {
		system("CLS");
		chooseService("AlacarteSide", "Side");
	}
	else {
		system("CLS");
		FoodnBeverageMngmt();
	}
}
string validateChoice(string choice,int n) {
	while (true) {
		if (choice.length() != 1) {
			cout << "\t\tOnly 1 digit is allowed." << endl;
			cout << "\t\tEnter again: ";
			getline(cin, choice);
		}

		else if (!isdigit(choice[0])) {
			cout << "\t\tOthers symbol are not allowed" << endl;
			cout << "\t\tEnter again: ";
			getline(cin, choice);
		}
		else {
			int count = 0;
			int temp_choice = stoi(choice);
			for (int i = 0; i < n; i++) {
				if (temp_choice != i) {
					count++;
				}
			}
			if (count == n) {
				cout << "\t\tInvalid choice" << endl;
				cout << "\t\tEnter again: ";
				getline(cin, choice);
			}
			else {
				return choice;
			}
		}
	}
	
}

//Module of choosing service
void chooseService(string filename, string itemname) {
	int i = 1;
	char SChoice;
	ifstream DISPfile;
	DISPfile.open("text/" + filename + ".txt");
	//Get data from fileand insert into map
	while (getline(DISPfile, fname)) {
		DISPfile >> fprice;
		itemMap.insert(pair<string, double>(fname, fprice));
		getline(DISPfile, fname);
	}
	DISPfile.close();
	system("CLS");
	//Display existing item in the map
	cout << "\t\t==============Existing " <<
		itemname << "==============" << endl;
	cout << "\t\t" <<  setw(40) << left << "    NAME" << setw(5) << left << "PRICE(RM)" << endl;
	for (itemMapitr = itemMap.begin(); itemMapitr != itemMap.end(); itemMapitr++) {
		cout << "\t\t" << i << ". " << setw(40) << left << itemMapitr->first << setw(5) << right << fixed << setprecision(2) << itemMapitr->second << '\n';
		i++;
	}
	cout << endl;
	cout << "\t\t1. Update item" << endl;
	cout << "\t\t2. Insert new item" << endl;
	cout << "\t\t3. Delete previous item" << endl;
	cout << "\t\t0. Exit to category menu" << endl;
	cout << "\t\t------------------------------------------------------" << endl;
	cout << "\t\tEnter your service: ";
	getline(cin, choice);
	choice = validateChoice(choice, 4);
	//Determine service based on the choice
	if (choice == "1") {
		UPDService(filename, itemname);
	}
	else if (choice == "2") {
		INSService(filename, itemname);
	}
	else if (choice == "3") {
		DELService(filename, itemname);
	}
	else {
		itemMap.clear();
		system("CLS");
		FoodnBeverageMngmt();
	}
}
//Module of update item service
void UPDService(string filename, string itemname) {
	cout << "\t\tEnter the item name that you want to update: ";
	getline(cin, IptName);
	//Check the validity of name input
	//The name input is not found in map
	while (itemMap.find(IptName) == itemMap.end()) {
		cout << "\t\tInvalid item name." << endl;
		cout << "\t\tEnter again: ";
		getline(cin, IptName);
	}
	cout << "\t\tUpdate name or price?" << endl;
	cout << "\t\tEnter 'N' for name or 'P' for price: ";
	getline(cin, choice);
	while (choice != "N" && choice != "n"
		&& choice != "P" && choice != "p") {
		cout << "\t\tInvalid option." << endl;
		cout << "\t\tEnter again: ";
		getline(cin, choice);
	}
	if (choice == "N" || choice == "n") {
		cout << "\t\tEnter the updated name: ";
		getline(cin, UPDname);
		while (UPDname.empty()) {
			cout << "\t\tEmpty field is not allowed." << endl;
			cout << "\t\tEnter again: ";
			getline(cin, UPDname);
		}
		cout << "\t\tDo you confirm you want to update the food name from '" << IptName << "' to '" << UPDname << "' ?" <<
			"\n\t\tEnter 'Y' for confirm or 'N' to cancel: ";
		getline(cin, choice);
		while (choice != "Y" && choice != "y"
			&& choice != "N" && choice != "n") {
			cout << "\t\tInvalid option." << endl;
			cout << "\t\tEnter again: ";
			getline(cin, choice);
		}
		if (choice == "Y" || choice == "y") {
			//store the key and element selected in the variables
			itemMapitr = itemMap.find(IptName);
			IptName = itemMapitr->first;
			UPDprice = itemMapitr->second;
			//Erase the current namee
			itemMap.erase(IptName);
			//Insert updated name and price
			itemMap.insert(pair<string, double>(UPDname, UPDprice));
			//Open file and insert map into file
			ofstream UPDfile;
			UPDfile.open("text/" + filename + ".txt");
			for (itemMapitr = itemMap.begin(); itemMapitr != itemMap.end(); itemMapitr++) {
				UPDfile << itemMapitr->first << "\n" << itemMapitr->second << "\n";
			}
			UPDfile.close();
			cout << "\n";
			cout << "\t\tUpdate completely!!!" << endl;
			cout << "\t\t";
			system("PAUSE");
			system("CLS");
			FoodnBeverageMngmt();
		}
		else {
			//Clear all the elements in the map
			itemMap.clear();
			system("CLS");
			chooseService( filename,  itemname);
		}
	}
	else {
		cout << "\t\tEnter the updated price: ";
		cin >> UPDprice;
		while (UPDprice <= 0) {
			cout << "\t\tZero or negative value is not allowed." << endl;
			cout << "\t\tEnter again: ";
			cin >> UPDprice;
		}
		//store the key and element selected in the variables
		itemMapitr = itemMap.find(IptName);
		UPDname = itemMapitr->first;
		IptPrice = itemMapitr->second;
		cin.get();
		cout << "\t\tDo you confirm you want to update the item price from '" << IptPrice << "' to '" << UPDprice << "' ?" <<
			"\n\t\tEnter 'Y' for confirm or 'N' to cancel: ";
		getline(cin, choice);
		while (choice != "Y" && choice != "y"
			&& choice != "N" && choice != "n") {
			cout << "\t\tInvalid option." << endl;
			cout << "\t\tEnter again: ";
			getline(cin, choice);
		}
		if (choice == "Y" || choice == "y") {
			//Erase the current name and price
			itemMap.erase(IptName);
			//Insert updated name and price
			itemMap.insert(pair<string, double>(UPDname, UPDprice));
			//Open file and insert map into file
			ofstream UPDfile;
			UPDfile.open("text/" + filename + ".txt");
			for (itemMapitr = itemMap.begin(); itemMapitr != itemMap.end(); itemMapitr++) {
				UPDfile << itemMapitr->first << "\n" << itemMapitr->second << "\n";
			}
			UPDfile.close();
			cout << "\n";
			cout << "\t\tUpdate completely!!!" << endl;
			cout << "\t\t";
			system("PAUSE");
			system("CLS");
			FoodnBeverageMngmt();
		}
		else {
			//Clear all the elements in the map
			itemMap.clear();
			system("CLS");
			chooseService( filename,  itemname);
		}
	}
}
//Module of insert new item service
void INSService(string filename, string itemname) {
	cout << "\t\tInsert the name for the new item: ";
	getline(cin, IptName);
	while (IptName.empty()) {
		cout << "\t\tEmpty field is not allowed." << endl;
		cout << "\t\tEnter again: ";
		getline(cin, IptName);
	}
	//Validate if the input name is found in the map
	//The name input is not found in map
	while (itemMap.find(IptName) != itemMap.end()) {
		cout << "\t\tThe item is existed already. Please try another new name." << endl;
		cout << "\t\tEnter again: ";
		getline(cin, IptName);
	}
	cout << "\t\tEnter the price for the new item: ";
	cin >> IptPrice;
	while (IptPrice <= 0) {
		cout << "\t\tZero or negative value is not allowed." << endl;
		cout << "\t\tEnter again: ";
		cin >> IptPrice;
	}
	cin.get();
	cout << "\t\tAre you sure you want to insert a new item called '" << IptName << "' with the price RM" <<
		fixed << setprecision(2) << IptPrice << " ?" << endl;
	cout << "\t\tEnter 'Y' for confirm or 'N' to cancel: ";
	getline(cin, choice);
	while (choice != "Y" && choice != "y"
		&& choice != "N" && choice != "n") {
		cout << "\t\tInvalid option." << endl;
		cout << "\t\tEnter again: ";
		getline(cin, choice);
	}
	if (choice == "Y" || choice == "y") {
		//Insert the name and price of new item
		itemMap.insert(pair<string, double>(IptName, IptPrice));
		//Open file and insert map into file
		ofstream INSfile;
		INSfile.open("text/" + filename + ".txt");
		for (itemMapitr = itemMap.begin(); itemMapitr != itemMap.end(); itemMapitr++) {
			INSfile << itemMapitr->first << "\n" << itemMapitr->second << "\n";
		}
		INSfile.close();
		cout << "\n";
		cout << "\t\tInsert completely!!!" << endl;
		cout << "\t\t*Please noted that the item name is inserted according to the alphabet." << endl;
		cout << "\t\t";
		system("PAUSE");
		system("CLS");
		FoodnBeverageMngmt();
	}
	else {
		//Clear all the elements in the map
		itemMap.clear();
		system("CLS");
		chooseService( filename,  itemname);
	}
}
void DELService(string filename, string itemname) {
	cout << "\t\tEnter the item name that want to delete: ";
	getline(cin, IptName);
	while (IptName.empty()) {
		cout << "\t\tEmpty field is not allowed." << endl;
		cout << "\t\tEnter again: ";
		getline(cin, IptName);
	}
	while (itemMap.find(IptName) == itemMap.end()) {
		cout << "\t\tInvalid item name." << endl;
		cout << "\t\tEnter again: ";
		getline(cin, IptName);
	}

	cout << "\t\tAre you sure you want to delete '" << IptName << "' item ?" << endl;
	cout << "\t\tEnter 'Y' for confirm or 'N' to cancel: ";
	getline(cin, choice);
	while (choice != "Y" && choice != "y"
		&& choice != "N" && choice != "n") {
		cout << "\t\tInvalid option." << endl;
		cout << "\t\tEnter again: ";
		getline(cin, choice);
	}
	if (choice == "Y" || choice == "y") {
		//Delete the name input in the map
		itemMap.erase(IptName);
		ofstream DELfile;
		DELfile.open("text/" + filename + ".txt");
		for (itemMapitr = itemMap.begin(); itemMapitr != itemMap.end(); itemMapitr++) {
			DELfile << itemMapitr->first << "\n" << itemMapitr->second << "\n";
		}
		DELfile.close();
		cout << "\n";
		cout << "\t\tDelete completely!!!" << endl;
		cout << "\t\t";
		system("PAUSE");
		system("CLS");
		FoodnBeverageMngmt();
	}
	else {
		//Clear all the elements in the map
		itemMap.clear();
		system("CLS");
		chooseService( filename,  itemname);
	}
}

void check_profit() {
	system("CLS");
	ifstream infile;
	//open the text file 
	infile.open("duit.txt");

	cout << "\t\t=======================================";
	cout << "\n\t\t           #Check Profit#" << endl;
	cout << "\t\t=========================================" << endl;

	//if cannot find the file
	if (!infile)
	{
		cout << "\t\tCheck profit unavailable! " << endl;
		cin.ignore();
		cin.ignore(99, '\n');	//stop until user press enter
		admin();
	}

	while (getline(infile, line)) {
		if (line[0] == '#') {
			date = line.substr(1, 25);
			cout <<"\n\t\t"<< date << endl;
			cout << "\t\t-------------------------------------------------" << endl;
		}
		else if (line[0] == '.') {
			foodcode = line.substr(1, 4);
			cout << "\t\t" << foodcode<<"\t";
			
		}
		else if (line[0] == '*') {
			foodname = line.substr(1, 50);
			cout<< "\t\t" <<setw(35)<<left<< foodname ;
			
		}
		else if (line[0] == ':') {
			amount = line.substr(1, 2);
			cout<< "\t\t" <<setw(3)<<right<<"X" <<amount << endl;
		
		}
		else if (line[0] == '$') {
			chk_price = stod(line.substr(1, line.length()-1));
			chk_profit += chk_price;
			cout<< "\t\t" << "Price:RM " << chk_price << endl;	//check value
			
		}
	}
	cout << endl<<"\t\tCheck profit = RM " << chk_profit<<endl;
	infile.close();   //closing the file
	cout << "\t\t";
	system("PAUSE");
	admin();
}

void staff_mag() {

	system("CLS");

	staffMenu();

	cin >> choice;

	choice = valid_staffChoice(choice);

	if (choice == "1") {
		addStaff();
	}
	else if (choice == "2") {
		delStaff();
	}
	else if (choice == "3") {
		mag_staffList();
	}
	else
		admin();

}

void addStaff() {

	string staffName, staffIC, cChoice, staffPWD, pwd1, pwd2, staffID;
	int staffAge;
	char staffGender;

	do {
		system("CLS");
		cout << "\n\t\t================================================" << endl;
		cout << "\t\t\t\t  ADD NEW STAFF" << endl;
		cout << "\t\t================================================\n" << endl;

		cout << "\t\tStaff Name\t: ";
		cin.get();
		getline(cin, staffName);

		staffName = valid_Name(staffName);

		cout << "\n\t\tStaff IC.NO\t: ";
		getline(cin, staffIC);

		staffIC = valid_staffIC(staffIC);

		staffAge = calc_staffAge(staffIC);

		if (staffAge != 0) {

			cout << "\n\t\tStaff Age\t: " << staffAge << endl;

			staffGender = valid_staffGender(staffIC);

			cout << "\n\t\tStaff Gender\t: " << staffGender << endl;

			cout << "\n\t\t================================================" << endl;
			cout << "\n\t\t\t1. Confirm" << endl;
			cout << "\t\t\t2. Reenter" << endl;
			cout << "\n\t\tEnter Your Choice\t: ";
			cin >> cChoice;

			while (cChoice != "1" && cChoice != "2") {
				cout << "\n\t\tPlease Enter 1 or 2 only." << endl;
				cout << "\t\tEnter Your Choice\t: ";
				cin >> cChoice;
			}
		}
		else
			cChoice = "2";

	} while (cChoice == "2");

	ofstream staffDetails;
	staffDetails.open("Staff/Staff.txt", ofstream::app);
	staffDetails << staffName << "\n" << staffAge << "\n" << staffGender << "\n" << staffIC << endl;
	staffDetails.close();

	for (int i = 0; i < 3; i++) {
		staffPWD += staffName.at(i);
	}

	for (int j = 10; j < staffIC.length(); j++) {
		staffPWD += staffIC.at(j);
	}

	cout << "\n\t\tSTAFF NAME: " << staffName << endl;
	cout << "\t\tLOGIN PWD : " << staffPWD << endl;

	ofstream staffLogin;
	staffLogin.open("Staff/" + staffName + ".txt");
	staffLogin << staffPWD;
	staffLogin.close();

	nextStaffChoice();
}

void disp_staffList() {

	string line;
	int staffnum = 5, countline = 0, num = 0, j = 0, n = 20;

	system("CLS");
	cout << "\n\t\t===========================================================================" << endl;
	cout << "\t\t\t\t\tSTAFF LIST" << endl;
	cout << "\t\t===========================================================================" << endl;
	cout << "\t\t NO. ||\t" << setw(15) << right << "NAME" << setw(18) << "||   AGE" << "   ||  GENDER  ||   " << setw(10) << "IC NUMBER" << endl;
	cout << "\t\t===========================================================================\n" << endl;
	ifstream staffDetails;

	staffDetails.open("Staff/Staff.txt");

	while (getline(staffDetails, line)) {
		countline++;
	}

	staffDetails.close();

	staffDetails.open("Staff/Staff.txt");
	for (int i = 0; i < countline; i += 4) {
		getline(staffDetails, sName[j]);
		getline(staffDetails, sAge[j]);
		getline(staffDetails, sGender[j]);
		getline(staffDetails, sICnumber[j]);
		num++;
		cout << "\t\t " << num << ". \t" << setw(30) << left << sName[j].substr(0, 25) << setw(12) << sAge[j] << setw(10) << sGender[j] << setw(15) << sICnumber[j] << endl;
		if (sName[j].length() > 25) {
			int k = 1; //counter
			const int name_length = 25;
			if (sName[j].length() > name_length)
			{
				string name_temp;
				name_temp = sName[j].substr((double)name_length * k, name_length);
				cout << "\t\t" << name_temp << endl;
				k++;
				for (double i = (double)sName[j].length() / name_length; i > 2; i--)
				{
					name_temp = sName[j].substr((double)name_length * k, name_length);
					cout << "\t\t" << name_temp << endl;
					k++;
				}
			}
		}

		j++;
	}

	staffDetails.close();
}

void mag_staffList() {

	string line;
	int staffnum = 5, countline = 0, num = 0, j = 0, n = 20;

	disp_staffList();

	cout << "\n\t\t===========================================================================" << endl;
	cout << "\n\t\tDo you want to apply sorting? (According to)" << endl;
	cout << "\t\t1. Name" << endl;
	cout << "\t\t2. Age" << endl;
	cout << "\t\t0. No Sorting" << endl;
	cout << "\t\tEnter Your Choice : ";
	cin >> choice;

	while (choice != "1" && choice != "2" && choice != "0") {

		if (choice.length() > 1) {
			cout << "\n\t\tOnly One Character Is Accepted." << endl;
		}
		else if (isalpha(choice.at(0))) {
			cout << "\n\t\tChoice Cannot Include Alphabet." << endl;
		}
		else {
			cout << "\n\t\tWill Accept 1, 2 or 0 Only." << endl;
		}

		cout << "\t\tEnter Choice Again: ";
		cin >> choice;
	}

	if (choice == "0")
		nextStaffChoice();
	else if (choice == "1") {
		sortStaff(sName, sAge, sGender, sICnumber, n);
		store(n);
	}
	else{
		sortStaff(sAge, sName, sGender, sICnumber, n);
		store (n);
	}

	nextStaffChoice();
}

void store(int size){
	ofstream sortFile;
	sortFile.open("Staff/Staff.txt", ofstream::trunc);

	
	for (int i = 0; i < size; i++) {
		if (!sName[i].empty()) {
			sortFile << sName[i] << "\n" << sAge[i] << "\n" << sGender[i] << "\n" << sICnumber[i] << "\n";
		}
		else {
			continue;
		}
	}
	for(int i = 0;i < 50; i++) {
		sName[i].clear();
		sAge[i].clear();
		sGender[i].clear();
		sICnumber[i].clear();
	}
			
	cout << "\n\t\tSorted Completely" << endl;
	sortFile.close();
}

void swapping(string& a, string& b) {
	string temp;
	temp = a;
	a = b;
	b = temp;
}

void sortStaff(string* array1, string* array2, string* array3, string* array4, int size) {
	for (int i = 0; i < size; i++) {
		int swap = 0;
		for (int j = 0; j < size - i - 1; j++) {
			if (array1[j] >  array1[j + 1]) {
				swapping(array1[j], array1[j + 1]);
				swapping(array2[j], array2[j + 1]);
				swapping(array3[j], array3[j + 1]);
				swapping(array4[j], array4[j + 1]);
				swap = 1;
			}
		}
		if (!swap)
			break;
	}

}

void nextStaffChoice() {

	do {
		cout << "\n\t\t===========================================================================" << endl;
		cout << "\n\t\t1. Check Staff List" << endl;
		cout << "\t\t2. Add Staff" << endl;
		cout << "\t\t3. Remove Staff" << endl;
		cout << "\t\t0. Back" << endl;
		cout << "\t\tEnter Your Choice : ";
		cin >> choice;

		while (choice != "1" && choice != "2" && choice != "3" && choice != "0") {

			if (choice.length() > 1) {
				cout << "\n\t\tOnly One Character Is Accepted." << endl;
			}
			else if (isalpha(choice.at(0))) {
				cout << "\n\t\tChoice Cannot Include Alphabet." << endl;
			}
			else {
				cout << "\n\t\tWill Accept 1, 2, 3 or 0 Only." << endl;
			}

			cout << "\t\tEnter Choice Again: ";
			cin >> choice;
		}

		if (choice == "0")
			staff_mag();
		else if (choice == "1")
			disp_staffList();
		else if (choice == "2")
			addStaff();
		else
			delStaff();

	} while (choice == "1");

}

string valid_staffChoice(string choice) {

	while (choice != "1" && choice != "2" && choice != "3" && choice != "0") {

		if (choice.length() > 1) {
			cout << "\n\t\tOnly One Character Is Accepted." << endl;
		}
		else if (isalpha(choice.at(0))) {
			cout << "\n\t\tStaff Management Choice Cannot Include Alphabet." << endl;
		}
		else {
			cout << "\n\t\tStaff Choosen Will Accept 1, 2, 3 or 0 Only." << endl;
		}

		cout << "\t\tEnter Choice Again: ";
		cin >> choice;
	}
	return choice;
}

string valid_Name(string Name) {

	while (true) {

		int digit = 0, empty = 0, min = 0, other = 0;


		if (Name.empty()) {
			empty++;
		}

		else {
			for (int i = 0; i < Name.length(); i++) {

				if (Name.length() < 4)
					min++;

				else if (isdigit(Name.at(i)))
					digit++;

				else if (isalpha(Name.at(i)))
					continue;

				else if (isspace(Name.at(i)))
					continue;

				else
					other++;
			}
		}


		if (empty != 0)
			cout << "\n\t\tName cannot be EMPTY." << endl;

		else if (min != 0)
			cout << "\n\t\tName cannot be less than 4 WORDS." << endl;

		else if (digit != 0)
			cout << "\n\t\tName cannot include DIGIT." << endl;

		else if (other != 0)
			cout << "\n\t\tName cannot include others CHARACTER." << endl;

		else {
			for (int i = 0; i < Name.length(); i++) {
				Name.at(i) = toupper(Name.at(i));
			}
			return Name;
		}

		cout << "\t\tEnter Name Again\t: ";
		getline(cin, Name);
	}
}

int calc_staffAge(string staffIC) {

	int staffAge = 0;

	int year = ((int)staffIC.at(0) - 48) * 10 + ((int)staffIC.at(1) - 48);

	if (year < 100 && year>60) {
		year += 1900;
	}
	else {
		year += 2000;
	}

	staffAge = 2021 - year;

	if (staffAge > 0 && staffAge < 18)
		cout << "\n\t\tInvalid Staff Age. Legal Working Staff Age Must Above 18." << endl;
	else if (staffAge > 60 && staffAge <= 100)
		cout << "\n\t\tInvalid Staff Age. Legal Working Staff Age Must Below 60." << endl;
	else if (staffAge > 100 || staffAge <= 0)
		cout << "\n\t\tInvalid Staff Age." << endl;
	else
		return staffAge;

	staffAge = 0;
	Sleep(3000);
	return staffAge;
}

char valid_staffGender(string staffIC) {

	char staffGender;

	int gender = (int)staffIC.at(13) - 48;

	if (gender % 2 == 0) {
		staffGender = 'F';
	}
	else {
		staffGender = 'M';
	}

	return staffGender;
}

string valid_staffIC(string staffIC) {

	bool valid_ic = false;

	while (valid_ic != true) {

		if (staffIC.empty()) {
			cout << "\n\t\t* Staff IC Number Cannot Be Empty." << endl;
		}

		else if (staffIC.length() != 14 || staffIC.at(6) != '-' || staffIC.at(9) != '-') {
			cout << "\n\t\t* Staff IC Number Must Follow Format (xxxxxx-xx-xxxx)." << endl;
		}

		else {
			for (int i = 0; i < staffIC.length(); i++) {

				if (isdigit(staffIC.at(i)))
				{
					valid_ic = true;
					continue;
				}
				else if (i == 6 && staffIC.at(i) == '-')
				{
					valid_ic = true;
					continue;
				}
				else if (i == 9 && staffIC.at(i) == '-')
				{
					valid_ic = true;
					continue;
				}
				else if (isalpha(staffIC.at(i)))
				{
					i = 0;
					valid_ic = false;
					cout << "\n\t\t* IC Number Cannot Include Alphabet." << endl;
					break;
				}
				else
				{
					i = 0;
					valid_ic = false;
					cout << "\n\t\t* Staff IC Number Cannot Include Other Characters." << endl;
					break;
				}

			}
		}

		if (valid_ic == true) {

			int year = ((int)staffIC.at(0) - 48) * 10 + ((int)staffIC.at(1) - 48);

			int month = ((int)staffIC.at(2) - 48) * 10 + ((int)staffIC.at(3) - 48);
			int day = ((int)staffIC.at(4) - 48) * 10 + ((int)staffIC.at(5) - 48);

			int leapYear[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
			int Year[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
			bool leap;

			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				leap = true;
			else
				leap = false;
		

			if (month >= 1 && month <= 12) {
				if (day >= 1) {
					if (leap) {
						if (day > leapYear[month] && day < 1)
							valid_ic = false;
						else
							valid_ic = true;
					}
					else {
						if (day > Year[month])
							valid_ic = false;
						else
							valid_ic = true;
					}
				}
				else
					valid_ic = false;
			}
			else {
				valid_ic = false;
			}

		}


		if (valid_ic == true) {

			if (staffIC.at(7) == '0' || staffIC.at(7) == '2')
			{
				if (staffIC.at(8) == '0') {
					valid_ic = false;
				}
				else {
					valid_ic = true;
				}
			}

			else if (staffIC.at(7) == '1')
			{
				if (staffIC.at(8) >= '7') {
					valid_ic = false;
				}
				else {
					valid_ic = true;
				}
			}
			else if (staffIC.at(7) > '5') {
				valid_ic = false;
			}
			else {
				valid_ic = true;
			}
		}

		if (valid_ic != true) {
			cout << "\n\t\tInvalid IC Number." << endl;
			cout << "\t\tEnter Staff IC Again\t: ";
			getline(cin, staffIC);
		}
		else {
			break;
		}
	}
	return staffIC;
}

void delStaff() {

	char staffFile[] = "Staff/Staff.txt";
	char tempFile[] = "Staff/temp.txt";

	int num, startLine = 0, endLine = 0, countline = 0, staffCount = 0, k = 0, renameRSLT, removeRSLT;
	string info, fileLine, fileName, removeStaff[4];

	disp_staffList();

	ifstream staffInfo;
	staffInfo.open(staffFile);

	while (getline(staffInfo, fileLine)) {
		countline++;
	}
	staffInfo.close();

	staffCount = countline / 4;

	cout << "\n\t\t===========================================================================" << endl;
	cout << "\n\t\tEnter [0] for exit." << endl;
	cout << "\n\t\tPlease enter the corresponding number of the staff you want to delete." << endl;
	cout << "\n\t\tEnter your choice : ";
	cin >> num;

	while (cin.fail()) {
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		cout << "\n\t\tYou can only enter numbers.\n";
		cout << "\t\tEnter your choice : ";
		cin >> num;
	}

	while (num > staffCount || num < 0) {
		cout << "\n\t\tThe number is out of range ( 1-" << staffCount << " )" << endl;
		cout << "\t\tEnter your choce again : ";
		cin >> num;
	}

	if (num == 0)
		staff_mag();
	else {
		endLine = num * 4;

		startLine = endLine - 3;

		staffInfo.open(staffFile);

		for (int i = 1; i <= endLine; i++) {
			getline(staffInfo, info);

			if (i >= startLine) {
				if (i == startLine) {
					fileName = info;
				}
				removeStaff[k] = info;
				k++;
			}
		}

		staffInfo.close();

		ifstream check(staffFile);
		ofstream store(tempFile);

		k = 0;
		while (getline(check, fileLine)) {
			if (fileLine != removeStaff[k]) {
				store << fileLine << endl;
			}
			else {
				k++;
			}
		}

		check.close();
		store.close();

		remove(staffFile);
		renameRSLT = rename(tempFile, staffFile);

		fileName = "Staff/" + fileName + ".txt";

		removeRSLT = remove((fileName).c_str());

		if (removeRSLT == 0 && renameRSLT == 0)
			cout << "\n\t\tStaff Has Been Removed Successfully." << endl;
		else
			cout << "\n\t\tStaff Removed Fail." << endl;


		for (int i = 0; i < 50; i++) {
			sName[i].clear();
			sAge[i].clear();
			sGender[i].clear();
			sICnumber[i].clear();
		}
	}
	nextStaffChoice();
}

void staffMenu() {

	cout << "\n\t================================================" << endl;
	cout << "\t\t\tSTAFF MANAGEMENT" << endl;
	cout << "\t================================================\n" << endl;
	cout << "\t\t1.\tAdd New Staff" << endl;
	cout << "\t\t2.\tRemove Staff" << endl;
	cout << "\t\t3.\tStaff List Management" << endl;
	cout << "\t\t0.\tBack" << endl;
	cout << "\n\t\t================================================\n" << endl;
	cout << "\t\tEnter you choice: ";

}

void customer_det() {
	system("CLS");
	string custName, custPhone, custGender, custDescript,custAddress, unused, line;
	int count = 0, width;
	cout << "\t\t==================================================================================================" << endl;
	cout << "\t\t||                                    CUSTOMER DETAILS                                          ||" << endl;
	cout << "\t\t==================================================================================================" << endl;
	cout << "\t\t        NAME                    PHONE NUMBER      GENDER     DELIVERY ADDRESS" << endl;
	cout << "\t\t--------------------------------------------------------------------------------------------------" << endl;
	int j = 1;
	ifstream openCustFile;
	openCustFile.open("text/CustomerDetails.txt");

	while (getline(openCustFile, custName)) 
	{
		getline(openCustFile, custPhone);
		getline(openCustFile, custGender);
		getline(openCustFile, custAddress);
		if (j < 10) {
			width = 5;
		}
		else {
			width = 4;
		}
		cout << "\t\t  [" << j << setw(width) << left << "]  " << setw(25) << left << custName << setw(18) << left << custPhone
			<< setw(10) << left << custGender;

		//address
		int h = 0; //counter
		const int address_length = 36;
		if (custAddress.length() > address_length)
		{
			string address_temp;
			address_temp = custAddress.substr((double)address_length * h, address_length); //store part of description
			cout << address_temp << endl;
			h++;
			for (double i = (double)custAddress.length() / address_length; i > 1; i--)	//i > 1 because already output once
			{
				address_temp = custAddress.substr((double)address_length * h, address_length);
				cout << string(62, ' ') << address_temp << endl;
				h++;
			}
		}
		else
		{
			cout << custAddress << endl;
		}
		j++;
		
	}
	openCustFile.close();
	cout << "\t\t";
	system("PAUSE");
	admin();
}


void change_pass() {
	system("cls");

	cout << "\n\t------------------------------------------" << endl;
	cout << "\t\t    Change Password" << endl;
	cout << "\t------------------------------------------" << endl;

	string password;
	// Read from the text file
	ifstream readpass("admin.txt");

	getline(readpass, password);

	string currentpass;
	while (currentpass != password) {
		cout << "\n\n\t\tCurrent Password: ";
		cin >> currentpass;
		if (currentpass == password) {
			break;
		}
		else {
			cout << "\n\t\tCurrent password is incorrect!";
		}
	}
	// Close the file
	readpass.close();

	string newpass;
	system("cls");
	cout << "\n\n\t\t                      >>>>> New Password <<<<<                     " << endl;
	cout << "\n\t\t......................................................................." << endl;
	cout << "\t\t.                                                                     ." << endl;
	cout << "\t\t.    1. You are recommended to change a strong password.              ." << endl;
	cout << "\t\t.                                                                     ." << endl;
	cout << "\t\t.    2. New password cannot same with current or old password.        ." << endl;
	cout << "\t\t.                                                                     ." << endl;
	cout << "\t\t.    3. New password must contain at least:                           ." << endl;
	cout << "\t\t.    --> 1 uppercase, 1 lowercase, 1 special character and 1 number.  ." << endl;
	cout << "\t\t.    --> Password length must be more than 8 characters.              ." << endl;
	cout << "\t\t.                                                                     ." << endl;
	cout << "\t\t......................................................................." << endl;

	int l_case = 0, u_case = 0, digit = 0, special = 0, len = 0;

	/*cin >> newpass;*/
	int l = newpass.length(), i;
	while (((l_case * u_case * digit * special * len) != 1)) {
		cout << "\n\t\tNew password: ";
		cin >> newpass;
		int l = newpass.length(), i;
		for (i = 0; i < l; i++)
		{
			if (islower(newpass[i]))
				l_case = 1;
			if (isupper(newpass[i]))
				u_case = 1;
			if (isdigit(newpass[i]))
				digit = 1;
			if (!isalpha(newpass[i]) && !isdigit(newpass[i]))
				special = 1;
		}
		if (l >= 8) {
			len = 1;
		}
		if ((l_case * u_case * digit * special * len) != 1) {
			cout << "\n\t\t--> Weak password" << endl;
		}
		if (newpass == currentpass) {
			cout << "\t\t--> Same password" << endl;
		}
	}
	ofstream oldpsw;
	oldpsw.open("admin.txt");
	oldpsw << newpass;
	oldpsw.close();
	string anykey;
	cout << "\n\t\tYour password is changed successfully!" << endl;
	cout << "\n\t\tYou are required to login again." << endl;
	cout << "\t\t";
	system("PAUSE");

	admin_login();
}

void staff_login() {

	string staffName, staffPWD, loginPWD;
	bool valid_user = false;

	system("CLS");

	cout << "\n\t================================================" << endl;
	cout << "\t\t\t   STAFF LOGIN" << endl;
	cout << "\t================================================" << endl;

	cin.get();
	cout << "\n\t\tEnter Staff Name     : ";
	getline(cin, staffName);


	for (int i = 0; i < staffName.length(); i++) {
		if (islower(staffName.at(i))) {
			valid_user = false;
			break;
		}
		else
			valid_user = true;
	}

	if (valid_user == true) {

		ifstream staffData;

		staffData.open("Staff/" + staffName + ".txt");

		if (!staffData.fail()) {

			getline(staffData, loginPWD);
			cout << "\n\t\tEnter Login Password : ";
			getline(cin, staffPWD);

			if (staffPWD == loginPWD) {
				valid_user = true;
			}
			else {
				cout << "\n\t\tInvalid Login Password" << endl;
				valid_user = false;
			}
		}
		else {
			cout << "\n\t\tInvalid Staff." << endl;
			valid_user = false;
		}

		staffData.close();
	}
	else {
		cout << "\n\t\tInvalid Staff." << endl;
	}
	if (valid_user == true) {
		insertMapFunc();
		order_menu();
	}
	else {
		cout << "\n\t\t1. Try Again" << endl;
		cout << "\t\t2. Back" << endl;
		cout << "\t\tEnter Your Choice : ";
		cin >> choice;
		while (choice != "1" && choice != "2") {
			cout << "\n\t\tOnly [1] and [2] allowed to enter." << endl;
			cout << "\t\tEnter Your Choice Again : ";
			cin >> choice;
		}
		if (choice == "1") {
			staff_login();
		}
		else {
			main();
		}
	}
}


void insertMapFunc() {
	string it_name, it_price;
	int i = 1;
	//Open the file and clear all the data in the file, then close it
	//To make sure the file is always empty before insert all item to the file
	ofstream insertFile;
	insertFile.open("text/FoodCode.txt", ofstream::trunc);
	insertFile.close();
	food_map.clear();
	price_map.clear();
	insertMap("PersonalFriedChicken", "11", &i);
	insertMap("PersonalChickenBurger", "11", &i);
	insertMap("PersonalFishBurger", "11", &i);
	i = 1;
	insertMap("FamilyFriedChicken", "12", &i);
	insertMap("FamilyChickenBurger", "12", &i);
	insertMap("FamilyFishBurger", "12", &i);
	i = 1;
	insertMap("AlacarteChickenBurger", "21", &i);
	insertMap("AlacarteFishBurger", "21", &i);
	i = 1;
	insertMap("AlacarteFriedCchicken", "22", &i);
	i = 1;
	insertMap("AlacarteSide", "23", &i);
	i = 1;
	insertMap("Beverage", "3", &i);
	food_map.clear();
	//Open and read file and insert file into map
	ifstream openFile3;
	openFile3.open("text/FoodCode.txt");
	//Get data from fileand insert into map
	while (getline(openFile3, code)) {
		getline(openFile3, name);
		food_map.insert(pair<string, string>(code, name));
	}
	openFile3.close();
}

void insertMap(string filename, string code, int* i) {
	string it_name, it_price;
	food_map.clear();
	//Open and read file and insert file into map
	ifstream openFile;
	openFile.open("text/" + filename + ".txt");
	//Get data from file and insert into map
	while (getline(openFile, it_name)) {
		getline(openFile, it_price);
		food_map.insert(pair<string, string>(it_name, it_price));
	}
	openFile.close();
	//Open and write file by append method
	ofstream insertFile;
	insertFile.open("text/FoodCode.txt", ofstream::app);


	for (it_food = food_map.begin(); it_food != food_map.end(); it_food++) {
		int j = *i;
		name = it_food->first;
		price = it_food->second;
		insertFile << code + to_string(j) << "\n" << name << "\n";

		//insert to price map
		price_map.insert(pair<string, double>(code + to_string(j), stod(price)));
		*i = j + 1;
	}
	insertFile.close();
}

//display 3 type menu
void displayMenu3(string filename1, string filename2, string filename3, string titlename,
	string typename1, string typename2, string typename3) {
	string it_name;
	double it_price;
	cout << "\t\t.............." <<
		titlename << ".............." << endl;
	cout << "\t\t" << setw(34) << left << "\t    NAME" << setw(5) << left << "PRICE(RM)" << endl;
	int length = 28 + titlename.length();
	cout << "\t\t"<<string(length, '.') << endl;
	cout << "\t\t"<< typename1 << endl;
	int i = 1;
	ifstream displaymenu1;
	displaymenu1.open("text/" + filename1 + ".txt");
	while (getline(displaymenu1, it_name)) {
		displaymenu1 >> it_price;
		cout << "\t\t" << i << ". " << setw(34) << left << it_name << setw(5) << right << fixed << setprecision(2) << it_price << '\n';
		i++;
		getline(displaymenu1, it_name);
	}
	displaymenu1.close();
	cout << endl;
	cout << "\t\t" << typename2 << endl;
	ifstream displaymenu2;
	displaymenu2.open("text/" + filename2 + ".txt");
	while (getline(displaymenu2, it_name)) {
		displaymenu2 >> it_price;
		cout << "\t\t" << i << ". " << setw(34) << left << it_name << setw(5) << right << fixed << setprecision(2) << it_price << '\n';
		i++;
		getline(displaymenu2, it_name);
	}
	displaymenu2.close();
	cout << endl;
	cout << "\t\t" << typename3 << endl;
	ifstream displaymenu3;
	displaymenu3.open("text/" + filename3 + ".txt");
	while (getline(displaymenu3, it_name)) {
		displaymenu3 >> it_price;
		cout << "\t\t" << i << ". " << setw(34) << left << it_name << setw(5) << right << fixed << setprecision(2) << it_price << '\n';
		i++;
		getline(displaymenu3, it_name);
	}
	displaymenu3.close();
	cout << "\t\t0. Back to food menu" << endl;
	cout << "\t\t*******************************************" << endl;
	cout << "\t\tWhich would you like to order?" << endl;
	cout << "\t\t-------------------------------------------" << endl;
}


//display 2 type menu
void displayMenu2(string filename1, string filename2, string titlename,
	string typename1, string typename2) {
	string it_name;
	double it_price;
	cout << "\t\t..................." <<
		titlename << "..................." << endl;
	cout << "\t\t" << setw(34) << left << "    NAME" << setw(5) << left << "PRICE(RM)" << endl;
	int length = 38 + titlename.length();
	cout << "\t\t"<< string(length, '.') << endl;
	cout << "\t\t" << typename1 << endl;
	int i = 1;
	ifstream displaymenu1;
	displaymenu1.open("text/" + filename1 + ".txt");
	while (getline(displaymenu1, it_name)) {
		displaymenu1 >> it_price;
		cout << "\t\t" << i << ". " << setw(34) << left << it_name << setw(5) << right << fixed << setprecision(2) << it_price << '\n';
		i++;
		getline(displaymenu1, it_name);
	}
	displaymenu1.close();
	cout << endl;
	cout <<  "\t\t" << typename2 << endl;
	ifstream displaymenu2;
	displaymenu2.open("text/" + filename2 + ".txt");
	while (getline(displaymenu2, it_name)) {
		displaymenu2 >> it_price;
		cout <<  "\t\t" << i << ". " << setw(34) << left << it_name << setw(5) << right << fixed << setprecision(2) << it_price << '\n';
		i++;
		getline(displaymenu2, it_name);
	}
	displaymenu2.close();
	cout << "\t\t0. Back to food menu" << endl;
	cout << "\t\t*******************************************" << endl;
	cout << "\t\tWhich would you like to order?" << endl;
	cout << "\t\t-------------------------------------------" << endl;
}

//display 1 type menu
void displayMenu1(string filename1, string titlename) {
	string it_name;
	double it_price;
	cout <<  "\t\t" << "..............." <<
		titlename << "..............." << endl;
	cout <<  "\t\t" << setw(34) << left << "    NAME" << setw(5) << left << "PRICE(RM)" << endl;
	int length = 30 + titlename.length();
	cout <<  "\t\t" << string(length, '.') << endl;
	int i = 1;
	ifstream displaymenu1;
	displaymenu1.open("text/" + filename1 + ".txt");
	while (getline(displaymenu1, it_name)) {
		displaymenu1 >> it_price;
		cout <<  "\t\t" << i << ". " << setw(34) << left << it_name << setw(5) << right << fixed << setprecision(2) << it_price << '\n';
		i++;
		getline(displaymenu1, it_name);
	}
	displaymenu1.close();
	cout << "\t\t0. Back to food menu" << endl;
	cout << "\t\t*******************************************" << endl;
	cout << "\t\tWhich would you like to order?" << endl;
	cout << "\t\t-------------------------------------------" << endl;
}

//=========================================================  ORDER MENU START =====================


//Record the ordered food and amount of order
int	num_order() {
	system("CLS");
	bool check_order = false;
	int order_amount;
	map <string, int>::iterator it_order;

	//check if the string in order is valid
	if (food_map.find(order) == food_map.end())
	{
		//set check_order as false and return check_order if invalid
		check_order = true;
		return check_order;
	}
	cout << "\t\t " << string(40, '.') << "Order Amount" << string(40, '.') << endl;
	cout << "\t\t  0. Back" << endl << endl;
	//prompt for amount of order
	cout << "\t\t How many would you like to order?" << endl;
	cout << "\t\t " << string(43, '-') << endl << " ";
	//get amount of order
	cin >> order_amount;
	if (order_amount > 0)
	{
		//check for duplicates
		it_order = order_map.find(order);
		if (it_order != order_map.end())
		{
			//delete the duplicate
			order_map.erase(it_order);
		}
		//insert order as key and amount of order as value into order_map after deleting
		order_map.insert(pair<string, int>(order, order_amount));
	}
	else if (order_amount == 0) {} // do nothing if input is 0
	else {
		cout << "\t\t " << string(43, '/') << "\n Please enter a positive integer or 0 to go back to main menu\n" << string(43, '\\') << endl;
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		num_order(); //repeat num_order function to let user redo
	}
	cout << endl;
	return check_order;
}

//----------------------------First option of ordering food
void order_menu() {
	string read;
	char order_temp = '1'; //to start the loop
	order_complete = false;
	while (order_temp != '0')	//loop that continues as long as input is not 0
	{
		system("CLS");
		//read from order_menu.txt and stop at end of file
		ifstream get_output("text/order_menu.txt");
		while (getline(get_output, read)) {
			cout <<"\t\t" <<  read << endl;
		}
		get_output.close();
		cout << "\t\t ";
		//get input
		cin >> order_temp;
		cout << endl;
		//accumulate order_temp to form food code
		order = order_temp;
		switch (order_temp)
		{
		case '0': //do nothing if input is zero
			break;
		case '1':
			package();
			break;
		case '2':
			a_la_carte();
			break;
		case '3':
			beverage();
			break;
		case '4':
			check_cart();
			break;
		case '5':
			if (order_map.empty())
			{
				cout << "\t\t " << string(43, '/') << "\n Please order before checkout\n " << string(43, '\\') << endl;
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();	//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
			}
			else
			{
				checkout();
			}
			break;
		default:
			cout << "\t\t " << string(43, '/') << "\n Please Enter an integer from 0 to 5\n " << string(43, '\\') << endl;
			cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
			cin.ignore();							//ignore newline left by last cin
			cin.ignore(100, '\n');					 //continue the program enter key is entered
			break;
		}
		order = "";
	}
}

//----------------------------Second option of ordering food
//order_menu/package
void package() {
	system("CLS");
	string read;
	char order_temp;
	//read from package.txt until file is finished
	ifstream get_output("text/package.txt");
	while (getline(get_output, read)) {
		cout << "\t\t" <<  read << endl;
	}
	get_output.close();
	cout << "\t\t ";
	//get input
	cin >> order_temp;
	cout << endl;
	//accumulate order_temp to form food code
	order += order_temp;
	switch (order_temp) {
	case '0': //do nothing if input is zero
		break;
	case '1':
		personal();
		break;
	case '2':
		family();
		break;
	default:
		cout << "\t\t " << string(43, '/') << "\n Please Enter an integer from 0 to 2\n " << string(43, '\\') << endl << endl;
		order.erase(order.end() - 1); //delete last character in order
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		package(); //repeat package function to let user redo
		break;
	}
}

//order_menu/a_la_carte
void a_la_carte() {
	system("CLS");
	string read;
	char order_temp;
	//read from a_la_carte.txt until file is finished
	ifstream get_output("text/a_la_carte.txt");
	while (getline(get_output, read)) {
		cout << "\t\t" <<  read << endl;
	}
	get_output.close();
	cout << "\t\t ";
	//get input
	cin >> order_temp;
	cout << endl;
	//accumulate order_temp to form food code
	order += order_temp;
	switch (order_temp) {
	case '0': //do nothing if input is zero
		break;
	case '1':
		burger();
		break;
	case '2':
		fried_chicken();
		break;
	case '3':
		side();
		break;
	default:
		cout << "\t\t " << string(43, '/') << "\n Please Enter an integer from 0 to 3\n " << string(43, '\\') << endl << endl;
		order.erase(order.end() - 1); //delete last character in order
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		a_la_carte(); //repeat a_la_carte function to let user redo
		break;
	}
}

//order_menu/beverage
void beverage() {
	system("CLS");
	bool check_bool;
	string read;
	char order_temp;
	displayMenu1("Beverage", "...Beverage...");
	cout << "\t\t ";
	cin >> order_temp;
	cout << endl;
	//accumulate order_temp to form food code
	order += order_temp;
	if (isdigit(order_temp))
	{
		if (order_temp == '0') {} //do nothing if input is zero
		else {
			//check if order is valid
			check_bool = num_order();
			if (check_bool)
			{
				cout << "\t\t " << string(43, '/') << "\n Please Enter an integer from 0 to 17\n " << string(43, '\\') << endl << endl;
				order.erase(order.end() - 1); //delete last character in order
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();							//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
				beverage(); // repeat beverage function to let user redo
			}
		}
	}
	else
	{
		cout << "\t\t " << string(43, '/') << "\n Please Enter an integer from 0 to 7\n " << string(43, '\\') << endl << endl;
		order.erase(order.end() - 1); //delete last character in order
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		beverage(); //repeat personal function to let user redo
	}
}

//order_menu/check_cart
void check_cart() {
	system("CLS");
	
	food_map.clear();
	//Open and read file and insert file into map
	ifstream openFile2;
	openFile2.open("text/FoodCode.txt");
	//Get data from fileand insert into map
	while (getline(openFile2, name)) {
		getline(openFile2, price);
		food_map.insert(pair<string, string>(name, price));
	}
	openFile2.close();

	map <string, int>::iterator it_order;
	map <string, double>::iterator it_price;
	string validation;
	char order_temp;
	double food_price, total_price = 0;
	//show list of ordered food
	cout << "\t\t " << left << setw(12) << "Food Code" << setw(35) << "Food Name" << setw(14) << "Amount Ordered" << right << setw(14) << "Price" << endl;
	for (it_order = order_map.begin(); it_order != order_map.end(); it_order++)
	{
		it_food = food_map.find(it_order->first);
		it_price = price_map.find(it_order->first);
		food_price = it_price->second * it_order->second;
		total_price += food_price;
		cout << "\t\t " << left << setw(12) << it_food->first << setw(35) << food_map[it_order->first] << right << setw(14) << it_order->second << setw(4) << "RM" << setw(10) << food_price << endl;
	}
	//show choices and get input
	cout << "\t\t " << string(75, '-') << endl;
	cout << "\t\t " << setw(64) << "Total: RM" << fixed << setprecision(2) << setw(10) << total_price << endl;
	cout << "\t\t " << string(75, '-') << endl << endl;
	cout << "\t\t  0. Back to food menu" << endl;
	cout << "\t\t  1. Change amount of order" << endl;
	cout << "\t\t  2. Delete order" << endl;
	cout << "\t\t What would you like to do?" << endl;
	cout << "\t\t " << string(75, '-') << endl << " ";
	cin >> order_temp;
	switch (order_temp)
	{
	case '0': //do nothing if input is zero
		break;
	case '1':
		while (order_temp != '0') //stop the loop if input is zero
		{
			system("CLS");
			//show list of ordered food
			cout << "\t\t " << left << setw(12) << "Food Code" << setw(35) << "Food Name" << setw(14) << "Amount Ordered" << right << setw(14) << "Price" << endl;
			for (it_order = order_map.begin(); it_order != order_map.end(); it_order++)
			{
				it_food = food_map.find(it_order->first);
				it_price = price_map.find(it_order->first);
				food_price = it_price->second * it_order->second;
				total_price += food_price;
				cout << " " << left << setw(12) << it_food->first << setw(35) << food_map[it_order->first] << right << setw(14) << it_order->second << setw(4) << "RM" << setw(10) << food_price << endl;
			}
			//prompt and get food code to delete
			cout << "\t\t " << string(75, '-') << endl;
			cout << "\t\t " << setw(64) << "Total: RM" << fixed << setprecision(2) << setw(10) << total_price << endl;
			cout << "\t\t " << string(75, '-') << "\n\n\t\t Type the food code of the food you want to change\n\t\t " << string(75, '-') << endl << "\t\t ";
			cin >> order;
			//check if food code entered is in the list
			//show error message if food code is not found
			if (order == "0")
			{
				break;
			}
			else if (order_map.find(order) == order_map.end())
			{
				cout << "\t\t " << string(75, '/') << "\n Please enter a number from the list\n " << string(75, '\\') << endl;
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();							//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
				continue;
			}
			num_order();
			system("CLS");
			//show list of ordered food after editing amount
			cout << "\t\t Updated list of cart\n" << endl;
			cout << "\t\t " << left << setw(12) << "Food Code" << setw(35) << "Food Name" << setw(14) << "Amount Ordered" << right << setw(14) << "Price" << endl;
			for (it_order = order_map.begin(); it_order != order_map.end(); it_order++)
			{
				it_food = food_map.find(it_order->first);
				it_price = price_map.find(it_order->first);
				food_price = it_price->second * it_order->second;
				total_price += food_price;
				cout << " " << left << setw(12) << it_food->first << setw(35) << food_map[it_order->first] << right << setw(14) << it_order->second << setw(4) << "RM" << setw(10) << food_price << endl;
			}
			//show choices and get input
			cout << "\t\t " << string(75, '-') << endl;
			cout << "\t\t " << setw(64) << "Total: RM" << fixed << setprecision(2) << setw(10) << total_price << endl;
			cout << "\t\t " << string(75, '-') << endl;
			cout << "\n\t\t  0. Back to food menu\n\t\t  1. Continue\n";
			cout << "\t\t What is your choice?\n\t\t" << " " << string(75, '-') << endl << "\t\t ";
			cin >> order_temp;
			while (order_temp != '0' && order_temp != '1')
			{
				cout << "\n\t\t " << string(75, '/') << "\n\t\t Please enter a number from the list\n " << string(75, '\\') << endl;
				cout << "\n\t\t  0. Back to food menu\n\t\t  1. Continue\n\n";
				cout << "\t\t What is your choice?\n\t\t" << " " << string(75, '-') << endl << "\t\t ";
				cin >> order_temp;
			}
		}
		break;
	case '2':
		while (order_temp != '0') //stop the loop if input is zero
		{
			system("CLS");
			//show the list of ordered food
			cout << "\t\t " << left << setw(12) << "Food Code" << setw(35) << "Food Name" << setw(14) << "Amount Ordered" << right << setw(14) << "Price" << endl;
			for (it_order = order_map.begin(); it_order != order_map.end(); it_order++)
			{
				it_food = food_map.find(it_order->first);
				it_price = price_map.find(it_order->first);
				food_price = it_price->second * it_order->second;
				total_price += food_price;
				cout << " " << left << setw(12) << it_food->first << setw(35) << food_map[it_order->first] << right << setw(14) << it_order->second << setw(4) << "RM" << setw(10) << food_price << endl;
			}
			cout << "\t\t " << string(75, '-') << endl;
			cout << "\t\t " << setw(64) << "Total: RM" << fixed << setprecision(2) << setw(10) << total_price << endl;
			//prompt and get food code to delete
			cout << "\t\t " << string(75, '-') << "\n\n Type the food code of the food you want to remove\n " << string(75, '-') << endl << " ";
			cin >> order;
			//check for the code in the list
			//return error message if not found
			it_order = order_map.find(order);
			if (order == "0")
			{
				break;
			}
			else if (it_order != order_map.end())
			{
				order_map.erase(it_order);
			}
			else
			{
				cout << "\t\t " << string(75, '/') << "\n Please enter a number from the list\n " << string(75, '\\') << endl;
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();							//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
				continue;
			}
			system("CLS");
			cout << "\t\t Updated list of cart\n" << endl;
			//show the list of ordered food after deleting
			cout << "\t\t " << left << setw(12) << "Food Code" << setw(35) << "Food Name" << setw(14) << "Amount Ordered" << right << setw(14) << "Price" << endl;
			for (it_order = order_map.begin(); it_order != order_map.end(); it_order++)
			{
				it_food = food_map.find(it_order->first);
				it_price = price_map.find(it_order->first);
				food_price = it_price->second * it_order->second;
				total_price += food_price;
				cout << "\t\t " << left << setw(12) << it_food->first << setw(35) << food_map[it_order->first] << right << setw(14) << it_order->second << setw(4) << "RM" << setw(10) << food_price << endl;
			}
			//show choices and get input
			cout << "\t\t " << string(75, '-') << endl;
			cout << "\t\t " << setw(64) << "Total: RM" << fixed << setprecision(2) << setw(10) << total_price << endl;
			cout << "\t\t " << string(75, '-') << endl;

			cout << "\n\t\t  0. Back to food menu\n  1. Continue\n\n";
			cout << "\t\t What is your choice?\n" << " " << string(75, '-') << endl << " ";
			cin >> order_temp;
			while (order_temp != '0' && order_temp != '1')
			{
				cout << "\n\t\t " << string(75, '/') << "\n\t\t Please enter a number from the list\n " << string(75, '\\') << endl;
				cout << "\n\t\t  0. Back to food menu\n\t\t  1. Continue\n\n";
				cout << "\t\t What is your choice?\n" << " " << string(75, '-') << endl << " ";
				cin >> order_temp;
			}
		}
		break;
	default:
		break;
	}
}

//order_menu/bill
void bill() {
	//get time
	time_t current_time = time(NULL);
	char time_str[26] = {};
	ctime_s(time_str, 26, &current_time);
	double food_price, total_price = 0;
	map <string, double>::iterator it_price;
	map <string, int>::iterator it_order;

	system("CLS");

	//--------------------------display bill
	logo();
	//show date and time
	cout << setw(63) << time_str << endl;

	//show list of ordered food
	cout << "\t\t" << string(22, ' ') << left << setw(35) << "Food Name" << right << setw(10) << "Amount" << setw(14) << "Price" << endl;
	for (it_order = order_map.begin(); it_order != order_map.end(); it_order++)
	{
		it_food = food_map.find(it_order->first);
		//calculate food price
		it_price = price_map.find(it_order->first);
		food_price = it_price->second * it_order->second;
		total_price += food_price;

		//show food name, amount and price line by line
		cout << string(22, ' ') << left << setw(35) << food_map[it_order->first] << right << setw(10) << it_order->second << setw(4) << "RM" << setw(10) << food_price << endl;
	}
	cout<< "\t\t" << string(21, ' ') << string(61, '-') << endl;
	cout<< "\t\t" << string(21, ' ') << setw(50) << "Total: RM" << fixed << setprecision(2) << setw(10) << total_price << endl;
	cout<< "\t\t" << string(21, ' ') << string(61, '-') << endl;

	//-------------------------- store in file
	ofstream sales_rec;
	sales_rec.open("duit.txt", ios_base::app);	//::app means append = add to end of file instead of clearing the file

	sales_rec << "#" << time_str;				//store time in file
	for (it_order = order_map.begin(); it_order != order_map.end(); it_order++)
	{
		it_food = food_map.find(it_order->first);
		//calculate food price
		it_price = price_map.find(it_order->first);
		food_price = it_price->second * it_order->second;
		//store record in duit.txt file
		sales_rec << "." << it_order->first << "\n*" << it_food->second << "\n:" << it_order->second << "\n$" << fixed << setprecision(2) << food_price << endl;
	}
	if (!(description.empty()))
	{
		int j = 0;	//counter
		const int desc_length = 46;
		if (description.length() > desc_length)
		{
			string description_temp;
			description_temp = description.substr((double)desc_length * j, desc_length); //store part of description
			cout << "\t\t" <<string(22, ' ') << "Description: " << description_temp << endl;
			j++;
			for (double i = (double)description.length() / desc_length; i > 1; i--)	//i > 1 because already output once
			{
				description_temp = description.substr((double)desc_length * j, desc_length);
				cout << string(35, ' ') << description_temp << endl;
				j++;
			}
		}
		else
		{
			cout<< "\t\t" << string(22, ' ') << "Description: " << description << endl;
		}
	}
	sales_rec << "Description: " << description << endl;
	
	int j = 0; //counter
	string full_address = address + ", " + user_postcode + ", " + userstate;
	const int address_length = 50;
	if (full_address.length() > address_length)
		{
			string address_temp;
			address_temp = full_address.substr((double)address_length * j, address_length); //store part of description
			cout<< "\t\t" << string(22, ' ') << "Address: " << address_temp << endl;
			j++;
			for (double i = (double)full_address.length() / address_length; i > 1; i--)	//i > 1 because already output once
			{
				address_temp = full_address.substr((double)address_length * j, address_length);
				cout << string(31, ' ') << address_temp << endl;
				j++;
			}
		}
	else
		{
			cout<< "\t\t" << string(22, ' ') << "address: " << full_address << endl;
		}

	sales_rec << endl;
	sales_rec.close();
	cout << endl << "\t\t" << string(22, ' ') << "Order successful!" << endl;
	cout << "\t\t" << string(22, ' ') << "Press enter to continue" << endl;
	cout << "\t\t" << string(22, ' ');
	cin.ignore();	//ignore newline left by last cin
	cin.ignore(100, '\n');	//ignore until enter
	cout << "\t\t"<< string(22, ' ');
	//clear orders
	order_map.clear();
	description.clear();
	order_complete = true;
}

void delivery() {
	while (address != "0") {
		if(order_complete == true){
			break;
		}
		// cin.get();
		system("CLS");
		//confirmation address from user
		cout << "\t\t===========================================" << endl;
		cout << setw(26) << "\t\t\t---Delivery---" << endl;
		cout << "\t\t===========================================" << endl;
		cout << "\n\t\tEnter your address:";
		cin.ignore();
		getline(cin, address);
		cout << "\t\tYour address:" << address << endl;
		state();
	}
}

void state() {
	system("CLS");
	cout << "\t\t===========================================" << endl;
	cout << setw(22) << "\t\t---State---" << endl;
	cout << "\t\t===========================================" << endl;
	cout << "\t\t1.Johor" << setw(24) << "7.Penang" << endl;
	cout << "\t\t2.Kedah" << setw(23) << " 8.Perak" << endl;
	cout << "\t\t3.Kelantan" << setw(21) << " 9.Perlis" << endl;
	cout << "\t\t4.Malacca" << setw(24) << "10.Selangor" << endl;
	cout << "\t\t5.Negeri Sembilan" << setw(18) << "11.Terengganu" << endl;
	cout << "\t\t6.Pahang" << setw(29) << "12.Kuala Lumpur" << endl;
	cout << "\t\t0.Back to previous" << endl << endl;
	cout << "\t\tYour address:" << address << endl;
	cout << "\t\tBased on the numbers above, choose delivery state." << endl;
	cout << "\n\t\tCustomer state : ";
	cin >> user_state;

	while (!(user_state >= 0 && user_state <= 12)) {
		cout << "\n\t\tInvalid state!" << endl;
		cout << "\n\t\tCustomer State: ";
		cin >> user_state;
	}
	if (user_state == 1) {
		userstate = "Johor";
	}
	else if (user_state == 2) {
		userstate = "Kedah";
	}
	else if (user_state == 3) {
		userstate = "Kelantan";
	}
	else if (user_state == 4) {
		userstate = "Malacca";
	}
	else if (user_state == 5) {
		userstate = "Negeri Sembilan";
	}
	else if (user_state == 6) {
		userstate = "Pahang";
	}
	else if (user_state == 7) {
		userstate = "Penang";
	}
	else if (user_state == 8) {
		userstate = "Perak";
	}
	else if (user_state == 9) {
		userstate = "Perlis";
	}
	else if (user_state == 10) {
		userstate = "Selangor";
	}
	else if (user_state == 11) {
		userstate = "Terengganu";
	}
	else if (user_state == 12) {
		userstate = "Kuala Lumpur";
	}
	else {
		delivery();
	}

	cout << "\t\tYour state: " << userstate << endl;
	cout << "\t\tState confirmed." << endl;
	postcode();
}

//get user postcode
void postcode() {
	int i;
	system("CLS");
	cout << "\t\t===========================================" << endl;
	cout << setw(22) << "\t\t---Postcode---" << endl;
	cout << "\t\t===========================================" << endl;
	cout << "\t\tYour address: " << address << endl;
	cout << "\t\tYour state: " << userstate << endl;
	cout << "\t\tEnter your postcode: ";
	cin >> user_postcode;

checkPostcode:
	while (user_postcode.length() != 5) {
		cout << "\n\t\tInvalid postcode!\nPostcode length must be 5 characters.\n";
		cout << "\t\tEnter your postcode:";
		cin >> user_postcode;
	}

	for (i = 0; i < user_postcode.length(); i++)
	{
		if (!isdigit(user_postcode[i]))
		{
			cout << "\t\tInvalid postcode!\nPostcode cannot contain other symbols.\n";
			cout << "\t\tEnter your postcode:";
			cin >> user_postcode;
			goto checkPostcode;
		}
	}

	cout << "\t\tYour postcode: " << user_postcode << endl;
	confirm_address();
}

//confirm address
void confirm_address() {
	system("CLS");
	cout << "\t\t===========================================" << endl;
	cout << setw(25) << "\t\t*---Confirm Address---*" << endl;
	cout << "\t\t===========================================" << endl;
	cout << "\t\tYour address: " << address << endl;
	cout << "\t\tYour state: " << userstate << endl;
	cout << "\t\tYour postcode: " << user_postcode << endl;
	cout << "\t\tPress 'Y' to confirm OR 'N' to change : ";
	cin >> confirmation;

	//invalid 
	while (confirmation != "Y" && confirmation != "y" && confirmation != "N" && confirmation != "n") {
		cout << "\n\t\tInvalid choice!\n";
		cout << "\t\tDo you want to use your current address?" << endl;
		cout << "\t\tPress 'Y' to confirm OR 'N' to change : " ;
		cin >> confirmation;

	}
	//confirm current address
	if (confirmation == "Y" || confirmation == "y") {
		cout << "\t\tDelivery address confirmed." << endl;
		ofstream storeAddress;
		storeAddress.open("text/CustomerDetails.txt", ofstream::app);
		storeAddress << address << ", " << user_postcode << ", " << userstate << "\n";
		storeAddress.close();
		cout << "\t\t";
		system("PAUSE");
		bill();
	}
	else {
		postcode();
	}
}

//order_menu/checkout
void checkout() {
	double food_price, total_price = 0;
	int checkout_choice;
	map <string, double>::iterator it_price;
	map <string, int>::iterator it_order;
	system("CLS");

	food_map.clear();
	//Open and read file and insert file into map
	ifstream openFile2;
	openFile2.open("text/FoodCode.txt");
	//Get data from fileand insert into map
	while (getline(openFile2, name)) {
		getline(openFile2, price);
		food_map.insert(pair<string, string>(name, price));
	}
	openFile2.close();

	//show list of ordered food
	cout << "\t\t " << left << setw(35) << "Food Name" << right << setw(10) << "Amount" << setw(14) << "Price" << endl;
	for (it_order = order_map.begin(); it_order != order_map.end(); it_order++)
	{
		it_food = food_map.find(it_order->first);
		//calculate food price
		it_price = price_map.find(it_order->first);
		food_price = it_price->second * it_order->second;
		total_price += food_price;
		//show food name, amount and price line by line
		cout << "\t\t " << left << setw(35) << food_map[it_order->first] << right << setw(10) << it_order->second << setw(4) << "RM" << setw(10) << food_price << endl;
	}
	cout << "\t\t " << string(59, '-') << endl;
	cout << setw(50) << "\t\tTotal: RM" << fixed << setprecision(2) << setw(10) << total_price << endl;
	cout << "\t\t " << string(59, '-') << endl;
	//show description
	if (!(description.empty()))
	{
		int j = 0;	//counter
		const int desc_length = 46;
		if (description.length() > desc_length)
		{
			string description_temp;
			description_temp = description.substr((double)desc_length * j, desc_length); //store part of description
			cout << "\t\t Description: " << description_temp << endl;
			j++;
			for (double i = (double)description.length() / desc_length; i > 1; i--)	//i > 1 because already output once
			{
				description_temp = description.substr((double)desc_length * j, desc_length);
				cout << "\t\t" << string(14, ' ') << description_temp << endl;
				j++;
			}
		}
		else
		{
			cout << "\t\tDescription: " << description << endl;
		}
	}
	//display choices
	cout << "\n\t\t  0. Back to food menu" << endl;
	cout << "\t\t  1. Add/change description" << endl;
	cout << "\t\t  2. Confirm checkout" << endl << endl;
	cout << "\t\t Enter your choice" << endl;
	cout << "\t\t " << string(59, '-') << endl << " >> ";
	//get choice
	cin >> checkout_choice;
	switch (checkout_choice)
	{
	case 0:
		break;
	case 1:
		cout << endl << "\t\t  0. Back" << endl;
		cout << "\t\t " << string(59, '-') << endl;
		cout << "\t\t Description: ";
		cin.ignore();
		getline(cin, description);
		if (description == "0")
		{
			description.clear();
		}
		checkout();
		break;
	case 2:
		system("CLS");
		det_fill();
		break;
	default:
		cout << "\t\tPlease enter a choice from 0 to 2" << endl;
		cout << "\t\tPress enter to continue" << endl;
		cin.ignore();	//ignore newline left by last cin
		cin.ignore(100, '\n');  //ignore until enter
		checkout();
		break;
	}
}

//----------------------------Third option of ordering food
//order_menu/package/personal
void personal() {
	system("CLS");
	bool check_bool;
	string read;
	char order_temp;
	displayMenu3("PersonalFriedChicken", "PersonalChickenBurger", "PersonalFishBurger", "Personal Package",
		"*Fried Chicken", "*Chicken Burger", "*Fish Burger");
	cout << "\t\t ";
	cin >> order_temp;
	cout << endl;
	//accumulate order_temp to form food code
	order += order_temp;
	if (isdigit(order_temp))
	{
		if (order_temp == '0') {} //do nothing if input is zero
		else {
			//check if order is valid
			check_bool = num_order();
			if (check_bool)
			{
				cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
				order.erase(order.end() - 1); //delete last character in order
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();							//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
				personal(); // repeat personal function to let user redo
			}
		}
	}
	else
	{
		cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
		order.erase(order.end() - 1); //delete last character in order
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		personal(); //repeat personal function to let user redo
	}
}

//order_menu/package/family
void family() {
	system("CLS");
	bool check_bool;
	string read;
	char order_temp;
	displayMenu3("FamilyFriedChicken", "FamilyChickenBurger", "FamilyFishBurger", ".Family Package.",
		"*Fried Chicken", "*Chicken Burger", "*Fish Burger");
	cout << "\t\t ";
	//get input
	cin >> order_temp;
	cout << endl;
	//accumulate order_temp to form food code
	order += order_temp;
	if (isdigit(order_temp))
	{
		if (order_temp == '0') {} //do nothing if input is zero
		else {
			//check if order is valid
			check_bool = num_order();
			if (check_bool)
			{
				cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
				order.erase(order.end() - 1); //delete last character in order
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();							//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
				family(); //repeat family function to let user redo
			}
		}
	}
	else
	{
		cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
		order.erase(order.end() - 1); //delete last character in order
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		family(); //repeat family function to let user redo
	}
}

//order_menu/a_la_carte/Burger
void burger() {
	system("CLS");
	bool check_bool;
	string read;
	char order_temp;
	displayMenu2("AlacarteChickenBurger", "AlacarteFishBurger", "Burger", "*Chicken", "*Fish");
	cout << "\t\t ";
	//get input
	cin >> order_temp;
	cout << endl;
	//accumulate order_temp to form food code
	order += order_temp;
	if (isdigit(order_temp))
	{
		if (order_temp == '0') {} //do nothing if input is zero
		else {
			//check if order is valid
			check_bool = num_order();
			if (check_bool)
			{
				cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
				order.erase(order.end() - 1); //delete last character in order
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();							//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
				burger(); //repeat burger function to let user redo
			}
		}
	}
	else
	{
		cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
		order.erase(order.end() - 1); //delete last character in order
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		burger(); //repeat burger function to let user redo
	}
}

//order_menu/a_la_carte/fried_chicken
void fried_chicken() {
	system("CLS");
	bool check_bool;
	string read;
	char order_temp;
	displayMenu1("AlacarteFriedCchicken", "Fried Chicken");
	cout << " ";
	//get input
	cin >> order_temp;
	cout << endl;
	//accumulate order_temp to form food code
	order += order_temp;
	if (isdigit(order_temp))
	{
		if (order_temp == '0') {} //do nothing if input is zero
		else {
			//check if order is valid
			check_bool = num_order();
			if (check_bool)
			{
				cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
				order.erase(order.end() - 1); //delete last character in order
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();							//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
				fried_chicken(); //repeat fried_chicken function to let user redo
			}
		}
	}
	else
	{
		cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
		order.erase(order.end() - 1); //delete last character in order
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		fried_chicken(); //repeat fried_chicken function to let user redo
	}
}

//order_menu/a_la_carte/side
void side() {
	system("CLS");
	bool check_bool;
	string read;
	char order_temp;
	displayMenu1("AlacarteSide", ".....Side.....");
	cout << "\t\t ";
	cin >> order_temp;
	cout << endl;
	//accumulate order_temp to form food code
	order += order_temp;
	if (isdigit(order_temp))
	{
		if (order_temp == '0') {} //do nothing if input is zero
		else {
			//check if order is valid
			check_bool = num_order();
			if (check_bool)
			{
				cout << "\t\t " << string(43, '/') << "\n Please Enter an option from above\n " << string(43, '\\') << endl << endl;
				order.erase(order.end() - 1); //delete last character in order
				cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
				cin.ignore();							//ignore newline left by last cin
				cin.ignore(100, '\n');					 //continue the program enter key is entered
				side(); // repeat side function to let user redo
			}
		}
	}
	else
	{
		cout << "\t\t " << string(43, '/') << "\n Please Enter option from above\n " << string(43, '\\') << endl << endl;
		order.erase(order.end() - 1); //delete last character in order
		cout << "\n\t\t Press enter to continue: ";//stop the program to let user read error message
		cin.ignore();							//ignore newline left by last cin
		cin.ignore(100, '\n');					 //continue the program enter key is entered
		side(); //repeat personal function to let user redo
	}
}

//=========================================================  ORDER MENU END =====================

void det_fill() {
	string custName, custPhone, custDescript, temp_gender;
	char custGender;
	cin.get();
	cout << "\t\t============================Customer Details=============================" << endl << endl;
	cout << "\t\tEnter name: ";
	getline(cin, custName);
	custName = valid_Name(custName);
	cout << "\t\tEnter phone number (012-34567890): ";
	getline(cin, custPhone);
	custPhone = validatePhone(custPhone);
	cout << "\t\tEnter gender ('M' for male / 'F' for female) : ";
	getline(cin, temp_gender);
	custGender = validateGender(temp_gender);
	cout << "\t\t=========================================================================" << endl;
	cout << "\t\tCustomer name: " << custName << endl;
	cout << "\t\tCustomer phone number: " << custPhone <<  endl;
	cout << "\t\tCustomer gender: " << custGender << endl;
	cout << "\t\tAre you confirm the customer details? " << endl;
	cout << "\t\tEnter 'Y' for confirm or 'N' for cancel : ";
	cin >> choice;
	while (choice != "Y" && choice != "y"
		&& choice != "N" && choice != "n") {
		cout << "\t\tInvalid option." << endl;
		cout << "\t\tEnter again: ";
	}
	if (choice == "Y" || choice == "y"){
		//Add customer's details into a file
		ofstream CustDetails;
		CustDetails.open("text/CustomerDetails.txt", ofstream::app);
		CustDetails << custName << "\n" << custPhone << "\n" << custGender << "\n";
		CustDetails.close();

		cout << "\t\tEnter completely!!!" << endl;
		cout << "\t\t";
		system("PAUSE");
		delivery();
	}
	else{
		system("CLS");
		det_fill();
	}
}

string validatePhone(string custPhone) {

	while (true) {
		if (custPhone.length() < 10 || custPhone.length() > 12) {
			cout << "\t\tThe length of phone number must in the range of 10 - 12!" << endl;
			cout << "\t\tEnter phone number: ";
			getline(cin, custPhone);
		}
		else if (custPhone.at(3) != '-') {
			cout << "\t\tIncorrect format! Please follow the format (012-34567890)" << endl;
			cout << "\t\tEnter phone number: ";
			getline(cin, custPhone);
		}
		else {
			int count = 0;
			for (int i = 0; i < custPhone.length(); i++) {
				if (i == 3) {
					count++;
					continue;
				}
				else if (isdigit(custPhone.at(i))) {
					count++;
					continue;
				}
				else {
					cout << "\t\tAlphabet or others symbol is not allowed!" << endl;
					break;
				}
			}
			if (count != custPhone.length()) {
				cout << "\t\tEnter phone number: ";
				getline(cin, custPhone);
			}
			else {
				return custPhone;
			}
		}
		
	}
	
}

char validateGender(string temp_gender) {
	char custGender;
	while (true) {
		if (temp_gender.length() > 1) {
			cout << "\t\tYou only can enter 1 character! ('M' or 'F') " << endl;
			cout << "\t\tEnter gender ('M' for male / 'F' for female) : ";
			getline(cin, temp_gender);
		}
		else {
			custGender = toupper(temp_gender[0]);
			if (isdigit(custGender)) {
				cout << "\t\tDigit is not allowed!" << endl;
			}
			else if (custGender != 'F' && custGender != 'M') {
				cout << "\t\tInvalid option!" << endl;
			}
			else {
				break;
			}
			cout << "\t\tEnter gender ('M' for male / 'F' for female) : ";
			getline(cin, temp_gender);
		}
	}
	return custGender;
}


void logo() {
	system("CLS");
	cout << "  .----------------.  .----------------.  .----------------.  .----------------.  .----------------." << endl;
	cout << "  | .--------------. || .--------------. || .--------------. || .--------------. || .--------------.|" << endl;
	cout << "  | |  _________   | || |      __      | || |  _________   | || |     ______   | || |     ____     ||" << endl;
	cout << "  | | |_   ___  |  | || |     /  \\     | || | |  _   _  |  | || |   .' ___  |  | || |   .'    `.   ||" << endl;
	cout << "  | |   | |_  \\_|  | || |    / /\\ \\    | || | |_/ | | \\_|  | || |  / .'   \\_|  | || |  /  .--.  \\  ||" << endl;
	cout << "  | |   |  _ | _   | || |   / /__\\ \\   | || |     | |      | || |  | |         | || |  | |    | |  ||" << endl;
	cout << "  | |  _| |___/ |  | || | _/ /    \\ \\_ | || |    _| |_     | || |  \\ `.___.'\\  | || |  \\  `--'  /  ||" << endl;
	cout << "  | | |_________|  | || ||____|  |____|| || |   |_____|    | || |   `._____.'  | || |   `.____.'   ||" << endl;
	cout << "  | |              | || |              | || |              | || |              | || |              ||" << endl;
	cout << "  | '--------------' || '--------------' || '--------------' || '--------------' || '--------------'|" << endl;
	cout << "  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'" << endl;
	cout << "\n\n                     ----------------------WELCOME TO EATco-----------------------" << endl;
}

