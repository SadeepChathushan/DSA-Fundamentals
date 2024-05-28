#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
 struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

// Function to find the minimum value in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from the BST
struct Node* delete(struct Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);     
        preorder(root->right); 
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);  
    }
}


// Main function to test the BST implementation with user input
int main() {
    struct Node* root = NULL;
    int choice, value;
    
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
		printf("7. Exit\n");
        

    while (1) {
      
        printf("Enter your choice: ");      
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value inserted.\n");
                break;
            case 2:
                scanf("%d", &value);
                if (search(root, value) != NULL)
                    printf("Value found in the tree.\n");
                else
                    printf("Value not found in the tree.\n");
                break;
            case 3:
                scanf("%d", &value);
                root = delete(root, value);
                printf("Value deleted (if it was in the tree).\n");
                break;
            case 4:
                inorder(root);
                printf("\n");
                break;
            case 5:
                preorder(root);
                printf("\n");
                break;
			case 6:
                postorder(root);
                printf("\n");
                break;    
            case 7:
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

