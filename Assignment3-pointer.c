#include<stdio.h>
#define SIZE 5

float Total(float *Ptr);
void ToMili(float *Ptr);
void ToCenti(float *Ptr);
void ToKilo(float *Ptr);
void ToMeter(float *Ptr);

int i;

int main()
{
	printf("\t\t\tThis program is about changing input 'Meter' values to other Metric units\n\n");
	
	float Num[SIZE];
	
	//Request Meter Values
	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter length %d in meter:",i+1);
		scanf("%f",&Num[i]);
	}
	
	//Show Back Input Meter Values
	float *NumPtr = Num;
	for(i=0;i<SIZE;i++)
	{
		printf("\nlength %d is:%f meters",i+1,*(Num+i));	
	}
	
	//Show Total Sum of Input Meter Values
	float total = Total(Num);
	printf("\n\nTotal Length is:%f meters\n",total);
	
	//Change into Milimeter
	printf("\nTo Milimeter\n");
	ToMili(Num);
	
	//Change into Centimeter
	printf("\n\nTo Centimeter\n");
	ToCenti(Num);

	//Change into Kilometer
	printf("\n\nTo Kilometer\n");
	ToKilo(Num);
	
	//Change into Meter
	printf("\n\nTo meter\n");
	ToMeter(Num);
	for(i=0;i<SIZE;i++)
	{
		printf("\nlength %d is:%f meters",i+1,Num[i]);	
	}
	
	return 0;
}

float Total(float *Ptr)
{
	float total;
	for(i=0; i<SIZE ;i++)
	{
		total += Ptr[i] ;
	}
	return total;
	
}

void ToMili(float *Ptr)
{	
	for(i=0 ; i<SIZE ; i++)
	{
		*(Ptr+i) *= 1000  ;
		printf("\nlength %d is:%f milimeters",i+1,*(Ptr+i));
	}
}

void ToCenti(float *Ptr)
{
	for(i=0; i<SIZE ;i++)
	{
		Ptr[i] /= 10;
		printf("\nlength %d is:%f centimeters",i+1,Ptr[i]);
	}
	
}

void ToKilo(float *Ptr)
{
	for(i=0; i<SIZE ;i++)
	{
		*Ptr /=100000;
		printf("\nlength %d is:%f kilometers",i+1,*Ptr);
		Ptr++;
	}
}

void ToMeter(float *Ptr)
{
	for(i=0 ; i<SIZE ; i++)
	{
		*(Ptr++) *= 1000;
	}
}
