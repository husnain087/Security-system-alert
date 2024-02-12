#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;
// Maximum account numbers...
int const maxaccounts = 100;
//Arrays to store data
string accNumber[maxaccounts];
string username[maxaccounts];
int age[maxaccounts];
char accType[maxaccounts];
string city[maxaccounts];
int pin[maxaccounts];
double initialBalance[maxaccounts];
// key functionalities....
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAccountDetails();
void closeAccount();
//Other Functions...
void banner1();
void banner2();
void banner3();
void banner4();
void banner5();
void banner6();
void banner7();
void banner8();
void banner9();
void menu();
void greeting();
void loadingBar();
void accNumberGenerator();
void countdown();
int accountcounter = 0;
// main function....
int main() {
banner1();
greeting();
loadingBar();   
                                                           
  int key;
  		 do {
  		 	menu();
  		 	cout<<setw(30)<<setfill(' ')<<"";
    cin>>key;
    system("cls");
    switch(key){
      case 1:
    createAccount();
      break;
      case 2:
    deposit();
      break;
      case 3:
 withdraw();
      break;
      case 4:
 	checkBalance();
      break;case 5:
displayAccountDetails();
      break;
      break;case 6:
    closeAccount();
      break;
      case 7:
      	banner8();
      	cout<<"\n\n\n\t\t\t\t\t\tThank You!\n\n\n";
      	key = 0;
      	
      	break;
      default:
      cout<<"Invalid choice...Please choose again ";
    }
  }while(key!=0);

 return 0;
 //End of the main Function...
}
//Function to Create a account in arrays
void createAccount(){
banner2();
	    cout<<setw(40)<<setfill(' ')<<"\n\n\nCreating Account..... "<<endl;
loadingBar();
	   banner2();
  if(accountcounter<maxaccounts){
  	cout<<"\n\n\n";
//For Details Input
    cout<<"Enter Your Name: ";
    cin.ignore();
    getline(cin,username[accountcounter]);
    cout<<"Enter Your Age: ";
    cin>>age[accountcounter];
    cout<<"Enter Your City: ";
    cin.ignore();
    getline(cin,city[accountcounter]);
    cout<<"Enter Your Account Type (S/G): ";
    cin>>accType[accountcounter];
    accType[accountcounter] = toupper(accType[accountcounter]);

	
//For Chechking Valid Input or not...
    do{
    	if((accType[accountcounter]=='s'||accType[accountcounter]=='S')||(accType[accountcounter]=='g'||accType[accountcounter]=='G')){
    		break;
		}
		else{
			cout<<"Invalid Input...\n";
			cout<<"Enter Again... ";
			cin>>accType;
		}
	}while(accType[accountcounter]);

    cout<<"Enter Your initial balance: ";
    cin>>initialBalance[accountcounter];
    cout<<"Enter Your 4-Digit Pin: ";
    cin>>pin[accountcounter];
    //For Chechking Valid Input or not...
    do{
    	if(pin[accountcounter]<=9999&&pin[accountcounter]>=1000){
    		break;
		}
		else{
			cout<<"Invalid Input...\n";
			cout<<"Enter Again... ";
			cin>>pin[accountcounter];
		}
	}while(pin[accountcounter]);
    accNumberGenerator();
    accountcounter++;
    
         cout<<setw(40)<<setfill(' ')<<"\nAccount is successfully created...\n\n\n";
countdown();
}
  }
