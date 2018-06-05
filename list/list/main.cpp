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
    
    
    std::cout << "ОДНОСВЯЗНЫЙ:" <<std::endl<<std::endl;
    Init(&begin, a,4);
    Init(&begin1, b,4);
    std::cout << "List 1:" <<std::endl;
    Print(&begin);
    std::cout << "List 2:" <<std::endl;
    Print(&begin1);
    
    
    std::cout << std::endl;
    InsertTail(&begin, &begin1, 3);
    std::cout << "List 1:" <<std::endl;
    Print(&begin);
    std::cout << std::endl;
    std::cout << "List 2:" <<std::endl;
    Print(&begin1);
    Clear(&begin);
    Clear(&begin1);
    
    std::cout << "ДВУХСВЯЗНЫЙ:" <<std::endl<<std::endl;
    Init_2way(&begin3,c,4);
    Init_2way(&begin4,d,4);
    
    std::cout << "List 1:" <<std::endl;
    Print_2way(&begin3);
    std::cout << "List 2:" <<std::endl;
    Print_2way(&begin4);
    std::cout << std::endl;
    InsertTail_2way(&begin3, &begin4, 2);
    std::cout << "List 1:" <<std::endl;
    Print_2way(&begin3);
    std::cout << "List 2:" <<std::endl;
    Print_2way(&begin4);
    Clear_2way(&begin3);
    Clear_2way(&begin4);
    
}
void Print(LIST **begin){
    LIST *temp;
    temp = *begin;
    while(temp != NULL){
        std::cout<<temp->a.Name<<std::endl;
        temp = temp->next;
    }
    std::cout<<std::endl;
}
void Print_2way(LIST1 **begin){
    LIST1 *temp;
    temp = *begin;
    while(temp != NULL){
        std::cout<<temp->a.Name<<std::endl;
        temp = temp->next;
    }
    std::cout<<std::endl;
}

void Init(LIST **begin, A a[],int num)
{
    LIST* p;
    for (int i(0); i < num; i++)
    {
        p = new LIST;
        p->a = a[i];
        p->next = *begin;
        *begin = p;
    }
}
void Init_2way(LIST1 **begin, A a[],int num)
{
    LIST1* p;
    for (int i(0); i < num; i++)
    {
        p = new LIST1;
        p->a = a[i];
        p->next = *begin;
        *begin = p;
        p->prev = *begin;
    }
}

void InsertTail(LIST **begin, LIST **begin2, int l)
{
    LIST* last = *begin2;
    while (last->next) last = last->next;
    last->next = *begin;
    for (int i=0; i<l; i++){
        last = last->next;
    }
    *begin = last->next;
    last->next=NULL;
}


void InsertTail_2way(LIST1 **begin, LIST1 **begin2, int l)
{
    LIST1* last = *begin2;
    while (last->next) last = last->next;
    last->next = *begin;
    for (int i=0; i<l; i++){
        last->prev = last;
        last = last->next;
    }
    *begin = last->next;
    last->next=NULL;
}

void Clear(LIST **begin){
    LIST* p = *begin;
    while(p != NULL){
        delete *begin;
        p = p-> next;
        *begin = p;
    }
}
void Clear_2way(LIST1 **begin){
    LIST1* p = *begin;
    while(p != NULL){
        p -> prev = *begin;
        delete *begin;
        p = p-> next;
        *begin = p;
    }
}


