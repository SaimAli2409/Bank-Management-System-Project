//***************************************************************
//					LIBRARIES USED IN PROGRAM
//***************************************************************

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <exception>
#include <stdlib.h>

using namespace std;		// STANDARD NAMESPACE

//***************************************************************
//						CLASS BANK
//***************************************************************

class Bank{
	
	private:
		
		string bankname;
		string branchname;
		string banknumber;
		
	public:
		
		Bank()
		{
			
		}
		
		Bank( string bankname , string branchname, string banknumber )
		{
			this->bankname = bankname;
			this->branchname = branchname;
			this->banknumber = banknumber;
		
		}
	
		~Bank()
		{
			
		}
		
		void set_BankName(string bankname)
		{
			this->bankname = bankname;
		}
		
		void set_BranchName(string branchname)
		{
			this->branchname = branchname;
		}
		
		string get_BankName()
		{
			return bankname;
		}
		
		string get_BranchName()
		{
			return branchname;
		}
		
		friend ostream& operator << (ostream& out, Bank &obj);
		
};

ostream& operator << (ostream& out, Bank &obj)
{
	out<<"Bank Name: "<<obj.bankname;
	out<<"\nBranch Name: "<<obj.branchname;
	out<<"\nBank Number: "<<obj.banknumber;
	
	return out;
}

//****************************************************************
//						CLASS PERSON
//****************************************************************

class Person{
	
	protected:
		
		char name[50], phonenumber[50];		// MEMBERS ARE PROTECTED
		
	public:
		
		Person()
		{
			// DEFAULT CONSTRUCTOR
		}
		
		~Person()
		{
		
		}
		
		void set_Name(char name[50])
		{
			strcpy(name, name);				// STRING COPY FUNCTION
		}
		
		void set_PhoneNumber(char phonenumber[50]) 		// MUTATORS
		{
			strcpy(name, name);
		}
		
		char* get_Name()		// ACCESSORS
		{
			return name;
		}
		
		char* get_PhoneNumber()
		{
			return phonenumber;
		}
		
		virtual void Display() = 0;			// PURE VIRTUAL FUNCTION
};

//***************************************************************
//						CLASS CUSTOMER
//***************************************************************

class Customer : public Person{
	
	protected:
		
	public:
		
		Customer()
		{
			// DEFAULT CONSTRUCTOR
		}
		
		~Customer()
		{
			
		}
		
};

//***************************************************************
//						CLASS STAFF
//***************************************************************

class Staff : public Person {
	
	private : 
		
		int EmployeeID ;
		double Salary ;
		char Designation[50] ;
	
	public : 
		
		Staff()
		{
		}
		
		Staff( int empID , double sal , char desig[50] )
		{
			EmployeeID = empID ;
			Salary = sal ;
			strcpy( Designation , desig );
		}
		
		~Staff()
		{
			
		}
		
		void set_ID( int empid )
		{
			EmployeeID = empid ;
		}
		
		void set_Salary( double sal )
		{
			Salary = sal ;
		}
		
		void set_Designation( char desig[50] )
		{
			strcpy( Designation , desig );
		}
		
		int get_ID();
		
		double get_Salary()
		{
			return Salary ;
		}
		
		char* get_Designation()
		{
			return Designation ;
		}
		
		void Input_Employees();
		
		void Display()
		{
			cout<<"\n\nEMPLOYEE DETAILS";
			cout<<"\n\nName: "<<name;
			cout<<"\nPhone Number: "<<phonenumber;
			cout<<"\nID: "<<EmployeeID;
			cout<<"\nDesignation: "<<Designation;
			cout<<"\nSalary: $"<<Salary;
		}
		
		friend ostream& operator << (ostream& out, Staff &obj);
};

ostream& operator << (ostream& out, Staff &obj)
{
	out<<"\n\nName: "<<obj.name;
	out<<"\nPhone Number: "<<obj.phonenumber;
	out<<"\nID: "<<obj.EmployeeID;
	out<<"\nDesignation: "<<obj.Designation;
	out<<"\nSalary: $"<<obj.Salary;
}

void Staff::Input_Employees()
{
		
	cout<<"Enter Name: ";
	scanf(" %s", name);
	
	cout<<"\nEnter Phone Number: ";
	scanf(" %s", phonenumber);

	cout << "\nEnter Employee ID : " ;
	cin >> EmployeeID ;
	
	fflush(stdin);
	cout << "\nEnter Designation : " ;
	scanf(" %s", Designation);

	cout << "\nEnter Salary : ";
	cin >> Salary ;
	
	cout << "\n\nCreated .... " << endl ; 		
}