//Function to deposit cash
void deposit(){
		banner3();
		    cout<<setw(40)<<setfill(' ')<<"\n\n\n\n\nDepositing Account..... "<<endl;
loadingBar();
	banner3();
	system("color 6");
	  	string accountnum;
  	cout<<"\n\nEnter account Number: ";
  	cin>>accountnum;
  	 int ammount;
  	int index = -1;
  	
  	do{
  		  	for(int i = 0; i<maxaccounts; i++){
  		
  		if(accountnum==accNumber[i]){
  			index = i;
  		
		  }
	  }
	  if(index!=-1){
	  		cout<<setw(30)<<setfill(' ')<<"\n\t\t\t\t\t\tWelcome Sir..\n";
	  	  int accpin;
	  cout<<"Please Enter Your Account Pin: \n";
	  cin>>accpin;
	 do{
	 	 if(accpin==pin[index]){
	  		cout<<"\t\t\t\t\t\tLogin Successfully!\n\nEnter ammount to add: ";
	  cin>>ammount;
	  initialBalance[index]+=ammount;
	  cout<<"You Entered: "<<ammount;
	  cout<<"\nAmmount has Deposited Successfully...\n\n\n\t\t\t\t\t\tYour new balance is "<<initialBalance[index]<<endl;
break;
	  }
	  else {
	  		  	cout<<"Incorrect Password!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accpin;
	  }
	  	  
	 }while(true);
	 break;
	  }
	  else{
	  	cout<<"Account didn't found!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accountnum;
	  }
	  }while(1);

countdown();	  
}
//Function to Withdrawl cash
void withdraw(){
		banner4();
		    cout<<setw(40)<<setfill(' ')<<"\n\n\nWithdrwaing Account..... "<<endl;
loadingBar();
	banner4();
	system("color 6");
	  	string accountnum;
  	cout<<"\n\nEnter account Number: ";
  	cin>>accountnum;
  	 int ammount;
  	int index = -1;
  	
  	do{
  		  	for(int i = 0; i<maxaccounts; i++){
  		
  		if(accountnum==accNumber[i]){
  			index = i;
  		
		  }
	  }
	  if(index!=-1){
	  		cout<<setw(30)<<setfill(' ')<<"\n\t\t\t\t\t\tWelcome Sir..\n";
	  	  int accpin;
	  cout<<"Please Enter Your Account Pin: \n";
	  cin>>accpin;
	 do{
	 	 if(accpin==pin[index]){
	  		cout<<"\t\t\t\t\t\tLogin Successfully!\n\nEnter ammount to Withdraw: ";
	  cin>>ammount;
	  initialBalance[index]-=ammount;
	  cout<<"You Entered: "<<ammount;
	  cout<<"\nAmmount has Withdrawl Successfully...\n\n\n\t\t\t\t\t\tYour new balance is "<<initialBalance[index]<<endl;
break;
	  }
	  else {
	  		  	cout<<"Incorrect Password!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accpin;
	  }
	  	  
	 }while(true);
	 break;
	  }
	  else{
	  	cout<<"Account didn't found!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accountnum;
	  }
	  }while(1);

countdown();
}

//Function to checkBalance

void checkBalance(){
	
			banner5();
		    cout<<setw(40)<<setfill(' ')<<"\n\n\nChecking Balance..... "<<endl;
loadingBar();
	banner5();
		system("color 3");
	  	string accountnum;
  	cout<<"\n\nEnter account Number: ";
  	cin>>accountnum;
  	int index = -1;
  	
  	do{
  		  	for(int i = 0; i<maxaccounts; i++){
  		
  		if(accountnum==accNumber[i]){
  			index = i;
  		
		  }
	  }
	  if(index!=-1){
	  		cout<<setw(30)<<setfill(' ')<<"\n\t\t\t\t\t\tWelcome Sir..\n";
	  	  int accpin;
	  cout<<"Please Enter Your Account Pin: \n";
	  cin>>accpin;
	 do{
	 	 if(accpin==pin[index]){
	  		cout<<"\t\t\t\t\t\tLogin Successfully!\n\n";
	  cout<<"\nYour Account balance is "<<initialBalance[index]<<endl;
break;
	  }
	  else {
	  		  	cout<<"Incorrect Password!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accpin;
	  }
	  	  
	 }while(1);
	 break;
	  }
	  else{
	  	cout<<"Account didn't found!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accountnum;
	  }
	  }while(1);

countdown();
}

