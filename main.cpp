#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("email.in");

    if(fin.fail())
    {
        perror("email.in");
        return 1;
    }

    cout << "If you want to sign up for an email press 1. If you want to log into your email click 2." << endl;
    int one;
    cin >> one;

    // capture the size of the file

    string tempInput;
    int Size = 0;

    while(getline(fin, tempInput))
        Size++;

    bool alteredFile = false;

    if(one == 1)
    {
        ofstream fout;
        fout.open("email.out", ios::app);

        if(fout.fail())
        {
            perror("email.out");
            return 1;
        }

        cout << "Enter your username (all lowercase): ";
        string username;
        cin >> username;
        cout << "Enter your password: ";
        string password;
        cin >> password;
        cout << "Confirm your password: ";
        string confirmPassword;
        cin >> confirmPassword;

        if(password != confirmPassword)
        {
            cout << "The passwords that you have entered do not match. Try again." << endl;
            return 1;
        }

        // check to see if another account has already been made with the same username

        string tempString;
        fin.clear();
        fin.seekg(0);

        for(int i = 0; i < 2*Size; i++)
        {
            fin >> tempString;
            if(tempString.compare(username) == 0 && i % 2 == 0)
            {
                cout << "There is already an account with this same username. Please try again with a different one." << endl;
                return 1;
            }
        }

        fout << username << " " << password << endl;
        cout << "We have created your account!" << endl;
        cout << username << " " << password << endl;
        alteredFile = true;
    }
    else if(one == 2)
    {
        fin.clear();
        fin.seekg(0);

        ofstream fout;
        fout.open("email.out");
        if(fout.fail())
        {
            perror("email.out");
            return 1;
        }

        cout << "Enter your username: ";
        string username;
        cin >> username;

        string tempString;
        bool foundUsername = false;

        for(int i = 0; i < 2*Size; i++)
        {
            fin >> tempString;
            if(username.compare(tempString) == 0 && i % 2 == 0)
            {
                foundUsername = true;
                cout << "Enter your password: ";
                string password;
                cin >> password;
                fin >> tempString;

                if(password.compare(tempString) == 0)
                    cout << "Great! You are in the system!" << endl;
                else cout << "Sorry, but the password has been entered in incorrectly. Please try again." << endl;
            }
        }

        if(foundUsername == false)
            cout << "Sorry, but the username has not been entered in correctly. Please try again." << endl;
    }
    else
    {
        cout << "You have not entered a valid command. Please try again." << endl;
        return 1;
    }

    // copy the contents from the altered file over to the unaltered file

    fin.clear();
    fin.seekg(0);

    if(alteredFile == true)
    {
        // copy the contents of ofstream into ifstream

        fin.close();

        ofstream copyContents;
        ifstream copyContents2;

        copyContents.open("email.in");
        copyContents2.open("email.out");

        string copyString2;

        if(copyContents && copyContents2)
        {
            while(getline(copyContents2, copyString2))
                copyContents << copyString2 << "\n";
        }

        copyContents.close();
        copyContents2.close();

        return 0;
    }
    else
    {
        string copyString;
        ofstream fout;
        fout.open("email.out");
        if(fout.fail())
        {
            perror("email.out");
            return 1;
        }

        if(fin && fout)
        {
            while(getline(fin, copyString))
                fout << copyString << "\n";
        }
    }

    fin.close();

    return 0;
}
