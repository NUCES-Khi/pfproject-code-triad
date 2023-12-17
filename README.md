E-Store Management System
Introduction
The E-Store Management System is a simple command-line application developed in C. It serves as a basic electronic store, allowing users to operate either as customers or employees. The project includes functionalities such as user authentication, product management, and customer account management.

Team Members
Hamza Sheikh
Syed Muneeb ur Rehman
Yesaullah Sheikh
Batch and Department
Batch: 2023
Department: BAI-1A
Project Overview
The E-Store Management System is designed to provide a user-friendly interface for customers and employees to interact with the electronic store. The program includes the following main features:

For Employees
Login: Employees can log in using their credentials.
View Items: Employees can view the available items in the store.
Add Product: Employees can add a new product to the store.
Delete Product: Employees can remove a product from the store.
View Customers: Employees can view details of all registered customers.
For Customers
Authentication:
Log In: Existing customers can log in with their credentials.
Sign Up: New customers can create an account by providing necessary details.
Functionality:
View Items: Customers can view the available items in the store.
Buy Item: Customers can purchase items, and the corresponding balance is updated.
View Balance: Customers can check their account balance.
Withdraw/Deposit Money: Customers can manage their account balance.
How to Run
Open the terminal or command prompt.
Navigate to the directory containing the project files.
Compile the program using a C compiler (e.g., gcc).
bash
Copy code
gcc e_store_management.c -o e_store_management
Run the executable.
bash
Copy code
./e_store_management
Important Notes
The program utilizes CSV files (Stock.csv, Employee.csv, and Costumer.csv) to store data. Make sure these files are present in the same directory as the executable.
Ensure that the necessary C libraries (stdio.h, string.h, windows.h, unistd.h) are available in your environment.
Screenshots
Include screenshots or GIFs demonstrating the program's functionality.

Future Improvements
Implement secure password handling and storage.
Enhance error handling and input validation.
Improve user interface and provide more informative prompts.
Conclusion
The E-Store Management System project provides a foundation for a basic electronic store management application. It demonstrates fundamental programming concepts such as file handling, user authentication, and data manipulation. The project can be extended and enhanced for more sophisticated e-commerce solutions.