int Staff::get_ID()
{
	return EmployeeID ;
}


template <typename T>
class Account : public Customer{
	
	private :
		
		char account_type ;
		T AccountNumber ; 
		
	protected :
		
		double balance , addmoney , submoney ;
	 
	public : 
	
		Account(){
		}
		
		Account( double bal , double addamount , double subamount , char type , int accnum ){
			balance = bal ;
			addmoney = addamount ;
			submoney = subamount ;
			account_type = type ;
			AccountNumber = accnum ;
		}
		
		~Account(){
		}
		
		void set_Balance(double bal)
		{
			balance = bal;
		}
		
		void set_AddMoney(double addmoney)
		{
			this->addmoney = addmoney;
		}
		
		void set_SubMoney(double submoney)
		{
			this->submoney = submoney;
		}
		
		void DepositB()
		{
			balance = balance + addmoney;
		}
		
		void WithdrawB()
		{
			balance = balance - submoney;
		}
	
		double get_AddMoney()
		{
			return addmoney;
		}
		
		double get_SubMoney()
		{
			return submoney;
		}
		
		double get_Balance()
		{
			return balance;
		}
		
		char get_AccountType()
		{
			return account_type;
		}
		
		T get_AccountNumber();
		void Create_Account();
		void Display();
		void Modify();
};

template <typename T>
void Account<T>::Create_Account(){
	
	fflush(stdin);
	cout << "\nEnter Name : " ;
	gets(name);
	
	cout << "\nEnter Phone # " ;
	gets(phonenumber);
	
	cout << "\nEnter Account # " ;
	cin >> AccountNumber ;
	
	cout << "\nEnter Account Type ( C / S ) : " ;
	cin >> account_type ;
	
	cout << "\nEnter Balance : $" ;
	cin >> balance ;
	
	cout << "\n\nAccount Created...." << endl ;
}


template <typename T>
T Account<T>::get_AccountNumber(){
	return AccountNumber ;
}


template <typename T>
void Account<T>::Modify(){

	cout << "\n\nAccount # " << AccountNumber ;
	cout << "\nBalance : $" << balance ;
	
	fflush(stdin);
	cout << "\nEnter Name : " ;
	gets(name);
	
	cout << "\nEnter Phone # " ;
	gets(phonenumber);
	
	cout << "\nEnter Account Type ( C / S ) : " ;
	cin >> account_type ;
	
}


template <typename T>
void Account<T>::Display(){
	
	cout << "\n\nAccount # " << AccountNumber ;
	cout << "\nName : " << name ;
	cout << "\nPhone # " << phonenumber ;
	cout << "\nAccount Type : " << account_type ;
	cout << "\nBalance : $" << balance ;
	   
}


//*************************************************
//				FUNCTION DECLARATION OF ACCOUNT
//*************************************************

void CreateAcc();
void UpdateAcc();
void DeleteAcc();
void DisplayAllAcc();
void SearchAcc();

void DepositAcc();
void WithdrawAcc();

//*************************************************
//				FUNCTION DECLARATION OF STAFF
//*************************************************

void CreateST();
void SearchST();
void DeleteST();
void DisplayAllST();
void Intro();

//**************************************************
//					MAIN FUNCTION
//**************************************************

