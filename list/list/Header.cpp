#include "Header.h"

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
