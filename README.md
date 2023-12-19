# E-Store Management System

## Introduction
The E-Store Management System is a simple command-line application developed in C. It serves as a basic electronic store, allowing users to operate either as customers or employees. The project includes functionalities such as user authentication, product management, and customer account management.

## Team Members
- Hamza Sheikh
- Syed Muneeb ur Rehman
- Yesaullah Sheikh

## Individual Contribution
* Yesaullah Sheikh
  - Log-in
  - Sign-up
  - int main()
  - Interface
  - Formatting
* Syed Muneeb Ur Rehman
  - Stock (Filling , Struct & Updating) Functions
  - Employee (Filling , Struct & Updating) Functions
  - Costumer (Filing , Struct & Updating) Functions
* Hamza Sheikh
  - All Purchasing Functions
  - Adding and Updating Stock Functions
  - All Depositing and Withdrawing Functions

## Batch and Department
- Batch: 2023
- Department: BAI-1A

## Project Overview
The E-Store Management System is designed to provide a user-friendly interface for customers and employees to interact with the electronic store. The program includes the following main features:

### For Employees
1. **Login:** Employees can log in using their credentials.
2. **View Items:** Employees can view the available items in the store.
   - Edit Product:
        * Increase Quantity
        * Decrease Quantity
   - Add Product: Employees can add a new product to the store.
   - Delete Product: Employees can remove a product from the store.
4. **View Customers:** Employees can view details of all registered customers.

### For Customers
1. **Authentication:**
   - Log In: Existing customers can log in with their credentials.
   - Sign Up: New customers can create an account by providing necessary details.
2. **Functionality:**
   - View Items: Customers can view the available items in the store.
   - Buy Item: Customers can purchase items, and the corresponding balance is updated.
   - View Balance: Customers can check their account balance.
   - Withdraw/Deposit Money: Customers can manage their account balance.

## Project Overview
This project aims to create a user-friendly C-language program for the management system of an E-store. The program caters to both the employees and the customers. For customers, it offers functionalities such as login/signup options, viewing items available in the store, buying items, and viewing the account balance. The user also gets to submit or withdraw money from his account. As for the employees, first, they will be asked to log in to the system, then they can view items in the store, add items, update the already present items, and they can also choose to view all the customers who have signed up for the e-store. Exception handling is added where it had to be added to make the code more efficient.

## Data Structures
- Structs are used to store details about the items, the employees, and the customers.
- Arrays are used to store data related to these structures.
- File pointers are used to open files for reading and writing purposes.

## Major Problems Faced
File handling was the most major problem for us while writing this code. We did not know much about filing when we started with this project hence, at the start, we were unable to make use of filing quite efficiently. Error handling, which also included references to files was yet another major problem we faced. For example, checking if someone does not have enough account balance then he must not be able to buy anything. However, we overcame these problems by listening to YouTube lectures, online websites and the course books available on Google Classroom.

## Logic Used
The code is divided into several different parts. The structures are defined at the start of the code, and then the user-defined functions are declared, after which the main functions start. The arrays of structure’s types are declared to store data. Based on the user inputs it is decided how and in what sequence the code will run. The code makes use of several nested if statements and takes inputs from the user to determine what the user intends to do with the program. Error messages are printed in case any error is faced, and suitable prompts are output in certain cases. System cls() and sleep() functions are used at certain places in the code to make the interface more user-friendly. Moreover, there are 20 user-defined functions which are defined for different functionalities.

## Possible Improvements
In the future, it's our goal to add efficient ways through which our customers can purchase items we want to add a cart system before checking out, this way they can keep track of their bill and will be able to remove any unwanted item. For Employees, we want a way to update the names, prices of any items this way they can give more or less discount as they please. We also aim to change how the program recommends products to the customer and keep track of all the previous purchases made by a customer.
