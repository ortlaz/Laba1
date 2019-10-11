#include "Structers.h"
#include "windows.h"
using namespace std;

//�������� ������
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


//����� ������
void outList(Car* List){
Car* newCar = List;
    cout<<"Information.\n";
while (newCar){
    cout<<"Type:"<<newCar->type<<"\nCountry:"<<newCar->country<<"\nYear:"<<newCar->year<<endl;
    newCar = newCar->next;
    }
}
//������ �������� �� ��������
Car* findElement(Car* List,string value){

Car* pointer= List;

while(pointer){
    if(pointer->type==value)
        break;
    pointer=pointer->next;
}
return pointer;
}
//������� ��������
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
//�������
ptr=pointer->next;
pointer->next=temp;
temp->next = ptr;

return temp;
}
//�������� ������ ������� �����
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
//����� ������ ������� �����

void outNewList(Models* List){
Models* ptr = List;
   cout<<"Information about cars.\n";
while (ptr){
    cout<<"Type:"<<ptr->type<<endl;
    ptr = ptr->next;
    }
}
//�������� ���������
Car* deleteModel(Models* List, Car* L, string value){
   Models* pointer= List;
   Car* temp;

//����� ��������� �� ������ ��������� �������
while(pointer){
    if(pointer->type==value){
        break;
        }
    pointer=pointer->next;
}

	//���� ������� �������, ������� ����� �������
	if (pointer && pointer->begining)
	{
		temp = pointer->begining;//��� ��������

		while (temp->type == value && temp->next) {
			//���� �����
			temp->country = temp->next->country;
			temp->type = temp->next->type;
			temp->year = temp->next->year;
			temp->next = temp->next->next;
		}

		//��������
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
{   SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    Car* List = NULL;
    Models* Spisk = NULL;
    int var;
while(var){
    system("cls");
    cout<<"����:\n"<<"1.�������� ���������� ������ �����.\n2.����� ���������� ������ �����.\n3.����� �������� � ��������� ������\n4.������� ���������� � ����� ������.\n5.�������� ������ �������� �����\n6.����� ������ �����\n7.�������� ���������� � ������� ����������� ������\n0.�����\n";

    cout<<"�������� ��������:";
    cin>>var;

    switch(var){
        case 1:{

            int n=4;
            //�������� ������ �����
            createList(List,n);
            system("pause");
            break;
        }
        case 2:{
            //����� ������ �����
            outList(List);
            system("pause");
            break;
        }

        case 3:{
            //����� ��������
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
            //������� ��������
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
            //�������� ���������
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
            cout<<"�������� ����� �� 0 �� 7\n";
            system("pause");
            break;
    }
}
    return 0;
}
