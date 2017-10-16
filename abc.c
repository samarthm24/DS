#include<stdio.h>
#include<stdlib.h>
struct data 
{
char alpha;
int cnt;	
}d[126];
void bsortDesc(struct data d[126], int s)
{
    int i, j;
    struct data temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (d[j].cnt < d[j + 1].cnt)
            {
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            } 
        }
    }
}


int main()
{
int frequency[126]={0};
int ch;
char sa[20];
printf("Enter the file name to be compressed ");
gets(sa);
FILE* txt_file = fopen (sa, "r");
if(txt_file==NULL)
printf("invalid file");
while(1)
{
	ch=fgetc(txt_file);
	if(ch==EOF) break;
	d[ch].cnt+=1;
	d[ch].alpha=ch;
	
}
bsortDesc(d,126);
for(int i =0;i<126;i++)
	{
		if(d[i].cnt>0)
		printf(" %c : % d \n",d[i].alpha,d[i].cnt );
	}
}