int main()
{
	int opt, opt2, opt3, opt4;
	
	Intro();
	getch();
	system("cls");
	
	do{
	
		
		do{
			
			try{
				
				exception e;
				
				cout<<"\t\t*** HABIB BANK LIMITED ***\n\n";
			
				cout<<"1: Customer Portal\n2: Staff Portal\n3: Contact Us\n4: Exit\n\nEnter Option: ";
				cin>>opt;
				
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					
					system("cls");
					
					throw e;
				}
				else
				{
					break;
				}
			}
			catch(exception e)
			{
				cerr<<"ERROR! MISMATCHED INPUT "<<e.what();
			}
			
		}while(1);
		
		if(opt == 4)
		{
			break;
		}
		
		system("cls");
		
		switch(opt)
		{
			case 1:
			{
				
				do{
					
					do{
						
						try{
							
							exception e;
							
							cout<<"\t\t*** CUSTOMER PORTAL ***\n\n";
							cout<<"1: Create Account\n2: Search Account\n3: Update Account\n4: Delete Account\n5: Display All Accounts\n6: Transactions\n7: Back\n\nEnter Option: ";
							cin>>opt2;
							
							if(cin.fail())
							{
								cin.clear();
								cin.ignore();
								
								system("cls");
								
								throw e;
							}
							else
							{
								break;
							}
							
						}
						catch(exception e)
						{
							cerr<<e.what();
						}
						
					}while(1);
					
					if(opt2 == 7)
					{
						break;
					}
					
					system("cls");
					
					switch(opt2)
					{
						case 1:{
							
							cout<<"\t\t*** OPEN ACCOUNT ***\n\n";
							
							CreateAcc();
							
							getch();
							break;
						}
						
						case 2:{
							
							cout<<"\t\t*** SEARCH ACCOUNT ***\n\n";
							
							SearchAcc();
							
							getch();
							break;
						}
						
						case 3:{
							
							cout<<"\t\t*** UPDATE ACCOUNT ***\n\n";
							
							UpdateAcc();
							
							getch();
							break;
						}
						
						case 4:{
							
							cout<<"\t\t*** DELETE ACCOUNT ***\n\n";
							
							DeleteAcc();
							
							getch();
							break;
						}
						
						case 5:{
							
							cout<<"\t\t*** ACCOUNT HOLDER LIST ***\n\n";
							
							DisplayAllAcc();
							
							getch();
							break;
						}
						
						case 6:{
							
							do{
								
								do{
								
									try{
										
										exception e;
										
										cout<<"\t\t*** TRANSACTION ***\n\n";
										
										cout<<"1: Deposit\n2: Withdraw\n3: Back\n\nEnter Option: ";
										cin>>opt3;
										
										if(cin.fail())
										{
											cin.clear();
											cin.ignore();
											
											system("cls");
											
											throw e;
										}
										else
										{
											break;
										}
										
									}
									
									catch(exception e)
									{
										cerr<<e.what();
									}
								
								
								}while(1);
								
								if(opt3 == 3)
								{
									break;
								}
								
								system("cls");
								
								switch(opt3)
								{
									case 1:{
										
										cout<<"\t\t*** DEPOSIT ***\n\n";
										
										DepositAcc();
										
										break;
									}
									
									case 2:{
										
										cout<<"\t\t*** WITHDRAW ***\n\n";
										
										WithdrawAcc();
										
										break;
									}
								}
								system("cls");
							}while(1);
							
							getch();
						}
						break;
					}
					system("cls");
				}while(1);
			}
			break;
		
		case 2:
		{
			
			do{
				
				do{
					
						try{
							
							exception e;
							
							cout<<"\t\t*** STAFF PORTAL ***\n\n";
							
							cout<<"1: Create Employee\n2: Search Employee\n3: Delete Employee\n4: Employee List\n5: Back\n\nEnter Option: ";
							cin>>opt4;
							
							if(cin.fail())
							{
								cin.clear();
								cin.ignore();
								
								system("cls");
								
								throw e;
							}
							else
							{
								break;
							}
						}
						
						catch(exception e)
						{
							cout<<"what()	"<<e.what();
						}
						
					}while(1);
					
					if(opt4 == 5)
					{
						break;
					}
					
					system("cls");
					
					switch(opt4)
					{
						case 1:{
							
							cout<<"\t\t*** NEW EMPLOYEE ***\n\n";
							
							CreateST();
							
							getch();
						}
						break;
						
						case 2:{
							
							cout<<"\t\t*** SEARCH EMPLOYEE ***\n\n";
							
							SearchST();
							
							getch();
						}
						break;
						
						case 3:{
							
							cout<<"\t\t*** DELETE EMPLOYEE ***\n\n";
							
							DeleteST();
							
							getch();
						}
						break;
						
						case 4:{
							
							cout<<"\t\t*** EMPLOYEE LIST ***\n\n";
							
							DisplayAllST();
							
							getch();
						}
						break;
					}
					system("cls");
				}while(1);
			}
			break;
			
		case 3:
			{
				cout<<"\t\t*** CONTACT US ***\n\n";
							
				Bank bank("Habib Bank Limited", "Karachi, Sindh", "(021) 111 111 425");
				
				cout<<bank;
				
				getch();
			}
			break;
		}
		system("cls");
	}while(1);
}
//**************************************************
//						MAIN END
//**************************************************

//				**** GLOBAL FUNCTIONS ****

//**************************************************
//					CREATE ACCOUNT
//**************************************************

void Intro()
{	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPROJECT BANK\n\n\n\t\t\t\t\tCreated By:\n\n\t\t\t\t\tAli Faisal (17-K3791)\n\t\t\t\t\tSaim Ali (17-K3932)\n";
}

//***************************************************************
//    	function to write in file
//****************************************************************
void CreateAcc()
{
	Account<int> obj;
	
	ofstream outFile;
	
	outFile.open("account.dat",ios::binary|ios::app);
	
	obj.Create_Account();
	
	outFile.write(reinterpret_cast<char *> (&obj), sizeof(Account<int>));
	
	outFile.close();
}

