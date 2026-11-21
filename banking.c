
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int choice;
    char name[50];
int accountNumber;
float balance = 0;
int accountCreated = 0;
FILE *file;

file = fopen("account.txt", "r");
if (file != NULL) {
    if (fscanf(file, " %49[^\n]\n%d\n%f",
               name, &accountNumber, &balance) == 3) {
        accountCreated = 1;
    }

    fclose(file);
}

    do {
        printf("\n===== BANKING MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Account Details\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
    printf("Invalid input! Enter a number.\n");

    while (getchar() != '\n');

    continue;
}

        switch(choice) {
            case 1: {
   

    printf("Enter customer name: ");
    scanf(" %49[^\n]", name);

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    printf("Enter initial deposit: ");
    scanf("%f", &balance);
    file = fopen("account.txt", "w");

    if (file == NULL) {
    printf("Error saving account!\n");
    break;
}


fprintf(file, "%s\n%d\n%.2f\n", name, accountNumber, balance);

fclose(file);
accountCreated = 1;


    printf("\nAccount created successfully!\n");
    printf("Name: %s\n", name);
    printf("Account Number: %d\n", accountNumber);
    printf("Balance: %.2f\n", balance);

    break;
}

          case 2: {
    float amount;
    if (accountCreated == 0) {
    printf("Please create an account first!\n");
    break;
}

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance = balance + amount;
        file = fopen("account.txt", "w");

if (file == NULL) {
    printf("Error saving deposit!\n");
    balance = balance - amount;
    break;
}

fprintf(file, "%s\n%d\n%.2f\n", name, accountNumber, balance);

fclose(file);
        printf("Deposit successful!\n");
        printf("New balance: %.2f\n", balance);
    } else {
        printf("Invalid deposit amount!\n");
    }

    break;
}

            case 3: {
    float amount;

    if (accountCreated == 0) {
        printf("Please create an account first!\n");
        break;
    }

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
    }
    else if (amount > balance) {
        printf("Insufficient balance!\n");
    }
    else {
        balance = balance - amount;
        file = fopen("account.txt", "w");

if (file == NULL) {
    printf("Error saving withdrawal!\n");
    balance = balance + amount;
    break;
}

fprintf(file, "%s\n%d\n%.2f\n", name, accountNumber, balance);
fclose(file);

        printf("Withdrawal successful!\n");
        printf("Remaining balance: %.2f\n", balance);
    }

    break;
}


            case 4:
    if (accountCreated == 0) {
        printf("Please create an account first!\n");
    } else {
        printf("Your current balance is: %.2f\n", balance);
    }
    break;

            case 5:
    if (accountCreated == 0) {
        printf("Please create an account first!\n");
    } else {
        printf("\n===== ACCOUNT DETAILS =====\n");
        printf("Customer Name: %s\n", name);
        printf("Account Number: %d\n", accountNumber);
        printf("Current Balance: %.2f\n", balance);
    }
    break;


            case 6:
                printf("Thank you for using our bank!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 6);

    return 0;
}

