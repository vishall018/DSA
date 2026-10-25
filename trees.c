#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int id;
    char name[30], desig[30];
    struct node *leftChild, *rightSibling, *parent;
};

int main()
{
    struct node *emp[100], *root = NULL, *n, *m, *t;
    struct node *stack[100], *path[100];
    int count = 0, choice, id, i, top, level, x;
    char name[30];

    while (1)
    {
        printf("\n\n===== ORGANIZATIONAL HIERARCHY =====\n");
        printf("1. Create Organization\n");
        printf("2. Add Employee\n");
        printf("3. Display Organization\n");
        printf("4. Search Employee\n");
        printf("5. Number of Subordinates\n");
        printf("6. Reporting Path\n");
        printf("7. Display Subordinates\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        /* 1. Create Organization */
        if (choice == 1)
        {
            n = malloc(sizeof(struct node));

            printf("Enter CEO ID: ");
            scanf("%d", &n->id);
            printf("Enter CEO Name: ");
            scanf(" %[^\n]", n->name);
            printf("Enter Designation: ");
            scanf(" %[^\n]", n->desig);

            n->leftChild = n->rightSibling = n->parent = NULL;
            root = n;
            emp[count++] = n;

            printf("Organization Created!\n");
        }

        /* 2. Add Employee */
        else if (choice == 2)
        {
            if (root == NULL)
            {
                printf("Create Organization First!\n");
                continue;
            }

            printf("Enter Manager ID: ");
            scanf("%d", &id);

            m = NULL;
            for (i = 0; i < count; i++)
                if (emp[i]->id == id)
                    m = emp[i];

            if (m == NULL)
            {
                printf("Manager Not Found!\n");
                continue;
            }

            n = malloc(sizeof(struct node));

            printf("Enter Employee ID: ");
            scanf("%d", &n->id);
            printf("Enter Name: ");
            scanf(" %[^\n]", n->name);
            printf("Enter Designation: ");
            scanf(" %[^\n]", n->desig);

            n->leftChild = n->rightSibling = NULL;
            n->parent = m;

            if (m->leftChild == NULL)
                m->leftChild = n;
            else
            {
                t = m->leftChild;
                while (t->rightSibling != NULL)
                    t = t->rightSibling;
                t->rightSibling = n;
            }

            emp[count++] = n;
            printf("Employee Added!\n");
        }

        /* 3. Display Organization */
        else if (choice == 3)
        {
            if (root == NULL)
            {
                printf("Organization Empty!\n");
                continue;
            }

            top = 0;
            stack[0] = root;

            while (top >= 0)
            {
                n = stack[top--];

                level = 0;
                t = n;
                while (t->parent != NULL)
                {
                    level++;
                    t = t->parent;
                }

                for (i = 0; i < level; i++)
                    printf("  ");

                printf("%d - %s (%s)\n",
                       n->id, n->name, n->desig);

                if (n->rightSibling != NULL)
                    stack[++top] = n->rightSibling;

                if (n->leftChild != NULL)
                    stack[++top] = n->leftChild;
            }
        }

        /* 4. Search Employee */
        else if (choice == 4)
        {
            printf("Enter Employee ID: ");
            scanf("%d", &id);

            n = NULL;
            for (i = 0; i < count; i++)
                if (emp[i]->id == id)
                    n = emp[i];

            if (n)
                printf("\nID: %d\nName: %s\nDesignation: %s\n",
                       n->id, n->name, n->desig);
            else
                printf("Employee Not Found!\n");
        }

        /* 5. Number of Subordinates */
        else if (choice == 5)
        {
            printf("Total Number of Subordinates: %d\n", count - 1);
        }

        /* 6. Reporting Path */
        else if (choice == 6)
        {
            printf("Enter Employee ID: ");
            scanf("%d", &id);

            n = NULL;
            for (i = 0; i < count; i++)
                if (emp[i]->id == id)
                    n = emp[i];

            if (n == NULL)
            {
                printf("Employee Not Found!\n");
                continue;
            }

            top = 0;
            while (n != NULL)
            {
                path[top++] = n;
                n = n->parent;
            }

            printf("\nReporting Path:\n");

            for (i = top - 1; i >= 0; i--)
            {
                printf("%s (%s)", path[i]->name, path[i]->desig);

                if (i != 0)
                    printf(" -> ");
            }
            printf("\n");
        }

        /* 7. Display Subordinates */
        else if (choice == 7)
        {
            printf("Enter Manager ID: ");
            scanf("%d", &id);

            m = NULL;
            for (i = 0; i < count; i++)
                if (emp[i]->id == id)
                    m = emp[i];

            if (m == NULL)
            {
                printf("Manager Not Found!\n");
                continue;
            }

            n = m->leftChild;

            if (n == NULL)
            {
                printf("No Subordinates!\n");
                continue;
            }

            printf("\nSubordinates of %s:\n", m->name);

            while (n != NULL)
            {
                printf("%d - %s (%s)\n",
                       n->id, n->name, n->desig);
                n = n->rightSibling;
            }
        }

        /* 8. Exit */
        else if (choice == 8)
        {
            printf("Thank You!\n");
            break;
        }

        else
            printf("Invalid Choice!\n");
    }

    return 0;
}