#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
using namespace std;
class menu{
	private:
		void edit_records(void);
		void report(void);
		void roomf(void);
		void customerf(void);
	public:
		void overview(void);
		void main_menu(void);
		void enter_password(void);	
	
};
class room{
	private:
		int recordno(int);
		void display_record(int);
		int roomno;
		char roomcode[5], status;
		float tariff;
	public:
		void add(void);
		void modify(void);
		void deletion(void);
		void display_room_record(int);
		void display_list(void);
		int room_found(int);
		void change_status(int, char);
		char room_status(int);
		float get_data(int);
	
};
class customer{
	private:
		int recordno(int);
		void display_record(int);
		void delete_record(int);
		int roomno;
		char name[25], phone[12];
		float advance, misc, room_srv;
	public: 
		void add(void);
		void modify(void);
		void deletion(void);
		void display_list(void);
		void display_customer_record(int);
};

void menu::main_menu(){
	int l;
	char ch;
//	clrscr();
	gotoxy(3,2);
	cout<<"Twin Hotel";
	goto xy ;(3,3);
	cout<<"------------------------";
	goto xy ;(9,4);
	cout<<"Nepal";
	goto xy ;(55,2);
	cout<<"Baneshor, Kathmandu";
	goto xy;(55,3);
	cout<<"Near   ";
	goto xy;(55,4);
	cout<<"Kathmandu 10, Nepal";
	goto xy;(55,5);
	cout<<"023-550402, 9850372451";
	goto xy;(55,2);
	cout<<"Baneshor, Kathmandu";
	goto xy;(30,11);
	cout<<"1. Edit Records";
	goto xy;(30,13);
	cout<<"2. Display Room Records";
	goto xy;(30,15);
	cout<<"3. Display Customer Records";
	goto xy;(30,17);
	cout<<"4. Exit To DOS";
	goto xy;(30,23);
	cout<<"Enter your choice: ";
	cin>>ch;
	
	if(ch=='3'){
		char ans;
		do{
			//clrscr();
			cout<<"Enter the room fo customer to be displayed: ";
			cin>>l;
			customer c;
			c.display_customer_record(l);
			cout<<"\nDo you wish to see more records (Y or N): ";
			cin>>ans;
		}while(ans=='Y');
		main_menu();
			
	}else if(ch=='2'){
		char ans1;
		do{
			//clrscr();
			int m;  
			cout<<"Enter room to be displayed: ";
			cin>>m;
			room r;
			r.display_room_record(m);
			cout<<"\nDo you wish to see more records: ";
			cin>>ans1;
			
		} while(ans1== 'Y');
		main_menu();
	
	}else if(ch=='1')
	edit_records();
	
	if(ch=='4'){
	//	clrscr();
		goto xy;(26,10);
		cout<<"Thank You For Using Our Project";
		getch();
		goto xy;(32,12);
		cout<<"Have a Nice Day";
		getch();
		exit(0);		
		
	}
	
}
void menu::edit_records(void){
	int ch;
	while(ch!=3){
		//clrscr();
		goto xy(34,4);
		cout<<"     Edit";
		goto xy(30,8);
		cout<<"1._Room Records";
		goto xy(30,10);
		cout<<"2. Customer Records";
		goto xy(30,12);
		cout<<"3. Back";
		goto xy(30,15);
		cout<<"Enter your choice: ";
		cin>>ch;
		getch();
		if(ch==1)
		roomf();
		else if(ch==2)
		customerf();
		else if(ch==3)
		main_menu();
			
	}
	
}

void menu::roomf(void){
	int ch;
	while(1){
		clrscr();
		goto xy(34,4);
		cout<<"Edit Room";
		goto xy(30,8);
		cout<<"1. Add Room Records";
		goto xy(30,10);
		cout<<"2. Modify Room Records";
		goto xy(30,12);
		cout<<"3. Delete Room Records";
		goto xy(30,14);
		cout<<"4. Back";
		goto xy(30,17);
		cout<<"Enter your choice: ";
		cin>>ch;
		getch();
		
		if(ch==1)
		roomf();
		else if(ch==2)
		customerf();
		else if(ch==3)
		main_menu();
		
	}
	
}

void menu::roomf(void){
	
	int ch;
	while(1){
		clrscr();
		goto xy(34,4);
		cout<<"Edit Room";
		goto xy(30,8);
		cout<<"1. Add Room Records";
		goto xy(30,10);
		cout<<"2. Modify Room Record";
		goto xy(30,12);
		cout<<"3. Delete Room Records";
		goto xy(30,14);
		cout<<"4. Back";
		goto xy(30,17);
		cout<<"Enter your choice: ";
		cin>>ch;
		getch();
		
		if(ch==1){
			room r;
			r.add();
		}
		else if(ch==2){
			room r;
			r.modify();
		} else if(ch==3){
			room r;
			r.deletion();
		}else if(ch==4){
			room r;
			r.room_status();
		}
		
		
	}
	 
		
}

void main(void){
	clrscr();
	menu m;
	textmode(C80);
	textbackground(WHITE);
	textcolor(RED);
	m.main_menu();
	getch();
	
}