//Function to displayAccountDetails


  void displayAccountDetails(){
  		banner6();
		    cout<<setw(40)<<setfill(' ')<<"\n\n\nDisplaying Account Details.. "<<endl;
loadingBar();
	banner6();
		system("color 3");
		  	string accountnum;
  	cout<<"\n\n\nEnter account Number: ";
  	cin>>accountnum;
  	 int ammount;
  	int index = -1;
  	do{
  		  	for(int i = 0; i<maxaccounts; i++){
  		
  		if(accountnum==accNumber[i]){
  			index = i;
		  }
	  }
	  if(index!=-1){
	  		cout<<setw(30)<<setfill(' ')<<"\n\t\t\t\t\t\tWelcome Sir..\n";
	  		  int accpin;
	  cout<<"Please Enter Your Account Pin: \n";
	  cin>>accpin;
	  do{
	  	if(accpin==pin[index]){
	  		cout<<"\t\t\t\t\t\tLogin Successfully!\n\n";
	  			  	  string ACCtYPE;
    if(accType[accountcounter]=='G'){
    	ACCtYPE = "Gold";
	}
	else{
		ACCtYPE = "Silver";
	}
	      cout<<"\n";	  	
	    cout<<setw(20)<<setfill(' ')<<""<<setw(50)<<setfill('=')<<""<<endl;
	cout<<setw(20)<<setfill(' ')<<""<<left<<setw(17)<<setfill(' ')<<"||   Acc Number: "<<right<<setw(22)<<setfill(' ')<<accNumber[index]<<setw(11)<<setfill(' ')<<"||"<<endl;
	cout<<setw(20)<<setfill(' ')<<""<<left<<setw(17)<<setfill(' ')<<"||   Name: "<<right<<setw(22)<<setfill(' ')<<username[index]<<setw(11)<<setfill(' ')<<"||"<<endl;
	cout<<setw(20)<<setfill(' ')<<""<<left<<setw(17)<<setfill(' ')<<"||   Age: "<<right<<setw(22)<<setfill(' ')<<age[index]<<setw(11)<<setfill(' ')<<"||"<<endl;
	cout<<setw(20)<<setfill(' ')<<""<<left<<setw(17)<<setfill(' ')<<"||   City: "<<right<<setw(22)<<setfill(' ')<<city[index]<<setw(11)<<setfill(' ')<<"||"<<endl;
	cout<<setw(20)<<setfill(' ')<<""<<left<<setw(17)<<setfill(' ')<<"||   Acc Type: "<<right<<setw(22)<<setfill(' ')<<ACCtYPE<<setw(11)<<setfill(' ')<<"||"<<endl;
	cout<<setw(20)<<setfill(' ')<<""<<left<<setw(17)<<setfill(' ')<<"||   Acc Pin: "<<right<<setw(22)<<setfill(' ')<<pin[index]<<setw(11)<<setfill(' ')<<"||"<<endl;
	cout<<setw(20)<<setfill(' ')<<""<<setw(50)<<setfill('=')<<""<<endl;
	  break;
		  }
		 else {
	  		cout<<"Account didn't found!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accountnum;
	  }
	  }while(1);
break;
	  }
	  
	  else{
	  	cout<<"Account didn't found!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accountnum;
	  }
	  }while(1);
	    countdown();
}
//Function to Close a account
void closeAccount(){
		banner7();
		    cout<<setw(40)<<setfill(' ')<<"\n\n\nRemoving Account..... "<<endl;
loadingBar();
  system("color 4"); 
	banner7();
	 	string accountnum;
  	cout<<"\n\n\nEnter account Number: ";
  	cin>>accountnum;
  	int index = -1;
		for(int i = 0; i<maxaccounts; i++){
  		
  		if(accountnum==accNumber[i]){
  			index = i;
		  }
	  }
	  do{
	  	 if(index!=-1){
	 		cout<<setw(30)<<setfill(' ')<<"\n\t\t\t\t\t\tWelcome Sir..\n";
	  		  int accpin;
	  cout<<"Please Enter Your Account Pin: \n";
	  cin>>accpin;
	  do{
	  	if(accpin==pin[accountcounter]){
	  		for(int i = 1 ; i<maxaccounts-1 ;i++){
	 		accNumber[index] = accNumber[index+1]; 
	 		accType[maxaccounts] = accType[maxaccounts+1];
	 		age[index] = age[index+1];
	 		city[index] = city[index+1];	  
	 		initialBalance[index] = initialBalance[index+1]; 
		 }
		 accountcounter--;
			  break;
		  }
		  else{
		  		  	cout<<"Incorrect Password!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accpin;
		  }
	  }while(1);
	 	break;
		 }
		 else{
		 		cout<<"Account didn't found!!!\n\n";
	  	cout<<"Please Enter Again Correctly...\n\n";
	  	cin>>accountnum;
		 }
	  }while(1);
	
	 }

