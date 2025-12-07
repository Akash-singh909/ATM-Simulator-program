#include <stdio.h>
#include <string.h>

int main() {
    int enteredPin, accountBalance = 5000, choice, amount;
    int attempts = 3; 

    printf("=== Welcome to ATM Simulation ===\n");

    do {
        printf("Please enter your PIN : ");
        scanf("%d", &enteredPin);

        if (enteredPin == 1234) {
            printf("\nPIN Verified Successfully!\n");
            
            while (1) {
                printf("=== ATM Menu ===\n");
                printf("1. Check Balance\n");
                printf("2. Cash Withdrawal\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                switch (choice) {
                    case 1:
                        printf("Your current balance: Rs. %d\n\n", accountBalance);
                        break;
                        
                    case 2:
                        printf("Enter amount to withdraw: Rs. ");
                        scanf("%d", &amount);
                        
                        if (amount > accountBalance) {
                            printf("Insufficient balance!\n");
                        } else if (amount < 100 || amount % 100 != 0) {
                            printf("Amount must be multiple of 100 and minimum Rs. 100\n");
                        } else {
                            accountBalance -= amount;
                            printf("Rs. %d withdrawn successfully!\n", amount);
                            printf("Remaining balance: Rs. %d\n\n", accountBalance);

                            if (accountBalance <= 0) {
                                printf("!! Alert: Account balance is now zero, Please maintain minimum 500rs balance.\n Thank you.\n");
                                return 0;
                            }
                            
                        }  
                        break;
                        
                    case 3:
                        printf("Thank you for using our ATM.\n");
                        return 0; 
                        
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
            }
            
        } else {
            attempts--;
            printf("Wrong PIN! Attempts remaining: %d\n", attempts);
            
            if (attempts == 0) {
                printf("Card locked! Contact bank.\n");
                return 0;
            }

        }

    } while (enteredPin != 1234 && attempts > 0);

    return 0; 
}