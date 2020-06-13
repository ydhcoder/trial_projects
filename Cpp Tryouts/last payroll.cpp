#include <iostream>
#include<fstream>
#include<cstdlib>
#include<windows.h>
using namespace std;
	struct payroll
    {
    	int id;
      string date_employed,account_num,design,adress;
      string name;
      int p_number;
      char gender;
      double salary,loan;
    } ;
	payroll emp[100000];//creating an array of 100000 structure called "payroll"
void new_emp();
void add();
void display();
void delet();
void edit();
void modify();
void slip();
void list();
int a,m,num,choice,d,y;
 char s;
int main()
{
	system("color 3F");// 3f color of the background of the console screen
	cout<<"\t\t=============================================================="<<endl;
	cout<<"\t\t=============================================================="<<endl;
	cout<<"\t\t==============PAYROLL MANAGMENT SYSTEM for ABC Company========"<<endl;
	cout<<"\t\t=========================== C++ PROJECT======================="<<endl;
	cout<<"\t\t=============================================================="<<endl;
	cout<<"\t\t=============================================================="<<endl;
	cout<<"\t\t=============================================================="<<endl;
	  new_emp();
	  cout<<"Press any key,except \"Enter\" to continue... : \n";
	  cin>>s;
	  system("cls");
	  system("pause")
     loop:for(;;)
  {
  	cout<<"                               Select your Choice:: \n"
      <<"                         =====================================\n"
      <<"                             ENTER                             \n"
	  <<"                                   : 1 TO ADD NEW EMPLOYEE \n"
      <<"                                   : 2.DISPLAYE EMPLOYEE:\n"   // this shows only recordes of one employee we needed
      <<"                                   : 3. LIST OF ALL EMPLOYEE \n"
      <<"                                   : 4.TO PRINT SALARY SLIPE \n"
      <<"                                   : 5. TO EDITE EMPLOYEE RECORED \n"
      <<"                                   : 5 TO DELET \n"
      <<"                                   : 0 EXITE \n";
      cin>>choice;
      system("cls");
      if(choice==0)
        break;
  switch (choice)
  {
 case 1:
   	{
    add();
     cout<<"Press any key,except \"Enter\" to continue......";
	  cin>>s;
	  system("cls");
    break;
    }
 case 2:
 	{
 	display();
 cout<<"Press any key,except \"Enter\" to go to Main_menu......";
 	cin>>s;
	  system("cls");
	  break;
}
 case 3:
 	{
 		list();
 		cout<<"Press any key,except \"Enter\" to go to Main_menu......";
 	cin>>s;
	  system("cls");
	 break;		
	}
 case 4:
    {
  	slip();
  	 cout<<"Press any key to go to main menu.....";
	  cin>>s;
	  system("cls");
  	break;
    }
	case 5:
 	{
 		edit();
	}
  }
  
 }
cout<<"\n \n       ~~~~~~~~~~~~    GOOD BY     ~~~~~~~~~~~~\n\n";
return 0;
}
void new_emp()
{
cout<<"How many employee do you have?";
            cin>>num;
            system("cls");
for(a=0;a<num;a++)
	{
	cout<<"     Enter the information about EMPLOYEE"<<a+1<<endl
        <<"======================================================\n";
    cout<<"ID of employee   :  ";
    cin>>emp[a].id;
    cout<<"FULL name        :  ";
    cin.ignore();
    getline( cin,emp[a].name);
    cout<<"Date of employed :  ";
    cin>>emp[a].date_employed;
    cout<<"phone number     :  +251";
    cin>>emp[a].p_number;
    cout<<"Gender of employ :  ";
    cin>>emp[a].gender;
    cout<<"Monethly Salary  :  ";
    cin>>emp[a].salary;
    cout<<"Loan        :Birr.  ";
    cin>>emp[a].loan;
    cout<<"Designation      :  ";
    cin>>emp[a].design;
    cout<<"account number   :  ";
    cin>>emp[a].account_num;
	cout<<   "__________________________________________________________\n"
	    <<"          You have successfully record Employee "<<a+1<<endl
	    <<"````````````````````````````````````````````````````````````\n\n";			
	}
	m=a-1;
}
void add()
{

m++;
    cout<<"      Enter the correct information about EMPLOYEE"<<m<<endl
        <<"==============================================================\n";
    cout<<"ID of employee     :  ";
    cin>>emp[m].id;    
    cout<<"Date of employed   :  ";
    cin>>emp[m].date_employed;
    cout<<"FULL name          :  ";
    cin.ignore();
    getline( cin,emp[m].name);
    cout<<"phone number       :  +251";
    cin>>emp[m].p_number;
    cout<<"Gender of employee :  ";
    cin>>emp[m].gender;
     cout<<"Loan        :Birr.  ";
    cin>>emp[m].loan;
    cout<<"Designation      :  ";
    cin>>emp[m].design;
    cout<<"Salary             :  ";
    cin>>emp[m].salary;
    cout<<"account number     :  ";
    cin>>emp[m].account_num;
	cout<<" __________________________________________________________\n"
	    <<"          You have successfully record Employee "<<a+2<<endl
	    <<"``````````````````````````````````````````````````````````\n\n";	    	
}
void display(){
	cout<<"Enter ID of EMPLOYEE";
	cin>>d;
	system("cls");
	cout<<"\n\n\nEmployee ID        :  "<<emp[d-1].id<<endl;   
	cout<<"Date of employed   :                                                          "<<emp[d-1].date_employed<<endl;
    cout<<"FULL name          :  "<<emp[d-1].name<<endl;
    cout<<"phone number       :  +251"<<emp[d-1].p_number<<endl;
    cout<<"Gender of employee :  "<<emp[d-1].gender<<endl;
    cout<<"Salary             :Birr.  "<<emp[d-1].salary<<endl;
     cout<<"Loan              :Birr.  "<<emp[d-1].loan<<endl;
    cout<<"Designation        :  "<<emp[d-1].design<<endl;
    cout<<"account number     :  "<<emp[d-1].account_num<<endl;
}	
void slip()
{
	int x,dd,mm,yy,tr,hr,r,net_salary,tax;
	cout<<"enter the EMPLOYEE ID\n";
	cin>>x;
	for(;x>m+1;x)
{
	cout<<"no record found....\n"
    <<"Enter valied code : ";
    cin>>x;
    	  system("cls");
}
    
	cout<<"Enter the date in the format dd/mm/yy :  ";//current date
	cin>>dd>>mm>>yy;
	system("cls");
	 cout<<"Enter tax rate for this employee in %";
	 cin>>tr;
	 cout<<"Enter number of hours worked overtime,if there";
	 cin>>hr;
	  cout<<"Enter the rate of over time,Birr.per hour";
	  cin>>r;
	  system("cls");
	  ofstream slip;
	  tax=(emp[x-1].salary*tr)/100;
	  net_salary=((emp[x-1].salary+(hr*r))-(tax+emp[x-1].loan));
	cout<<"                                                                   DATE:"<<dd<<"/"<<mm<<"/"<<yy<<endl;
	cout<<"                                                                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	cout<<"\tID               :  "<<emp[x-1].id<<endl<<endl;
	cout<<"\tFll Name         :  "<<emp[(x-1)].name<<endl<<endl;
	 cout<<"\taccount number   :  "<<emp[(x-1)].account_num<<endl<<endl;
   	cout<<"\tTAX..................................Birr."<<tax<<endl<<endl;
    cout<<"\tNET SALARY...........................Birr."<<net_salary<<endl<<endl;  
	 cout<<"\n\n\n~~~~~~~prepared by:\tABC company HRD"<<endl; // HRD means human resource managment
	 
	  cout<<"\tFax:.....\n\tEmail:abc@gmail.com"<<endl;
	  slip.open("slipe.txt");
	   slip<<"                                                                   DATE:"<<dd<<"/"<<mm<<"/"<<yy<<endl;
	 slip<<"                                                                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	 slip<<"\tID               :  "<<emp[x-1].id<<endl<<endl;
	 slip<<"\tFll Name         :  "<<emp[(x-1)].name<<endl<<endl;
	  slip<<"\taccount number   :  "<<emp[(x-1)].account_num<<endl<<endl;
    slip<<"\tTAX..................................Birr."<<tax<<endl<<endl;
     slip<<"\tNET SALARY...........................Birr."<<net_salary<<endl<<endl;  
	  slip<<"\n\n\n~~~~~~~prepared by:\tABC company HRD"<<endl; // HRD means human resource managment
	   slip<<"\tFax:.....\n\tEmail:abc@gmail.com"<<endl;
	   slip.close();
	   	}
