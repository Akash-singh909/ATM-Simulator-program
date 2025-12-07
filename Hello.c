#include <stdio.h>
#include <string.h>

int main() {
    int pin, enteredPin, accountBalance = 5000, choice, amount;
    int attempts = 3;
    
    printf("=== Welcome to ATM Simulation ===\n");
    printf("Please enter your PIN : ");
    scanf("%d", &enteredPin);
    
    // PIN Verification (Default PIN: 1234)
    if (enteredPin == 1234) {
        printf("\nPIN Verified Successfully!\n");
        printf("Account Balance: Rs. %d\n\n", accountBalance);
        
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
                    }
                    break;
                    
                case 3:
                    printf("Thank you for using our ATM. Goodbye!\n");
                    return 0;
                    
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
    } else {
        printf("Wrong PIN!\n");
        while (attempts > 0) {
            printf("Attempts remaining: %d\n", attempts);
            printf("Re-enter PIN: ");
            scanf("%d", &enteredPin);
            
            if (enteredPin == 1234) {
                printf("\nPIN Verified Successfully!\n");
                // Restart main menu logic here (simplified)
                printf("Account Balance: Rs. %d\n\n", accountBalance);
                break;
            } else {
                attempts--;
                if (attempts == 0) {
                    printf("Card locked! Contact bank.\n");
                    return 0;
                }
            }
        }
    }
    
    return 0;
}
