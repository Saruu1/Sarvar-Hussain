#include<iostream>
#include<math.h>
using namespace std;
class Node{
    int val;
    Node *next;
public:
    void set_val(int x){   val = x;}
    int get_val(){   return val; }
    void set_next(Node *n){   next = n; }
    Node* get_next(){   return next; }
};
Node *head = NULL, *tail = NULL;
void insert_before(){

    int i, data;
    cout<<"Enter element BEFORE which data is to be inserted: ";
    cin>>i; 
    cout<<"Enter new data: ";
    cin>>data;
    
    Node *tmp = new Node();
    tmp->set_val(data);
    Node *t = head;
    
    if (t->get_val() == i){
        tmp->set_next(t);
        head = tmp;
    }
    
    else if(head->get_next() == NULL){
        cout<<"\n**Element not found**\n\n";
    }
    
    else{
        while(t->get_next()->get_val() != i && t->get_next() != tail){
            t = t->get_next();
        }

        if(t->get_next()->get_val() == i){
            tmp->set_next(t->get_next());
            t->set_next(tmp);
        }
        else cout<<"\n**Element not found**\n\n";
    }
}
void insert_after(){
    int data, i;
    cout<<"Enter element AFTER which data is to be inserted: ";
    cin>>i;
    cout<<"Enter new data: ";
    cin>>data;
    
    Node *tmp = new Node;
    tmp->set_val(data);
    Node *t = head;
    
    while (t->get_val() != i && t != tail){
        t = t->get_next();
    }
    if (t->get_val() == i){
        tmp->set_next(t->get_next());
        t->set_next(tmp);
        if (t == tail) 
            tail = tmp;
    }
    else cout<<"\n**Element not found**\n\n";
}
void view_frequency_val(){
    int data;
    cout<<"Enter element for checking its frequency: ";
    cin>>data;
    int count = 0;
    Node *t = head;
    while(t != NULL){
        if(t->get_val() == data){
            count++;
        }
        t = t->get_next();
    }
    cout<<"Frequency of "<<data<<" is "<<count<<endl;
}
void view_min_max_val(){
    if(head == NULL){
        cout<<"Empty List.\n";
        return;
    }
    else{
        Node *t = head;
        int min = t->get_val();
        int max = t->get_val();
        while(t != NULL){
            if(t->get_val() < min){
                min = t->get_val();
            }
            if(t->get_val() > min){
                max = t->get_val();
            }
            t = t->get_next();
        }
    cout<<"Min val: "<<min<<endl;
    cout<<"Max val: "<<max<<endl;
    }
}
bool isprime(int n){
    if(n < 2 )
        return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}
