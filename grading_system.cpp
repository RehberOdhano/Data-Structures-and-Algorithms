#include <iostream>
using namespace std;

struct student{

    int ID;
    string name;
    int prelim;
    int mid_term;
    int preFinal;
    int tentative_final;
};

student s[3];

void insertStudent(int i)
{
    cout<<"Enter ID Number: ";
    cin>>s[i].ID;
    cout<<"Enter your name: ";
    cin>>s[i].name;
    cout<<"Enter prelim: ";
    cin>>s[i].prelim;
    cout<<"Enter midterm: ";
    cin>>s[i].mid_term;
    cout<<"Enter preFinal: ";
    cin>>s[i].preFinal;
    cout<<"Enter tentative_final: ";
    cin>>s[i].tentative_final;
    cout<<"\n";
}

int main()
{

    for(int i = 0; i < 3; i++)
        insertStudent(i);

    float final_grade;

    cout<<"ID No"<<"\t"<<"Name"<<"\t"<<"PreLim"<<"\t"<<"MidTerm"<<"\t"<<"TentativeFinal\t";
    cout<<"FG"<<"\t"<<"Pt Grade"<<"\t"<<"Remarks\n";

    for(int i = 0; i < 3; i++)
    {
        final_grade = (s[i].prelim * 0.2) + (s[i].mid_term * 0.2) + 
                      (s[i].preFinal * 0.2) + (s[i].tentative_final * 0.4);

        if(final_grade >= 97 && final_grade <= 100)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"1.00 ";
            cout<<"Passed\n";
        }
        else if(final_grade >= 94 && final_grade <= 96)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"1.25 ";
            cout<<"Passed\n";
        }
        else if(final_grade >= 91 && final_grade <= 93)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"1.50 ";
            cout<<"Passed\n";
        }
        else if(final_grade >= 88 && final_grade <= 90)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"1.75 ";
            cout<<"Passed\n";
        }
        else if(final_grade >= 85 && final_grade <= 87)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"2.00 ";
            cout<<"Passed\n";
        }
        else if(final_grade >= 82 && final_grade <= 84)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"2.25 ";
            cout<<"Passed\n";
        }
        else if(final_grade >= 80 && final_grade <= 81)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"2.50 ";
            cout<<"Passed\n";
        }
        else if(final_grade >= 78 && final_grade <= 79)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"2.75 ";
            cout<<"Passed\n";
        }
        else if(final_grade >= 75 && final_grade <= 77)
        {
            cout<<s[i].ID<<" ";
            cout<<s[i].name<<" ";
            cout<<s[i].prelim<<" ";
            cout<<s[i].mid_term<<" ";
            cout<<s[i].preFinal<<" ";
            cout<<s[i].tentative_final<<" ";
            cout<<final_grade<<" ";
            cout<<"3.00 ";
            cout<<"Passed\n";
        }
        else if(final_grade <= 74)
        {
            cout<<s[i].ID<<"\t";
            cout<<s[i].name<<"\t";
            cout<<s[i].prelim<<"\t";
            cout<<s[i].mid_term<<"\t";
            cout<<s[i].preFinal<<"\t";
            cout<<s[i].tentative_final<<"\t";
            cout<<final_grade<<"\t";
            cout<<"5.00 ";
            cout<<"Failed\n";
        }
    }

    return 0;
}