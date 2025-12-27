#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Item structure (Singly Linked List)
typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

// Category structure (Singly Linked List)
typedef struct Category {
    char name[50];
    Item* items;
    struct Category* next;
} Category;

// ===== Utility Functions =====
Item* createItem(const char* name, int qty, float price) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = qty;
    newItem->price = price;
    newItem->next = NULL;
    return newItem;
}

Category* createCategory(const char* name) {
    Category* newCat = (Category*)malloc(sizeof(Category));
    strcpy(newCat->name, name);
    newCat->items = NULL;
    newCat->next = NULL;
    return newCat;
}

// Case-insensitive string compare
int strCaseCmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2))
            return (tolower((unsigned char)*s1) - tolower((unsigned char)*s2));
        s1++; s2++;
    }
    return *s1 - *s2;
}

// Convert string to lowercase (in place)
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// ===== Category Operations =====
void insertCategoryEnd(Category** head, const char* name) {
    Category* newCat = createCategory(name);
    if (*head == NULL) {
        *head = newCat;
    } else {
        Category* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newCat;
    }
    printf("Category '%s' added.\n", name);
}

Category* findCategory(Category* head, const char* name) {
    while (head != NULL) {
        if (strCaseCmp(head->name, name) == 0) return head;
        head = head->next;
    }
    return NULL;
}

void deleteCategory(Category** head, const char* name) {
    if (*head == NULL) {
        printf("No categories.\n");
        return;
    }
    Category* temp = *head;
    Category* prev = NULL;
    while (temp != NULL && strCaseCmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Category '%s' not found.\n", name);
        return;
    }
    if (prev == NULL) *head = temp->next;
    else prev->next = temp->next;

    // Free all items inside category
    Item* item = temp->items;
    while (item) {
        Item* del = item;
        item = item->next;
        free(del);
    }
    free(temp);
    printf("Category '%s' deleted.\n", name);
}

// ===== Item Operations =====
void insertItemEnd(Category* head, const char* categoryName, const char* itemName, int qty, float price) {
    Category* cat = findCategory(head, categoryName);
    if (cat == NULL) {
        printf("Category '%s' not found.\n", categoryName);
        return;
    }
    Item* newItem = createItem(itemName, qty, price);
    if (cat->items == NULL) {
        cat->items = newItem;
    } else {
        Item* temp = cat->items;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newItem;
    }
    printf("Item '%s' added to '%s'.\n", itemName, categoryName);
}

void deleteItem(Category* head, const char* categoryName, const char* itemName) {
    Category* cat = findCategory(head, categoryName);
    if (cat == NULL) {
        printf("Category not found.\n");
        return;
    }
    Item* temp = cat->items;
    Item* prev = NULL;
    while (temp != NULL && strCaseCmp(temp->name, itemName) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Item '%s' not found in '%s'.\n", itemName, categoryName);
        return;
    }
    if (prev == NULL) cat->items = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Item '%s' deleted from '%s'.\n", itemName, categoryName);
}

void searchItem(Category* head, const char* term) {
    int found = 0;
    char searchTerm[50];
    strcpy(searchTerm, term);
    toLowerCase(searchTerm);

    while (head != NULL) {
        Item* it = head->items;
        while (it != NULL) {
            char lowerName[50];
            strcpy(lowerName, it->name);
            toLowerCase(lowerName);

            if (strstr(lowerName, searchTerm) != NULL) {
                printf("Found: %s -> %s (Qty: %d, Price: %.2f)\n",
                       head->name, it->name, it->quantity, it->price);
                found = 1;
            }
            it = it->next;
        }
        head = head->next;
    }

    if (!found)
        printf("No items found matching '%s'.\n", term);
}

// ===== Display =====
void displayWarehouse(Category* head) {
    if (head == NULL) {
        printf("Warehouse empty.\n");
        return;
    }
    while (head != NULL) {
        printf("\nCategory: %s\n", head->name);
        Item* it = head->items;
        if (it == NULL) {
            printf("  No items.\n");
        } else {
            printf("  %-20s %-10s %-10s\n", "Item", "Quantity", "Price");
            printf("  %-20s %-10s %-10s\n", "----", "--------", "-----");
            while (it != NULL) {
                printf("  %-20s %-10d $%-9.2f\n",
                       it->name, it->quantity, it->price);
                it = it->next;
            }
        }
        head = head->next;
    }
}

// ===== Elegant Menu =====
void menu() {
    const char *options[] = {
        "Add Category",
        "Delete Category",
        "Add Item",
        "Delete Item",
        "Search Item",
        "Display Warehouse",
        "Exit"
    };
    int numOptions = sizeof(options) / sizeof(options[0]);

    printf("\n╔════════════════════════════════════╗\n");
    printf("║      WAREHOUSE MANAGEMENT MENU     ║\n");
    printf("╠════════════════════════════════════╣\n");

    for (int i = 0; i < numOptions; i++) {
        printf("║ %d. %-30s ║\n", i + 1, options[i]);
    }

    printf("╚════════════════════════════════════╝\n");
    printf("Enter your choice: ");
}

// ===== Main =====
int main() {
    Category* warehouse = NULL;
    int choice, qty;
    float price;
    char cname[50], iname[50], term[50];

    do {
        menu();
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter category name: ");
                fgets(cname, sizeof(cname), stdin);
                cname[strcspn(cname, "\n")] = 0;
                insertCategoryEnd(&warehouse, cname);
                break;
            case 2:
                printf("Enter category to delete: ");
                fgets(cname, sizeof(cname), stdin);
                cname[strcspn(cname, "\n")] = 0;
                deleteCategory(&warehouse, cname);
                break;
            case 3:
                printf("Enter category name: ");
                fgets(cname, sizeof(cname), stdin);
                cname[strcspn(cname, "\n")] = 0;
                printf("Enter item name: ");
                fgets(iname, sizeof(iname), stdin);
                iname[strcspn(iname, "\n")] = 0;
                printf("Enter quantity: ");
                scanf("%d", &qty);
                printf("Enter price: ");
                scanf("%f", &price);
                getchar();
                insertItemEnd(warehouse, cname, iname, qty, price);
                break;
            case 4:
                printf("Enter category name: ");
                fgets(cname, sizeof(cname), stdin);
                cname[strcspn(cname, "\n")] = 0;
                printf("Enter item name: ");
                fgets(iname, sizeof(iname), stdin);
                iname[strcspn(iname, "\n")] = 0;
                deleteItem(warehouse, cname, iname);
                break;
            case 5:
                printf("Enter search term: ");
                fgets(term, sizeof(term), stdin);
                term[strcspn(term, "\n")] = 0;
                searchItem(warehouse, term);
                break;
            case 6:
                displayWarehouse(warehouse);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}