void create_list(){
    int n;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    cout<<"Enter data:\n";
    for(int i = 0; i < n; i++){
        Node *tmp = new Node();
        int x;
        cin>>x;
        tmp->set_val(x);
        tmp->set_next(NULL);
        if (i == 0){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->set_next(tmp);
            tail = tmp;
        }
    }
}
void view_list(){
    Node *t = head;
    cout<<"List:\n";
    while(t != NULL){
        cout<<t->get_val()<<" ";
        t = t->get_next();
    }
    cout<<endl;
}
void view_even(){
    Node *t = head;
    cout<<"Even List:\n";
    while(t != NULL){
        if(t->get_val() % 2 == 0){
            cout<<t->get_val()<<" ";
        }
        t = t->get_next();
    }
    cout<<endl;
}
void view_odd(){
    Node *t = head;
    cout<<"Odd List:\n";
    while(t != NULL){
        if(t->get_val() % 2 != 0){
            cout<<t->get_val()<<" ";
        }
        t = t->get_next();
    }
    cout<<endl;
}
void view_prime(){
    Node *t = head;
    cout<<"Prime List:\n";
    while(t != NULL){
        if(isprime(t->get_val())){
            cout<<t->get_val()<<" ";
    }
    t = t->get_next();
    }
    cout<<endl;
}
void view_sorted_ascending(){
    if(head == NULL){
        return;
    }
    else{
        Node *t = head;
        Node *index = NULL;
        while (t != NULL){
            index = t->get_next();
            while(index != NULL){
                if(t->get_val() > index->get_val()){  
                    int tmp = t->get_val();  
                    t->set_val(index->get_val());  
                    index->set_val(tmp);  
                }
                index = index->get_next();
            }
            t = t->get_next();
        }
        cout<<"After sorting in ascending order, ";
        view_list();
    }
}
void view_sorted_descending(){
    if(head == NULL){
        return;
    }
    else{
        Node *t = head;
        Node *index = NULL;
        while (t != NULL){
            index = t->get_next();
            while(index != NULL){
                if(t->get_val() < index->get_val()){  
                    int tmp = t->get_val();  
                    t->set_val(index->get_val());  
                    index->set_val(tmp);  
                }
                index = index->get_next();
            }
            t = t->get_next();
        }
        cout<<"After sorting in ascending order, ";
        view_list();
    }
}
void delete_all_instances(){
    int data;
    cout<<"Enter element to be deleted: ";
    cin>>data;

    Node *t = head;
    Node *prev = NULL;
    bool flag = false;
    while(true){
        if(head->get_val() == data){
            head = t->get_next();
            flag = true;
            delete t;
        }
        
        while(t != NULL){
            if(t->get_val() != data){
                prev = t;
                t = t->get_next();
            }
            else if(flag == true)
                continue;
            else if(t->get_val() == data)
                flag = true;
        }
        if(t == NULL){
            if(flag) cout<<"Element(s) deleted";
            else cout<<"Element not present\n";
            break;
        }
        prev->set_next(t->get_next());
        delete t;
    }
}
void create_sorted_list(){
    int n;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    cout<<"Enter data:\n";
    for(int i = 0; i < n; i++){
        Node *tmp = new Node();
        int data;
        cin>>data;
        tmp->set_val(data);
        tmp->set_next(NULL);
        if (i == 0){
            head = tmp;
            tail = tmp;
        }
        else{
            Node *t = head, *prev;
            while (t != NULL && t->get_val() < data)
            {
                prev = t;
                t = t->get_next();
            }
            if (t == head)
            {
                tmp->set_next(head);
                head = tmp;
            }
            else if (t == NULL)
            {
                tail->set_next(tmp);
                tail = tmp;
            }
            else
            {
                tmp->set_next(t);
                prev->set_next(tmp);
            }
        }
    }
}
int main()
{
    int ch;
    bool flag = false;
    while(1){
        cout<<"Enter an option:\n";
        cout<<"1.Create List\n2.View List\n3.View Even List\n4.View Odd List\n5.View Prime List\n5.View Prime List\n6.View Min and Max Values\n7.View Frequency of an Element\n8.View Sorted List (Ascending)\n9.View Sorted List (Descending)\n10.Insert (Before Element)\n11.Insert (After Element)\n12.Create Sorted List\n13.Delete all instances of Element\n\n";
        cout<<"Enter 0 to exit.\n";
        cin>>ch;
        if(flag == false){
            if(ch == 1){
                create_list();
                flag = true;
            }
            else if(ch == 12){
                create_sorted_list();
                flag = true;
            }
            else cout<<"* Create a list first. *\n\n";
        }
        else{
        if(ch == 1){
            create_list();
            flag = true;
        }
        else if(ch == 2){
            view_list();
        }
        else if(ch == 3){
            view_even();
        }
        else if(ch == 4){
            view_odd();
        }
        else if(ch == 5){
            view_prime();
        }
        else if(ch == 6){
            view_min_max_val();
        }
        else if(ch == 7){
            view_frequency_val();
        }
        else if(ch == 8){
            view_sorted_ascending();
        }
        else if(ch == 9){
            view_sorted_descending();
        }
        else if(ch == 10){
            insert_before();
        }
        else if(ch == 11){
            insert_after();
        }
        else if(ch == 12){
            create_sorted_list();
            flag = true;
        }
        else if(ch == 13){
            delete_all_instances();
        }
        else if(ch == 0)
            return 0;
        else cout<<"\n** Please enter a valid choice. ***\n\n";
        }
    }
    return 0;
}
