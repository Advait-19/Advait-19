typedef struct {
    char* key;
    char* value;
}ht_item;

// Define the structure for the hash table
typedef struct{
    int size;
    int count;
    ht_item **items; // Array of pointers to hash items
}hash_table;