//Other Functions.....
void menu(){
banner9();
    system("color 7"); 
    cout<<"\n\n";
    cout<<setw(32)<<setfill(' ')<<""<<setw(38)<<setfill('_')<<""<<endl;
    cout<<"\n";
	cout<<setw(40)<<setfill(' ')<<"||   1: "<<setw(14)<<setfill(' ')<<"Create Account"<<setw(16)<<setfill(' ')<<"||"<<endl;
	cout<<setw(40)<<setfill(' ')<<"||   2: "<<setw(12)<<setfill(' ')<<"Deposit Cash"<<setw(18)<<setfill(' ')<<"||"<<endl;
	cout<<setw(40)<<setfill(' ')<<"||   3: "<<setw(13)<<setfill(' ')<<"Withdraw Cash"<<setw(17)<<setfill(' ')<<"||"<<endl;
	cout<<setw(40)<<setfill(' ')<<"||   4: "<<setw(13)<<setfill(' ')<<"Check Balance"<<setw(17)<<setfill(' ')<<"||"<<endl;
	cout<<setw(40)<<setfill(' ')<<"||   5: "<<setw(15)<<setfill(' ')<<"Account Details"<<setw(15)<<setfill(' ')<<"||"<<endl;
	cout<<setw(40)<<setfill(' ')<<"||   6: "<<setw(15)<<setfill(' ')<<"Account Closure"<<setw(15)<<setfill(' ')<<"||"<<endl;
	cout<<setw(40)<<setfill(' ')<<"||   7: "<<setw(13)<<setfill(' ')<<"Close Program"<<setw(17)<<setfill(' ')<<"||"<<endl;
	cout<<setw(32)<<setfill(' ')<<""<<setw(38)<<setfill('_')<<""<<endl;
}
void greeting(){
	cout<<setw(20)<<setfill(' ')<<""<<"Welcome to our Bank Sir....\n"<<endl;
	cout<<setw(20)<<setfill(' ')<<""<<"We are Opening Menu for You...."<<endl;
}
void loadingBar() 
{ 

    system("color 0A"); 
    char a = 177, b = 219; 
    cout<<"\n\n\t\t\t\t\t\t Loading...\n\n"; 
    cout<<"\t\t\t\t\t"; 
  
    for (int i = 0; i < 26; i++) {
    	cout<<a; 
	}
    cout<<"\r\t\t\t\t\t"; 
  
    for (int i = 0; i < 26; i++) { 
       cout<<b;
  
        Sleep(200); 
      
    } 
      system("cls");
} 
void countdown(){ 
cout<<setw(40)<<setfill(' ')<<"This tab will be close in 10 Seconds...\n\n";
	        for(int i = 1 ; i<=10 ; i++){
        	cout<<i<<"\t";
        	Sleep(1000);
		}
        system("cls");

}
  void accNumberGenerator(){
  	
  	string temp = "";
  	string temp2 = "4530";
  	string temp3 = "";
  	temp = accType[accountcounter];
  	temp3 = to_string(accountcounter);
   accNumber[accountcounter] = temp+temp2+temp3;
    cout<<"\n\n\t\t\t\t\tYour Account Number is:"<<accNumber[accountcounter]<<endl;
  }


