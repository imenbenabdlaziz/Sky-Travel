#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

void welcome(char msg[], int role)
{
        if(role==1)
        {
                strcat(msg, " Admin");
        }
        if(role==2)
        {
                strcat(msg, " Client");
        }
        if(role==3)
        {
                strcat(msg, " Employee");
        }

}

int verifier (char login[], char password[])
{
	FILE* f;
	char nom[30];
	char motdepasse[30];
	int role;
	f=fopen("users.txt","r");
	if(f !=NULL)
	{
		while(fscanf(f,"%s %s %d \n",nom,motdepasse,&role)!=EOF)
		{
			if(strcmp(login,nom)==0)
			{
				if(strcmp(password,motdepasse)==0)
					{
						fclose(f);
						return(role);
					}
			}
		}
		fclose(f);
		return(-1);
	}
}
