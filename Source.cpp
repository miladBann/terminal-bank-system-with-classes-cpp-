#include <iostream>
#include <string>
#include <map>
#include <vector>


class New_Account {
	public:
		std::string first_name;
		std::string last_name;
		int id_num;
		int current_balance;
		int pin_num;

	public:
		New_Account() {

			id_num = 0;
			current_balance = 0;
			pin_num = 0;

			std::cout << "default constructor for the new account has been called..." << std::endl;
		};

		New_Account(std::string f_name, std::string l_name, int id, int balance, int pin) {
			first_name = f_name;
			last_name = l_name;
			id_num = id;
			current_balance = balance;
			pin_num = pin;
		}

		void show_info() {
			std::cout << "Full name: " << first_name << " " << last_name << std::endl;
			std::cout << "ID number: " << id_num << std::endl;
			std::cout << "Current Balance: " << current_balance << std::endl;
			std::cout << "Pin number: " << pin_num << std::endl;
		}
};

int main() {

	int response;

	std::vector <New_Account> accounts;
	
	auto main_page = [&]() {
		std::cout << "welcome to the banking system.\n" << std::endl;
		std::cout << "please choose a service:" << std::endl;
		std::cout << "1- Create a new account.   " << "2- Delete account.   " << "3- Show account info." << std::endl;
		std::cout << "4- Deposit money.   " << "       5- Withdraw money.   " << "6- transfer money." << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

	};

	bool end = false;

	while (end == false) {

		main_page();

		std::cin >> response;

		if (response == 1) {

			std::system("cls");

			std::cout << "you chose to create a new account.\n" << std::endl;

			std::string f_name;
			std::string l_name;
			int id;
			int balance{ 0 };
			int pin;

			std::cout << "type your first name:  ";
			std::cin >> f_name;

			std::cout << "type your last name:  ";
			std::cin >> l_name;

			std::cout << "type your id number:  ";
			std::cin >> id;

			std::cout << "type the pin you want to use:  ";
			std::cin >> pin;

			New_Account acc(f_name, l_name, id, balance, pin);

			accounts.push_back(acc);

			std::system("cls");
			std::cout << std::endl;
			std::cout << "account created succesfully.\n" << std::endl;

			std::cout << "here is the new account information:\n" << std::endl;
			std::cout << "First name: " << acc.first_name << std::endl;
			std::cout << "Last name: " << acc.last_name << std::endl;
			std::cout << "ID number: " << acc.id_num << std::endl;
			std::cout << "Balance: " << acc.current_balance << std::endl;
			std::cout << "Pin name: " << acc.pin_num << std::endl;

			std::cout << std::endl;
			char response2{ 'n' };

			std::cout << "want another service? y or n" << std::endl;
			std::cin >> response2;

			if (response2 == 'y') {
				std::system("cls");
				continue;
			}
			else
			{
				end = true;
				std::system("cls");
				std::cout << "thanks for choosing us :)" << std::endl;
			}

		}

		else if (response == 2) {

			std::system("cls");
			std::cout << "you chose to delete an account\n" << std::endl;

			int id_to_delete;
			std::cout << "type the id of the account you want to delete:  ";
			std::cin >> id_to_delete;

			for (auto& acc : accounts) {
				if (acc.id_num == id_to_delete) {

					std::cout << "deleting ..." << std::endl;

					acc.first_name = "";
					acc.last_name = "";
					acc.id_num = 0;
					acc.current_balance = 0;
					acc.pin_num = 0;

					std::cout << "account with the id of " << id_to_delete << " has been deleted." << std::endl;

					break;
				}
			}

			std::cout << std::endl;
			char response2{ 'n' };

			std::cout << "want another service? y or n" << std::endl;
			std::cin >> response2;

			if (response2 == 'y') {
				std::system("cls");
				continue;
			}
			else
			{
				end = true;
				std::system("cls");
				std::cout << "thanks for choosing us :)" << std::endl;
			}

		}
		else if (response == 3) {
			
			std::system("cls");
			std::cout << "you chose to view account info.\n" << std::endl;

			int id_to_view;
			std::cout << "type the id of the account you want to view:  ";
			std::cin >> id_to_view;

			for (auto& acc : accounts) {
				if (acc.id_num == id_to_view) {

					std::cout << "First name: " << acc.first_name << std::endl;
					std::cout << "Last name: " << acc.last_name << std::endl;
					std::cout << "ID number: " << acc.id_num << std::endl;
					std::cout << "Balance: " << acc.current_balance << std::endl;
					std::cout << "Pin: " << acc.pin_num << std::endl;

					break;
				}
			}

			std::cout << std::endl;
			char response2{ 'n' };

			std::cout << "want another service? y or n" << std::endl;
			std::cin >> response2;

			if (response2 == 'y') {
				std::system("cls");
				continue;
			}
			else
			{
				end = true;
				std::system("cls");
				std::cout << "thanks for choosing us :)" << std::endl;
			}


		} else if (response == 4) {

			std::system("cls");
			std::cout << "you chose to deposit money in the account.\n" << std::endl;

			int account_id;
			std::cout << "type the id of the account you want to deposit to:  ";
			std::cin >> account_id;

			for (auto& acc : accounts) {

				if (acc.id_num == account_id) {

					std::cout << "current account balance is " << acc.current_balance << std::endl;

					double amount;
					std::cout << "type the amount you want to deposit:  ";
					std::cin >> amount;

					std::cout << "\nProcessing...\n" << std::endl;
					acc.current_balance =  acc.current_balance + amount;

					std::cout << "account was credited with the amount of " << amount << " succesfully\n" << std::endl;
					std::cout << "account balance is now " << acc.current_balance << std::endl;

					break;
				}
			}

			std::cout << std::endl;
			char response2{ 'n' };

			std::cout << "want another service? y or n" << std::endl;
			std::cin >> response2;

			if (response2 == 'y') {
				std::system("cls");
				continue;
			}
			else
			{
				end = true;
				std::system("cls");
				std::cout << "thanks for choosing us :)" << std::endl;
			}
		}
		else if (response == 5) {
			std::system("cls");
			std::cout << "you chose to withdraw money from the account.\n" << std::endl;

			int account_id;
			std::cout << "type the id of the account you want to withdraw from:  ";
			std::cin >> account_id;

			for (auto& acc : accounts) {

				if (acc.id_num == account_id) {

					std::cout << "current account balance is " << acc.current_balance << std::endl;

					double amount;
					std::cout << "type the amount you want to withdraw:  ";
					std::cin >> amount;

					std::cout << "\nProcessing...\n" << std::endl;
					acc.current_balance = acc.current_balance - amount;

					std::cout << "account was credited with the amount of " << amount << " succesfully\n" << std::endl;
					std::cout << "account balance is now " << acc.current_balance << std::endl;

					break;
				}
			}

			std::cout << std::endl;
			char response2{ 'n' };

			std::cout << "want another service? y or n" << std::endl;
			std::cin >> response2;

			if (response2 == 'y') {
				std::system("cls");
				continue;
			}
			else
			{
				end = true;
				std::system("cls");
				std::cout << "thanks for choosing us :)" << std::endl;
			}

		}
		else if (response == 6) {
			std::system("cls");
			std::cout << "you chose to transfer money to another account.\n" << std::endl;

			int user_id;
			std::cout << "type your account id:  " << std::endl;
			std::cin >> user_id;

			int target_id;
			std::cout << "type the target account id:  " << std::endl;
			std::cin >> target_id;

			for (auto& acc : accounts) {
				if (acc.id_num == user_id) {

					std::cout << "your current account balance is: " << acc.current_balance << std::endl;

					int amount;
					std::cout << "type the amount you want to transfer:  " << std::endl;
					std::cin >> amount;

					acc.current_balance -= amount;

					for (auto& acc : accounts) {
						if (acc.id_num == target_id) {
							acc.current_balance += amount;
							break;
						}
					}
				}
			}

			std::cout << std::endl;
			std::cout << "money transfered succesfully!" << std::endl;

			std::cout << std::endl;
			char response2{ 'n' };

			std::cout << "want another service? y or n" << std::endl;
			std::cin >> response2;

			if (response2 == 'y') {
				std::system("cls");
				continue;
			}
			else
			{
				end = true;
				std::system("cls");
				std::cout << "thanks for choosing us :)" << std::endl;
			}
		}

	}
	

	return 0;
}