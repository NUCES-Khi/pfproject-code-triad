# E-Store Management System

## Introduction
The E-Store Management System is a simple command-line application developed in C. It serves as a basic electronic store, allowing users to operate either as customers or employees. The project includes functionalities such as user authentication, product management, and customer account management.

## Team Members
- Hamza Sheikh
- Syed Muneeb ur Rehman
- Yesaullah Sheikh

## Batch and Department
- Batch: 2023
- Department: BAI-1A

## Project Overview
The E-Store Management System is designed to provide a user-friendly interface for customers and employees to interact with the electronic store. The program includes the following main features:

### For Employees
1. **Login:** Employees can log in using their credentials.
2. **View Items:** Employees can view the available items in the store.
   - Add Product: Employees can add a new product to the store.
   - Delete Product: Employees can remove a product from the store.
3. **View Customers:** Employees can view details of all registered customers.

### For Customers
1. **Authentication:**
   - Log In: Existing customers can log in with their credentials.
   - Sign Up: New customers can create an account by providing necessary details.
2. **Functionality:**
   - View Items: Customers can view the available items in the store.
   - Buy Item: Customers can purchase items, and the corresponding balance is updated.
   - View Balance: Customers can check their account balance.
   - Withdraw/Deposit Money: Customers can manage their account balance.

## How to Run
1. Open the terminal or command prompt.
2. Navigate to the directory containing the project files.
3. Compile the program using a C compiler (e.g., `gcc`).
   ```bash
   gcc e_store_management.c -o e_store_management
