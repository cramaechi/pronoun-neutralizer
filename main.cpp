//Program replaces masculine pronouns with gender-neutral pronouns.
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void input(string& s);
//Reads in a line of text and stores it in the string variable s.

void neutralizePronouns(string& s);
//Precondition: s is a non-empty string.
//Postcondition: Replaces all masculine pronouns with gender-neutral pronouns.

void output(string& s);
//Prints the modified s.

int main()
{
    string s;
    char ans; 

    do
    {
        input(s);
        neutralizePronouns(s);
        output(s);

        cout<<"\nWould like to enter input more text (y/n)? ";
        cin>>ans;
        cin.ignore(1, '\n');
        cout<<endl<<endl;
    }while(ans == 'y' || ans == 'Y');

    return 0;
}

void input(string& s)
{
    cout<<"Enter a sentence: ";
    getline(cin, s);
    cout<<endl;
}

void neutralizePronouns(string& s)
{
    char cstring[s.length()];
    strcpy(cstring, s.c_str());
    char *word = strtok(cstring, " \n~`!@#$%^&*()-_+={[}]|:;\"'<,>.?/");

    while (word != NULL)
    {
        if (!strcmp(word, "him"))
        {
            int pos = s.find("him");
            while (pos >= 0)
            {
                if (pos < 7 || (pos >= 7 && s.substr(pos - 7, 7) != "her or "))
                {
                    s.replace(pos, 3, "her or him");
                    break;
                }
                pos = s.find(word, pos + 1);
            }
        }
        else if (!strcmp(word, "he") || !strcmp(word, "He"))
        {
            int pos;
            if (islower(word[0]))
                pos = s.find("he");
            else
                pos = s.find("He");

            while (pos >= 0)
            {
                if (((pos == 0 && isspace(s[pos + 2])) || (pos > 0 && 
                    isspace(s[pos - 1]) && (isspace(s[pos + 2]) || 
                    ispunct(s[pos + 2])))) && (pos < 7 || (pos >= 7 && 
                    (s.substr(pos - 7, 7) != "she or " && 
                    s.substr(pos - 7, 7) != "She or "))))
                {
                    if (islower(word[0]))
                    {
                        s.replace(pos, 2, "she or he");
                        break;
                    }
                    else
                    {
                        s.replace(pos, 2, "She or he");
                        break;
                    }
                }
                pos = s.find(word, pos + 1);
            }
        }
        else if (!strcmp(word, "his") || !strcmp(word, "His"))
        {
            int pos;
            if (islower(word[0]))
                pos = s.find("his");
            else
                pos = s.find("His");

            while (pos >= 0)
            {
                if ((pos == 0 && isspace(s[pos - 1])) || (pos > 0 &&
                            isspace(s[pos - 1]) && isspace(s[pos + 3])))
                {
                    if (islower(word[0]))
                    {
                        s.replace(pos, 3, "her(s)");
                        break;
                    }
                    else
                    {
                        s.replace(pos, 3, "Her(s)");
                        break;
                    }
                }
                pos = s.find(word, pos + 1);
            }
        }

        word = strtok(NULL, " \n~`!@#$%^&*()-_+={[}]|:;\"'<,>.?/");
    }
}

void output(string& s)
{
    cout<<"Gender neutralized sentence: "<< s<<endl;
}
