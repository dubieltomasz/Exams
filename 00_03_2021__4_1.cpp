#include <iostream>
#include <fstream>
using namespace std;

void times(string fileName, string countryCode)
{
    fstream file;
    string line, newCountryCode, countryCode1, countryCode2, countryCode3;
    int count = 0;

    file.open(fileName, ios::in);
        while(!file.eof())
        {
            getline(file, line);
            countryCode1 = line[0];
            countryCode2 = line[1];
            countryCode3 = line[2];
            
            if(countryCode2 != " ")
                newCountryCode = countryCode1 + countryCode2 + countryCode3;
            else
                newCountryCode = countryCode1 + countryCode2;

            if(countryCode == newCountryCode)
                count ++;
        }
    file.close();
    
    cout << countryCode << "\t" << count << endl;
}

int import(string fileName, string array[])
{
    fstream file;
    string line, countryCode1, countryCode2, countryCode3;
    int i = 0;

    file.open(fileName, ios::in);
        while(!file.eof())
        {
            getline(file, line);
            countryCode1 = line[0];
            countryCode2 = line[1];
            countryCode3 = line[2];
        
            if(countryCode2 != " ")
                array[i] = countryCode1 + countryCode2 + countryCode3;
            else
                array[i] = countryCode1 + countryCode2;

            i++;
        }
    file.close();

    return i;
}

void cut(string array[], int size)
{
    for(int i = 0; i < size; i++)
        for(int j = i+1; j < size; j++)
            if(array[i] == array[j])
                array[j] = "";
}

int main()
{
    string fileName = "galerie.txt", array[50];
    int size;

    size = import(fileName, array);

    cut(array, size);

    for(int j = 0; j < size; j++)
        if(array[j] != "")
            times(fileName, array[j]);

    return 0;
}
