#include "Structers.h"

void createList(Car*& List, int n){
Car* newCar;

for(int i=0;i<n;i++){
    newCar=new Car;

    cout<< "Enter information about a car.\n";
    cout<<"Type:";
    cin>>newCar->type;
    cout<<"Country:";
    cin>>newCar->country;
    cout<<"Year:";
    cin>>newCar->year;

    newCar->next = 0;

    if(List==NULL){
        List=newCar;
    }
    else{
        Car* newCar1 = List;
        while(newCar1->next){
            newCar1=newCar1->next;
        }
         newCar1->next = newCar;
    }
}
}


//вывод списка
void outList(Car* List){
Car* newCar = List;
    cout<<"Information.\n";
while (newCar){
    cout<<"Type:"<<newCar->type<<"\nCountry:"<<newCar->country<<"\nYear:"<<newCar->year<<endl;
    newCar = newCar->next;
    }
}
//поискк элемента по значению
Car* findElement(Car* List,string value){

Car* pointer= List;

while(pointer){
    if(pointer->type==value)
        break;
    pointer=pointer->next;
}
return pointer;
}
//вставка элемента
Car* pushEl(Car* List){
Car *temp, *ptr, *pointer=List;

temp=new Car;
    cout<< "Enter information about a new car.\n";
    cout<<"Type:";
    cin>>temp->type;
    cout<<"Country:";
    cin>>temp->country;
    cout<<"Year:";
    cin>>temp->year;

while(pointer->next){
    if (pointer->next->type==temp->type){
        if(pointer->next->year<temp->year){
        break;
        }
      }else if(pointer->type==temp->type){
        break;
      }
pointer=pointer->next;

}
//вставка
ptr=pointer->next;
pointer->next=temp;
temp->next = ptr;

return temp;
}
//создание списка моделей машин
void createNewList(Models*& List, int m, Car* L){
Models* ptr;

for(int i=0;i<m;i++){
    ptr=new Models;

    cout<< "Enter information.\n";
    cout<<"Type:";
    cin>>ptr->type;

    ptr->next = 0;

    if(List==NULL){
        List=ptr;
    }
    else{
        Models* ptr1 = List;
        while(ptr1->next){
            ptr1=ptr1->next ;
        }
         ptr1->next = ptr;
    }
    ptr->begining = findElement(L,ptr->type);
}

}
//вывод списка моделей машин

void outNewList(Models* List){
Models* ptr = List;
   cout<<"Information about cars.\n";
while (ptr){
    cout<<"Type:"<<ptr->type<<endl;
    ptr = ptr->next;
    }
}
//удаление элементов
Car* deleteModel(Models* List, Car* L, string value){
   Models* pointer= List;
   Car* temp;

//поиск указателя на первый удаляемый элемент
while(pointer){
    if(pointer->type==value){
        break;
        }
    pointer=pointer->next;
}

temp=pointer->begining;//для удобства

while(temp->type==value && temp->next){
    //Трюк Вирта
    temp->country=temp->next->country;
    temp->type=temp->next->type;
    temp->year=temp->next->year;
    temp->next = temp->next->next;
}
//удаление
if(temp->next==0 || temp->next->type!=value){
        temp = temp->next;
    if(temp == L){
        L=temp->next;
        free(temp);
    }
}
return L;
}


