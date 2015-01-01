#include<stdio.h>
#include<string.h>
void main()
{
	char dd[]="01",mm[]="01",yy[]="2015";
	for(int i=0;i<500;i++)
	{
		FILE *f = fopen("log.txt","w");
		if(f==NULL)
			break;
		char cmd[25]="sudo date ";

		dd[1]++;
		if(dd[1]==58)
		{
			dd[1]=48;
			dd[0]++;
		}
		if(!strcmp(mm,"13"))
                {
                        yy[3]++;
                        dd[0]=48;
                        dd[1]=49;
                        mm[0]=48;
                        mm[1]=49;
                }

		if(!strcmp(dd,"30"))
		{
			dd[0]=48;
			dd[1]=49;	
			mm[1]++;
		}
		if(mm[1]==58)
		{
			mm[0]=49;
			mm[1]=48;
		}
		strcat(cmd,mm);
			strcat(cmd,dd);
			strcat(cmd,"0000");
			strcat(cmd,yy);
			strcat(cmd,".00");
			system(cmd);
			 fprintf(f, "LOG DATE: %s%s%s\n", mm,dd,yy);
			fclose(f);
			system("git add log.txt");
			char com[]="git commit -m 'Contributions; Day ";
			strcat(com,dd);
			strcat(com,"'");
			system(com);
		//printf("%s/%s/%s\n",dd,mm,yy);
	}
	
}
