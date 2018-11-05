#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>  

#define MAXLINE 1024 
#define NO 0
#define YES 1

int main() 
{ 
	FILE *fpin; 
	char line[MAXLINE]; 
	char **arr;
	char *ptr;
	char *start_ptr;
	int i, j, k;
	int word_cnt;
	int word_len;
	int flag;

	fpin = fopen( "id.txt", "rt" ); 
	if( fpin == NULL ) 
		return 1;

	i = 0;
	j = 0;
	k = 0;
	word_len = 0;
	word_cnt = 0;
	flag = NO;
	ptr = line;
	start_ptr = line;

	arr = (char**)malloc( 10 * sizeof(char*) );

	while( ptr = fgets(line, MAXLINE, fpin) )
	{
		while( *ptr )
		{
			if( *ptr >= 'A' && *ptr <= 'Z' || *ptr >= 'a' && *ptr <= 'z' )
			{
				if( !flag )
				{
					start_ptr = ptr;
					word_cnt++;
					arr = (char**)realloc( arr, word_cnt * sizeof(char*) );
				}

				flag = YES;
				word_len++;
			}
			else
			{
				if( flag )
				{
					*(arr + i) = (char*)malloc( (word_len + 1) * sizeof(char) );
					strncpy( *(arr + i), start_ptr, word_len + 1 );
					*( *(arr + i) + word_len ) = '\0';
					start_ptr = *(arr + i);
					while( *start_ptr )
					{
						if( *start_ptr - 91 < 0 )
							*start_ptr += 32;

						start_ptr++;
					}
					word_len = 0;
					flag = NO;
					i++;
				}
			}
			ptr++;
		}
	}

	ptr = (char*)malloc( 15 * sizeof(char) );
	k = i;
	for (i = 1; i < k; i++) 
	{ 
		for (j = 0; j < k - i; j++) 
		{
			if (strcmp( *(arr + j), *(arr + j + 1) ) > 0)		
			{ 
				strcpy( ptr, *(arr + j) ); 
				strcpy( *(arr + j), *(arr + j + 1) ); 
				strcpy( *(arr + j + 1), ptr ); 
			} 
		}
	}

	for( i = 0; i < k; i++ )  
		puts( *(arr + i) );

	getchar(); getchar();
	return 0;
}
