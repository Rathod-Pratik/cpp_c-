#include <iostream>
#include <list>
#include <string>

using namespace std;

class Hash_table {
private:
    static const int HashGroups = 10; // Number of groups in the hash table
    list<pair<int, string>> table[HashGroups]; // Array of lists for chaining

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    void printTable();
};

// Checks if the hash table is empty
bool Hash_table::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < HashGroups; i++) {
        sum += table[i].size();
    }
    return sum == 0;
}

// Hash function to determine the index based on the key
int Hash_table::hashFunction(int key) {
    return key % HashGroups;
}

// Inserts an item; updates if key exists, adds otherwise
void Hash_table::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue]; // Use reference to the cell
    bool keyExists = false;

    for (auto &item : cell) {
        if (item.first == key) { // If key exists, update value
            keyExists = true;
            item.second = value;
            cout << "Key exists, value replaced" << endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value); // Insert new item if key doesn't exist
    }
}

// Removes an item by key, if it exists
void Hash_table::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    bool keyExist = false;

    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) { // Key found, erase item
            keyExist = true;
            it = cell.erase(it);
            cout << "Item removed" << endl;
            break;
        }
    }

    if (!keyExist) {
        cout << "Key not found" << endl;
    }
}

// Prints all key-value pairs in the hash table
void Hash_table::printTable() {
    for (int i = 0; i < HashGroups; i++) {
        if (table[i].empty()) continue; // Skip empty cells

        for (const auto &item : table[i]) {
            cout << "[INFO] Key: " << item.first << " Value: " << item.second << endl;
        }
    }
}

int main() {
    Hash_table ht;

    if (ht.isEmpty()) {
        cout << "Hash table is empty." << endl;
    } else {
        cout << "Hash table is not empty!" << endl;
    }

    // Inserting items into the hash table
    ht.insertItem(110, "rathod");
    ht.insertItem(120, "mohan");
    ht.insertItem(130, "rahul");
    ht.insertItem(140, "anish");
    ht.insertItem(150, "krish");

    ht.printTable(); // Print all items

    // Removing items from the hash table
    ht.removeItem(130);
    ht.removeItem(190); // Key that doesn't exist

    return 0;
}
