/*
	|	|	|	|	|	|	|	*** PROGRAMMING FUDAMENTALS SEMESTER FINAL PROJECT ***	|	|	|	|	|	|	|
									
	Names: Hamza Sheikh, Syed Muneeb ur Rehman, Yesaullah Sheikh.
	Batch: 2023
	Department: BAI-1A
	Topic: E-Store management system.
	Description:    1) The program first asks if the user is a Customer or an Employee, it also provides an option to exit the program
					2) If the user is an employee: 
						--> Program asks for Employee credentials
						--> Three options are provided 
							1) Exit
							2) View items
								--> User can then either add a product, update a product or exit the program
							3) View Customers
								--> All the customer details are printed on the screen.
					3) If the user is a customer.
						--> He can either choose to log-in or sign-up
						--> If he chooses to log-in:
							1) User credentials are asked
							2) User can then either view any item, buy any item or view his balance
							3) Based on the user's choice, the user can also make changes to his balance.
						--> If he chooses to sign-up:
							1) Program asks for the credentials and adds them to the respective file.
*/
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>

int N_stock;
int N_Employee;
int N_Costumer;


//Stock Struct
struct Stock
{
    int Icode;
    char Iname[20];
    int Iprice;
    int Iqtt;
    char Icat;
};
//Employee Struct
struct Employee
{
    int Emp_ID;
    char Emp_Name[20];
    char Emp_Pass[20];
};

//Costumer Struct
struct Costumer
{
    char User_Name[20];
    char Password[20];
    int Balance;
};

// User defined functions used in this Program
int LinesCheck(FILE *file);
int Read_Stock(struct Stock item[], FILE *stock, int Lines);
void Print_Stock(struct Stock item[], int Lines);
int Read_Emp(struct Employee List_Employee[], FILE *file);
void Print_Emp(struct Employee List_Employee[], int n);
char *Emplyee_LOGIN(struct Employee List_Employee[]);
int Read_Costumer(struct Costumer user[], FILE *file);
void Print_Costumer(struct Costumer user[], int n);
void Print_All_Customers();
void Add_Costumer();
int *Check_Costumer(struct Costumer user[]);
void Write_Costumer(struct Costumer user[], int n);
void Number_Check();
void buyItem(struct Costumer user[], int n, struct Stock item[], int m);
void viewBalance(struct Costumer user[], int n);
void withdrawMoney(struct Costumer user[], int n);
void depositMoney(struct Costumer user[], int n);
void Add_Product(struct Stock item[], int *n);
void Delete_Product(struct Stock item[], int *n);
void Increase_Quantity(struct Stock item[], int n);
void Reduce_Quantity(struct Stock item[], int n);

