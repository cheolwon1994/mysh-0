#include <utils.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char str[50];
	char *temp;
	strcpy(str,command);
				
	int i =0;
	*argv = (char**)malloc(sizeof(char)*5);		
	char *token = NULL;	
	char *separator = " \t\n"; // 토큰을 나누는 구분자로 쓰인다.  복수개로 지정 가능하다. 
	token = strtok(str, separator); // 첫번째 토큰 추출 
	if(token == NULL)
	{
		*argc=1;
		*(*argv+i)=(char*)malloc(sizeof(char)*5);
		strcpy(*(*argv+(i++)),"");
	}	
	else{
		*(*argv+i)=(char*)malloc(sizeof(char)*strlen(token));//토큰의 길이만큼 메모리 할당
		strcpy(*(*argv+(i++)),token);
		*argc = 1;

		while ((token = strtok(NULL, separator)) != NULL) // 토큰이 발생할 때까지 추출 
		{ 
			*argc=*argc+1;
			*(*argv+i)=(char*)malloc(sizeof(char)*strlen(token));
			strcpy(*(*argv+(i++)),token);
		}
	} 
  // TODO: Fill this!
}
