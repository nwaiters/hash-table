//  Created by Nyra Waiters on 4/29/25.
//

#include <iostream>
using namespace std;

const int CAPACITY = 10;

void initTable(int data[]);
void printTable(int data[]);
int hash_function(int key);
void hashInsert(int data[], int key);
bool key_occurs(int data[], int search_key);


int main()
{
    int data[CAPACITY];
    
    initTable(data);
    
    hashInsert(data, 10);
    hashInsert(data, 22);
    hashInsert(data, 11);
    hashInsert(data, 31);
    hashInsert(data, 24);
    hashInsert(data, 88);
    hashInsert(data, 38);
    hashInsert(data, 21);

    cout << "Part 1: Hash table" << endl;
    printTable(data);
    
    cout << "\n\nPart 2: Checking numbers in the hash table" << endl;
    int sk1 = 11, sk2 = 31, sk3 = 23;
    
    if (key_occurs(data, sk1))
    {
        cout << sk1 << " is found" << endl;
    }
    else
    {
        cout << sk1 << " is not found" << endl;
    }
    
    if (key_occurs(data, sk2))
    {
        cout << sk2 << " is found" << endl;
    }
    else
    {
        cout << sk2 << " is not found" << endl;
    }
    
    if (key_occurs(data, sk3))
    {
        cout << sk3 << " is found" << endl;
    }
    else
    {
        cout << sk3 << " is not found" << endl;
    }
    
    cout << endl;
    
    
    return 0;
}

void initTable(int data[])
{
    for (int i = 0; i < CAPACITY; i++)
    {
        data[i] = -1;
    }
}

void printTable(int data[])
{
    for (int i = 0; i < CAPACITY; i++)
    {
        cout << data[i] << " ";
    }
}

int hash_function(int key)
{
    return (key % CAPACITY);
}

void hashInsert(int data[], int key)
{
    int index = hash_function(key);
    int i = 0;
    int pos;
    
    if (data[i] == -1)
    {
        data[i] = key;
    }
    else
    {
        do
        {
            pos = (index + (i*i)) % CAPACITY;
            if (data[pos] == -1)
            {
                data[pos] = key;
                return;
            }
            i++;
            
        }while (i < CAPACITY);
    }
}

bool key_occurs(int data[], int search_key)
{
    int index = hash_function(search_key);
        int i = 0;
        int pos;

        do
        {
            pos = (index + i * i) % CAPACITY;

            if (data[pos] == -1)
            {
                return false;
            }

            if (data[pos] == search_key)
            {
                return true;
            }

            i++;
        } while (i < CAPACITY);

    return false;
}