//start main 
int main() {
    system("cls"); 		//this will clear the screen
    struct Costumer user[N_Costumer]; 		//struct array declaration
    Number_Check();
    FILE *stock; 		//file pointer for stocks file
    stock = fopen("Stock.csv", "r"); 		//opening stock.csv file in read mode
    struct Stock item[N_stock]; 		//struct array declaration
    if (Read_Stock(item, stock, N_stock) == 0) {
        return 1;
    }
    fclose(stock);

    FILE *Emp; 		// file pointer for employee.csv
    Emp = fopen("Employee.csv", "r"); 		//opening employee.csv in read mode 
    struct Employee Employees[N_Employee]; 		//struct array declaration
    if (Read_Emp(Employees, Emp) == 0) {
        return 1;
    }
    fclose(Emp); 		//closing file

    int ACT = 0;
    while (1) {
        printf("\t\t\t\n\n");
        // printf("\t\t\t                           _^_\n");
        printf("\t\t\t                          _____\n");
        printf("\t\t\t                         //   \\\\\n");
    	printf("\t\t\t                        //     \\\\\n");
    	printf("\t\t\t                       //       \\\\\n");
    	printf("\t\t\t      ________________//_________\\\\________________\n");
    	printf("\t\t\t     |               ||           ||               |\n");
    	printf("\t\t\t     |    \033[1;3;33;5mWELCOME\033[0m    ||    \033[1;3;33;5mTO\033[0m     ||     \033[1;3;33;5mESTORE\033[0m    |\n");
    	printf("\t\t\t     |               ||           ||               |\n");
    	printf("\t\t\t     |               ||           ||               |\n");
    	printf("\t\t\t     |      _______  ||    ___    ||  _______      |\n");
    	printf("\t\t\t     |     |       | ||   |   |   || |       |     |\n");
    	printf("\t\t\t     |     |       | ||   |   |   || |       |     |\n");
   		printf("\t\t\t     |     |_______| ||___|___|___|| |_______|     |\n");
    	printf("\t\t\t     |_______|_______||___________||_______|_______|\n");
    	printf("\t\t\t     /=============================================\\\n");
    	printf("\t\t\t    /===============================================\\\n");
		sleep(2);
    	printf("\033[33m");
    	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    	printf("\033[0m");
        printf("\033[33m------------------------------------\033[m\n--> Press '0' to exit the program.\n--> Press '1' if you are an Employee.\n--> Press '2' if you are a Customer.\n------------------------------------\n\n");
        printf("\033[33m");
		printf("------------------------------------\n");
		printf("\033[0m");
		printf("--> Enter your choice: "); 			//Taking input for the users choice 
        scanf("%d", &ACT);
        printf("\033[33m");
        printf("------------------------------------\n");
        printf("\033[0m");
		system("cls");
		//cheking if the user wants to exit the program
        if (ACT == 0){ 		
        printf("\n**YOU HAVE SUCCESSFULLY EXITED THE PROGRAM**");
        break;
		}   
        //Login as Employee;
        if (ACT == 1) {
            system("cls"); 
            printf("\n");
            printf("\t * Welcome %s *\n\n", Emplyee_LOGIN(Employees));
            printf("--> Press '0' to exit the program.\n--> Press '1' if you want to view any item.\n--> Press '2' if you want to view customers.\n\n");
            getchar();
			printf("--> Enter your choice: ");
            char key_3;
            scanf(" %c", &key_3);
            system("cls"); 
			//cheking if the user wants to exit the program
            if (key_3 == '0') {
            	printf("\n**YOU HAVE SUCCESSFULLY EXITED THE PROGRAM**");
                exit(1);
            }
            //	IF THE USERS WANTS TO VIEW ITEMS
				else if (key_3 == '1') {
                Print_Stock(item, N_stock);
                printf("\n\n--> Press '0' to exit the program.\n--> Press '1' if you want to update a product.\n--> Press '2' if you want to add a product.\n\n");
                getchar();
				printf("--> Enter your choice: ");
                char key_4;
                scanf(" %c", &key_4);
                system("cls");
				//	EXITTING PROGRAM	
                if (key_4 == '0') {
                printf("\n**YOU HAVE SUCCESSFULLY EXITED THE PROGRAM**");
                    exit(1);
                }
                //	IF THE USER WANTS TO Update A PRODUCT
				else if (key_4 == '1') {
                    Print_Stock(item, N_stock);
					printf("\n--> Press '0' to exit the program.\n--> Press '1' if you want to increase the quantity of any item.\n--> Press '2' if you want to reduce the quantity of any item.\n\n");
                    printf("--> Enter your choice: ");
                    getchar();

                    char key_5;
                    scanf(" %c", &key_5);
                    system("cls");
					// EXITTING PROGRAM	
                    if (key_5 == '0') {
                        exit(1);
                    }
                    //	IF QUANTITY OF AN ITEM NEEDS TO BE INCREASED
					else if (key_5 == '1') {
                        Print_Stock(item, N_stock);
                        Increase_Quantity(item, N_stock);
                    } 
					//	IF THE QUANTITY OF AN ITEM NEEDS TO BE DECREASED
					else if (key_5 == '2') {
                        Print_Stock(item, N_stock);
                        Reduce_Quantity(item, N_stock);
                    }
                }
                // IF THE USER WANTS TO ADD AN ITEM
				else if (key_4 == '2') {
                    Print_Stock(item, N_stock);
                    Add_Product(item, &N_stock);
                }
            }
            //	IF THE USER WANTS TO VIEW THE CUSTOMERS
			else if (key_3 == '2') {
				printf("\t  __________________\n");
                printf("\t |  VIEW CUSTOMERS  |");
                Print_All_Customers();
                sleep(10); //this will take 10 seconds before clearing the screen to display the initial stage of the code.
                system("cls");
                printf("\033[33m");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("\033[0m");
            }
        }
		signuped:
        //Login or Signup As Costumer
        if (ACT == 2) {
        	printf("--> Press '1' if you want to log-in.\n--> Press '2' if you want to sign  up.\n");
        	printf("\n--> Enter your choice: ");
        	scanf(" %d", &ACT);
			system("cls");
            // Login
            if (ACT == 1) {
                FILE *costumer;
                costumer = fopen("Costumer.csv", "r");
                N_Costumer = LinesCheck(costumer) - 1;
                printf("\033[33m");
                printf("------------------------------------\n");
                printf("\033[0m");
                printf("costumers = %d", N_Costumer);
                printf("\033[33m");
                printf("\n------------------------------------\n");
                printf("\033[0m");
                struct Costumer user[N_Costumer];
                printf("*LOG-IN PROCESS HAS BEEN INITIATED*\n\n");
                Read_Costumer(user, costumer);
                fclose(costumer);
				int *balance = Check_Costumer(user);
				system("cls");
				printf("\033[33m");
                printf("------------------------------------\n");
                printf("\033[0m");
                printf("\t * Welcome user *\n\n");
                
                printf("--> Press '0' to exit the program.\n--> Press '1' if you want to view any item.\n--> Press '2' if you want to buy any item.\n--> Press '3' if you want to know your balance.\n\n");
                int key_1;
                printf("--> Enter your choice: ");
            	scanf("%d", &key_1);
            	system("cls");
            	//	EXITTING PROGRAM
           		if (key_1 == 0) {
            		printf("\n**YOU HAVE SUCCESSFULLY EXITED THE PROGRAM**");
                	exit(1);
            	} 
				//	IF AN ITEM NEEDS TO BE VIEWED
				else if (key_1 == 1) {
               		Print_Stock(item, N_stock);
                	printf("\n**PROGRAM WILL NOW RUN ALL OVER AGAIN**\n\n");
                	sleep(5); // takes 5 seconds to clear the screen 
                	system("cls");
            	} 
				//	IF ANY ITEM NEEDS TO BE BOUGHT
				else if (key_1 == 2) {
                	printf("\t\t\t _____________\n");
                	printf("\t\t\t|  BUY ITEMS  |\n");
                	printf("\033[33m");
                	printf("\t\t------------------------------------\n");
                	printf("\033[0m");
                    Print_Stock(item, N_stock);
                	buyItem(user, N_Costumer, item, N_stock);
            	} 
				//	IF THE USER WANTS TO DO ANYTHING ABOUT HIS BANK BALANCE
				else if (key_1 == 3) {
            		printf("\t ________________\n");
                	printf("\t|  VIEW BALANCE  |\n");
                	printf("\033[33m");
                	printf("------------------------------------\n");
                	printf("\033[0m");
                	viewBalance(user, N_Costumer);
                	char key_2;
                	printf("--> Press '0' to exit the program.\n--> Press '1' if you want to deposit some amount.\n--> Press '2' if you want to withdraw some amount.\n\n");
                	printf("--> Enter your choice: ");
                	scanf(" %c", &key_2);
                	system("cls");
                	//	EXITTING THE PROGRAM
                	if (key_2 == '0') {
                		printf("\n**YOU HAVE SUCCESSFULLY EXITED THE PROGRAM**");
                    	exit(1);
                	} 
					//	IF THE USER WANTS TO DEPOSIT ANY AMOUNT OF MONEY
					else if (key_2 == '1') {
                    	depositMoney(user, N_Costumer);
                	} 
					//	IF THE USER WANTS TO WITHDRAW SOME AMOUNT
					else if (key_2 == '2') {
                    	withdrawMoney(user, N_Costumer);
                	}
            	}
        	}
        // Signup
        if (ACT == 2) {
            Add_Costumer();
            goto signuped;
        }
    }
}

return 0;

}
// Line Check Function
int LinesCheck(FILE *file){
    char chk;
    int Lines=0;
    do{
        fscanf(file,"%c",&chk);

        if(chk == '\n'){
            Lines++;
        }
    }while(!feof(file));
    rewind(file);
    return Lines;
}

