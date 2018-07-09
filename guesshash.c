
#include <stdio.h>
#include <string.h>

void loginDefaultEncrypt
    (
    char *in,                           /* input string */
    char *out                           /* encrypted string */
    )
{
    int            ix;
    unsigned long  magic     = 31695317;
    unsigned long  passwdInt = 0;

   if (strlen (in) < 8 || strlen (in) > 40)
        {
	//errnoSet (S_loginLib_INVALID_PASSWORD);
        //return (ERROR);
        printf("password is not long enough\n");
        }

    for (ix = 0; ix < strlen(in); ix++)         /* sum the string */
        passwdInt += (in[ix]) * (ix+1) ^ (ix+1);

    sprintf (out, "%u", (long) (passwdInt * magic)); /* convert interger
							to string */
    /* make encrypted passwd printable */

    for (ix = 0; ix < strlen (out); ix++)
        {
        if (out[ix] < '3')
            out[ix] = out[ix] + '!';    /* arbitrary */

        if (out[ix] < '6')
            out[ix] = out[ix] + '/';    /* arbitrary */

        if (out[ix] < '9')
            out[ix] = out[ix] + 'A';    /* arbitrary */
        }

    return ;
}
 
int main()
{
        char inC[255];
        char outC[255];
 
	FILE *fp = fopen("1.txt", "r");  //
	if(NULL == fp)
	{
		printf("failed to open dos.txt\n");
		return 1;
	}
 
	while(!feof(fp))
	{
		memset(inC, 0, 255);
                memset(outC, 0, 255);
		fgets(inC, sizeof(inC) - 1, fp); // 包含了换行符
                if(strlen(inC)<8)
                   continue;
                int len = strlen(inC);
                len=len-2;
                inC[len] = 0; //delete huanhangfu
                loginDefaultEncrypt(inC,outC);        
                if(strcmp(outC, "cQwwddSRxS")==0)
                {
		    printf("password:%s to hash:%s\n",inC, outC);
                    //return 0;
                }

	}
 
	fclose(fp);
	return 0;
}