void modify()
{
 cout<<"Enter ID  :";
 cin>>y;
for(;y>m+1;y)
{
	cout<<"no record found....\n"
    <<"Enter valied code : ";
    cin>>y;
    	  system("cls");
}
    cout<<"          Last record of employee #"<<y<<endl
        <<"``````````````````````````````````````````````\n";
	cout<<"\nEmployee ID        :  "<<emp[y-1].id<<endl;   
	cout<<"Date of employed   :                                                          "<<emp[y-1].date_employed<<endl;
    cout<<"FULL name          :  "<<emp[y-1].name<<endl;
    cout<<"phone number       :  +251"<<emp[d-1].p_number<<endl;
    cout<<"Gender of employee :  "<<emp[y-1].gender<<endl;
    cout<<"Salary             :Birr.  "<<emp[y-1].salary<<endl;
     cout<<"Loan              :Birr.  "<<emp[y-1].loan<<endl;
    cout<<"Designation        :  "<<emp[y-1].design<<endl;
    cout<<"account number     :  "<<emp[y-1].account_num<<endl<<endl<<endl;	
 cout<<"DO you want to Make a change to EMPLOYEE"<<y<<"records?(y/n)"<<endl;
 char c;
 cin>>c;
 system("cls");
 switch(c){
 	case 'y':{
        cout<<"ID of employee     :  ";
    cin>>emp[m].id;    
    cout<<"Date of employed   :  ";
    cin>>emp[m].date_employed;
    cout<<"FULL name          :  ";
    cin.ignore();
    getline( cin,emp[m].name);
    cout<<"phone number       :  +251";
    cin>>emp[m].p_number;
	cout<<"Gender of employee :  ";
    cin>>emp[m].gender;
     cout<<"Loan        :Birr.  ";
    cin>>emp[m].loan;
    cout<<"Designation      :  ";
    cin>>emp[m].design;
    cout<<"Salary             :  ";
    cin>>emp[m].salary;
    cout<<"account number     :  ";
    cin>>emp[m].account_num;
	cout<<" __________________________________________________________\n" 	
	    <<"            \7Record Modified!"<<endl
	    <<"``````````````````````````````````````````````````````````\n\n";
	    break;
}
case 'n':
{
	cout<<"RECORD NOT MODIFIED!";
	break;
}
   }
       }
