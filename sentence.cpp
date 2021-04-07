#include <bits/stdc++.h>
using namespace std;

struct letter_count{
    char letter;
    int count;
};

letter_count arr[27];

int main()
{
    string str, word;
    cout<<"Enter a sentence: ";
    getline(cin, str);

    // converting lower case letters in the string to the upper case
    for(int i = 0; i < str.length(); i++)
    {
        if(int(str[i]) >= 97 && int(str[i]) <= 122)
            str[i] = char(int(str[i])-32);
    }

    // used to split string
    istringstream ss(str);

    // storing each letter in the array
    int char_value = 65;
    for(int i = 0; i < 26; i++)
    {   
        arr[i].letter = char(char_value);
        char_value++; 
    }

    // reading each word of the string
    while(ss >> word)
    { 
        // checking the each word of the read word  
        for(int i = 0; i < word.length(); i++)
        {
            if(arr[int(word[i]-65)].letter == word[i] && arr[int(word[i]-65)].count == 0)
                arr[int(word[i]-65)].count = 1;
            else if(arr[int(word[i]-65)].letter == word[i] && arr[int(word[i]-65)].count >= 1)
                arr[int(word[i]-65)].count++; 
        }
    }

    //printing the characters with occurrences
    for(int i = 0; i < 26; i++)
    {
        cout<<arr[i].letter<<"\t"<<arr[i].count<<"\n";
    }

    return 0;
}