// Read Stock Funtion
int Read_Stock(struct Stock item[],FILE *stock,int Lines){
    int record = 0;
    int i;
    for( i=0;i<Lines;i++,record++){
        if (fscanf(stock,
                  "%d,%19[^,],%d,%d,%c\n",
                  &item[i].Icode,
                  item[i].Iname,
                  &item[i].Iprice,
                  &item[i].Iqtt,
                  &item[i].Icat) != 5){
                    printf("Error");
                    return 0;
                  }
    }
    return record;

}

// Print Stock Function
void Print_Stock(struct Stock item[],int Lines){
    printf("\t\t ______________\n");
    printf("\t\t|  VIEW ITEMS  |\n");
    printf("\033[33m");
    printf("-----------------------------------------------------------\n");
    printf("\033[0m");
    printf("Code\tName\t\t\tPrice\tQuant.\tCategory\n");
    printf("\033[33m");
    printf("-----------------------------------------------------------\n");
    printf("\033[0m");
    int i;
   
    for( i=0;i<Lines;i++){
        printf("%d\t%s\t\t\t%d\t%d\t%c\n",
        item[i].Icode,
        item[i].Iname,
        item[i].Iprice,
        item[i].Iqtt,
        item[i].Icat);
    }
    printf("\033[33m");
    printf("-----------------------------------------------------------");
    printf("\033[0m");
}

