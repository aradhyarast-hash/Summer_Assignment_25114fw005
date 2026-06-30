#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

struct Item
{
    int itemID;
    string name;
    string category;
    int quantity;
    float price;
    int reorderLevel;
    string supplier;
};

Item inventory[MAX_ITEMS];
int count = 0; // actual number of items stored

// ==================== UTILITY ========================

void printLine()
{
    cout << "-------------------------------------------" << endl;
}
void printDoubleLine()
{
    cout << "===========================================" << endl;
}

int findItem(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (inventory[i].itemID == id)
            return i;
    }
    return -1;
}

// ================= CORE FUNCTIONS ====================

void addItem()
{
    if (count >= MAX_ITEMS)
    {
        cout << "Inventory full! Cannot add more items." << endl;
        return;
    }

    int id;
    cout << "\n--- ADD ITEM ---" << endl;
    cout << "Enter Item ID    : ";
    cin >> id;

    if (findItem(id) != -1)
    {
        cout << "Item with this ID already exists!" << endl;
        return;
    }

    Item it;
    it.itemID = id;

    cin.ignore();
    cout << "Enter Name       : ";
    getline(cin, it.name);
    cout << "Enter Category   : ";
    getline(cin, it.category);
    cout << "Enter Quantity   : ";
    cin >> it.quantity;
    cout << "Enter Price      : ";
    cin >> it.price;
    cout << "Enter Reorder Lvl: ";
    cin >> it.reorderLevel;
    cin.ignore();
    cout << "Enter Supplier   : ";
    getline(cin, it.supplier);

    inventory[count] = it;
    count++;

    cout << "Item added successfully!" << endl;
}

void displayItem(int idx)
{
    printLine();
    cout << "Item ID       : " << inventory[idx].itemID << endl;
    cout << "Name          : " << inventory[idx].name << endl;
    cout << "Category      : " << inventory[idx].category << endl;
    cout << "Quantity      : " << inventory[idx].quantity << endl;
    cout << "Price         : Rs. " << inventory[idx].price << endl;
    cout << "Reorder Level : " << inventory[idx].reorderLevel << endl;
    cout << "Supplier      : " << inventory[idx].supplier << endl;
    cout << "Status        : " << (inventory[idx].quantity <= inventory[idx].reorderLevel ? "LOW STOCK!" : "OK") << endl;
    printLine();
}

void displayAllItems()
{
    if (count == 0)
    {
        cout << "No items in inventory!" << endl;
        return;
    }
    printDoubleLine();
    cout << "          ALL INVENTORY ITEMS" << endl;
    printDoubleLine();
    for (int i = 0; i < count; i++)
    {
        displayItem(i);
    }
}

void searchByID()
{
    int id;
    cout << "Enter Item ID to search: ";
    cin >> id;
    int idx = findItem(id);
    if (idx == -1)
        cout << "Item not found!" << endl;
    else
        displayItem(idx);
}

void searchByName()
{
    cin.ignore();
    string name;
    cout << "Enter Name to search: ";
    getline(cin, name);
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (inventory[i].name == name)
        {
            displayItem(i);
            found = true;
        }
    }
    if (!found)
        cout << "No item found with that name!" << endl;
}

void searchByCategory()
{
    cin.ignore();
    string cat;
    cout << "Enter Category to search: ";
    getline(cin, cat);
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (inventory[i].category == cat)
        {
            displayItem(i);
            found = true;
        }
    }
    if (!found)
        cout << "No items found in that category!" << endl;
}

