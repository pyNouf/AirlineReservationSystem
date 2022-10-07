//AIRLINES RESERVATION SYSTEM 
//NOOF ALMAHASHEER
//Joud AlFadhel
//Alhatoon alanazy
//Sereen Bawazir
//Rana Alshaikh


#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;


//Global variables 
const int limit = 100;
int size;
string Data="Data.txt";
string Report="Statical_Report.txt";
string Backup="Backup.txt";
int counter[6] ={0}; // counters for statical file 

//PASSENGER INFORMATION STRUCTURES
struct flightInfo
{
        int flightno;
        string from;
        string to;
};

struct passengerinfo 
{
   string name;
   int passID;
   int  tnumber;
   flightInfo flight;
   };

//FUNCTIONS PROTOTYPE      
void menu();
void welcome();
void add(passengerinfo passenger[]) ;
int search( int &found, passengerinfo passenger[]);
void update (passengerinfo passenger[]);
void deletee(passengerinfo passenger[]);
void sort (passengerinfo passenger[]);
void display(passengerinfo passenger[] , int num , int size) ;
void loadData ( passengerinfo passenger[]) ;
void  DatatoFile( passengerinfo passenger[]);
void statical_report ();
void backup ();

//MAIN BODY
int main()
{
passengerinfo passenger[limit]; 
loadData  ( passenger) ;

int choice;
welcome (); //WELCOME FUNC
display (passenger, 0, size ) ;
counter[5]--; // we decrement one because we call display function
menu(); // MENU FUNC
cout<<"\n\n\t\t\t";
cin>> choice;

while (choice!=7)
{
switch(choice)
{
       case 1:add( passenger) ;
       break;
       
       case 2: 
	   {
	   	int found=-1;
	   	search( found , passenger);
      	if(found>-1)
         {   display (passenger, found , found+1) ;
counter[5]--; // we decrement one because we call display function
}
        else
            cout<<"\t\t\tThe Passenger Was Not Founded...Try Again."; 	   
	   }
       break;
       
       case 3: {  update ( passenger); }

       break;
       
       case 4: deletee( passenger);
       break;
       
       case 5: sort ( passenger);
       break;
       case 6: display (passenger, 0 , size) ;
       break;
       
       default:
         cout<<"\t\t\tYou Haven't Entered A Correct Number...Try Again.";
   }
 cout<<endl<<endl;
 menu(); // MENU FUNC
 cout<<"\n \n \t\t\t";
 cin>> choice;
   }
DatatoFile(passenger) ; 
statical_report ();
backup ();
return 0;}



//FUNCTIONS BODY  


void welcome ()
{
cout<<"\n\n\t\t\t\tWELCOME TO AIRLINES RESERVATION SYSTEM \n\n";
cout<<"\t\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
cout<<"\t\t\t\t Add || Edit the data Easily && Quickly "<<endl;
cout<<"\t\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl<<endl;
        
}



void menu()
{
cout<<"\t\t\tChoose From The Following Services By Entering The Number: "<<endl;
cout<<"\t\t\t__________________________________________________________";
cout<<"\n\t\t\t\1. New Reservation (1) "<<endl;
cout<<"\t\t\t\2. Search For a Specific Passenger (2)"<<endl;
cout<<"\t\t\t\3. Update a Passenger Reservation (3)"<<endl;
cout<<"\t\t\t\4. Delete a Passanger Reservation (4)"<<endl;
cout<<"\t\t\t\5. Sort Passenger's Name Alphabetically (5)"<<endl;
cout<<"\t\t\t\6. Display Booked Flights (6)"<<endl;
cout<<"\t\t\t\4. To Exit (7)"<<endl;
}

