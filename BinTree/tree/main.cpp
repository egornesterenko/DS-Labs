#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *rigth;
};

node * tree=NULL;
node * copytree = NULL;
void add(int a,node **t);
void print (node *t,int u);
void copy (node * t, node * &tcop);

int main ()
{
    int s;
    cout<<"ведите корень дерева  ";
    cin>>s;
    
    while (s!=000) {
        add(s, &tree);
        s = NULL;
        cout<<"ведите число (или 000 если хотите остановить ввод)  ";
        cin>>s;
    }
    
    cout << endl;
    cout << endl;
    print(tree,0);
    print (copytree, 0);
    copy(tree, copytree);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    print(copytree, 0);
    
    cout << "ведите элемент для добавления, или 000 что бы выйти  ";
    cin >> s;
    while (s!= 000)  {
        add(s, &tree);
        print(tree,0);
        copy(tree, copytree);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        print(copytree, 0);
        cout << "ведите элемент для добавления, или 000 что бы выйти  ";
        cin >> s;
    } }

void add(int a,node **t)
{
    if ((*t)==NULL)
    {
        (*t)=new node;
        (*t)->data=a;
        (*t)->left=(*t)->rigth=NULL;
        return;
    }
    if (a>(*t)->data) add(a,&(*t)->rigth);
    else if (a<(*t)->data) add(a,&(*t)->left);
}

void print (node *t,int u)
{
    if (t==NULL) return;
    else
    {
        print(t->rigth,++u);
        for (int i=0;i<u;++i) cout<<"     ";
        cout<<"---"<<t->data<<endl;
        u--;
    }
   print(t->left,++u);
}
void copy (node * t, node * &tcop)
{
    
    if (t == NULL)
        tcop = NULL;
    else
    { tcop = new node;
        tcop->data = t->data;
        copy(t->left, tcop->left);
        copy(t->rigth, tcop->rigth);
    }
}
