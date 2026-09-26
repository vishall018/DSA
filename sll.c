#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode, *temp, *prev;
    int choice, data, pos, i, count;

    while (1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insertion Using Position\n");
        printf("2. Insertion at End\n");
        printf("3. Insertion at Beginning\n");
        printf("4. Delete Given Element\n");
        printf("5. Delete Using Position\n");
        printf("6. Search Element\n");
        printf("7. Count Elements\n");
        printf("8. Display List\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* 1. Insertion Using Position */
        if (choice == 1)
        {
            printf("Enter data: ");
            scanf("%d", &data);

            printf("Enter position: ");
            scanf("%d", &pos);

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;

            if (pos == 1)
            {
                newnode->next = head;
                head = newnode;
            }
            else
            {
                temp = head;

                for (i = 1; i < pos - 1 && temp != NULL; i++)
                    temp = temp->next;

                if (temp == NULL)
                {
                    printf("Invalid position\n");
                    free(newnode);
                }
                else
                {
                    newnode->next = temp->next;
                    temp->next = newnode;
                }
            }
        }

        /* 2. Insertion at End */
        else if (choice == 2)
        {
            printf("Enter data: ");
            scanf("%d", &data);

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = NULL;

            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                temp = head;

                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = newnode;
            }
        }

        /* 3. Insertion at Beginning */
        else if (choice == 3)
        {
            printf("Enter data: ");
            scanf("%d", &data);

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = head;

            head = newnode;
        }

        /* 4. Delete Given Element */
        else if (choice == 4)
        {
            printf("Enter element to delete: ");
            scanf("%d", &data);

            temp = head;
            prev = NULL;

            while (temp != NULL && temp->data != data)
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL)
            {
                printf("Element not found\n");
            }
            else
            {
                if (prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;

                free(temp);
                printf("Element deleted\n");
            }
        }

        /* 5. Delete Using Position */
        else if (choice == 5)
        {
            printf("Enter position: ");
            scanf("%d", &pos);

            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                temp = head;

                if (pos == 1)
                {
                    head = head->next;
                    free(temp);
                    printf("Element deleted\n");
                }
                else
                {
                    for (i = 1; i < pos && temp != NULL; i++)
                    {
                        prev = temp;
                        temp = temp->next;
                    }

                    if (temp == NULL)
                    {
                        printf("Invalid position\n");
                    }
                    else
                    {
                        prev->next = temp->next;
                        free(temp);
                        printf("Element deleted\n");
                    }
                }
            }
        }

        /* 6. Search Element */
        else if (choice == 6)
        {
            printf("Enter element to search: ");
            scanf("%d", &data);

            temp = head;
            pos = 1;

            while (temp != NULL)
            {
                if (temp->data == data)
                {
                    printf("Element found at position %d\n", pos);
                    break;
                }

                temp = temp->next;
                pos++;
            }

            if (temp == NULL)
                printf("Element not found\n");
        }

        /* 7. Count Elements */
        else if (choice == 7)
        {
            count = 0;
            temp = head;

            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }

            printf("Number of elements = %d\n", count);
        }

        /* 8. Display */
        else if (choice == 8)
        {
            temp = head;

            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("List: ");

                while (temp != NULL)
                {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
                }

                printf("NULL\n");
            }
        }

        /* 9. Exit */
        else if (choice == 9)
        {
            break;
        }

        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}