// // Read EMPLOYEE Funtion
int Read_Emp(struct Employee List_Employee[],FILE *file){
   
    int n = LinesCheck(file)-1;
    int i;
    for( i=0 ;i<n;i++){
        if(fscanf(file,"%d,%19[^,],%19[^\n]",
        &List_Employee[i].Emp_ID,
        List_Employee[i].Emp_Name,
        List_Employee[i].Emp_Pass) != 3){
            printf("Error at line %d\n\n",i+1);
            return 0;
        }
    }
    rewind(file);
    return n;
}

// Print Employee Data
void Print_Emp(struct Employee List_Employee[],int n){
int i;
    for(i=0 ;i<n;i++){
        printf("%d,%s,%s\n",
        List_Employee[i].Emp_ID,
        List_Employee[i].Emp_Name,
        List_Employee[i].Emp_Pass);    
    }
}

// Allow Login To An Employee, Return pointer to name of that Employee
char *Emplyee_LOGIN(struct Employee List_Employee[]){
    int i=0;
    int ID_input;
    char name[20];
    char password[20];
    while(1){
    	printf("\033[33m");
    	printf("------------------------------------\n");
    	printf("\033[0m");
        printf("|*EMPLOYEE LOGIN PROCESS HAS BEEN INITIATED.|*\n\n");
        printf("--> Please enter Employee ID: ");
        scanf(" %d",&ID_input);
        for(i=0;i<N_Employee;i++){
            if(ID_input == List_Employee[i].Emp_ID){
                goto P1;
            }
        }
        printf("**INVALID ID**");
    }
    P1:
    while(1){
        printf("--> Please enter your password: ");
        scanf(" %s",password);
        printf("\033[33m");
        printf("------------------------------------");
        printf("\033[0m");
        printf("\n");
        if(strcmp(password,List_Employee[i].Emp_Pass)==0){
            return List_Employee[i].Emp_Name;
        }
        printf("**INVALID PASSWORD**\n");
    }
    return NULL;
}

// Read Costumer from a file into a structure
int Read_Costumer(struct Costumer user[], FILE *file) {
    int n = LinesCheck(file)-1;
    int i;
    for (i = 0; i < n; i++) {
        if (fscanf(file, "%19[^,],%19[^,],%d\n", user[i].User_Name, user[i].Password, &user[i].Balance) != 3) {
            printf("Error While Reading Line %d", i);
            return 0;
        }
    }
    return n;
}