void add(passengerinfo passenger[]) 
{counter[0]++;//add_counter 
if(size <limit)
{
cout<<"\n\t\t\tEnter Passenger Name is: ";
cin>>passenger[size].name;
cout<<"\t\t\tEnter Passenger Pass ID: ";
cin>>passenger[size].passID;
cout<<"\t\t\tEnter Passenger Ticket Number: ";
cin>>passenger[size].tnumber;
cout<<"\t\t\tEnter Flight Number: ";
cin>>passenger[size].flight.flightno;
cout<<"\t\t\tEnter Departure from: ";
cin>>passenger[size].flight.from;
cout<<"\t\t\tTo: ";
cin>>passenger[size].flight.to;
size++;
DatatoFile(passenger) ; }

else
cout<<"\t\t\tThe Records Are Full, You Should Delete a Record To Add New Reservation."<<endl;

}


int search( int &found , passengerinfo passenger[])
{counter[1]++;//search_counter
    int ID;
    cout<<"\t\t\tEnter The Passenger's ID:";
    cin>>ID;
    for(int i=0 ; i<size ;i++)
        if(passenger[i].passID==ID){
        	found=i; }
return (found);
}


void update ( passengerinfo passenger[])
{ counter[2]++;//update_counter
    
    int updateID, updatetnumber, upadteflightno;
    string updatename, updatefrom, updateto;
 
    int found=-1;
    search (found, passenger);
    counter[1]--; // we decrement one because we call Search function
    if(found>-1){
            
            cout<<"\n\t\t\tEnter Passenger Name is: ";
            cin>>updatename;
            passenger[found].name= updatename;
            
            cout<<"\t\t\tEnter Passenger Pass ID: ";
            cin>> updateID;
            passenger[found].passID= updateID;
            
            cout<<"\t\t\tEnter Passenger Ticket Number: ";
            cin>> updatetnumber;
            passenger[found].tnumber= updatetnumber;
            
            cout<<"\t\t\tEnter Flight Number  : ";
            cin>> upadteflightno;
            passenger[found].flight.flightno=upadteflightno;
           
            cout<<"\t\t\tEnter Departure from: ";
            cin>>updatefrom;
            passenger[found].flight.from=updatefrom;
           
            cout<<"\t\t\tTo: ";
            cin>>updateto;
            passenger[found].flight.to=updateto ;
        
          cout<<"\n\t\t\tThe Information Has Been Updated Succesfully."<<endl; 
		  DatatoFile(passenger) ;  }
    else
        cout<<"\t\t\tThe Passenger Wasn't Found."<<endl;
}
 
    
void deletee(passengerinfo passenger[])
{
counter[3]++;//delete_counter
int deleted;
bool founded=0; 
cout<<"\t\t\tEnter The ID of Passenger You Want To Delete: ";
		cin>> deleted;

			    for(int i=0 ; i<size ;i++)
			    {
        if(passenger[i].passID==deleted)
			{founded=1;
				passenger[i].name=passenger[i+1].name;
  				passenger[i].passID=passenger[i+1].passID;
				passenger[i].tnumber=passenger[i+1].tnumber;
				passenger[i].flight.flightno=passenger[i+1].flight.flightno;
				passenger[i].flight.from=passenger[i+1].flight.from;
				passenger[i].flight.to=passenger[i+1].flight.to;
				size--;	
				cout<<"\t\t\tThe Passenger is Deleted Successfully. "<<endl;	
			}}	
			if (!founded)
			cout<<"\t\t\tThe Passenger is Not Founded!"<<endl;
			else
			DatatoFile(passenger) ; 

}









void sort (passengerinfo passenger[]) 
{counter[4]++;//sort_counter
passengerinfo temp;
	if(size<2)
    	cout<<"\t\t\tThere is Nothing To Sort.";
	else {
	
    	for(int i=0; i<size-1;i++){
        	for(int j=0; j<size-1;j++){
            	if (passenger[j].name>passenger[j+1].name){
                	temp=passenger[j];
                	passenger[j]=passenger[j+1];
                	passenger[j+1]=temp;
            	}
        	}}
    DatatoFile(passenger) ;	}

	 

}