//**************************************************
//			DISPLAY ACCOUNT HOLDER LIST
//**************************************************

void DisplayAllAcc(){

	Account<int> obj ;

	ifstream inFile;

	inFile.open("account.dat",ios::binary);

	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

	while(inFile.read(reinterpret_cast<char *> (&obj), sizeof(Account<int>)))

	{
		obj.Display();
	}

	inFile.close();
}

//**************************************************
//					SEARCH ACCOUNT
//**************************************************

void SearchAcc()
{
	Account<int> MyAccount;
	int accnum;
	ifstream inFile;
	int flag = 0 ;  
	
	inFile.open("account.dat", ios::binary);
	
	cout<<"Enter Account Number: ";
	cin>>accnum;
	
	cout<<"\n\n";
	
	if(inFile.is_open())
	{
		while(inFile.read(reinterpret_cast<char*>(&MyAccount), sizeof(Account<int>)))
		{
			if(MyAccount.get_AccountNumber() == accnum)
			{
				MyAccount.Display();
				flag =1 ;
			}
		}
		if( flag == 0 ){
			cout << "Record Not found!!" << endl ;
		}
		inFile.close();
	}
	else
	{
		cout<<"\nFile Could Not Be Opened!";
	}
}

//**************************************************
//					DELETE ACCOUNT
//**************************************************

void DeleteAcc()
{
	int n ;
	cout << "Enter Account Number : " ;
	cin >> n ;
	
	Account<int> obj;
	
	ifstream inFile;
	ofstream outFile;
	
	inFile.open("account.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
	outFile.open("temp.dat",ios::binary);
	
	inFile.seekg(0,ios::beg);
	
	while(inFile.read(reinterpret_cast<char *> (&obj), sizeof(Account<int>)))
	{
		if( obj.get_AccountNumber() != n )
		{
			outFile.write(reinterpret_cast<char *> (&obj), sizeof(Account<int>));
		}
	}
	
	inFile.close();
	outFile.close();
	
	remove("account.dat");
	rename("temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

//**************************************************
//					UPDATE ACCOUNT
//**************************************************

void UpdateAcc()
{
	int n ;
	cout << "Enter Account Number : " ;
	cin >> n ;
	
	bool found=false;
	
	Account<int> obj ;
	
	fstream File;
	
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&obj), sizeof(Account<int>));
		
		if( obj.get_AccountNumber() == n ){
			
			obj.Display();
			
			cout<<"\n\nEnter The New Details of account"<<endl;
			
			obj.Modify();
			
			int pos=(-1)*static_cast<int>(sizeof(Account<int>));
			
			File.seekp(pos,ios::cur);
			
			File.write(reinterpret_cast<char *> (&obj), sizeof(Account<int>));
			
			cout<<"\n\n\t Record Updated";
			
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

//**************************************************
//					DEPOSIT ACCOUNT
//**************************************************

void DepositAcc()
{
	fstream File;
	
	Account<int> MyAccount;
	
	int accnum, position, c = 0;
	double addmoney;
	
	File.open("account.dat", ios::binary | ios::in | ios::out);
	
	system("cls");
	
	do{
		
		cout<<"\t\t*** Deposit ***\n\n";
	
		cout<<"Enter Account Number: ";
		cin>>accnum;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			
			system("cls");
		}
		else
		{
			break;
		}
		
	}while(1);
	
	if(File.is_open())
	{
		while(File.read(reinterpret_cast<char*>(&MyAccount), sizeof(Account<int>)))
		{
			if(MyAccount.get_AccountNumber() == accnum)
			{
				c = 1;
				
				do{
					
					try
					{
						exception e;
						
						cout<<"\n\nEnter Amount For Deposit: $";
						cin>>addmoney;
						
						if(cin.fail())
						{
							cin.clear();
							cin.ignore();
							throw e;
						}
						else
						{
							break;
						}
					}
					catch(exception e)
					{
						cerr<<"ERROR!	"<<e.what();
						getch();
					}
					
					system("cls");
					cout<<"\t\t*** Deposit ***\n\n";
				}while(1);
				
				if(addmoney  >= 0)
				{
					MyAccount.set_AddMoney(addmoney);
					
					MyAccount.DepositB();
					
					position = (-1)*static_cast<int>(sizeof(MyAccount));
					
					File.seekp(position, ios::cur);
					
					File.write(reinterpret_cast<char*>(&MyAccount), sizeof(Account<int>));
				}
				else
				{
					cout<<"\nInvalid Amount!";
				}
			}
		}
		
		if(c == 0)
		{
			cout<<"\nAccount Does Not Exist!";
		}
		
		File.close();
	}
	else
	{
		cout<<"\nFile Not Found!";
	}
}

//**************************************************
//					WITHDRAW ACCOUNT
//**************************************************

void WithdrawAcc()
{
	fstream File;
	
	Account<int> MyAccount;
	
	int accnum, position, c = 0;
	double balance, submoney;
	
	File.open("account.dat", ios::binary | ios::in | ios::out);
	
	system("cls");
	
	do{
		
		try
		{
			exception e;
			
			cout<<"\t\t*** Withdraw ***\n\n";
	
			cout<<"Enter Account Number: ";
			cin>>accnum;
			
			if(cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw e;
			}
			else
			{
				break;
			}
		}
		catch(exception e)
		{
			cerr<<"ERROR!	"<<e.what();
			getch();
		}
		
		system("cls");
	}while(1);
	
	if(File.is_open())
	{
		while(File.read(reinterpret_cast<char*>(&MyAccount), sizeof(Account<int>)))
		{
			if(MyAccount.get_AccountNumber() == accnum)
			{
				c = 1;
				
				do{
					
					try
					{
						exception e;
				
						cout<<"Enter Amount To Withdraw: ";
						cin>>submoney;
						
						if(cin.fail())
						{
							cin.clear();
							cin.ignore();
							throw e;
						}
						else
						{
							break;
						}
					}
					catch(exception e)
					{
						cerr<<"ERROR!	"<<e.what();
						getch();
					}
					
					system("cls");
				}while(1);
				
				if(MyAccount.get_Balance() >= submoney && submoney >= 0)
				{
					MyAccount.set_SubMoney(submoney);
					
					MyAccount.WithdrawB();
					
					position = (-1)*static_cast<int>(sizeof(MyAccount));
				
					File.seekp(position, ios::cur);
				
					File.write(reinterpret_cast<char*>(&MyAccount), sizeof(Account<int>));
				}
				else
				{
					cout<<"\nInsufficient Amount!";
					getch();
				}
			}
		}
		
		if(c == 0)
		{
			cout<<"\nAccount Does Not Exist!";
			getch();
		}
		
		File.close();
	}
	else
	{
		cout<<"\nFile Not Found!";
		getch();
	}
}

//***********************************************************
//					STAFF CREATE
//***********************************************************

void CreateST()
{
	Staff st;
	
	ofstream outFile;
	
	outFile.open("Staff.dat", ios::binary | ios::app);
	
	st.Input_Employees();

	outFile.write(reinterpret_cast<char *> (&st), sizeof(Staff));

	outFile.close();
}

//***********************************************************
//					STAFF LIST
//***********************************************************

void DisplayAllST()
{
	Staff st;
	ifstream inFile;
	
	inFile.open("Staff.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"File Not Open!!\nPress Any Key...";
		return;
	}
	
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Staff)))
	{
		cout<<st;
	}
	
	inFile.close();
}