void banner1(){
cout<<"\n\n";
cout<<setw(20)<<setfill(' ')<<""<<"____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n";
cout<<setw(20)<<setfill(' ')<<""<<"\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n";
cout<<setw(20)<<setfill(' ')<<""<<" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n";
cout<<setw(20)<<setfill(' ')<<""<<"  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n";
cout<<setw(20)<<setfill(' ')<<""<<"   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n";
cout<<setw(20)<<setfill(' ')<<""<<"    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n\n\n\n" ; 
 
}
void banner2(){
	cout<<"\n\n";
cout<<setw(20)<<setfill(' ')<<""<<"   _____                _   _                                                 _   \n";
cout<<setw(20)<<setfill(' ')<<""<<"  / ____|              | | (_)                 /\\                            | |  \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |     _ __ ___  __ _| |_ _ _ __   __ _     /  \\   ___ ___ ___  _   _ _ __ | |_ \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |    | '__/ _ \\/ _` | __| | '_ \\ / _` |   / /\\ \\ / __/ __/ _ \\| | | | '_ \\| __|\n";
cout<<setw(20)<<setfill(' ')<<""<<" | |____| | |  __/ (_| | |_| | | | | (_| |  / ____ \\ (_| (_| (_) | |_| | | | | |_ \n";
cout<<setw(20)<<setfill(' ')<<""<<"  \\_____|_|  \\___|\\__,_|\\__|_|_| |_|\\__, | /_/    \\_\\___\\___\\___/ \\__,_|_| |_|\\__|\n";
cout<<setw(20)<<setfill(' ')<<""<<"                                     __/ |                                        \n";
cout<<setw(20)<<setfill(' ')<<""<<"                                    |___/                                         \n";

}
void banner3(){
	cout<<"\n\n";
cout<<setw(20)<<setfill(' ')<<""<<"  _____                       _ _      _____          _     \n";
cout<<setw(20)<<setfill(' ')<<""<<" |  __ \\                     (_) |    / ____|        | |\n";
cout<<setw(20)<<setfill(' ')<<""<<" | |  | | ___ _ __   ___  ___ _| |_  | |     __ _ ___| |__  \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |  | |/ _ \\ '_ \\ / _ \\/ __| | __| | |    / _` / __| '_ \\ \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |__| |  __/ |_) | (_) \\__ \\ | |_  | |___| (_| \\__ \\ | | |\n";
cout<<setw(20)<<setfill(' ')<<""<<" |_____/ \\___| .__/ \\___/|___/_|\\__|  \\_____\\__,_|___/_| |_|\n";
cout<<setw(20)<<setfill(' ')<<""<<"             | |                                            \n";
cout<<setw(20)<<setfill(' ')<<""<<"             |_|                                            \n";

}
void banner4(){
	cout<<"\n\n";
cout<<setw(20)<<setfill(' ')<<""<<" __          ___ _   _         _                       _____          _     \n";
cout<<setw(20)<<setfill(' ')<<""<<" \\ \\        / (_) | | |       | |                     / ____|        | |    \n";
cout<<setw(20)<<setfill(' ')<<""<<"  \\ \\  /\\  / / _| |_| |__   __| |_ __ __ ___      __ | |     __ _ ___| |__  \n";
cout<<setw(20)<<setfill(' ')<<""<<"   \\ \\/  \\/ / | | __| '_ \\ / _` | '__/ _` \\ \\ /\\ / / | |    / _` / __| '_ \\ \n";
cout<<setw(20)<<setfill(' ')<<""<<"    \\  /\\  /  | | |_| | | | (_| | | | (_| |\\ V  V /  | |___| (_| \\__ \\ | | |\n";
cout<<setw(20)<<setfill(' ')<<""<<"     \\/  \\/   |_|\\__|_| |_|\\__,_|_|  \\__,_| \\_/\\_/    \\_____\\__,_|___/_| |_|\n";

}
void banner5(){
	cout<<"\n\n";
cout<<setw(20)<<setfill(' ')<<""<<"   _____ _               _      ____        _                      \n";
cout<<setw(20)<<setfill(' ')<<""<<"  / ____| |             | |    |  _ \\      | |                     \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |    | |__   ___  ___| | __ | |_) | __ _| | __ _ _ __   ___ ___ \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |    | '_ \\ / _ \\/ __| |/ / |  _ < / _` | |/ _` | '_ \\ / __/ _ \\ \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |____| | | |  __/ (__|   <  | |_) | (_| | | (_| | | | | (_|  __/\n";
cout<<setw(20)<<setfill(' ')<<""<<"  \\_____|_| |_|\\___|\\___|_|\\_\\ |____/ \\__,_|_|\\__,_|_| |_|\\___\\___|\n";

}
void banner6(){
	cout<<"\n\n";
cout<<setw(20)<<setfill(' ')<<""<<"                                          _     _____         _          _  _      \n";
cout<<setw(20)<<setfill(' ')<<""<<"     /\\                                  | |   |  __ \\       | |        (_)| |     \n";
cout<<setw(20)<<setfill(' ')<<""<<"    /  \\    ___  ___  ___   _   _  _ __  | |_  | |  | |  ___ | |_  __ _  _ | | ___ \n";
cout<<setw(20)<<setfill(' ')<<""<<"   / /\\ \\  / __|/ __|/ _ \\ | | | || '_ \\ | __| | |  | | / _ \\| __|/ _` || || |/ __|\n";
cout<<setw(20)<<setfill(' ')<<""<<"  / ____ \\ |(__  (__  (_) || |_| || | | || |_  | |__| ||  __/| |_  (_| || || |\\__ \\ \n";
cout<<setw(20)<<setfill(' ')<<""<<" /_/    \\_\\\\___|\\___|\\___/  \\__,_||_| |_| \\__| |_____/  \\___| \\__|\\__,_||_||_||___/\n";

}
void banner7(){
	cout<<"\n\n";
  cout<<setw(20)<<setfill(' ')<<""<<"                                        _     _____                                         _ \n";
 cout<<setw(20)<<setfill(' ')<<""<<"    /\\                                  | |   |  __ \\                                       | |\n";
 cout<<setw(20)<<setfill(' ')<<""<<"   /  \\    ___  ___  ___   _   _  _ __  | |_  | |__) | ___  _ __ ___    ___ __   __ ___   __| |\n";
 cout<<setw(20)<<setfill(' ')<<""<<"  / /\\ \\  / __|/ __|/ _ \\ | | | || '_ \\ | __| |  _  / / _ \\| '_ ` _ \\  / _ \\\\ \\ / // _ \\ / _` |\n";
 cout<<setw(20)<<setfill(' ')<<""<<" / ____ \\  |(__ (__| (_) || |_| || | | || |_  | | \\ \\|  __/| | | | | || (_) |\\ V /|  __/| (_| |\n";
 cout<<setw(20)<<setfill(' ')<<""<<"/_/    \\_\\\\___|\\___|\\___/  \\__,_||_| |_| \\__| |_|  \\_\\\\___||_| |_| |_| \\___/  \\_/  \\___| \\__,_|\n";
                                                                                                
}                                                                                          
void banner8(){
	cout<<"\n\n";
cout<<setw(20)<<setfill(' ')<<""<<"  _____                                             ______             _            _             \n";
cout<<setw(20)<<setfill(' ')<<""<<" |  __ \\                                           |  ____|           | |          | |            \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |__) |_ __  ___    __ _  _ __  __ _  _ __ ___   | |__    _ __    __| |  ___   __| |            \n";
cout<<setw(20)<<setfill(' ')<<""<<" |  ___/| '__|/ _ \\  / _` || '__|/ _` || '_ ` _ \\  |  __|  | '_ \\  / _` | / _ \\ / _` |            \n";
cout<<setw(20)<<setfill(' ')<<""<<" | |    | |  | (_) || (_| || |  | (_| || | | | | | | |____ | | | || (_| ||  __/| (_| | _  _  _  _ \n";
cout<<setw(20)<<setfill(' ')<<""<<" |_|    |_|   \\___/  \\__, ||_|   \\__,_||_| |_| |_| |______||_| |_| \\__,_| \\___| \\__,_|(_)(_)(_)(_)\n";
cout<<setw(20)<<setfill(' ')<<""<<"                      __/ |                                                                       \n";
cout<<setw(20)<<setfill(' ')<<""<<"                     |___/                                                                        \n";
}
void banner9(){
	cout<<"\n\n";                                                                
cout<<setw(20)<<setfill(' ')<<""<<"     ______  _______        ______    _____   ______    ____   ____ \n";
cout<<setw(20)<<setfill(' ')<<""<<"    |      \\/       \\   ___|\\     \\  |\\    \\ |\\     \\  |    | |    |\n";
cout<<setw(20)<<setfill(' ')<<""<<"   /          /\\     \\ |     \\     \\  \\    \\| \\     \\ |    | |    |\n";
cout<<setw(20)<<setfill(' ')<<""<<"  /     /\\   / /\\     ||     ,_____/|  \\|    \\  \\     ||    | |    |\n";
cout<<setw(20)<<setfill(' ')<<""<<" /     /\\ \\_/ / /    /||     \\--'\\_|/   |     \\  |    ||    | |    |\n";
cout<<setw(20)<<setfill(' ')<<""<<"|     |  \\|_|/ /    / ||     /___/|     |      \\ |    ||    | |    |\n";
cout<<setw(20)<<setfill(' ')<<""<<"|     |       |    |  ||     \\____|\\    |    |\\ \\|    ||    | |    |\n";
cout<<setw(20)<<setfill(' ')<<""<<"|\\____\\       |____|  /|____ '     /|   |____||\\_____/||\\___\\_|____|\n";
cout<<setw(20)<<setfill(' ')<<""<<"| |    |      |    | / |    /_____/ |   |    |/ \\|   ||| |    |    |\n";
cout<<setw(20)<<setfill(' ')<<""<<" \\|____|      |____|/  |____|     | /   |____|   |___|/ \\|____|____|\n";
cout<<setw(20)<<setfill(' ')<<""<<"    \\(          )/       \\( |_____|/      \\(       )/      \\(   )/  \n";
cout<<setw(20)<<setfill(' ')<<""<<"     '          '         '    )/          '       '        '   '   \n";
cout<<setw(20)<<setfill(' ')<<""<<"                               '                                    \n";

                                                    

                                                                   
}