void display (  passengerinfo passenger[], int  num , int size)
{
counter[5]++;//display_counter
cout<<endl<<"\t\t\tBooked Flights We Have"<<endl; 
cout<<"\t\t\t__________________________________________________________"<<endl;
for(int i=num ; i<size ;i++)
{
cout<<"\n\t\t\tPassenger Name is: "<<passenger[i].name<<endl;
cout<<"\t\t\tPassenger Pass ID: "<<passenger[i].passID<<endl;
cout<<"\t\t\tPassenger Ticket Number: "<<passenger[i].tnumber<<endl;
cout<<"\t\t\tFlight Number  : "<<passenger[i].flight.flightno<<endl;
cout<<"\t\t\tDeparture from: "<<passenger[i].flight.from;
cout<<" To: "<<passenger[i].flight.to<<endl;
}
cout<<"\t\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl<<endl;
}


void loadData ( passengerinfo passenger[])
{
ifstream DataFile;
DataFile.open(Data.c_str(), ios::in);
if(DataFile.is_open() == true || DataFile.is_open())
{
  int i=0;
        while(!DataFile.eof()) {
            getline(DataFile, passenger[i].name);
            DataFile>>passenger[i].passID;
            DataFile>>passenger[i].tnumber;
            DataFile>>passenger[i].flight.flightno;
            DataFile.ignore();
            getline(DataFile, passenger[i].flight.from);
            getline(DataFile, passenger[i].flight.to);
            i++;}
        size =i-1;
       DataFile.close();}
else 
cout<< "Failed -- or File is not exist.\n";
 }


void  DatatoFile (passengerinfo passenger[])
{ofstream DataFile;
DataFile.open(Data.c_str(), ios::out);

if(DataFile.is_open() == true || DataFile.is_open() ) {
for (int i=0;i<size;i++){
    DataFile<<passenger[i].name<<endl;
    DataFile<<passenger[i].passID<<endl;
    DataFile<<passenger[i].tnumber<<endl;
    DataFile<<passenger[i].flight.flightno<<endl;
    DataFile<<passenger[i].flight.from<<endl;
    DataFile<<passenger[i].flight.to<<endl;
}
DataFile.close();
cout << "\n\t\t\tData Saved Successfully.\n";}
else 
cout<< "Failed To Save New Data! Please Try Again. \n";
}



 void statical_report ()
{
ofstream ReportFile; 	
time_t t;	
t= time(NULL);
char *time=ctime(&t);
ReportFile.open(Report.c_str(), ios::app);
if (ReportFile.is_open())
{   ReportFile<<endl;
	ReportFile<<"The user ask to display data: "<<counter[5]<<" times"<<endl;
	ReportFile<<"The user ask to sort data: "<<counter[4] <<" times"<<endl;
	ReportFile<<"The user ask to add data: "<<counter[0]<<" times"<<endl;
	ReportFile<<"The user ask to add Update data: "<<counter[2]<<" times"<<endl;
	ReportFile<<"The user ask to delete data: "<<counter[3]<<" times"<<endl;
	ReportFile<<"The user ask to search data: "<<counter[1] <<" times"<<endl;
	ReportFile<<"The Date of Last update: "<<time<<endl;
}
else
cout<< "Failed To Save Last Modifications!\n";
ReportFile.close();
}





void backup ()
{
ifstream DataFile;
ofstream BackupFile;
DataFile.open(Data.c_str(), ios::in);
BackupFile.open(Backup.c_str(), ios::out);

string line;
if(DataFile.is_open() && BackupFile.is_open() ) {
do{
getline(DataFile,line); // read from original file
BackupFile<< line << endl; // write to backup file
}while(!DataFile.eof());

BackupFile.close();
DataFile.close();
cout<<"\t\t\tFile is Backed up Successfully.";
}
else
cout<<"\t\t\tError Failed To Open or Some Files Does Not Exist.";
}













