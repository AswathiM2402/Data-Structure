#include <stdio.h>
void main()
{
	int a[10],b[10],c[30],n1,n2,n3,i,j,k;
	printf("Enter the number of elements in first array:");
	scanf("%d",&n1);
	printf("Enter the number of elements in second array:");
	scanf("%d",&n2);
	
	printf("Enter the elements to first array:");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Enter the elements to second array:");
	for(j=0;j<n2;j++)
		{
		scanf("%d",&b[j]);
	}
	i=0;
	j=0;
	k=0;
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else if(a[i]>b[j])
		{
			c[k]=b[j];
			j++;
			k++;
		}
		else
		{
			c[k]=b[j];
			i++;
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		c[k]=b[j];
		k++;
		j++;
	}
n3=k;
printf("The merged array is:");
	for(k=0;k<n3;k++)
	{
		printf("%d\t",c[k]);
	}
	
	
}
