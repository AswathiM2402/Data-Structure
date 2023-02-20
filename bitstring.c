#include<stdio.h>
#include<string.h>
void union1(char*,char*,char*);
void intersection1(char*,char*,char*);
void difference1(char*,char*,char*);

void main()
{
	char s1[20],s2[20],s3[20];
	printf("\nEnter the first string:");
	scanf("%s",s1);
	printf("\nEnter the second string:");
	scanf("%s",s2);
	intersection1(s1,s2,s3);
	printf("\nIntersection is:%s",s3);
	union1(s1,s2,s3);
	printf("\nUnion is:%s",s3);
	difference1(s1,s2,s3);
	printf("\nDifferenece is:%s\n",s3);
}
void union1(char*s1,char*s2, char*s3)
{
	int i,l;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='0' && s2[i]=='0')
		s3[i]='0';
		else
		{
			s3[i]='1';
		}
		
	}
	s3='\0';
}
void intersection1(char *s1,char *s2, char* s3)
{
	int i,l;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='1' && s2[i]=='1')
		s3[i]='1';
		else
		{
			s3[i]='0';
		}
		
	}
	s3='\0';
}
void difference1(char *s1,char *s2, char* s3)
{
	int i,l;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='1' && s2[i]=='0')
		s3[i]='1';
		else
		{
			s3[i]='0';
		}
		
	}
	s3='\0';
}
