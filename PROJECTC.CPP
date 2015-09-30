//***************************************************************
//		    LIBRARY RECORD MANAGEMENT SYSTEM
//***************************************************************
//		      HEADER FILE USED IN PROJECT
//***************************************************************
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
char *g="GOLD";
char *s="SILVER";
//***************************************************************
//                   CLASSES USED IN PROJECT
//***************************************************************

class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{
		cout<<"\n- - - NEW BOOK ENTRY - - -\n";
		cout<<"\nEnter the Book No.: ";
		cin>>bno;
		cout<<"\n\nEnter the Name of The Book: ";
		gets(bname);
		cout<<"\n\nEnter the Author's Name: ";
		gets(aname);
		cout<<"\n\n\nBook Created !!";
	}

	void show_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nBook Name: ";
		puts(bname);
		cout<<"Books Author Name: ";
		puts(aname);
	}

	void modify_book()
	{
		cout<<"\nBook No.: "<<bno;
		cout<<"\nBook Name: ";
		gets(bname);
		cout<<"\nBooks Author Name: ";
		gets(aname);
	}

	char* retbno()
	{
		return bno;
	}

	void report()
	{cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}


};

class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int token;
public:
	char mem[7];
	void create_student()
	{
		clrscr();
		cout<<"\t NEW STUDENT ENTRY \n";
		cout<<"\n Enter the Admission No. ";
		cin>>admno;
		cout<<"\n\n Enter the Name of The Student:  ";
		gets(name);
		new_membership();
		token=0;
		stbno[0]='/0';
		cout<<"\n\n Student Record Created !!";
	 }


	void new_membership()
		{
		clrscr();
		int z;
		a:
		cout<<" \n We offer 2 types of membership : \n 1.Details of GOLD MEMBERSHIP \n 2. Details of SILVER MEMBERSHIP \n 3. Purchase Membership  \n 4. GO back to main menu \n";
		cin>>z;
		switch(z)
		{
			case 1:
				cout<<"\n\t GOLD MEMBERSHIP:\n Fine of rupee 1 \n Max date of return 15 \n Price Rs 500 for 1 year \n";
				getch();
				goto a;
				break;
			case 2:
				cout<<"\n\t SILVER MEMBERSHIP:\n Fine of rupee 2 \n Max date of return 7 \n Price Rs 300 for 1 year \n";
				getch();
				goto a;
				break;
			case 3:
				cout<<"\n Which Type of Memebership would you like to purchase(Enter GOLD for gold and SILVER for silver)\n";
				gets(mem);
				if(strcmpi(mem,g))
					{
						cout<<"\n Silver membership purchased ";
						}
				else if(strcmpi(mem,s))
					{
						cout<<"\n Gold membership purchased:";
						}
				break;
			case 4:
				return;
			}
			 }
		void purchase();
		void show_student()
	{
		cout<<"\nAdmission no. : "<<admno;
		cout<<"\nStudent’s Name: ";
		puts(name);
		cout<<"\n Membership Type \n";
		gets(mem);
		cout<<"\nNo of Book Issued: "<<token;
		if(token==1)
			cout<<"\nBook No.: "<<stbno;
	}

	void modify_student()
	{
		cout<<"\nAdmission No.: "<<admno;
		cout<<"\nStudents Name: ";
		gets(name);
		cout<<"\ Membership Type :";
		puts(mem);
	}

	char* retadmno()
	{
		return admno;
	}

	char* retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token=1;}

	void resettoken()
	{token=0;}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{cout<<"\t"<<admno<<setw(10)<<name<<setw(5)<<token<<setw(5)<<mem<<endl;}

};         //class ends here
//***************************************************************
//	GLOBAL DECLARATION FOR STREAM OBJECT,OBJECT
//***************************************************************
fstream f1,f2;
book bk;
student st;

//***************************************************************
//      	   FUNCTION TO WRITE IN FILE
//***************************************************************

