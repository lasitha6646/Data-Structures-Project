#include "Header.h"
#include <iostream>
using namespace std;


int calcTotal(int a, int b, int c)
{
    int tot = a + b + c;
    return tot;


}

int main()
{
    Node Data_Item, * root = NULL;

    double a;
    int b, c, d;
    string k, p;
    root = Data_Item.insertFunc(root, 65, "St_2201", 10, 20, 30);
    root = Data_Item.insertFunc(root, 202, "St_2203", 90, 34, 78);
    root = Data_Item.insertFunc(root, 157, "St_4502", 98, 64, 2);
    root = Data_Item.insertFunc(root, 202, "St_6667", 21, 34, 56);
    root = Data_Item.insertFunc(root, 60, "St_1245", 99, 5, 33);
    root = Data_Item.insertFunc(root, 131, "St_8874", 76, 33, 22);
    Data_Item.showRankings(root, Data_Item);
    cout << "Enter the Student_ID of the student: ";
    cin >> k;
    cout << "Enter the marks for Mathematics : ";
    cin >> b;
    cout << "Enter the marks for Chemistry : ";
    cin >> c;
    cout << "Enter the marks for English : ";
    cin >> d;


    root = Data_Item.insertFunc(root, calcTotal(b, c, d), k, b, c, d);
    Data_Item.showRankings(root, Data_Item);



    cout << endl;


    cout << "Enter the Student ID of the student you want to delete: ";
    cin >> p;
    cout << endl;
    root = Data_Item.deleteNode(&root, p);




    string up_name;
    int mth, che, eg;
    cout << "Enter the Student ID of the student you want to update: ";
    cin >> up_name;
    if (Data_Item.searchby_id(root, up_name) == NULL) {
        cout << "\n >>>> Student Not Found !\n" << endl;
    }
    else
    {
        cout << "Enter the marks for Mathematics : ";
        cin >> mth;
        cout << "Enter the marks for Chemistry : ";
        cin >> che;
        cout << "Enter the marks for English : ";
        cin >> eg;
        root = Data_Item.updateNode(root, up_name, calcTotal(mth, che, eg), mth, che, eg);
        Data_Item.showRankings(root, Data_Item);
    }



    string find_s;
    cout << "\nEnter the Student ID of the student you want Find: ";
    cin >> find_s;
    Node* find = Data_Item.searchby_id(root, find_s);
    if (find == NULL) {
        cout << "\nNo student found\n" << endl;

    }
    else
    {
        cout << "\n\nStudent found>>>>\n\n ";
        cout << "Student ID             " << find_s << endl;
        cout << " Mathematics marks      " << find->m_marks << endl;
        cout << " Chemistry marks        " << find->ch_marks << endl;
        cout << " English marks          " << find->en_marks << endl;
        cout << " Total Marks            " << calcTotal(find->en_marks, find->ch_marks, find->m_marks) << endl;
        cout << " Rank                   " << find->rank << endl;
        cout << "\n\n";

    }
    int upper, lower;
    cout << "\nEnter the upper limit of the range you want to filter : ";
    cin >> upper;
    cout << "\nEnter the lower limit of the range you want to filter : ";
    cin >> lower;
    cout << "\n\n";
    Data_Item.printValueRange(root, lower, upper);



    return 0;
}