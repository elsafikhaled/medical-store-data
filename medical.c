#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>

/* X-Y COORDINATES */
COORD coord={0,0};
void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/* All functions declarations */
void Box_up();
void bigBox();
void mainMenu();

/* ##########################             SUPPLIERS   DATA            ####################################*/

void supplierInfo();
void addSupplier();
void updateSupplier();
void searchSupplier();
void listSupplier();
int  getSupplier_ID();
struct supplier
{
	int  supplier_ID;
	char supplier_name[50];
	char supplier_mobile[20];
	char supplier_E_mail[50];
	char supplier_city[20];
}supp_data;

/* ############################## main function ####################################### */
int main()
{
	mainMenu();
    return 0;
}

/*  ###############################    mainMenu function     ############################# */
void mainMenu()
{
	char ch;
	Box_up();
	bigBox();
	gotoxy(5,4);
	printf("Supplier info");
	gotoxy(25,4);
	printf("Customer info");
	gotoxy(44,4);
	printf("Medicine");
	gotoxy(58,4);
	printf("About");
	gotoxy(70,4);
	printf("Exit");
	gotoxy(21,11);
	printf("Welcome to the medical store data");
	gotoxy(26,16);
	printf("   CAIRO   PHARMACY  ");
	gotoxy(4,29);
	printf("Enter the first letter of the option: ");
	/*scanf("%c",&ch);*/
	ch=toupper(getche());
	switch(ch)
	{
	  case 'S':
	  supplierInfo();break;

	}



}

/* making  upper box  */
void Box_up()
{   char column,row;
	gotoxy(2,1);
	printf("%c",220);
	for(column=3;column<=75;column++)
	{
		gotoxy(column,1);
		printf("%c",220);
	}
	gotoxy(75,2);
	printf("%c",219);
	for(row=3;row<=6;row++)
	{
		gotoxy(75,row);
		printf("%c",219);
	}
	gotoxy(74,6);
	for(column=74;column>=2;column--)
	{
		gotoxy(column,6);
		printf("%c",220);
	}
	for(row=6;row>1;row--)
	{
		gotoxy(2,row);
		printf("%c",219);
	}
}

/* big box under the upper one */
void bigBox()
{
	char column,row;
	gotoxy(2,9);
	printf("%c",220);
	for(column=3;column<=75;column++)
	{
		gotoxy(column,9);
		printf("%c",220);
	}
	for(row=10;row<=30;row++)
	{
		gotoxy(75,row);
		printf("%c",219);
	}
	gotoxy(74,30);
	for(column=74;column>=2;column--)
	{
		gotoxy(column,30);
		printf("%c",220);
	}
	for(row=30;row>9;row--)
	{
		gotoxy(2,row);
		printf("%c",219);
    }
}

/* ######################################   SUPLIER info functions ########################################## */
void supplierInfo()
{
	char ch;
	system("cls");
	Box_up();
	bigBox();
	gotoxy(26,4);
	printf("  *** CAIRO PHARMACY *** ");
    gotoxy(5,14);
	printf("* Add new supplier ");
	gotoxy(5,18);
	printf("* Update supplier info");
	gotoxy(5,22);
	printf("* Search supplier");
	gotoxy(5,26);
	printf("* list suppliers ");
	gotoxy(22,29);
	printf("# Enter the first letter of your choice: ");
	ch=toupper(getch());
	
	switch(ch)
	{
		case 'A':
		addSupplier();break;
	}
}

void addSupplier()
{
	char ch='y';
	FILE *fp;
	
	system("cls");
	
	fp=fopen("supplier.data","a");
	if(fp==NULL)
	{
	  printf("file can not be opened !!");
	  exit(0);
	}
	while(ch=='y')
	{
		Box_up();
	  bigBox();
	  gotoxy(26,4);
	  printf("  *** CAIRO PHARMACY *** ");
	  gotoxy(28,12);
	  printf("%c %c",175,175);
	  printf("  Add supplier  ");
	  gotoxy(46,12);
	  printf("%c %c",174,174);
		supp_data.supplier_ID=getSupplier_ID();
		gotoxy(4,14);
		printf("* Supplier    ID :%d",supp_data.supplier_ID);
		gotoxy(4,17);
		printf("* supplier   Name: ");
		gotoxy(4,20);
		printf("* supplier E-mail: ");
		gotoxy(4,23);
		printf("* supplier   City: ");
		
		getch();
	}
	
	gotoxy(15,40);
}

int  getSupplier_ID()
{
	FILE *fp;
	fp=fopen("supplier.data","r");
	if(fp==NULL)
	{
	  printf("file is not found !!");
	  getch();
	}
	supp_data.supplier_ID=0;
	rewind(fp);
	while(fscanf(fp,"%d %s %s %s",supp_data.supplier_ID,supp_data.supplier_name,supp_data.supplier_E_mail,supp_data.supplier_city)!=EOF)
	{
	 	
	}
	fclose(fp);
	return supp_data.supplier_ID+1;

}


