void write_book()
{
	char ch;
	f1.open("book.dat",ios::out|ios::app);
	do
	{
		clrscr();
		bk.create_book();
		f1.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more Records (y/n) ?";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f1.close();
}

void write_student()
{
	char ch;
	f1.open("student.dat",ios::out|ios::app);
	do
	{
		st.create_student();
		f1.write((char*)&st,sizeof(student));
		cout<<"\n\nDo you want to add more Records (y/n) ? ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f1.close();
}
//***************************************************************
//	FUNCTION TO READ SPECEFIC RECORD FROM FILE
//***************************************************************
void display_spb(char n[])
{
	cout<<"\t BOOK DETAILS \n";
	int flag=0;
	f1.open("book.dat",ios::in);
	while(f1.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			flag=1;
		}
	}

	f1.close();
	if(flag==0)
		cout<<"\n\nBook does not Exist !!";
	getch();
}

void display_sps(char n[])
{
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	f1.open("student.dat",ios::in);
	while(f1.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retadmno(),n)==0))
		{
			st.show_student();
			flag=1;
		}
	}

	f1.close();
	if(flag==0)
		cout<<"\n\nStudent Record does not Exist !!";
	getch();
}
//***************************************************************
//		FUNCTION TO MODIFY FILE RECORD
//***************************************************************
void modify_book()
{
	char n[6];
	int found=0;
	clrscr();
	cout<<"\t MODIFICATION OF  BOOK RECORD ";
	cout<<"\n\tEnter The Book no. of the Book whose Record is to be Modified: ";
	cin>>n;
	f1.open("book.dat",ios::in|ios::out);
	while(f1.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			cout<<"\nEnter the New Details of Book: "<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
			f1.seekp(pos,ios::cur);
			f1.write((char*)&bk,sizeof(book));
			cout<<"\n\n\tRecord Updated !!";
			found=1;
		}
	}

	f1.close();
	if(found==0)
		cout<<"\n\n Record not Found !!";
	getch();
}


void modify_student()
{
	char n[6];
	int found=0;
	clrscr();
	cout<<"\n\t MODIFICATION OF STUDENT RECORD ";
	cout<<"\n\n\tEnter the Admission No. of the Student whose Record is to be Modified: ";
	cin>>n;
	f1.open("student.dat",ios::in|ios::out);
	while(f1.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),n)==0)
		{
			st.show_student();
			cout<<"\nEnter the New Details of Student: "<<endl;
			st.modify_student();
			int pos=-1*sizeof(st);
			f1.seekp(pos,ios::cur);
			f1.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated !!";
			found=1;
		}
	}

	f1.close();
	if(found==0)
		cout<<"\n\n Record not Found !!";
	getch();
}
//***************************************************************
//		FUNCTION TO DELETE FILE RECORD
//***************************************************************
void delete_student()
{
	char n[6];
	int flag=0;
	clrscr();
	cout<<"\n\t DELETION OF STUDENT RECORD \n";
	cout<<"\n\n Enter the Admission No. of the Student whose record is to be Deleted : ";
	cin>>n;
	f1.open("student.dat",ios::in|ios::out);
	fstream f2;
	f2.open("Temp.dat",ios::out);
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmno(),n)!=0)
			f2.write((char*)&st,sizeof(student));
		else
			flag=1;
	}

	f2.close();
	f1.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted !!";
	else
		cout<<"\n\nRecord not Found !!";
	getch();
}


void delete_book()
{
	char n[6];
	clrscr();
	cout<<"\n\n\t DELETION OF BOOK  RECORD \n";
	cout<<"\n\nEnter the Book no. of the Book to be Deleted: \n";
	cin>>n;
	f1.open("book.dat",ios::in|ios::out);
	fstream f2;
	f2.open("Temp.dat",ios::out);
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)
		{
			f2.write((char*)&bk,sizeof(book));
		}
	}

	f2.close();
	f1.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}



//***************************************************************
//    	       FUNCTION TO DISPLAY LIST OF ALL STUDENT
//***************************************************************

