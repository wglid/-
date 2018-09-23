#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line( char buffer[] );
void main( void )
{
	char line[MAXLINE];
	gets( line );
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
	int found;
	flag = NO;
	found = NO;
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
	do
	{
		c = *buf_ptr;
		if( c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			if( flag == YES )
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
		}
		else
		{
			if( flag == NO ){
				begin = buf_ptr;
			if((c == 'q') || (c == 'c') || (c == 'b') || (c == 'd') || (c == 'r'))
			{
					found = YES;
			}
			}
			flag = YES;
		}
		buf_ptr++;
	}
	while( c != '\0' );
}