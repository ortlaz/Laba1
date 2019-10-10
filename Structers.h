#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct spisok{
string type;
string country;
int year;
spisok* next;
} Car;

typedef struct spisok2{
string type;
spisok* begining;
spisok2* next;
} Models;


