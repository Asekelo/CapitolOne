#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Admin.h"
#include "Banker.h"
#include "Customer.h"
#include "ATM.h"
#include "Audit.h"
#include <vector>

using namespace std;

// Declare global variables 
ifstream acct_in;
ofstream acct_out;

int  *nullptr = NULL;

// Function Prototype for 'Main Menu' function  - the main loop of the program
// (Called from the 'Main' function)
void main_menu(Customer* all_customers, Admin* all_admin, Banker* all_bankers, int* num_of_cust, int* num_of_bankers, int* num_of_admin);



// Main Menu function definition *******************************************************************
void main_menu(Customer* all_customers, Admin* all_admin, Banker* all_bankers, int* num_of_cust, int* num_of_bankers, int* num_of_admin) 
{
	int admins = 0, bankers = 0, user = -1, client_id, security_code, comma, comma_next, bday, bmon, byear, i, clients, count = 0;
	string password, PW_string, FNAME, LNAME, STREET, CITY, STATE;
    double checking, saving;
    
    // Vector used to store entered data  
    vector<int> vID;
    vector<int> vSORT_ID;
    vector<int> vTRACK_ID;
    vector<int>::iterator vIter;
    vector<int>::iterator vIter_next;
    vector<int>::iterator vSort_Iter;
    vector<int>::iterator vTrack_Iter;
    
    
	string all_records[100];
	  
    acct_in.open("account_record.txt");       // Open accounts file containing all
                                              // account records
   	string decrypt = "";
	string line = "";
	
	if (acct_in.is_open()) 
    {
	   // Key code value for decryption
       int key = 128;
                
       i = 0;
       
       // Read in all user account records and populate class arrays.
       while( getline(acct_in, all_records[i]))  
       {                                     
    
           // Decrypt record data from accounts file.
           line = all_records[i];
           
	       for(int l = 0; l < line.length(); l++) 
           {    
		   		decrypt += line[l] ^ (char)key;
           }
           
           all_records[i] = decrypt;
           
           /* 
           Source reference: basic_istream::operator >> 
           CPlusplus.com - C++ Reference
           http://www.cplusplus.com/reference/istream/basic_istream/operator%3E%3E/
    
           Purpose: Use of stringstream for syntax to convert string to integer
           */  
                       
           // Sort through each record for data (comma delimited file) ****************
           stringstream ID_string(decrypt.substr(0, 4));
           comma = decrypt.find(",",0,1);
           comma_next = decrypt.find(",",comma+1,1);
           PW_string = decrypt.substr(comma+1, comma_next - (comma+1));
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           stringstream SEC_string(decrypt.substr(comma+1, comma_next - (comma+1)));
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           FNAME = decrypt.substr(comma+1, comma_next - (comma+1));
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           LNAME = decrypt.substr(comma+1, comma_next - (comma+1)); 
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           STREET = decrypt.substr(comma+1, comma_next - (comma+1));                     
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           CITY = decrypt.substr(comma+1, comma_next - (comma+1));
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           STATE = decrypt.substr(comma+1, comma_next - (comma+1)); 
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           stringstream BDAY_string(decrypt.substr(comma+1, comma_next - (comma+1)));
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           stringstream BMON_string(decrypt.substr(comma+1, comma_next - (comma+1)));
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           stringstream BYEAR_string(decrypt.substr(comma+1, comma_next - (comma+1)));
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           stringstream CHECK_string(decrypt.substr(comma+1, comma_next - (comma+1)));           
           comma = comma_next;
           comma_next = decrypt.find(",",comma+1,1);
           stringstream SAV_string(decrypt.substr(comma+1, 13));           
                   
           /* 
           Source reference: basic_istream::operator >> 
           CPlusplus.com - C++ Reference
           http://www.cplusplus.com/reference/istream/basic_istream/operator%3E%3E/
    
           Purpose: Use of stringstream for syntax to convert string to integer
           */                    
                                        
           // Integer and floating point element conversions from string data types:
           ID_string >> client_id; 
           SEC_string >> security_code;
           BDAY_string >> bday;
           BMON_string >> bmon;
           BYEAR_string >> byear;
           CHECK_string >> checking; // (type double)
           SAV_string >> saving;     // (type double)
           
           /*
           Other string record elements:
                 PW_string: password
                 FNAME: first name
                 LNAME: last name
                 STREET: street address
                 CITY: customer city
                 STATE: customer state
           */      
           

           // Store values in class array pointer for all accounts.
           all_customers -> setID(client_id);
           all_customers -> setAccountPassword(PW_string);
           all_customers -> setSecurity(security_code);
           all_customers -> setFullName(FNAME, LNAME);
           all_customers -> setAddress(STREET + ", " + CITY + ", " + STATE);
           all_customers -> setBirthDate(bday, bmon, byear);
           all_customers -> setChecking(checking);
           all_customers -> setSaving(saving);
           
           all_customers++;   // Increment "accounts array" for all customers
           
           // Store values in class array pointer for all Bankers
           if(security_code == 1)
           {
              all_bankers -> setID(client_id);
              all_bankers -> setAccountPassword(PW_string);
              all_bankers++;
              bankers++;
              
           }
           
           // Store values in class array pointer for all Adminstrators
           if(security_code == 2)
           {
              all_admin -> setID(client_id);
              all_admin -> setAccountPassword(PW_string);
              all_admin++;
              admins++;
              
           }           
           
           // Enter Client ID into vector data structure for 'sorting'
           vID.push_back(client_id);
           vSORT_ID.push_back(client_id);
           vTRACK_ID.push_back(client_id);
           
              
           decrypt = "";
           i++;  // Increment main tracker counter for all accounts
                
                
       } // End of 'while' loop (Reading in and Storing all user account records) 
    
    }
   	else 
    {
		cout << "Unable to find customer accounts file.\n\n" << endl;
		system("PAUSE");
		return;
	}
	
    // Store account tracker values
    *num_of_cust = i;  
    *num_of_bankers = bankers;
    *num_of_admin = admins;

    
    // Close account file: "account_record.txt"    
    acct_in.close();  
    
    
    /*
    for(vIter = vID.begin(); vIter < vID.end(); vIter++)
    {

       cout << "#" << count + 1 << " " << *vIter << endl;
       count++;   
    }
    
    cout << "\n" << i << "\n\n";
    system("PAUSE");
    
    */
    
    count = 0;
    
    // Sort Routine ****************************************
    int change = 0, DONE = 0;
    vIter = vID.begin();
    vSort_Iter = vSORT_ID.begin();
    vTrack_Iter = vTRACK_ID.begin();
    
    do
    {
                 
       vIter = vID.begin();
       vSort_Iter = vSORT_ID.begin();
       vIter++;
       vIter_next = vIter;
       vIter--;
       
       for(clients = 0; clients < i - 1; clients++)
       {
          // vIter_next = vIter;
          if (*vIter > *vIter_next)
          {
             // Swap values        
             *vSort_Iter = *vIter_next;
             vSort_Iter++;
             *vSort_Iter = *vIter;
             vSort_Iter--;
             
             // Copy updated values back
             *vIter = *vSort_Iter;
             vIter++;
             vSort_Iter++;
             *vIter = *vSort_Iter;
             
             
             change++;
             // vIter++;
             // vSort_Iter++;
             vIter_next++;
          }
          else
          {
             vIter++;
             vSort_Iter++;
             vIter_next++;
          }
       
       
       }
              
       if(change == 0)
       {
          *vIter = *vSort_Iter;
          DONE = 1; 
       } 
          
       change = 0;     
    
    } while(!DONE);
    // End of Sort process ***********************************
    
    
    acct_out.open("account_record.txt"); // Open accounts file containing all account records    
    
   	string message;
	string encrypt;
	
	// Key code value for encryption
    int key = 128;
     
     
    // Write sorted records to encrypted accounts file. ******************
    for(vIter = vID.begin(); vIter < vID.end(); vIter++)
    {              
       vTrack_Iter = vTRACK_ID.begin();
       
       message = "";
       encrypt = "";               
       
       for(clients = 0; clients < i; clients++)
       {         
          message = all_records[clients];
       
          if(*vIter == *vTrack_Iter) // Check sorted ID's against the ID tracker 
          {                          // that contains all of the unsorted ID's      
                              
             for (int l = 0; l < message.length(); l++) 
             {
		         encrypt += message[l] ^ (char)key;
             }
             
             // Write encrypted data to accounts file             
             acct_out << encrypt << endl;
             encrypt = "";  
          
          }                               
          vTrack_Iter++;
         
       }
       
    } // End of writing sorted account data ********************
    
    acct_out.close();
     
    return;


}


