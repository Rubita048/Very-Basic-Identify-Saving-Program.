#include <stdio.h>
#include <stdlib.h>
/* 
	This is an identify saving program made by "Rubita"
	Read the informations at below and check funcitons for more detailed information.
-----------------------------------------------------------------------------------------------------------------------
	1- "savefile" function which adds new applications on text file (check "savefile" function for more detail).
	2- "readfile" function reads all identifies even saved on text file (check "executefile" function for more detail).
	3- "wipedata" function deletes all identifies saved at text file (check "wipedata" function for more detail).
	4- All those functions are called at "main" function. Make sure to check there first.
-----------------------------------------------------------------------------------------------------------------------
*/

int savefile()
/* 
	This is "savefile" function.
-----------------------------------------------------------------------------------------------------------------------
	1- This function adds new identifies to the text file.
	2- If you enter a number on "name/surname" section it will not shown at program.
	3- If you enter a string on "age" section it will not shown at program.
	4- You can edit the strings saved in this program at the text file.
	5- For deleting all information saved in this program check "wipedata" function.
-----------------------------------------------------------------------------------------------------------------------
*/
{
	int blank;
	key_wayback_newidentify:
	for (blank=0;blank<=1;blank++)
	printf("\n");
	char name1[20];
	char name2[20];
	char surname[20];
	int age;
	{
	FILE *Test = fopen("InfoList.txt","a");
	printf("Registery\n");
	printf("---------------------\n");
	printf("First Name => ");
	fgets(name1,sizeof(name1),stdin);
	scanf("%s",&name1);
	printf("Second Name => ");
	fgets(name2,sizeof(name2),stdin);
	scanf("%s",&name2);
	printf("Surname => ");
	fgets(surname,sizeof(surname),stdin);
	scanf("%s",&surname);
	printf("Age => ");
	scanf("%d",&age);
	fprintf(Test,"Name/Surname => %s %s %s\n",name1,name2,surname);
	fprintf(Test,"Age => %d\n",age);
	fprintf(Test,"\n");

	int key;
	printf("\n");
	printf("Do you want to add another identify?\n");
	printf("------------------------------------\n");
	printf("Press 1 for yes / Press 2 for no\n");
	printf("------------------------------------\n");
	printf("Enter one of the numbers shown at above => ");
	key_wayback_wrongnumber:
	scanf("%d",&key);
	switch(key)
	{
		case 1:
		goto key_wayback_newidentify;
		break;
		
		case 2:
		for (blank=0;blank<=1;blank++)
		printf("\n");
		printf("Exit Status Choosen\n");
		break;
		
		default:
		printf("Enter one of the numbers shown at above => ");
		goto key_wayback_wrongnumber;
		printf("\n");
		break;
	}

	fclose(Test);
	}
}

void readfile()
/* 
	This is "executefile" function.
-----------------------------------------------------------------------------------------------------------------------
	1- This function makes you able to read the information stored at text file.
	2- If the text file is empty this function will do nothing.
-----------------------------------------------------------------------------------------------------------------------
*/
{
	int blank;
	for (blank=0;blank<=1;blank++)
	printf("\n");
	char person[100];
	FILE *Test = fopen("InfoList.txt","r");
	fscanf(Test,"%[^.]",person);
	printf("%s",person);
	fclose(Test);
}

int wipedata()
/* 
	This is "wipedata" function
-----------------------------------------------------------------------------------------------------------------------
	1- This function deletes all information u stored at text file.
	2- If u press 1 all information will be deleted.
	3- If u press 2 this function will do nothing and exits from program.
	4- If u press a number which is not 1 or 2, program wants to enter one of those numbers again.
-----------------------------------------------------------------------------------------------------------------------
*/
{
	int choose;
	FILE *Test = fopen("InfoList.txt","a");
	int blank;
	for (blank=0;blank<=1;blank++)
	printf("\n");
	printf("Are you sure about deleting all information data?\n");
	printf("-------------------------------------------------\n");
	printf("Press 1 for yes / Press 2 for no\n");
	printf("-------------------------------------------------\n");
	printf("Enter one of the numbers shown at above => ");
	key_wayback_wrongnumber:
	scanf("%d",&choose);

	switch(choose)
	{
	case 1:
	fopen("InfoList.txt","w");
	fprintf(Test,"");
	for (blank=0;blank<=1;blank++)
	printf("\n");
	printf("The data has been deleted\n");
	break;
	
	case 2:
	fclose(Test);
	for (blank=0;blank<=1;blank++)
	printf("\n");
	printf("Exit Status Choosen\n");
	break;
	
	default:
	printf("Enter one of the numbers shown at above => ");
	goto key_wayback_wrongnumber;
	printf("/n");
	break;
	}
	fclose(Test);
}

int main()
/* 
	This is "main" function
-----------------------------------------------------------------------------------------------------------------------
	1- This function calls all functions writen in this program.
	2- Every number called in this function opens a specific function.
	3- 4 button makes you able to exit from program.
-----------------------------------------------------------------------------------------------------------------------
*/
{
	wayback_system:
	int key;
	printf("Choose the action u want to make\n");
	printf("--------------------------------\n");
	printf("1- Add new identify\n2- Read all identifies\n3- Delete all identifies\n4- Close Program\n");
	printf("--------------------------------\n");
	printf("Enter one of the numbers shown at above => ");
	wayback:
	scanf("%d",&key);
	
	switch(key)
	{
	case 1:
	savefile();
	break;
	
	case 2:
	readfile();
	break;
	
	case 3:
	wipedata();
	break;
	
	case 4:
	int blank;
	for (blank=0;blank<=1;blank++)
	printf("\n");
	printf("Exit Status Choosen\n");
	break;
	
	default:
	printf("Enter one of the numbers shown at above => ");
	goto wayback;
	printf("\n");
	break;
	}
	return (0);
}

/* 
	Function Status
-----------------------------------------------------------------------------------------------------------------------
	1- Has Bugs
	2- Working
	3- Working
	4- Working
-----------------------------------------------------------------------------------------------------------------------
*/

