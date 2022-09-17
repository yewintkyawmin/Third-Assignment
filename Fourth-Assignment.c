#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<stdbool.h>

char name[30];
int password,id,amount;
char location[50];

char new_name[30];
int new_password,new_id,new_amount;
char new_location[50];

int choice;
char ans;
char search_name[30];

void insert_to_file();
void read_from_file();
void find_data();
bool name_compare(char str1[],char str2[]);
void update_data();

int main(void)
{
	do{
		printf("\n1 : Input data into File");
		printf("\n2 : Output data from File");
		printf("\n3 : To Find data by name");
		printf("\n4 : To Update data");
		printf("\n5 : To Exit from Program");
		printf("\nEnter : ",choice);
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: insert_to_file();break;
			case 2:	read_from_file();break;
			case 3: find_data();break; 
			case 4: update_data();break;
			case 5: printf("Bye Bye");
					exit(0);
		}
	}while(true);
	
	return 0;
}

void request_data()
{
	printf("\nEnter Name:");
	scanf("%s",&name);
		
	printf("\nEnter Password:");
	scanf("%d",&password);
	
	printf("\nEnter Id:");
	scanf("%d",&id);
	
	printf("\nEnter Amount:");
	scanf("%d",&amount);
	
	printf("\nEnter Location:");
	scanf("%s",&location);
	
}

void show_data()
{
	printf("\nName:%s",name);
	printf("\nPassword:%d",password);
	printf("\nID:%d",id);
	printf("\nAmount:%d",amount);
	printf("\nLoaction:%s\n",location);
	
}

void insert_to_file()
{
	FILE *FilePtr ;
		
	if((FilePtr = fopen("User.txt","a"))== NULL)
	{
		printf("Cannot Open File");	
	}
	else
	{
		request_data();
		do{
			fprintf(FilePtr,"%s %d %d %d %s\n",name,password,id,amount,location);
			
			printf("\nDo you want to Try again?(y/n):");
			scanf(" %c",&ans);
			if(ans == 'n')
			{	break;	}
			else if( ans == 'y')
			{	request_data(); 	}
			else
			{	printf("Wrong Character!");	}	
		}while(FilePtr);
		
		fclose(FilePtr);
	}
}

void read_from_file()
{
	FILE *FilePtr ;
	
	if((FilePtr = fopen("User.txt","r"))==NULL)
	{
		printf("\nThere is no Data in File\n");
	}
	else
	{
		fscanf(FilePtr,"%s%d%d%d%s",&name,&password,&id,&amount,&location);
		
		while(!feof(FilePtr))
		{
			show_data();
			fscanf(FilePtr,"%s%d%d%d%s",&name,&password,&id,&amount,&location);
		}		
		fclose(FilePtr);
	}
}

void find_data()
{
	FILE *FilePtr ;
	
	if((FilePtr = fopen("User.txt","r"))==NULL)
	{
		printf("Can't Open");
	}
	else
	{
		printf("\nEnter Name U want to find:");
		scanf("%s",&search_name);
		
		fscanf(FilePtr,"%s%d%d%d%s",&name,&password,&id,&amount,&location);
		
		while(!feof(FilePtr))
		{
			if(name_compare(search_name,name))
			{
				show_data();
				break;
			}
			else
			{
				fscanf(FilePtr,"%s%d%d%d%s",&name,&password,&id,&amount,&location);
				if(feof(FilePtr))
				{
					printf("\nPerson not Found!\n");
				}
			}
		}	
		fclose(FilePtr);
	}
}

bool name_compare(char str1[],char str2[])
{
	int i;
	bool temp;
	while( str1[i]!='\0' | str2[i] !='\0')
	{
		if(str1[i] == str2[i])
		{
			temp = true ;
		}
		else
		{
			return false;
		}
		i++;
	}
	if(temp == true)
	{
		return true;
	}
}

void update_data()
{
	char update_person[30];
	int temp = 0;
	
	FILE *FilePtr;
	FILE *New_FilePtr;
	
	if( (FilePtr = fopen("User.txt","r")) == NULL )
	{
		printf("File can't open");
	}
	else
	{
		fscanf(FilePtr,"%s%d%d%d%s",&name,&password,&id,&amount,&location);
		
		New_FilePtr = fopen("NewUser.txt","a");
		printf("\nEnter Person's Name you  want to update:");
		scanf("%s",&update_person);
		
		while(!feof(FilePtr))
		{
			if(name_compare(update_person,name))
			{
				printf("\nEnter New Name:");
				scanf("%s",&new_name);
					
				printf("\nEnter New Password:");
				scanf("%d",&new_password);
				
				printf("\nEnter New Id:");
				scanf("%d",&new_id);
				
				printf("\nEnter New Amount:");
				scanf("%d",&new_amount);
				
				printf("\nEnter New Location:");
				scanf("%s",&new_location);
				
				temp = 1;
				fprintf(New_FilePtr,"%s %d %d %d %s\n",new_name,new_password,new_id,new_amount,new_location);	
			}
			else
			{
				fprintf(New_FilePtr,"%s %d %d %d %s\n",name,password,id,amount,location);
			}	
			
			fscanf(FilePtr,"%s%d%d%d%s",&name,&password,&id,&amount,&location);
			
			if(feof(FilePtr))
			{
				if(temp==0)
				{
					printf("\nPerson doesn't exit in File\n");
				}
			}
		}
		
		fclose(FilePtr);
		fclose(New_FilePtr);
		
		remove("User.txt");
		rename("NewUser.txt","User.txt");	
	}	
}