// FUNCTION TO PRINT CUSTOMER DETAILS
void Print_Costumer(struct Costumer user[],int n){
int i;
    for( i=0;i<n;i++){
        printf("%s,\t%s,\t%d\n",
        user[i].User_Name,
        user[i].Password,
        user[i].Balance);
    }
}

// Signup A Costumer
void Add_Costumer(){
    char username[20];
    char password[20];
    int balance;
   
    printf("\n--> Enter Username: ");
    scanf(" %19s", username);

    printf("--> Enter Password: ");
    scanf(" %19s", password);

    printf("--> Enter Bank Balance:");
    scanf(" %d", &balance);

    FILE *file;
    file = fopen("Costumer.csv", "a");
   
    fprintf(file, "%s,%s,%d\n", username, password, balance);

    fclose(file);
}

//Ask Costumer for Credentials & Return an integer array to balance of the costumer
int* Check_Costumer(struct Costumer user[]){
    //printf("%d",N_Costumer);
    char username[20];
    char password[20];
    int balance;
    int i=0;
    while(1){
        printf("--> Enter your userame: ");
        scanf(" %19s",username);
        for(i=0;i<N_Costumer;i++){
            if(strcmp(user[i].User_Name, username)==0){
               
                goto next;
            }
        }
        printf("**INVALID USERNAME**\n");
    }
    next:
    while(1){
        printf("--> Enter your password: ");
        scanf(" %19s",password);
        if(!strcmp(user[i].Password,password)){
            return &user[i].Balance;
        }
        printf("**INVALID PASSWORD**\n");
    }
    return NULL;
}

// WRITING DETAILS TO THE CUSTOMER.CSV FILE
void Write_Costumer(struct Costumer user[], int n) {
    FILE *file;
    file = fopen("Costumer.csv", "w");

    if (file == NULL) {
        printf("Error opening Costumer.csv\n");
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            fprintf(file, "%s,%s,%d", user[i].User_Name, user[i].Password, user[i].Balance);
            continue;
        }
        fprintf(file, "%s,%s,%d\n", user[i].User_Name, user[i].Password, user[i].Balance);
    }

    fprintf(file, "\n");
    fclose(file);
}


void Number_Check(){
    //READING and PRINTING Stock
    FILE *stock;
    stock = fopen("Stock.csv","r");
    if(stock == NULL ){
        printf("Error!");
    }
    N_stock = LinesCheck(stock)-1;
    fclose(stock);
     
    FILE *Emp;
    Emp = fopen("Employee.csv","r");
    if(Emp == NULL ){
        printf("Error!");
    }
    N_Employee = LinesCheck(Emp)-1;
    fclose(Emp);

}

// FUNCTION FOR THE FUNCTIONALITIES IF USER WANTS TO BUY AN ITEM 
void buyItem(struct Costumer user[], int n, struct Stock item[], int m) {
    char username[20];
    char itemName[20];
    int quantity;

    printf("\n--> Enter your username: ");
    scanf(" %19s", username);

    int i,k;
    for (i = 0; i < n; i++) {
        if (strcmp(user[i].User_Name, username) == 0) {
            break;
        }
    }

    if (i == n) {
    printf("**CUSTOMER NOT FOUND**\n");
        //printf("\n___Customer not found_\n");
        return;
    }

    printf("--> Current Balance: %d\n", user[i].Balance);

    printf("--> Enter Item Name: ");
    scanf(" %19s", itemName);
    printf("--> Enter Quantity: ");
    scanf("%d", &quantity);

    int j;
    for (j = 0; j < m; j++) {
        if (strcmp(item[j].Iname, itemName) == 0) {
            break;
        }
    }

    if (j == m) {
    	printf("**ITEM NOT FOUND IN STOCK**\n");
    	printf("\nPROGRAM WILL NOW RUN ALL OVER AGAIN.\n\n");
    	sleep(5);
    	system("cls");
        return;
    }

    if (item[j].Iqtt < quantity) {
    	printf("**NOT ENOUGH QUANTITY IN STOCK**\n");
    	printf("\nPROGRAM WILL NOW RUN ALL OVER AGAIN.\n\n");
    	sleep(5);
    	system("cls");
        return;
    }

    int totalPrice = item[j].Iprice * quantity;
    if (user[i].Balance < totalPrice) {
    	printf("**INSUFFIECIENT BALANCE**\n");
    	printf("\nPROGRAM WILL NOW RUN ALL OVER AGAIN.\n\n");
    	sleep(5);
    	system("cls");
        return;
    }
    user[i].Balance -= totalPrice;
    item[j].Iqtt -= quantity;
    Write_Costumer(user, n);

    // Open file and update stock
    FILE *stockFile = fopen("Stock.csv", "w");
    if (stockFile != NULL) {
        for ( k = 0; k < m; k++) {
            fprintf(stockFile, "%d,%s,%d,%d,%c\n", item[k].Icode, item[k].Iname, item[k].Iprice, item[k].Iqtt, item[k].Icat);
        }
        fclose(stockFile);
    }

    printf("\nPurchase Successful!\n");
    printf("Updated Balance: %d\n", user[i].Balance);
    printf("Updated Stock Quantity for %s: %d\n", itemName, item[j].Iqtt);
    printf("\nPROGRAM WILL NOW RUN ALL OVER AGAIN.\n\n");
    sleep(5);
    system("cls");
}