int main() // Program entry point ************************************************************
{
    // Initialize counters to track the number of accounts
	int number_of_customers = 0, number_of_bankers = 0, number_of_admin = 0;

    // For user input from the main menu
    int client_id, user = -1, PASS = 0;
    string password, client;  
    
    // Create generic class
    User* userPtr;
    
	// Create class array for all users (EVERYBODY HAS AN ACCOUNT) 
    Customer all_customers[100];
	Customer* customers;
	customers = &all_customers[0];
	
	// Create class array for all administrator accounts (Only 10 accounts max)
    Admin all_admin[10];
	Admin* admins;
	admins = &all_admin[0];

	// Create class array for all banker accounts (Only 20 accounts max)
    Banker all_bankers[20];
	Banker* bankers;
	bankers = &all_bankers[0];
	
	
    // ********************************************************************
	// ********************************************************************
    // Go to Main Menu and upload all account information into User classes
    // ********************************************************************
    // ******************************************************************** 	
	main_menu(all_customers, all_admin, all_bankers, &number_of_customers, &number_of_bankers, &number_of_admin);
	
	
    system("CLS");   
    	
	// Login screen *************************
	cout << "\n\n\n                       ===== Capitol One ATM ====="
		 << "\n"                
		 << "\n                             Login ID: ";
	cin >> client;

    cout << "\n\n                             Password: ";
    cin >> password;
    
    
    /* 
    Source reference: basic_istream::operator >> 
    CPlusplus.com - C++ Reference
    http://www.cplusplus.com/reference/istream/basic_istream/operator%3E%3E/
    
    Purpose: Use of stringstream for syntax to convert string to integer
    */      
    
    stringstream ID_string(client);  // Convert to integer 
    ID_string >> client_id;
 
 
    // Verify Customer input ***************************************************
    for (int cnt=0; cnt < number_of_customers; cnt++)
    {
        if (all_customers[cnt].getID() == client_id && all_customers[cnt].getAccountPassword() == password)
            user = cnt;
         
    }
    
    
    // Re-enter information if the ID and Password are INCORRECT ****************
    if (user == -1)
    {
       cout << "\n\n                     Login ID or Password is incorrect.\n\n";
       system("PAUSE");
       
       do
       {
 
	         system("CLS"); 
             fflush(stdin);  
    	
	         // Login screen *************************
             cout << "\n\n\n                       ===== Capitol One ATM ====="
		          << "\n"                
		          << "\n                             Login ID: ";
	              cin >> client;
	        
             cout << "\n\n                             Password: ";
             cin >> password;
             
             stringstream ID_string(client);
             ID_string >> client_id;
        
             // Verify Customer input again *****************
             for (int cnt=0; cnt < number_of_customers; cnt++)
             {
                 if (all_customers[cnt].getID() == client_id && all_customers[cnt].getAccountPassword() == password)
                 {
                    user = cnt;
                    PASS = 1;
                 }
             } // End of For loop
             
             if (user == -1)
             {
                cout << "\n\n                     Login ID or Password is incorrect.\n\n";
                system("PAUSE");
                // fflush(stdin);
             }
             
       } while (!PASS);
       
    }  // End of "IF" block (Re-entry block)
    
    
    if (all_customers[user].getSecurity() == 0 || all_customers[user].getSecurity() == 1)
    {
       customers = &all_customers[user];
       atmMenu(all_customers[user].getSecurity(), customers);
       saveLogin(all_customers[user].getAccountName(), all_customers[user].getAccountPassword(), "true");
	
    }
    
    if (all_customers[user].getSecurity() == 2)
	{
          userPtr = &all_customers[user];                                
          auditMenu(userPtr -> getSecurity());
          
    }

	// system("PAUSE");	
	
	
	return 0;
}
