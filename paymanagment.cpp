#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;

void companyname()
{
    system("CLS");
    cout<<"\n\t\t\t\t\t\t\tDunder Mifflin Paper Company\n\t\t\t\t\t\t\t  PAYROLL of December 2021\n\n\n";

}
class Employee
 {
  public:
        string Name[20], Desg[20], id[20];
        
        float workday, halfday, uninfoleave, payperday, bonus, number;
        fstream mf;

    void E_details(int j)
        { 
            companyname();
            cout<<endl;
        string ddt[60]; 
	    fstream mf; 
	    mf.open("codedata.csv", ios::in);
        int x=j,y=0;
	    while(x--)
        { 
		getline(mf,ddt[y],',');
                cout<<endl<<"Enter The Details Of Employee "<<ddt[y]<<" : "<<endl;
            getdata();
                cout<<"Name -> "<<ddt[y]<<endl;
        getline(mf,ddt[y+1],',');
	            cout<<"Designation -> "<<ddt[y+1]<<endl;
        getline(mf,ddt[y+2],',');
	            cout<<"ID Number -> "<<ddt[y+2]<<endl;
        
        P_details(ddt[y],ddt[y+1],ddt[y+2]);       
		y++;
	    } 
        mf.close();
        }   
	  
	void P_details(string Name, string desg, string id)
	   {
	   float x, y, z,m=0;
	   companyname();
       cout<<"Employee : "<<Name<<"\nDesignation : "<<desg<<"\nID : "<<id<<endl;
	   cout<<"Pay Per Day -> Rs."<<payperday<<endl;
	   cout<<"Days Of Working -> "<<workday<<endl;
	      x=payperday*workday;
	   cout<<"Gross Payment -> Rs."<<x<<endl;
	   cout<<"Half Days -> "<<halfday<<endl;
	   cout<<"Un Informed Leaves -> "<<uninfoleave<<endl;
	   cout<<"%Medical Tax -> 2%"<<endl;
	   cout<<"%Social Security Tax -> 1.5%"<<endl;
	     if(payperday<1200)
	      y=400*halfday;
	     else
	      y=600*halfday;
	   cout<<"Half Day Deductions -> Rs."<<y<<endl;
	      z=300*uninfoleave;
	   cout<<"Un Informed Leave Deduction -> Rs."<<z<<endl;
       cout<<"Bonus -> Rs."<<bonus<<endl;
	   cout<<"Net Deductions -> Rs."<<(x*0.02)+(x*0.015)+y+z<<endl;
	   cout<<"Net Payment -> Rs."<<x-((x*0.02)+(x*0.015)+y+z)+bonus<<"\n\n";

       cout<<"Do you want to print details to a file?\n\t(1) Yes \n\t(0) No\n : ";
        cin>>m;
            if(m==1)
                {
                    ofstream myfile;
                    myfile.open ("employee.txt",std::ios_base::app);
                    myfile << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    myfile << "										DUNDER MIFFLIN PAPER COMPANY\n";
                    myfile << "										   PAYSLIP December 2021\n";
                    myfile << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    myfile << "NAME : "<<Name<<endl;
                    myfile << "Gross Salary : Rs. "<<x<<endl;
                    myfile << "Total Leave : "<<31-workday-halfday<<endl;
                    myfile << "Net Deductions : Rs. "<<(x*0.02)+(x*0.015)+y+z<<endl;
                    myfile << "Bonus : Rs. "<<bonus<<endl;
                    myfile << "Net Payment : Rs. "<<x-((x*0.02)+(x*0.015)+y+z)+bonus<<endl;
                    myfile << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    myfile.close();
                }
            else if(m==0)
                m=1;
            else
                cout<<"Error!";
	   }

    void getdata()
    {
            cout<<"Pay Per Day : ";
	            cin>>payperday;
	            cout<<"Enter Total Number Of Working Days : ";
	            cin>>workday;
	            cout<<"Halfdays : ";
	             cin>>halfday;
	            cout<<"Number Of Un Informed Leaves : ";
	            cin>>uninfoleave;
                cout<<"Bonus : ";
	            cin>>bonus;
	            cout<<endl<<endl;
    }
 };

 class emp : public Employee
{ public:

void E_details()
	  { 
          companyname();
          string Name, Desg, id;
        cout<<endl<<endl;
	    cin.ignore();
	    cout<<"Enter Name : ";
	     getline(cin,Name);
	    cout<<"Enter Designation : ";
	     getline(cin,Desg);
	    cout<<"Enter Employee's ID Number : ";
	     getline(cin,id);
	    getdata();
        P_details(Name,Desg,id);
	  }

};


main()
 {
 int i,j,k;
    companyname();
 cout<<"Enter The Number Of Emplyoees : ";
 cin>>j;
 
 Employee Ei;
 emp ei;
 companyname();
 cout<<endl<<"(1) If you want to use data from file\n(0) If you want to enter a new Employee data\n: ";
 cin>>k;
 companyname();
 if(k==1)
    Ei.E_details(j);

 else if(k==0)
    {
    for(i=1;i<=j;i++)  
        ei.E_details();
    }
 else
    cout<<"Error";
  
 getch();
 return 0;
 }