// BANK BALANCE RELATED FUNCTION FOR THE CUSTOMER
void viewBalance(struct Costumer user[], int n) {
    char username[20];

    printf("\n--> Enter User Name:");
    scanf(" %19s", username);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(user[i].User_Name, username) == 0) {
            break;
        }
    }

    if (i == n) {
    printf("**CUSTOMER NOT FOUND**\n");
        return;
    }

    printf("--> Balance for %s = %d\n\n", username, user[i].Balance);
}

// FUNCTION IF THE CUSTOMER WANTS TO WITHDRAW MONEY
void withdrawMoney(struct Costumer user[], int n) {
    char username[20];
    int amount;

    printf("\n--> Enter username: ");
    scanf(" %19s", username);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(user[i].User_Name, username) == 0) {
            break;
        }
    }

    if (i == n) {
    printf("**CUSTOMER NOT FOUND**\n");
        return;
    }

    printf("\n--> Enter the amount you want to withdraw: ");
    scanf("%d", &amount);

    if (user[i].Balance < amount) {
    	printf("**INSUFFICIENT BALANCE FOR WITHDRAWAL**\n");
        return;
    }

    user[i].Balance -= amount;
	printf("**WITHDRAWAL SUCCESSFUL**\n");
    //printf("\nWithdrawal Successful!\n");
    printf("--> Updated Balance: %d\n", user[i].Balance);
	printf("\n**PROGRAM WILL NOW RUN ALL OVER AGAIN**\n\n");
	sleep(5);
	system("cls");
    Write_Costumer(user, n);  
}

// FUNCTION IF THE USER WANTS TO DEPOSIT MONEY
void depositMoney(struct Costumer user[], int n) {
    char username[20];
    int amount;

    printf("\n--> Enter your username: ");
    scanf(" %19s", username);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(user[i].User_Name, username) == 0) {
            break;
        }
    }

    if (i == n) {
    printf("**CUSTOMER NOT FOUND**\n");
        return;
    }

    printf("--> Enter the amount you want to deposit: ");
    scanf("%d", &amount);
	printf("\n");
    user[i].Balance += amount;

	printf("**DEPOSITED SUCCESSFULLY**\n");
    //printf("\nDeposit Successful!\n");
    printf("Updated Balance: %d\n", user[i].Balance);
   
    printf("\n**PROGRAM WILL NOW RUN ALL OVER AGAIN**\n\n");
    sleep(5);
    system("cls");

    Write_Costumer(user, n);  // Open file and update balance
}

