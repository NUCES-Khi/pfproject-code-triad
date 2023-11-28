#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Item {
    char name[50];
    int code;
    float wholesale_price;
    float sell_price;
    int in_stock;
    char category[50];
};

float balance = 0.0; // Global variable for balance

int ATM(char *username, int code) {
    char file_username[50];
    int file_code;
    FILE *file = fopen("project.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }
    while (fscanf(file, "ID: %s, Code: %d\n", file_username, &file_code) == 2) {
        if (strcmp(username, file_username) == 0 && file_code == code) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int credentials(char *username, char *password) {
    char file_username[50];
    char file_password[50];

    FILE *file = fopen("project.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    while (fscanf(file, "ID: %s, Password: %s\n", file_username, file_password) == 2) {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void readProductInfo(struct Item items[], int size) {
int i;
    FILE *file = fopen("product_info.txt", "r");
    if (file == NULL) {
        printf("Error opening the product file.\n");
        exit(1);
    }

    for (i = 0; i < size; i++) {
        fscanf(file, "%s %d %f %f %d %s\n", items[i].name, &items[i].code, &items[i].wholesale_price,
               &items[i].sell_price, &items[i].in_stock, items[i].category);
    }

    fclose(file);
}

void writeProductInfo(struct Item items[], int size) {
int i;
    FILE *file = fopen("product_info.txt", "w");
    if (file == NULL) {
        printf("Error opening the product file for writing.\n");
        exit(1);
    }

    for ( i = 0; i < size; i++) {
        fprintf(file, "%s %d %.2f %.2f %d %s\n", items[i].name, items[i].code, items[i].wholesale_price,
                items[i].sell_price, items[i].in_stock, items[i].category);
    }

    fclose(file);
}

void displayProductList(struct Item items[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d) %s\n", i + 1, items[i].name);
    }
}

void purchaseProduct(struct Item items[], int index) {
    if (balance < items[index].sell_price) {
        printf("Not enough balance\n");
        return;
    }

    if (items[index].in_stock == 0) {
        printf("Not available at the moment.\n");
        return;
    }

    balance -= items[index].sell_price;
    items[index].in_stock--;

    printf("Purchase successful!\n");
}

int main() {
    srand(time(NULL));
    struct Item items[5];
    int i;

    // Read product information from file
    readProductInfo(items, 5);

    char ID[50];
    char password[50];
    char name[50];
    int code;
    float withdraw;
    float deposit;

    printf("WELCOME TO THE FAST E STORE\n   1) LOG IN\n2) SIGN UP\n");
    printf("Press 1 or 2\n");

    char outerKey = getchar();

    while (getchar() != '\n');

    if (outerKey == '1') {
        printf("Enter your ID:\n");
        scanf("%s", ID);

        printf("Enter your password:\n");
        scanf("%s", password);

        if (credentials(ID, password)) {
            if (ID[0] == 'C' || ID[0] == 'c') {
                printf("WELCOME CUSTOMER\n");
                printf("1) BANK DETAIL\n");
                printf("2) PRODUCT LIST\n");
                printf("3) EXIT\n");

                char key_1 = getchar();
                while (getchar() != '\n');

                if (key_1 == '1') {
                    if (ATM(ID, code)) {
                        printf(" 1) Check balance\n");
                        printf(" 2) Withdraw money\n");
                        printf(" 3) Deposit money\n");

                        char key_2 = getchar();
                        while (getchar() != '\n');

                        if (key_2 == '1') {
                            printf("BALANCE IS : %.2f\n", balance);
                        } else if (key_2 == '2') {
                            if (balance == 0) {
                                printf(" Balance is 0, cannot withdraw money\n");
                            } else {
                                printf("Enter the amount you want to withdraw:\n");
                                scanf("%f", &withdraw);
                                balance = balance - withdraw;
                                printf("Withdrawal successful. Current balance: %.2f\n", balance);
                            }
                        } else if (key_2 == '3') {
                            printf("Enter the amount of money you want to deposit:\n");
                            scanf("%f", &deposit);
                            balance = balance + deposit;
                            printf("Deposit successful. Current balance: %.2f\n", balance);
                        }
                    }
                } else if (key_1 == '2') {
                    displayProductList(items, 5);
                    printf("Enter the product number you want to purchase:\n");
                    int productNumber;
                    scanf("%d", &productNumber);

                    if (productNumber >= 1 && productNumber <= 5) {
                        purchaseProduct(items, productNumber - 1);
                        // Update product information after purchase
                        writeProductInfo(items, 5);
                    } else {
                        printf("Invalid product number\n");
                    }
                } else if (key_1 == '3') {
                    exit(0);
                }
            } else if (ID[0] == 'S' || ID[0] == 's') {
                printf("WELCOME SELLER\n");
                printf("1) ATM\n");
                printf("2) Stock\n");
                printf("3) Products\n");
                printf("4) Exit\n");

                char key_4 = getchar();
                while (getchar() != '\n');

                if (key_4 == '1') {
                    if (ATM(ID, code)) {
                        printf(" 1) Check balance\n");
                        printf(" 2) Withdraw money\n");
                        printf(" 3) Deposit money\n");

                        char key_5 = getchar();
                        while (getchar() != '\n');

                        if (key_5 == '1') {
                            printf("BALANCE IS : %.2f\n", balance);
                        } else if (key_5 == '2') {
                            if (balance == 0) {
                                printf(" Balance is 0, cannot withdraw money\n");
                            } else {
                                printf("Enter the amount you want to withdraw:\n");
                                scanf("%f", &withdraw);
                                balance = balance - withdraw;
                                printf("Withdrawal successful. Current balance: %.2f\n", balance);
                            }
                        } else if (key_5 == '3') {
                            printf("Enter the amount of money you want to deposit:\n");
                            scanf("%f", &deposit);
                            balance = balance + deposit;
                            printf("Deposit successful. Current balance: %.2f\n", balance);
                        }
                    }
                } else if (key_4 == '2') {
                    for (i = 0; i < 5; i++) {
                        printf("%d) %s: %d\n", i, items[i].name, items[i].in_stock);
                    }
                    printf("1) Add Stock\n");
                    printf("2) Remove Stock\n");

                    char key_6 = getchar();
                    while (getchar() != '\n');

                    if (key_6 == '1') {
                        for (i = 0; i < 5; i++) {
                            printf("%d) %s\n", i + 1, items[i].name);
                        }
                        printf("Select the product to add stock:\n");
                        int selectedProduct;
                        scanf("%d", &selectedProduct);
                        if (selectedProduct >= 1 && selectedProduct <= 5) {
                            items[selectedProduct - 1].in_stock++;
                            printf("Stock added successfully.\n");
                            // Update product information after adding stock
                            writeProductInfo(items, 5);
                        } else {
                            printf("Invalid product selection.\n");
                        }
                    } else if (key_6 == '2') {
                        for (i = 0; i < 5; i++) {
                            printf("%d) %s\n", i + 1, items[i].name);
                        }
                        printf("Select the product to remove stock:\n");
                        int selectedProduct;
                        scanf("%d", &selectedProduct);
                        if (selectedProduct >= 1 && selectedProduct <= 5) {
                            if (items[selectedProduct - 1].in_stock > 0) {
                                items[selectedProduct - 1].in_stock--;
                                printf("Stock removed successfully.\n");
                                // Update product information after removing stock
                                writeProductInfo(items, 5);
                            } else {
                                printf("No stock available to remove.\n");
                            }
                        } else {
                            printf("Invalid product selection.\n");
                        }
                    }
                } else if (key_4 == '3') {
                    for (i = 0; i < 5; i++) {
                        printf("%d) %s    %d    %s    %.2f    %.2f\n", i + 1, items[i].name, items[i].code,
                               items[i].category, items[i].wholesale_price, items[i].sell_price);
                    }
                } else if (key_4 == '4') {
                    exit(1);
                }
            } else {
                printf("Invalid credentials. Please try again.\n");
            }
        } else {
            printf("Invalid credentials. Please try again.\n");
        }
    } else if (outerKey == '2') {
        printf("Enter your name:\n");
        scanf("%s", name);

        printf("ARE YOU A SELLER? 1) CUSTOMER\n 2) SELLER\n");
        while (getchar() != '\n');
        char innerKey = getchar();

        if (innerKey == '1') {
            sprintf(ID, "C%d", rand() % 1000);
        } else if (innerKey == '2') {
            sprintf(ID, "S%d", rand() % 1000);
        } else {
            printf("Press only 1 or 2\n");
            return 1;
        }

        printf("Your generated ID is: %s\n", ID);

        printf("Enter your ATM code:\n");
        scanf("%d", &code);

        printf("Set your password:\n");
        scanf("%s", password);

        FILE *file = fopen("project.txt", "a");

        if (file != NULL) {
            fprintf(file, "ID: %s, Password: %s, Code: %04d\n", ID, password, code);
            fclose(file);
            printf("User registered successfully.\n");
        } else {
            printf("Error opening the file for writing.\n");
            exit(1);
        }
   
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}