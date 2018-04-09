
#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include <stdlib.h>
#include<conio.h>
#define max 100

class Person
{
public:
char *name;
char *address;
char *phone;
};


class Room
{
public:
char type;
char stype;
char ac;
int roomNumber;
int rent;
int status;
class Person cust;
class Room addRoom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(Room);
};
//Global Declarations

class Room rooms[max];
int count=0;


Room Room::addRoom(int rno)
{
class Room room;
room.roomNumber=rno;
cout<<"\nType AC/Non-AC (A/N) ";
cin>>room.ac;
cout<<"\nType Comfort (S/N)";
cin>>room.type;
cout<<"\nType Size (B/S) ";
cin>>room.stype;
cout<<"\nRent: ";
cin>>room.rent;
room.status=0;
return room;
}


void Room::searchRoom(int rno)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
cout<<"Room Details\n";
if(rooms[i].status==1)
{
cout<<"\nRoom is Reserved";
}
else
{
cout<<"\nRoom is available";
}
displayRoom(rooms[i]);
getch();
}
else
{
cout<<"\nRoom not found";
getch();
}
}


void Room::displayRoom(Room tempRoom)
{
 cout<<"\nRoom Number:\t"<<tempRoom.roomNumber;
 cout<<"\nType AC/Non-AC (A/N) "<<tempRoom.ac;
 cout<<"\nType Comfort (S/N) "<<tempRoom.type;
 cout<<"\nType Size (B/S) "<<tempRoom.stype;
 cout<<"\nRent: "<<tempRoom.rent;
}



//hotel management protected data
class HotelMgnt:protected Room
{
public:
void reserveRoom();
void getAvailRoom();
void searchPerson(char *);
void generateBill(int);
};



//hotel management reservation of room
void HotelMgnt:: reserveRoom()
{
int i,found=0,rno;

class Room room;
cout<<"\nEnter Room number: ";
cin>>rno;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
if(rooms[i].status==1)
{
cout<<"\nRoom is already Reserved";
return;
}
//cout<<"\nEnter Customer Name: ";
//cin>>rooms[i].cust.name;
cout<<"\nEnter Customer Name: ";
cin>>rooms[i].cust.address;
//cout<<"\nEnter Customer Phone Number: ";
//cin>>rooms[i].cust.phone;
rooms[i].status=1;
}
}


//hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
cout<<"\nPress enter for next room";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nAll rooms are reserved";
getch();
}
}



//hotel management shows all persons that booked a room
void HotelMgnt::searchPerson(char *pname)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0)
{
//cout<<"\nCustomer Name:t"<<rooms[i].cust.name;
cout<<"\nRoom Number:t"<<rooms[i].roomNumber;
cout<<"\nName:t"<<rooms[i].cust.address;
//cout<<"\nPhone:t"<<rooms[i].cust.phone;
cout<<"\nPress enter for next record";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nPerson not found.";
getch();
}
}


//hotel managemt generates the bill of the expenses
void HotelMgnt::generateBill(int roomNum)
{
int i,found=0,days,rno;
float billAmount=0.0;//,other=0.0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{
//cout<<"\nCustomer Name:t"<<rooms[i].cust.name;
cout<<"\nRoom Number:t"<<rooms[i].roomNumber;
cout<<"\nName:t"<<rooms[i].cust.address;
//cout<<"\nPhone:t"<<rooms[i].cust.phone;
//rno = rooms[i].roomNumber;
found=1;
getch();
break;
}
}
if(found==1)
{
cout<<"\nEnter Number of Days:\t";
cin>>days;
billAmount=days * rooms[i].rent;
cout<<"\nTotal Bill Amount:\tLEK. "<<billAmount<<" /";
rooms[i].status=0;
}
getch();
}


//managing rooms (adding and searching available rooms)
void manageRooms()
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
system("cls");
cout<<"Hotel Management\n";
cout<<"\nManage Room";
cout<<"\n1. Add Room";
cout<<"\n2. Search Room";
cout<<"\n3. Back to Main Menu";
cout<<"\nEnter Option:\t";
cin>>opt;


//switch statement
switch(opt)
{
case 1:
cout<<"\nEnter Room Number:t";
cin>>rno;
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
cout<<"\nRoom Number is Present.\nPlease enter unique Number";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}
break;
case 2:
cout<<"\nEnter room number: ";
cin>>rno;
room.searchRoom(rno);
break;
case 3:
//	 cout<<"Do you want to Exit (Y/N:) ";
//	 cin>>ch;
break;
default:
cout<<"\nPlease Enter correct option";
break;
}
}while(opt!=3);
}

int main()
{
class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char *pname;
system("cls");
do
{
system("cls");
cout<<"Hotel Management\n";
cout<<"\n1. Manage Rooms";
cout<<"\n2. Reserve Room";
cout<<"\n3. Available Rooms";
cout<<"\n4. Search Person";
cout<<"\n5. Generate Bill";
cout<<"\n6. Exit";
cout<<"\nEnter Option:t";
cin>>opt;
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}
else
hm.reserveRoom();
break;
case 3:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}
else
hm.getAvailRoom();
break;
case 4:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}
else
{
cout<<"Enter Person Name: ";
cin>>pname;
hm.searchPerson(pname);
}
break;
case 5:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}
else
{
cout<<"Enter Room Number: ";
cin>>rno;
hm.generateBill(rno);
}
break;
case 6:
cout<<"\nTHANK YOU!";
break;
default:
cout<<"\nPlease Enter correct option";
break;
}
}while(opt!=6);
return 0;
}
