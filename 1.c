#include <stdio.h>

#define MAX 100

struct Product
{
    int id;
};

int main()
{
    struct Product inventory[MAX];
    int n = 0;
    int choice, id, pos, i, found;

    while(1)
    {
        printf("\n\n--- Inventory Management ---\n");
        printf("1. Add a new product\n");
        printf("2. Insert product at a specific position\n");
        printf("3. Remove a product by Product ID\n");
        printf("4. Search for a product by Product ID\n");
        printf("5. Update an existing Product ID\n");
        printf("6. Display all Product IDs\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(n == MAX)
                {
                    printf("Inventory is full!\n");
                }
                else
                {
                    printf("Enter Product ID: ");
                    scanf("%d", &id);

                    inventory[n].id = id;
                    n++;

                    printf("Product added successfully.\n");
                }
                break;


            case 2:
                if(n == MAX)
                {
                    printf("Inventory is full!\n");
                }
                else
                {
                    printf("Enter position: ");
                    scanf("%d", &pos);

                    if(pos < 1 || pos > n + 1)
                    {
                        printf("Invalid position!\n");
                    }
                    else
                    {
                        printf("Enter Product ID: ");
                        scanf("%d", &id);

                        for(i = n; i >= pos; i--)
                        {
                            inventory[i] = inventory[i - 1];
                        }

                        inventory[pos - 1].id = id;
                        n++;

                        printf("Product inserted successfully.\n");
                    }
                }
                break;


            case 3:
                printf("Enter Product ID to remove: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(inventory[i].id == id)
                    {
                        for(int j = i; j < n - 1; j++)
                        {
                            inventory[j] = inventory[j + 1];
                        }

                        n--;
                        found = 1;

                        printf("Product removed successfully.\n");
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Product not found.\n");
                }
                break;


            case 4:
                printf("Enter Product ID to search: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(inventory[i].id == id)
                    {
                        printf("Product found at position %d.\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Product not found.\n");
                }
                break;


            case 5:
                printf("Enter Product ID to update: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(inventory[i].id == id)
                    {
                        printf("Enter new Product ID: ");
                        scanf("%d", &inventory[i].id);

                        printf("Product ID updated successfully.\n");
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Product not found.\n");
                }
                break;


            case 6:
                if(n == 0)
                {
                    printf("Inventory is empty.\n");
                }
                else
                {
                    printf("\nProduct IDs in inventory:\n");

                    for(i = 0; i < n; i++)
                    {
                        printf("%d -> ", inventory[i].id);
                    }

                    printf("NULL\n");
                }
                break;


            case 7:
                printf("Exiting program...\n");
                return 0;


            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}