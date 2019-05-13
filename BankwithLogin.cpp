#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
	ofstream outfile;
	ifstream infile;
	bool run = true;
	int logTries = 3;
	while(run){
		if(logTries == 0){
			cout << "Unable to login." << endl << "EXITING PROGRAM..." << endl;
			//toRun = false;
			//run = false;
			return 0;
		}
		int option,i;
		cout << "1. Create Account" << endl;
		cout << "2. Login" << endl;
		cout << "3. Exit" << endl;
		cout << ">> ";
		cin >> option;
		system("cls");
		if(option == 1){
			outfile.open("bank.txt", ios::app);
			infile.open("bank.txt");
			//after asking for credintials check on wether they exist. 
			//If they do, ask to for them to be re-entered
			string name, accNum, cliNum, password;
			cout << "Enter name: ";
			cin >> name;
			outfile << "Name: " << name << " ";
			cout << "Enter account number: ";
			cin >> accNum;
			outfile << "accNum: " << accNum << " ";
			cout << "Enter client number: ";
			cin >> cliNum;
			outfile << "cliNum: " << cliNum << " ";
			cout << "Enter password: ";
			cin >> password;
			outfile << "Password: " << password << endl;
			outfile.close();
			clients client(name, accNum, cliNum);
			accounts account(accNum, password); 
			my_client.push_back(client);
			my_account.push_back(account);
			system("cls");
			/*cout << client.name;
			cout << account.accNum;*/	
		}else if(option == 2){
			string accNum, password;
			infile.open("bank.txt");
			cout << "Tries: " << logTries <<endl;
			cout << "Enter account number: ";
			cin >> accNum;
			cout << "Enter password: ";
			cin >> password;
			system("cls");
			for(i = 0; i < my_account.size(); i++){
				bool toRun=true;
				string line;
				int offset1, offset2;
				string num;
				string pass;
				num = accNum;
				pass = password;
				//while(!infile.eof()){
				//	getline(infile, line);
					
				infile.close();
				if((my_account[i].accNum == accNum && my_account[i].password == password) && logTries > 0){
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
					
				}else if((my_account[i].accNum != accNum || my_account[i].password != password) && logTries > 0){
					//cout << logTries << endl;
					cout << "Wrong Account Number or Password" << endl << "Try again" << endl;;
					logTries--;
					system("pause");
					system("cls");
					//cout << logTries << endl;
				}
			}
		}else if(option > 3){
			cout << "EXITING PROGRAM..." << endl;
			return 0;
		}
	}
}