void updateItem()
{
    int id;
    cout << "Enter Item ID to update: ";
    cin >> id;
    int idx = findItem(id);
    if (idx == -1)
    {
        cout << "Item not found!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter new Name       : ";
    getline(cin, inventory[idx].name);
    cout << "Enter new Category   : ";
    getline(cin, inventory[idx].category);
    cout << "Enter new Price      : ";
    cin >> inventory[idx].price;
    cout << "Enter new Reorder Lvl: ";
    cin >> inventory[idx].reorderLevel;
    cin.ignore();
    cout << "Enter new Supplier   : ";
    getline(cin, inventory[idx].supplier);

    cout << "Item updated successfully! (Use Stock In/Out to change quantity)" << endl;
}

void deleteItem()
{
    int id;
    cout << "Enter Item ID to delete: ";
    cin >> id;
    int idx = findItem(id);
    if (idx == -1)
    {
        cout << "Item not found!" << endl;
        return;
    }

    for (int i = idx; i < count - 1; i++)
    {
        inventory[i] = inventory[i + 1];
    }
    count--;

    cout << "Item deleted successfully!" << endl;
}

void stockIn()
{
    int id, qty;
    cout << "\n--- STOCK IN ---" << endl;
    cout << "Enter Item ID  : ";
    cin >> id;
    int idx = findItem(id);
    if (idx == -1)
    {
        cout << "Item not found!" << endl;
        return;
    }
    cout << "Enter Quantity to add: ";
    cin >> qty;
    if (qty <= 0)
    {
        cout << "Invalid quantity!" << endl;
        return;
    }
    inventory[idx].quantity += qty;
    cout << qty << " units added to \"" << inventory[idx].name << "\"" << endl;
    cout << "New Quantity: " << inventory[idx].quantity << endl;
}

void stockOut()
{
    int id, qty;
    cout << "\n--- STOCK OUT ---" << endl;
    cout << "Enter Item ID  : ";
    cin >> id;
    int idx = findItem(id);
    if (idx == -1)
    {
        cout << "Item not found!" << endl;
        return;
    }
    cout << "Enter Quantity to remove: ";
    cin >> qty;
    if (qty <= 0)
    {
        cout << "Invalid quantity!" << endl;
        return;
    }
    if (qty > inventory[idx].quantity)
    {
        cout << "Not enough stock! Available: " << inventory[idx].quantity << endl;
        return;
    }
    inventory[idx].quantity -= qty;
    cout << qty << " units removed from \"" << inventory[idx].name << "\"" << endl;
    cout << "New Quantity: " << inventory[idx].quantity << endl;

    if (inventory[idx].quantity <= inventory[idx].reorderLevel)
    {
        cout << "WARNING: Stock is at or below reorder level (" << inventory[idx].reorderLevel << ")!" << endl;
    }
}

void lowStockReport()
{
    if (count == 0)
    {
        cout << "No items in inventory!" << endl;
        return;
    }
    cout << "\n--- LOW STOCK ITEMS ---" << endl;
    bool any = false;
    for (int i = 0; i < count; i++)
    {
        if (inventory[i].quantity <= inventory[i].reorderLevel)
        {
            any = true;
            cout << inventory[i].itemID << " | " << inventory[i].name
                 << " | Qty: " << inventory[i].quantity
                 << " | Reorder Level: " << inventory[i].reorderLevel << endl;
        }
    }
    if (!any)
        cout << "No items are low on stock." << endl;
}

void totalInventoryValue()
{
    if (count == 0)
    {
        cout << "No items in inventory!" << endl;
        return;
    }
    float total = 0;
    for (int i = 0; i < count; i++)
    {
        total += inventory[i].quantity * inventory[i].price;
    }
    cout << "Total Inventory Value: Rs. " << total << endl;
}

void sortByPrice()
{
    if (count == 0)
    {
        cout << "No items to sort!" << endl;
        return;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (inventory[j].price > inventory[j + 1].price)
            {
                swap(inventory[j], inventory[j + 1]);
            }
        }
    }
    cout << "Items sorted by price (low to high):" << endl;
    displayAllItems();
}

void sortByQuantity()
{
    if (count == 0)
    {
        cout << "No items to sort!" << endl;
        return;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (inventory[j].quantity > inventory[j + 1].quantity)
            {
                swap(inventory[j], inventory[j + 1]);
            }
        }
    }
    cout << "Items sorted by quantity (low to high):" << endl;
    displayAllItems();
}

void sortByName()
{
    if (count == 0)
    {
        cout << "No items to sort!" << endl;
        return;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (inventory[j].name > inventory[j + 1].name)
            {
                swap(inventory[j], inventory[j + 1]);
            }
        }
    }
    cout << "Items sorted by name (A-Z):" << endl;
    displayAllItems();
}

// ==================== MAIN MENU =======================

void showMenu()
{
    printDoubleLine();
    cout << "       INVENTORY MANAGEMENT SYSTEM" << endl;
    printDoubleLine();
    cout << "1.  Add Item" << endl;
    cout << "2.  Display All Items" << endl;
    cout << "3.  Search by ID" << endl;
    cout << "4.  Search by Name" << endl;
    cout << "5.  Search by Category" << endl;
    cout << "6.  Update Item" << endl;
    cout << "7.  Delete Item" << endl;
    cout << "8.  Stock In" << endl;
    cout << "9.  Stock Out" << endl;
    cout << "10. Low Stock Report" << endl;
    cout << "11. Total Inventory Value" << endl;
    cout << "12. Sort by Price" << endl;
    cout << "13. Sort by Quantity" << endl;
    cout << "14. Sort by Name" << endl;
    cout << "0.  Exit" << endl;
    printDoubleLine();
}

int main()
{
    int choice = -1;

    while (choice != 0)
    {
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addItem(); 
            break;
        case 2:
            displayAllItems();
            break;
        case 3:
            searchByID();
            break;
        case 4:
            searchByName();
            break;
        case 5:
            searchByCategory();
            break;
        case 6:
            updateItem();
            break;
        case 7:
            deleteItem();
            break;
        case 8:
            stockIn();
            break;
        case 9:
            stockOut();
            break;
        case 10:
            lowStockReport();
            break;
        case 11:
            totalInventoryValue();
            break;
        case 12:
            sortByPrice();
            break;
        case 13:
            sortByQuantity();
            break;
        case 14:
            sortByName();
            break;
        case 0:
            cout << "Thank you for using Inventory Management System!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}