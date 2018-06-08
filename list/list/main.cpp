#include "Header.h"
using namespace std;

int main()
{
    LIST* begin = NULL;
    LIST* begin1 = NULL;
    LIST1* begin3 = NULL;
    LIST1* begin4 = NULL;
    
    A a[5] = { "Fedorov","Ivanov","Nesterenko","Petrov","Pupkin" };
    A b[5] = { "Egorov", "Kozlov", "Semenov", "Lobanov", "Uvarov" };
    A c[5] = { "Smit", "Fossil", "Klevan", "Denisuik", "Robenko" };
    A d[5] = { "Vasilyev", "Faradey", "Shimano", "Sokol", "Rud" };
    
    cout << "ОДНОСВЯЗНЫЙ:" << endl << endl;
    Init(&begin, a,4);
    Init(&begin1, b,4);
    
    cout << "List 1:" << endl;
    Print(&begin);
    cout << "List 2:" << endl;
    Print(&begin1);

    cout << endl;
    InsertTail(&begin, &begin1, 3);
    cout << "List 1:" << endl;
    Print(&begin);
    cout << endl;
    cout << "List 2:" << endl;
    Print(&begin1);
    
    Clear(&begin);
    Clear(&begin1);
    
    cout << "ДВУХСВЯЗНЫЙ:" << endl<< endl;
    Init_2way(&begin3,c,4);
    Init_2way(&begin4,d,4);
    
    cout << "List 1:" << endl;
    Print_2way(&begin3);
    cout << "List 2:" << endl;
    Print_2way(&begin4);
    cout << endl;
    
    InsertTail_2way(&begin3, &begin4, 2);
    cout << "List 1:" <<std::endl;
    Print_2way(&begin3);
    cout << "List 2:" << endl;
    Print_2way(&begin4);
    
    Clear_2way(&begin3);
    Clear_2way(&begin4);
    
}


