# Bank Application 

This application is a C based application which gives users various functionalities such as creating a Bank account from the List of Nationalized, State and Private Sector Banks registered across India,  Registering the user’s UPI Handle - which is a necessary requirement for money transfers on payment apps,  Bank operations -- Cash Withdrawal and Cash Deposit,  Generation of UPI Handle ID  (address which identifies the user on UPI; typically yourname@bankname). The application also allows multiple Bank account creations and UPI handle registrations,  and displays specified account information on command. 

## Description

1)	The application heavily focuses on the usage of Structures, String and Arithmetic operations for various functionalities, along with the usage of File Reading from text files to display List of Banks + States in India and the windows.h C library for Sleep() function. 
2)	Various options are presented to the user and executed using Switch Case.
3)	One structure is defined for storing Bank Account details such as name, bank, state, account number, address, IFSC code, etc. The application redirects user to the official RBI page to obtain the bank specific IFSC code. Details are stored in a created instance of the structure and can be retrieved when specified.
4)	The second structure is defined for storing UPI Handle details such as name, bank, account number, phone number, username and password.
5)	The application also allows Bank Operations, and user can deposit or withdraw specified amounts into their respective Bank accounts. The amount of cash exchange is computed using basic C arithmetic operations.  
6)	User can also check their Bank Account information by specifying the account number which displays all necessary details, or view their UPI handle details generated by the application. 
7)	Once the operations are done, user can choose to Exit the application or Return back 
          to the Options page. 