void display_alls()
{
	clrscr();
	f1.open("student.dat",ios::in);
	if(!f1)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\t STUDENT LIST \n\n";
	cout<<"================================================================================\n";
	cout<<"Admission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued"<<setw(20)<<"Membership Type\n";
	cout<<"================================================================================ \n";

	while(f1.read((char*)&st,sizeof(student)))
	{
		st.report();
	}

	f1.close();
	getch();
}


//***************************************************************
//    	      FUNCTION TO DISPLAY LIST OF ALL BOOKS
//***************************************************************

void display_allb()
{
	clrscr();
	f1.open("book.dat",ios::in);
	if(!f1)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
	cout<<"=========================================================================\n";

	while(f1.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
	f1.close();
	getch();
}
//***************************************************************
//    	          FUNCTION TO ISSUE BOOK
//***************************************************************

void book_issue()
{
	char sn[6],bn[6];
	int found=0,flag=0;
	clrscr();
	cout<<"\n\n BOOK ISSIUNG ";
	cout<<"\n\tEnter The Student's Admission no.: ";
	cin>>sn;
	f1.open("student.dat",ios::in|ios::out);
	f2.open("book.dat",ios::in|ios::out);
	while(f1.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()==0)
			{
				cout<<"\n\n\tEnter the book no. ";
				cin>>bn;
				while(f2.read((char*)&bk,sizeof(book))&& flag==0)
				{
					if(strcmpi(bk.retbno(),bn)==0)
					{
						bk.show_book();
						flag=1;
						st.addtoken();
						st.getstbno(bk.retbno());
						int pos=-1*sizeof(st);
						f1.seekp(pos,ios::cur);
						f1.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book Issued Successfully !!";
		cout<<"\n\nPlease Note: Write the current date in   backside of your book and submit within 15 Days Gold Member and 7 for Silver\n";
	 cout<<"\nKINDLY NOTE FOR GOLD: Fine of Rs. 1 will be charged for  each day after 15 days Period \n NOTE FOR SILVER: Fine of Rs. 2 will be charged for  each day after 7 days Period ";
					}
				}
				if(flag==0)
					cout<<"Book does not Exist !!";
			}
			else
				cout<<"Please Deposit the Last Book to Issue a New One !! ";

		}
	}
	if(found==0)
		cout<<"Student Record does not Exist !!";
	getch();
	f1.close();
	f2.close();
}

//***************************************************************
//    	            FUNCTION TO DEPOSIT BOOK
//***************************************************************

void book_deposit()
{
	 char sn[6],bn[6];
	 int found=0,flag=0,day,fine;
	 clrscr();
	 cout<<"\n\n BOOK DEPOSITING ";
	 cout<<"\n\tEnter The Students Admission No.: ";
	 cin>>sn;
	 f1.open("student.dat",ios::in|ios::out);
	 f2.open("book.dat",ios::in|ios::out);
	 while(f1.read((char*)&st,sizeof(student)) && found==0)
		 {
		 if(strcmpi(st.retadmno(),sn)==0)
		 {
			 found=1;
			 if(st.rettoken()==1)
			 {
			while(f2.read((char*)&bk,sizeof(book))&& flag==0)
			{
				if(strcmpi(bk.retbno(),st.retstbno())==0)
			{
				 bk.show_book();
				 flag=1;
				 cout<<"\n\nNo. Of Days in which Book Deposited: ";
				 cin>>day;
				  if(strcmpi(st.mem,g))
					{
				if(day>7)
				{
					fine=(day-7)*2;
					cout<<"\n\nFine need to be deposited is Rs. "<<fine;
				}
					st.resettoken();
					int pos=-1*sizeof(st);
					f1.seekp(pos,ios::cur);
					f1.write((char*)&st,sizeof(student));
					cout<<"\n\n\t Book deposited successfully !!";
				}
			  else if(strcmpi(st.mem,s))
					{
				if(day>15)
				{
					fine=(day-15)*1;
					cout<<"\n\nFine need to be deposited is Rs. "<<fine;
				}
					st.resettoken();
					int pos=-1*sizeof(st);
					f1.seekp(pos,ios::cur);
					f1.write((char*)&st,sizeof(student));
					cout<<"\n\n\t Book deposited successfully !!";
					 }
			}
			 }
		  if(flag==0)
			 cout<<"Book does not Exist";
				}
		 else
			cout<<"No Book is Issued..Please Check!!";
		}
		}

		if(found==0)
	cout<<"Student Record does not Exist !!";
	getch();
  f1.close();
  f2.close();
  }






