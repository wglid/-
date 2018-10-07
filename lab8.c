#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line( char buffer[] );
void main( void )
{
	char line[MAXLINE];
	fgets(line,sizeof(line),stdin);
	process_line( line );
	puts( line );
}
void process_line( char buffer[] )
{
	char *buf_ptr;
	char *end;
	char *begin;
	char c;
	int flag;
	int flag2;
	int found;
	flag = NO;
	found = NO;
	flag2 = YES;
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
	do
	{
		c = *buf_ptr;
		if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
		{
			if( flag == YES && flag2 == YES)
			{
				end = buf_ptr - 1;
				if( found == YES )
				{
					char *src = end + 1;
					char *dst = begin;
					while( (*dst++ = *src++ ) != '\0' );
					buf_ptr = begin;
				}
			}
			flag = NO;
			found = NO;
			flag2 = YES;
		}
		else
		{
			if( flag == NO ){
				begin = buf_ptr;
				if((c == 'y') || (c == 'o') || (c == 'u') || (c == 'e') || (c == 'a'))
				{
						found = YES;
				}
				flag = YES;
			}
			if(c >= '0' && c <= '9')
				flag2 = NO;
		}
		buf_ptr++;
	}
	while( c != '\0' );
}
