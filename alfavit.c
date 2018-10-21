#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void main(void)
{
    char words[100][32], word[32];
    FILE *finp;
	FILE *fout; 
    int count = 0, i, j;
    if((finp = fopen ("input.txt", "r")) == NULL){
        return;
    }
	fout = fopen("result.txt", "wt" );
	if( fout == NULL )
		return;
    /* —читываем слова из файла */
    while (feof(finp) == 0 || count > 100)
    {
        fscanf (finp, "%s", word);
        strcpy(words[count++], word);
    }
    fclose(finp);
    /* —ортировка методом пузырька */
    for(i = 1; i < count; i++)
        for(j = 0; j < count - i; j++)
            if(strcmp(words[j], words[j+1]) > 0){
                strcpy(word, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], word);
            }
    for(i = 0; i < count; i++)
        fprintf(fout,"%s\n", words[i]);
    system("pause");
}