// FUNCTION IF THE USER WANTS TO ADD A PRODUCT
void Add_Product(struct Stock item[], int *n) {
    FILE *file = fopen("Stock.csv", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Get product details from user
    struct Stock newProduct;
    printf("\n--> Enter product code: ");
    scanf("%d", &newProduct.Icode);
    printf("--> Enter product name: ");
    scanf("%19s", newProduct.Iname);
    printf("--> Enter product price: ");
    scanf("%d", &newProduct.Iprice);
    printf("--> Enter product quantity: ");
    scanf("%d", &newProduct.Iqtt);
    printf("--> Enter product category (single character): ");
    scanf(" %c", &newProduct.Icat);

    // Write the new product to the array and update the file
    item[*n] = newProduct;
    (*n)++;

    fprintf(file, "%d,%s,%d,%d,%c\n", newProduct.Icode, newProduct.Iname, newProduct.Iprice, newProduct.Iqtt, newProduct.Icat);

    fclose(file);

    printf("Product added successfully.\n");
    printf("\n**PROGRAM WILL NOW RUN ALL OVER AGAIN**\n\n");
    sleep(5);
    system("cls");
}

// FUNCTION FOR INCREASING THE QUANTITY OF AN ITEM 
void Increase_Quantity(struct Stock item[], int n) {
    int code, quantity;
    printf("\n--> Enter the product code of the item: ");
    scanf("%d", &code);

    int i,j;
    for (i = 0; i < n; i++) {
        if (item[i].Icode == code) {
            printf("--> Enter quantity to add: ");
            scanf("%d", &quantity);

            item[i].Iqtt += quantity;
            printf("\nQuantity increased successfully.\n");
            printf("\nPROGRAM WILL NOW RUN ALL OVER AGAIN.\n\n");
            sleep(5);
            system("cls");

            // Open file and update stock
            FILE *stockFile = fopen("Stock.csv", "w");
            if (stockFile != NULL) {
                for ( j = 0; j < n; j++) {
                    fprintf(stockFile, "%d,%s,%d,%d,%c\n", item[j].Icode, item[j].Iname, item[j].Iprice, item[j].Iqtt, item[j].Icat);
                }
                fclose(stockFile);
            }
            return;
        }
    }

    printf("Product with code %d not found.\n", code);
}

// FUNCTION TO REDUCE THE QUANTITY OF AN ITEM
void Reduce_Quantity(struct Stock item[], int n) {
    int code, quantity;
    printf("\n--> Enter the product code of the item: ");
    scanf("%d", &code);

    int i,j;
    for (i = 0; i < n; i++) {
        if (item[i].Icode == code) {
            printf("--> Enter quantity to reduce: ");
            scanf("%d", &quantity);

            if (item[i].Iqtt >= quantity) {
                item[i].Iqtt -= quantity;
                printf("\nQuantity reduced successfully.\n");
				printf("\nPROGRAM WILL NOW RUN ALL OVER AGAIN.\n\n");
				sleep(5);
				system("cls");
                // Open file and update stock
                FILE *stockFile = fopen("Stock.csv", "w");
                if (stockFile != NULL) {
                    for ( j = 0; j < n; j++) {
                        fprintf(stockFile, "%d,%s,%d,%d,%c\n", item[j].Icode, item[j].Iname, item[j].Iprice, item[j].Iqtt, item[j].Icat);
                    }
                    fclose(stockFile);
                }
            } else {
                printf("Insufficient quantity in stock.\n");
            }
            return;
        }
    }

    printf("Product with code %d not found.\n", code);
}

// FUNCTION TO PRINT THE DETAILS OF ALL THE CUSTOMERS
void Print_All_Customers() {
int i;
    FILE *costumerFile = fopen("Costumer.csv", "r");
   
    if (costumerFile == NULL) {
        printf("Error opening Costumer.csv\n");
        return;
    }

    int n = LinesCheck(costumerFile)-1;
    struct Costumer user[n];
    Read_Costumer(user, costumerFile);
    fclose(costumerFile);

    printf("\033[33m");
    printf("\n_________________________________________\n");
    printf("\033[0m");
    printf("|Username|\t|Password|\t|Balance|\n\n");
   
    for ( i = 0; i < n; i++) {
        printf("%s    |    %s    |    %d\n", user[i].User_Name, user[i].Password, user[i].Balance);
    }
}