//***************************************************************
//    	             INTRODUCTION FUNCTION
//***************************************************************

void intro()
{
	clrscr();
char pas[40];
char *p="library";
cout<<"\n enter password :";
cin>>pas;
if(strcmpi(pas,p)==0)
{  clrscr();
	textbackground(RED);
	gotoxy(35,5);
	cout<<"LIBRARY";
	gotoxy(33,6);
	cout<<"MANAGEMENT";
	gotoxy(35,8);
	cout<<"SYSTEM";
	cout<<"\n\nMADE BY : Hitanshu Paruthi";
	}
	else
{
exit(0);
}
	getch();
}

//***************************************************************
//    	             STAFF MENU
//***************************************************************

void staff_menu()
{
	clrscr();
	textbackground(YELLOW);
	int ch2;
	cout<<"\n\n\n\t STAFF MENU";
	cout<<"\n\n\t 1.CREATE STUDENT RECORD";
	cout<<"\n\n\t 2.DISPLAY ALL STUDENTS RECORD";
	cout<<"\n\n\t 3.DISPLAY SPECIFIC STUDENT RECORD ";
	cout<<"\n\n\t 4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t 5.DELETE STUDENT RECORD";
	cout<<"\n\n\t 6.CREATE BOOK ";
	cout<<"\n\n\t 7.DISPLAY ALL BOOKS ";
	cout<<"\n\n\t 8.DISPLAY SPECIFIC BOOK ";
	cout<<"\n\n\t 9.MODIFY BOOK ";
	cout<<"\n\n\t 10.DELETE BOOK ";
	cout<<"\n\n\t 11.BACK TO MAIN MENU";
	cout<<"\n\n\t Enter Your Choice (1-11):  ";
	cin>>ch2;
	switch(ch2)
	{
		case 1: clrscr();
			write_student();
			break;
		case 2: display_alls();
			break;
		case 3:
			char num[6];
			clrscr();
			cout<<"\n\n\tPlease Enter The Admission No.: ";
			cin>>num;
			display_sps(num);
			break;
		case 4: modify_student();
			break;
		case 5: delete_student();
			break;
		case 6: clrscr();
			write_book();
			break;
		case 7: display_allb();
			break;
		case 8: {
			char num[6];
			clrscr();
			cout<<"\n\n\tPlease Enter The book No.: ";
			cin>>num;
			display_spb(num);
			break;
			}
		case 9: modify_book();
			break;
		case 10: delete_book();
			break;
		case 11: return;
		default:cout<<"\a";
	}
	staff_menu();
}
/*void student::purchase()
{
cout<<"\n which membership do u wish to purchase (Enter GOLD for Gold Membership and SILVER for Silver Membership) :";
if(strcmpi(st.mem,g))
{
cout<<"\n Gold membership purchased :"<<st.mem;
}
else if(st.mem==s)
{
cout<<"\n Silver membership purchased:"<<st.mem;
}
} */


//***************************************************************
//    	            THE MAIN FUNCTION OF PROGRAM
//***************************************************************


void main()
{
 clrscr();
 char ch;
	intro();
	do
	{
		clrscr();
		textbackground(BLUE);
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. BOOK ISSUE";
		cout<<"\n\n\t02. BOOK DEPOSIT";
		cout<<"\n\n\t03. STAFF MENU";
		cout<<"\n\n\t04. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-4): ";
		ch=getche();
		switch(ch)
		{
			case '1':clrscr();
				 book_issue();
				 break;
			case '2':book_deposit();
				 break;
			case '3':staff_menu();
				 break;
			case '4':exit(0);
				 break;
			default :cout<<"\a";
		}
	}while(ch!='5');
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
