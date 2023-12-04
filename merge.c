#include<stdio.h>
#include<string.h>
#include<windows.h>

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

// Function used in this Program
int LinesCheck(FILE *file);
int Read_Stock(struct Stock item[],FILE *stock,int Lines);
void Print_Stock(struct Stock item[],int Lines);
int Read_Emp(struct Employee List_Employee[],FILE *file);
void Print_Emp(struct Employee List_Employee[],int n);
// char* ID_Check(struct Employee List_Employee[],int inp,int n,char name[20]);
char* Emplyee_LOGIN(struct Employee List_Employee[]);
int Read_Costumer(struct Costumer user[],FILE *file);
void Print_Costumer(struct Costumer user[],int n);
void Add_Costumer();
int* Check_Costumer(struct Costumer user[]);
void Write_Costumer(struct Costumer user[],int n);
void Number_Check();



int main(){

    Number_Check();
    FILE* stock;
    stock = fopen("Stock.csv","r");
    struct Stock item[N_stock];
    if(Read_Stock(item,stock,N_stock)==0){
        return 1;
    }
    fclose(stock);

    FILE* Emp;
    Emp=fopen("Employee.csv","r");
    struct Employee Employees[N_Employee];
    if(Read_Emp(Employees,Emp)==0){
        return 1;
    }
    fclose(Emp);

    int ACT=0;
    while (1)
    {
        printf("______________Welcome To E-STORE_____________");
        printf("\nExit(0)\nEmployee(1)\nCostumer(2)\n");
        scanf(" %d",&ACT);

        if(ACT == 0) break;
        //Login as Employee;
        if(ACT == 1){
            
            printf("Welcome %s",Emplyee_LOGIN(Employees));
            Sleep(10000);
            break;
        }
        signuped:
        //Login or Signup As Costumer
        if(ACT == 2){
            printf("\nLOG IN(1)\nSIGN UP(2)\n");
            scanf(" %d",&ACT);
            //Login
            if (ACT == 1){
                FILE* costumer;
                costumer = fopen("Costumer.csv","r");
                N_Costumer = LinesCheck(costumer)-1;
                printf("costumers = %d",N_Costumer);
                struct Costumer user[N_Costumer];
                Read_Costumer(user,costumer);
                Print_Costumer(user,N_Costumer);
                fclose(costumer);
                int *balance = Check_Costumer(user);
                printf("Welcome User");
                printf("...");
                break;
            }
            if (ACT == 2 ){
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
    for(int i=0;i<Lines;i++,record++){
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
    printf("Code\tName\t\t\tPrice\tQuant.\tCategory\n");
    for(int i=0;i<Lines;i++){
        printf("%d\t%s\t\t\t%d\t%d\t%c\n",
        item[i].Icode,
        item[i].Iname,
        item[i].Iprice,
        item[i].Iqtt,
        item[i].Icat);
    }
}

// // Read EMPLOYEE Funtion

int Read_Emp(struct Employee List_Employee[],FILE *file){
    
    int n = LinesCheck(file)-1;
    
    for(int i=0 ;i<n;i++){
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
    for(int i=0 ;i<n;i++){
        printf("%d,%s,%s\n",
        List_Employee[i].Emp_ID,
        List_Employee[i].Emp_Name,
        List_Employee[i].Emp_Pass);    
    }
}
// Check if this ID Exist
// char* ID_Check(struct Employee List_Employee[],int inp,int n,char name[20]){

//     if (n == 0){
//         if(List_Employee[n].Emp_ID == inp){
//             name = List_Employee->Emp_Name;
//             return List_Employee[n].Emp_Pass;
//         }
//         else return NULL;
//     }
//     if(List_Employee[n].Emp_ID == inp){
//         name = List_Employee->Emp_Name;
//         return List_Employee[n].Emp_Pass;
//     }
//     ID_Check(List_Employee,inp,n-1,name);

// }
// Allow Login To An Employee, Return pointer to name of that Employee
char *Emplyee_LOGIN(struct Employee List_Employee[]){
    int i=0;
    int ID_input;
    char name[20];
    char password[20];
    while(1){
        printf("Enter Employee ID:   ");
        scanf(" %d",&ID_input);
        for(i=0;i<N_Employee;i++){
            if(ID_input == List_Employee[i].Emp_ID){
                goto P1;
            }
        }
        printf("________Invalid ID_______");
    }
    P1:
    while(1){
        printf("Enter Password:   ");
        scanf(" %s",password);
        if(strcmp(password,List_Employee[i].Emp_Pass)==0){
            return List_Employee[i].Emp_Name;
        }
        printf("_______Invalid Password_______");
    }
    return NULL;
}

// Read Costumer from a file into a structure
int Read_Costumer(struct Costumer user[],FILE *file){
    int n = LinesCheck(file)-1;

    for(int i=0;i<n;i++){
        if(fscanf(file,
                    "%19[^,],%19[^,],%d\n",
                    user[i].User_Name,
                    user[i].Password,
                    &user[i].Balance) != 3){
                        printf("Error While Reading Line %d",i);
                        return 0;
                    }
    }
    return 1;
}
void Print_Costumer(struct Costumer user[],int n){
    for(int i=0;i<n;i++){
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
    printf("\nEnter User Name:");
    scanf(" %s",username);
    printf("Enter Password:");
    scanf(" %s",password);
    printf("Enter Bank Balance:");
    scanf(" %d",&balance);
    FILE * file;
    file = fopen("Costumer.csv","a");
    fprintf(file,"%s,%s,%d\n",username,password,balance); 
    fclose(file);
}
//Ask Costumer for Credentials & Return an integer array to balance of the costumer
int* Check_Costumer(struct Costumer user[]){
    printf("%d",N_Costumer);
    char username[20];
    char password[20];
    int balance;
    int i=0;
    while(1){
        printf("\nEnter User Name:");
        scanf(" %19s",username);
        for(i=0;i<N_Costumer;i++){
            if(strcmp(user[i].User_Name, username)==0){
                
                goto next;
            }
        }
        printf("\n_______Invalid Username_______\n");
    }
    next:
    while(1){
        printf("\nEnter Password:");
        scanf(" %19s",password);
        if(!strcmp(user[i].Password,password)){
            return &user[i].Balance;
        }
        printf("\n_______Invalid Password________");
    }
    return NULL;
}


void Write_Costumer(struct Costumer user[], int n){
    FILE* file;
    file= fopen("try.csv","w");
    for(int i=0;i<n;i++){
        if(i == n-1){
            fprintf(file,"%s,%s,%d",user[i].User_Name,user[i].Password,user[i].Balance);
            continue;
        }
        fprintf(file,"%s,%s,%d\n",user[i].User_Name,user[i].Password,user[i].Balance);
        
    }
    fprintf(file,"\n");
}

void Number_Check(){
    //READING and PRINTING Stock
    FILE *stock;
    stock = fopen("Stock.csv","r");
    if(stock == NULL ){
        printf("Error.....!");
    }
    N_stock = LinesCheck(stock)-1;
    fclose(stock);
     
    FILE *Emp;
    Emp = fopen("Employee.csv","r");
    if(Emp == NULL ){
        printf("Error.....!"); 
    }
    N_Employee = LinesCheck(Emp)-1;
    fclose(Emp);

}