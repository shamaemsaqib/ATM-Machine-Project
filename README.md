
# Automatic Teller Machine (ATM)

### ABSTRACT

The ATM System is the project which is used to access their bank accounts in order to make cash withdrawals. Whenever the user need to make cash withdraws, they can enter their PIN number (personal identification number) and it will display the amount to be withdrawn in the form of 50’s,100’s and 500’s. Once their withdrawn was successful, the amount will be debited in their account.

The ATM will service one customer at a time. A customer will be required to enter ATM Card number, personal identification number (PIN) – both of which will be sent to the database for validation as part of each transaction. The customer will then be able to perform one or more transactions. Also customer must be able to make a balance inquiry of any account linked to the card. The ATM will provide the customer with a printed receipt for each successful transaction, showing the date, time, machine location, type of transaction, account(s), amount, and ending and available balance(s) of the affected account (“to” account for transfers).

### Introduction:

Automated Teller Machine enables the clients of a bank to have access to their account without going to the bank. This is achieved only by development the application using online concepts. When the product is implemented, the user who uses this product will be able to see all the information and services provided by the ATM, when he enters the necessary option and arguments. The product also provides services like request for cheques, deposit cash and other advanced requirement of the user. The data is stored in the database and is retrieved whenever necessary. The implementation needs ATM machine hardware to operate or similar simulated conditions can also be used to successfully use the developed product.

### Objectives of ATM:

Our main objective is to speed up the transactions done by customers. No manual transactions needed generally. The second objective is to save the time which is very important now-a-days. It will include other objectives such as:

* To render accurate services to customer.
* The reduction of fraudulent activities
* To achieve speedy processing of customer data
* To reduce error processing, the guarantee of increase security
### Advantages:

This system provides paperless maintenance. Initially a cashier or an clerk can be appointed to do all the transaction and update and maintain records. In the new system the customer himself can do all the transaction and the computerized system automatically updates and maintains the records.

* Less effort to complete transaction.
* Less time required.
* No need to maintain the bulk of papers.

### Project Working:

In order to develop an Automatic Teller Machine, following classes are implemented:

1. ATM
2. Basic Unit ATM
3. Complex ATM
4. User
5. Bank Account
6. Saving Account
7. Checking Account
8. 8. Card

The class **Card** have the following attributes:
* CardNumber (int)
* PIN (int)
* A function that will automatically generate a card number for the user using rand function.

The class **BankAccount** have the following private attributes:
* BankName (char\*)
* Branch (char\*)
* TotalCash (float)

The class **SavingAccount** which is derived from the class **BankAccount** have the following private attributes:
* interestRate(float)
* A function to calculate the interest.

The class **CheckingAccount** which is derived from the class **BankAccount** have the following private attributes:
* fee per transaction(float)

The class **User** that has a **BankAccount** (saving or cheking), **Card** and some of the basic information of a person involving
* Name (char\*)
* PhoneNumber (int\*)
* Address (char\*)

The class **ATM** has a **User** and can perform the following tasks:
* Take input (Card\_number and PIN) from user.
* Validate the Card number and pin entered by user.

The class **BasicATM** which is derived from the class **ATM** can perform the following operations:
* Display the following menu to the user after taking input and validate it.

**Select your transaction**
1. Press “1” to withdrawal
2. Press “2” to display information

The class **ComplexATM** which is derived from the class **ATM** can perform the following operations:
* Display the following menu to the user after taking input and validate it.

**Select your transaction**
1. Press “1” to withdrawal
2. Press “2” for balance inquiry
3. Press “3” to transfer money
4. Press “4” to change your PIN
5. Press “5” to display information

**Overloaded the following operators**
* For withdrawal, overloaded the unary operator –
* For balance inquiry, overloaded the unary operator \*
* For transfer money, overload the operator %
* To change the pin, overload the operator ^
* To take input, overload the insertion operator >>
* To display information, overload the extraction operator <<