void list()
{
   ofstream list;  //opening a .txt format file to store some dynamic data in a permanent/static form
   list.open("list.txt");
   cout<<"\tID\tFULLNAME\t\t\tPHONE_NUMBER\tGENDER\t\tDATE\tDESIGNATION  SALARY\tLOAN     BANK ACCOUNT NUMBER  \n";
   cout<<"\t==\t========\t\t\t\t======\t\t====    ======\n";
    list<<"~~~~~~~~~~~~~~~~~~~~~~~~~~EMPLOYEES LIST~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    list<<"\tID\tFULLNAME\t\t\t\tPHONE_NUMBER\tGENDER\t\tDATE\tDESIGNATION  SALARY\tLOAN \t\t      BANK ACCOUNT NUMBER  \n";
    list<<"\t==\t========\t\t\t\t============\t======\t\t====\t===========  ======\t==== \t\t      ==== ======= ======  \n";
	for(int l=0;l<=m;l++)
	{
	cout<<"\t"<<emp[l].id<<"\t"<<emp[l].name<<emp[l].p_number<<" \t "<<emp[l].gender<<" \t"<<emp[l].date_employed<<"\t"<<emp[l].design<<emp[l].salary<<"\t"
	<<emp[l].loan<<"\t"<<emp[l].account_num<<endl;
    list<<"\t"<<emp[l].id<<"\t"<<emp[l].name<<"\t"<<emp[l].p_number<<" \t "<<emp[l].gender<<"\t "<<emp[l].date_employed<<"\t"<<emp[l].design<<"\t"<<emp[l].salary<<"\t"
	<<emp[l].loan<<"\t"<<emp[l].account_num<<endl;
	}
	list.close();
}
void delet()
{
	int dl;
	cout<<"Enter EMPLOYEE ID  :";
 cin>>dl;
for(;dl>m+1;dl)
{
	cout<<"no record found....\n"
    <<"Enter valied code : ";
    cin>>d;
    	  system("cls");
}
 cout<<"          Last record of employee #"<<dl<<endl
        <<"``````````````````````````````````````````````\n";
	cout<<"\n\n\nEmployee ID        :  "<<emp[dl-1].id<<endl;   
	cout<<"Date of employed   :                                                          "<<emp[dl-1].date_employed<<endl;
    cout<<"FULL name          :  "<<emp[dl-1].name<<endl;
    cout<<"phone number       :  +251"<<emp[dl-1].p_number<<endl;
    cout<<"Gender of employee :  "<<emp[dl-1].gender<<endl;
    cout<<"Salary             :  "<<emp[dl-1].salary<<endl;
     cout<<"Loan              :Birr.  "<<emp[dl-1].loan<<endl;
    cout<<"Designation        :  "<<emp[dl-1].design<<endl;
    cout<<"account number     :  "<<emp[dl-1].account_num<<endl;	
 cout<<"Are you shure you want to delete EMPLOYEE"<<dl<<"records?,~~It WILL NO LONGER TO EXIST~~(y/n)"<<endl;
 char cc;
 cin>>cc;
 system("cls");
    switch(cc)
    {
    	case 'y':
       {
	emp[dl-1].id='0';   
	emp[dl-1].date_employed="        ";
    emp[dl-1].name="DELETED"; 
    emp[dl-1].p_number='0'; 
    emp[dl-1].gender='0'; 
    emp[dl-1].salary=0; 
    emp[dl-1].loan=0; 
    emp[dl-1].design="DELETED"; 
    emp[dl-1].account_num="DELETED"; 
    cout<<"EMPLOYEE "<<dl<<" RECORED DELETED!";
    break;
	   }
    case 'n':
    	cout<<"employee #"<<dl<<"IS Not Deleted \n ";
    	break;
	}  
}
void edit(){
 for(;;){
	cout<<"                     EDIT-MENU  \n";
	cout<<"               ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"                     \t1.MODIFY : \n";
	cout<<"                     \t2.DELETE : \n";
	cout<<"                     \t0.EXITE  : \n";
	cout<<"================    ENTER YOUR CHOICE:=============";
	int edit;
	cin>>edit;
	system("cls");
	if(edit==0)
	break;
	switch(edit){
		case 1:
			{
				modify();
			cout<<"Press any key to go to Edit-MENU.....";
	 cin>>s;
	  system("cls");
	  break;
			}
			
			case 2:
				{
					delet();
						cout<<"Press any key to go to Edit-MENU.....";
	 cin>>s;
	  system("cls");
					//goto E;
					// goto loop;
					break;
				}
			//	case 0:{
				//	goto loop;
				//	break;
				}
	}
//}while(edit!=0);
}

       
    
