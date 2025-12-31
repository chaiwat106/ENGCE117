#include <stdio.h>

#define VAT_RATE 0.07 // โจทย์กำหนด 7% (0.07)

struct Item { 
    char name[50];
    float unitPrice;
    int quantity;
};

int main() {
    int N;
    float subTotal = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &N); 

    struct Item items[N]; 

    for (int i = 0; i < N; i++) {
        printf("Item %d (Name Price Qty): ", i + 1);
        scanf("%s %f %d", items[i].name, &items[i].unitPrice, &items[i].quantity);
    }

    printf("\n--- RECEIPT ---\n");
    for (int i = 0; i < N; i++) {
        float itemCost = items[i].unitPrice * items[i].quantity; 
        printf("%s x %d = %.2f\n", items[i].name, items[i].quantity, itemCost);
        subTotal += itemCost; 
    }

    float totalVAT = subTotal * VAT_RATE; /
    float grandTotal = subTotal + totalVAT; 

    printf("--------------------\n");
    printf("Subtotal: %.2f\n", subTotal);
    printf("VAT (7%%): %.2f\n", totalVAT);
    printf("Grand Total: %.2f\n", grandTotal);

    return 0;
}
3. โปรแกรมตู้กดน้ำอัตโนมัติ (Vending Machine)
โปรแกรมนี้ใช้ do-while และ switch case ตามขั้นตอนการทำงานที่กำหนด

C

#include <stdio.h>

int main() {
    int choice;
    float totalCost = 0.0;
    float paidAmount, change;

  
    do {
        printf("\n--- Vending Machine ---\n");
        printf("1. Coke (15.00)\n2. Water (10.00)\n3. Snack (25.00)\n4. Exit and Pay\n");
        printf("Current Total: %.2f\n", totalCost);
        printf("Select item (1-4): ");
        scanf("%d", &choice);

     
        switch(choice) {
            case 1: totalCost += 15.00; break;
            case 2: totalCost += 10.00; break;
            case 3: totalCost += 25.00; break;
            case 4: break; 
        }
    } while (choice != 4);

    if (totalCost > 0) {
        printf("Total due: %.2f\nEnter paid amount: ", totalCost);
        scanf("%f", &paidAmount); 

        if (paidAmount >= totalCost) { 
            change = paidAmount - totalCost;
            printf("Purchase successful. Change: %.2f\n", change);
        } else {
            printf("Insufficient payment. Purchase cancelled.\n");
        }
    }

    return 0;
}
