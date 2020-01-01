#include "Structers.h"
#include "windows.h"
using namespace std;

//создание списка
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

	//Если нашелся элемент, который нужно удалить
	if (pointer && pointer->begining)
	{
		temp = pointer->begining;//для удобства

		while (temp->type == value && temp->next) {
			//Трюк Вирта
			temp->country = temp->next->country;
			temp->type = temp->next->type;
			temp->year = temp->next->year;
			temp->next = temp->next->next;
		}

		//удаление
		if (temp->next == 0 || temp->next->type != value) {
			temp = temp->next;
			if (temp == L) {
				L = temp->next;
				free(temp);
			}
		}
	}
return L;
}


int main()
{   SetConsoleCP(866);
	SetConsoleOutputCP(866);
    Car* List = NULL;
    Models* Spisk = NULL;
    int var;
while(var){
    system("cls");
    cout<<"Меню:\n"<<"1.Создание модельного списка машин.\n2.Вывод модельного списка машин.\n3.Поиск элемента в модельном списке\n4.Вставка информации о новой машине.\n5.Создание списка моеделей машин\n6.Вывод списка машин\n7.Удаление информации о машинах определённой модели\n0.Выход\n";

    cout<<"Выберите действие:";
    cin>>var;

    switch(var){
        case 1:{

            int n=4;
            //создание списка машин
            createList(List,n);
            system("pause");
            break;
        }
        case 2:{
            //вывод списка машин
            outList(List);
            system("pause");
            break;
        }

        case 3:{
            //поиск элемента
            cout<<"ELEMENT:\n";
            Car* Lst = findElement(List, "Nissan");
            while (Lst && Lst->type=="Nissan"){
                cout<<"Type:"<<Lst->type<<"\nCountry:"<<Lst->country<<"\nYear:"<<Lst->year<<endl;
                Lst = Lst->next;
            }
            system("pause");
            break;
        }
        case 4:{
            //вставка элемента
            pushEl(List);
            system("pause");
            break;
        }
        case 5:{
            int m=2;
            createNewList(Spisk,m, List);
            system("pause");
            break;
        }
        case 6:{
            outNewList(Spisk);
            system("pause");
            break;
        }
        case 7:{
            //удаление элементов
            deleteModel(Spisk,List, "BMW");
            system("pause");
            break;
        }
        case 0:{
            exit(0);
            system("pause");
            break;
        }
        default:
            cout<<"Выберите число от 0 до 7\n";
            system("pause");
            break;
    }
}
    return 0;
}
