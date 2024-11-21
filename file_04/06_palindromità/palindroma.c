#include <stdlib.h>
#include <stdio.h>

int frase_palindroma(char s[]);
int mystrlen (char s[]);

int main ()
{
	char p[100];
	
	fgets(p, 100, stdin);
	
	if (frase_palindroma(p))
	{
		printf("palindroma\n");
	}
	else
	{
		printf("non palindroma\n");
	}
}

int frase_palindroma(char s[])
{
	int i, j;
	i = 0;
	j = mystrlen(s) - 1;
	
	while (i < j)
	{
		//salta gli spazi o simili
		while (s[i] == ' ' || s[i] == '\n')
			i++;
		
		while (s[j] == ' ' || s[j] == '\n')
			j--;
		
		
		if (s[i] != s[j])
		{
			return 0;
		}
		
		
		i++;
		j--;
	}
	
	return 1;
}

int mystrlen (char s[])
{
   int i;
   i = 0;

   while (s[i] != '\0')
   {
      i++;
   }

   return i;
}