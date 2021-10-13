//a1744546
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable
{
private:
    vector<string> hash_table;
    vector<bool> tombstone;

public:

    HashTable()
    {
        //Initialise hash table
        for (int i = 0; i < 26; i++)
        {
            hash_table.push_back("");
            tombstone.push_back(0);
        }
    };


    int search(string str)
    {
        // a is ASCII 97
        int hashKey = str[str.length()-1] - 97;

        
        if (hash_table[hashKey] == str && tombstone[hashKey] == 0)
        {
            return hashKey;
        }
        else
        {
            //Search next elements if occupied
            int i = hashKey + 1;
            //loop 26times
            
            for(int stop = 0; stop<26; stop++)
            {
                if(i > 25)
                {
                    i = i-26;
                }else
                {
                    i++;
                }
                if (hash_table[i] == str && tombstone[i] == 0)
                {
                    return i;
                }
                //Table element not used
                else if (hash_table[i] == "" && tombstone[i] == 0)
                {
                    return -1;
                }
            }

            return 0;
        }
        return 0;
    };

    void insert(string str)
    {
        //Stop if already in table
        if (search(str) != -1)
        {
            return;
        }

        int hashKey = str[str.length()-1] - 97;

        //Insert if unoccupied
        if (hash_table[hashKey] == "" || tombstone[hashKey] == 1)
        {
            hash_table[hashKey] = str;
            tombstone[hashKey] = 0;
        }
        else
        {
            //Goto next element if occupied
            int i = hashKey + 1;
            for(int stop = 0; stop<26; stop++)
            {
                if(i > 25)
                {
                    i = i - 26;
                }else
                {
                    i++;
                }
                if (hash_table[i] == "" || tombstone[i] == 1)
                {
                    hash_table[i] = str;
                    tombstone[i] = 0;
                    return;
                }
            }

        }

        return;
    };

    void del(string str)
    {
        int hashKey = search(str);

        if (hashKey == -1)
        {
            return;
        }
        else
        {
            tombstone[hashKey] = 1;
        }
        return;
    }

    void pring()
    {

        for (int i = 0; i < (int)hash_table.size(); i++)
        {
            if (hash_table[i] != "" && tombstone[i] != 1)
            {

                cout << hash_table[i] << " ";

            }
        }
        cout << endl;
    };

};

int main()
{
    vector<string> commands;
    string line;

    //Takes input
    getline(cin, line);
    int tracker = -1;
    int commandNum = 0;
    for (unsigned i = 0; i < line.length(); i++)
    {
        //Push  space or end of line
        if (line[i] == ' ' || i == line.length()-1)
        {
        
            if (i == line.length()-1)
            {
                i++;
            }
            commands.push_back("");
        
            for (unsigned j = tracker + 1; j < i; j++)
            {
                commands[commandNum] += line[j];
            }
            tracker = i;
            commandNum++;
        }

    }

    HashTable hash_table;

    for (unsigned i = 0; i < commands.size(); i++)
    {
        //Insert
        if (commands[i][0] == 'A')
        {
            commands[i].erase(commands[i].begin());
            hash_table.insert(commands[i]);
        }
        //Delete
        else if (commands[i][0] == 'D')
        {
            commands[i].erase(commands[i].begin());
            hash_table.del(commands[i]);
        }
    }
    //Print
    hash_table.pring();

    return 0;
}
