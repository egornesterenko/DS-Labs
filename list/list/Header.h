#include <iostream>

struct A
{
    const char* Name;
    
};

struct LIST
{
    A a;
    LIST* next;
    
} ;

struct LIST1
{
    A a;
    LIST1* next;
    LIST1* prev;
    
};


void Print(LIST **begin);
void Print_2way(LIST1 **begin);
void Init(LIST **begin, A a[], int num);
void Init_2way(LIST1 **begin, A a[], int num);
void InsertTail(LIST **begin, LIST **begin2, int l);
void InsertTail_2way(LIST1 **begin, LIST1 **begin2, int l);
void Clear(LIST **begin);
void Clear_2way(LIST1 **begin);
