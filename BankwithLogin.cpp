#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clients{
	string accNum, cliNum;
	public:
		string name;
		clients(){
			name = "";
			accNum = "";
			cliNum = "";
		}
		clients(string, string, string);
};

clients::clients(string cliName,string cliaccNum,string ccliNum){
	
	name = cliName;
	accNum = cliaccNum;
	cliNum = ccliNum;
	
}

class accounts{
	float balance;
	public:
		string accNum, password;
		accounts(){
			balance = 0;
		}
		accounts(string, string);
		float withdraw(float amount){
			if(amount <= balance){
				balance -= amount;
				cout << "Balance: " << balance << endl;
			}else{
				cout << "Withdraw amount larger than balance" << endl;
				cout << "Enter amount: ";
				float amount;
				cin >> amount;
				withdraw(amount);
			}
		}
		float deposit(float amount){
			balance += amount;
			cout << "Balance: " << balance << endl;
		}
		void accBalance(){
			cout << "Balance: " << balance << endl;
		}
};

accounts::accounts(string cliaccNum, string cliPass){
	
	accNum = cliaccNum;
	balance = 100;
	password = cliPass;
	
}

int main(){
	
	vector<clients> my_client;
	vector<accounts> my_account;
	
	bool run = true;
	while(run){
		int option,i;
		cout << "1. Create Account" << endl;
		cout << "2. Login" << endl;
		cout << "3. Exit" << endl;
		cout << ">> ";
		cin >> option;
		system("cls");
		if(option == 1){
			string name, accNum, cliNum, password;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter account number: ";
			cin >> accNum;
			cout << "Enter client number: ";
			cin >> cliNum;
			cout << "Enter password: ";
			cin >> password;
			clients client(name, accNum, cliNum);
			accounts account(accNum, password); 
			my_client.push_back(client);
			my_account.push_back(account);
			system("cls");
			/*cout << client.name;
			cout << account.accNum;*/	
		}else if(option == 2){
			string accNum, password;
			cout << "Enter account number: ";
			cin >> accNum;
			cout << "Enter password: ";
			cin >> password;
			system("cls");
			for(i = 0; i < my_account.size(); i++){
				bool toRun=true;
				if(my_account[i].accNum == accNum && my_account[i].password == password){
					cout << "Successful Login" << endl;
					while(toRun){
						cout << "1. Deposit" << endl;
						cout << "2. Withdraw" << endl;
						cout << "3. Balance" << endl;
						cout << "4. Logout" << endl;
						cout << ">> ";
						cin >> option;
						system("cls");
						float amount;
						if(option == 1){
							cout << "Enter amount: ";
							cin >> amount;
							my_account[i].deposit(amount);
							system("pause");
							system("cls");
						}else if(option == 2){
							my_account[i].accBalance();
							cout << "Enter amount: ";
							cin >> amount;
							my_account[i].withdraw(amount);
							system("pause");
							system("cls");
						}else if(option == 3) {
							my_account[i].accBalance();
							system("pause");
							system("cls");
						}else if(option == 4){
							cout << "Logging out..." << endl;
							toRun = false;
							system("pause");
							system("cls");
						}
					}
					
				}
			}
		}else if(option == 3){
			cout << "EXITING PROGRAM..." << endl;
			return 0;
		}
	}
}
