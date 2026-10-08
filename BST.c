#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

int main() {
	struct node *root=NULL,*newnode,*temp,*parent,*minnode;
	int choice,data,i;

	while(1) {
		printf("\n\n----- BINARY SEARCH TREE -----");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Search");
		printf("\n4. Find Minimum");
		printf("\n5. Inorder Traversal");
		printf("\n6. Exit");
		printf("\nEnter choice: ");
		scanf("%d",&choice);

		if(choice==1) {
			printf("Enter data: ");
			scanf("%d",&data);

			newnode=malloc(sizeof(struct node));
			newnode->data=data;
			newnode->left=NULL;
			newnode->right=NULL;

			if(root==NULL)
				root=newnode;
			else {
				temp=root;

				while(1) {
					if(data<temp->data) {
						if(temp->left==NULL) {
							temp->left=newnode;
							break;
						}
						temp=temp->left;
					}
					else {
						if(temp->right==NULL) {
							temp->right=newnode;
							break;
						}
						temp=temp->right;
					}
				}
			}

			printf("Node inserted\n");
		}

		else if(choice==2) {
			printf("Enter data to delete: ");
			scanf("%d",&data);

			temp=root;
			parent=NULL;

			while(temp!=NULL && temp->data!=data) {
				parent=temp;


				if(data<temp->data)
					temp=temp->left;
				else
					temp=temp->right;
			}

			if(temp==NULL) {
				printf("Element not found\n");
			}
			else if(temp->left==NULL && temp->right==NULL) {
				if(parent==NULL)
					root=NULL;
				else if(parent->left==temp)
					parent->left=NULL;
				else
					parent->right=NULL;

				free(temp);
				printf("Node deleted\n");
			}
			else if(temp->left==NULL) {
				if(parent==NULL)
					root=temp->right;
				else if(parent->left==temp)
					parent->left=temp->right;
				else
					parent->right=temp->right;

				free(temp);
				printf("Node deleted\n");
			}
			else if(temp->right==NULL) {
				if(parent==NULL)
					root=temp->left;
				else if(parent->left==temp)
					parent->left=temp->left;
				else
					parent->right=temp->left;

				free(temp);
				printf("Node deleted\n");
			}
			else {
				minnode=temp->right;

				while(minnode->left!=NULL)
					minnode=minnode->left;

				data=minnode->data;
				minnode->data=temp->data;
				temp->data=data;

				parent=temp;
				temp=temp->right;

				while(temp->left!=NULL) {
					parent=temp;
					temp=temp->left;
				}

				if(parent->left==temp)
					parent->left=temp->right;
				else
					parent->right=temp->right;

				free(temp);
				printf("Node deleted\n");
			}
		}

		else if(choice==3) {
			printf("Enter data to search: ");
			scanf("%d",&data);

			temp=root;

			while(temp!=NULL) {
				if(temp->data==data)
					break;

				if(data<temp->data)
					temp=temp->left;
				else
					temp=temp->right;
			}

			if(temp!=NULL)
				printf("Element found\n");
			else
				printf("Element not found\n");
		}

		else if(choice==4) {
			if(root==NULL)
				printf("Tree is empty\n");
			else {
				temp=root;

				while(temp->left!=NULL)
					temp=temp->left;

				printf("Minimum element = %d\n",temp->data);
			}
		}

		else if(choice==5) {
			if(root==NULL)
				printf("Tree is empty\n");
			else {
				printf("Inorder: ");

				struct node *stack[100];
				int top=-1;

				temp=root;

				while(temp!=NULL || top!=-1) {
					while(temp!=NULL) {
						stack[++top]=temp;
						temp=temp->left;
					}

					temp=stack[top--];
					printf("%d ",temp->data);

					temp=temp->right;
				}

				printf("\n");
			}
		}

		else if(choice==6) {
			printf("Exit\n");
			break;
		}

		else
			printf("Invalid choice\n");
	}

	return 0;
}