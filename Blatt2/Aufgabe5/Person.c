#include "Person.h"

//eigenschaften einer person
struct person
{
  char *vorname;
  char *nachname;
  char *datum;
  char *ort;
};

void* createPerson(char *vorname, char *nachname, char *datum, char *ort)
{
    struct person *neu = (struct person*)malloc(sizeof(struct person));
    neu->vorname = vorname;
    neu->nachname = nachname;
    neu->datum = datum;
    neu->ort = ort;

    return neu;
}

int kleinerPerson(void *person3, void *person4, int sort)
{
    //casten der void* zu person
    struct person *person1 = (struct person*) person3;
    struct person *person2 = (struct person*) person4;

 //sortiert nach datum SORT == 1
 if(sort==1)
 {
  //z�hlervariable zum durchgehen der chars;
 int x;

 //vergleicht das jahr
 for(x=6;x<10;x++)
 {
  if(person1->datum[x]>person2->datum[x])
  {
    return 0;
  }

  if(person1->datum[x]<person2->datum[x])
  {
   return 1;
  }
 }

 //vergleicht den monat
 for(x=3;x<5;x++)
 {
  if(person1->datum[x]>person2->datum[x])
  {
    return 0;
  }

  if(person1->datum[x]<person2->datum[x])
  {
   return 1;
  }
 }

 //vergleicht den tag
 for(x=0;x<2;x++)
 {
  if(person1->datum[x]>person2->datum[x])
  {
    return 0;
  }

  if(person1->datum[x]<person2->datum[x])
  {
   return 1;
  }
 }

 //gibt 0 zur�ck da datum1<datum2 nicht gilt
 return 0;
 }

 //sortiert nach vornamen SORT == 2
 if(sort==2)
 {
  //z�hlervariable zum durchlaufen er chars
 int x = 0;

 //vergleicht die beiden namen
 while((person1->vorname[x]!='\0') && (person2->vorname[x]!='\0'))
 {
  if(person1->vorname[x]>person2->vorname[x])
  {
   return 0;
  }
  else if(person1->vorname[x]<person2->vorname[x])
  {
   return 1;
  }
  x++;
 }

 //gibt 1 zur�ck falls name2 l�nger ist als name1
 if(person2->vorname[x]!='\0')
 {
  return 1;
 }

 //gibt null zur�ck da name1<name2 nicht gilt
 return 0;
 }

 //sortiert nach nachnamen SORT == 3
 if(sort==3)
 {
 //z�hlervariable zum durchlaufen er chars
 int x = 0;

 //vergleicht die beiden namen
 while((person1->nachname[x]!='\0') && (person2->nachname[x]!='\0'))
 {
  if(person1->nachname[x]>person2->nachname[x])
  {
   return 0;
  }
  else if(person1->nachname[x]<person2->nachname[x])
  {
   return 1;
  }
  x++;
 }

 //gibt 1 zur�ck falls name2 l�nger ist als name1
 if(person2->nachname[x]!='\0')
 {
  return 1;
 }

 //gibt null zur�ck da name1<name2 nicht gilt
 return 0;
 }

 //sortiert nach ort SORT == 4
 if(sort==4)
 {
  //z�hlervariable zum durchlaufen er chars
 int x = 0;

 //vergleicht die beiden namen
 while((person1->ort[x]!='\0') && (person2->ort[x]!='\0'))
 {
  if(person1->ort[x]>person2->ort[x])
  {
   return 0;
  }
  else if(person1->ort[x]<person2->ort[x])
  {
   return 1;
  }
  x++;
 }

 //gibt 1 zur�ck falls name2 l�nger ist als name1
 if(person2->ort[x]!='\0')
 {
  return 1;
 }

 //gibt null zur�ck da name1<name2 nicht gilt
 return 0;
 }
return 0;
}

void printPerson(void *person2)
{
    struct person *person1 = (struct person*) person2;

    printf("%s ",person1->vorname);
    printf("%s ",person1->nachname);
    printf("%s ",person1->datum);
    printf("%s\n",person1->ort);

    return;
}
void deletePerson(void *person2)
{
    struct person *person1 = (struct person*) person2;

 free(person1->vorname);
 free(person1->nachname);
 free(person1->datum);
 free(person1->ort);

 free(person1);

 return;
}