//***********************************************************
//					STAFF DELETE
//***********************************************************

void DeleteST()
{
	int ID;
	int flag = 0; 
	cout << "Enter ID Of Employee To Delete: ";
	cin >>ID;
	
	Staff st;
	
	ifstream inFile;
	ofstream outFile;
	
	inFile.open("Staff.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"File Not Open!!\nPress Any Key...";
		return;
	}
	
	outFile.open("Temp.dat",ios::binary);
	
	inFile.seekg(0,ios::beg);
	
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Staff)))
	{
		if(st.get_ID()!=ID)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(Staff));
			flag = 1 ;
		}
	}
	
	inFile.close();
	outFile.close();
	
	remove("Staff.dat");
	rename("Temp.dat","Staff.dat");
	cout<<"\n\n\tRecord Deleted...";
}

//***********************************************************
//					STAFF SEARCH
//***********************************************************

void SearchST()
{
	int ID;
	
	cout<<"Enter ID Of Employee To Display: ";
	cin>>ID;
	
	Staff st;
	
	bool flag = false;
	ifstream inFile;
	
	inFile.open("Staff.dat", ios::binary);
	
	if(!inFile)
	{
		cout<<"File Not Open!!\nPress Any Key...";
		return;
	}
	
	cout<<"\nEMPLOYEE DETAILS\n";

    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Staff)))
	{
		if(st.get_ID()==ID)
		{
			cout<<st;
			flag=true;
		}
	}
	
	inFile.close();
	
	if(flag==false)
		cout<<"\n\nERROR! Employee Not Found...";
}
