#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int LEN_STR_MAX =100;

struct Size_char{
    int _index;
    int _row_word_size;
    char **_text=NULL;
    
};



int main()

{
    char file_name[100];
    int lines_lenth,i,j;
    scanf("%s",file_name);

    FILE *file;
    file=(fopen(file_name,"r"));
    if (file==NULL)
    {
        printf("Error!");
        exit(1);
    }
    
    fscanf(file, "%d", &lines_lenth);
    
    
    struct Size_char *struct_array=(struct Size_char *)malloc(sizeof(struct Size_char)* lines_lenth);
    if (struct_array == NULL)
    {
        printf("Error!, cannot allocat memory");
        exit(1);
    };
    

    
    for (i = 0; i < lines_lenth; i++)
    {
        int curr_row_words_num;

        fscanf(file,"%d" "%d",&struct_array[i]._index,&struct_array[i]._row_word_size);
        
        struct_array[i]._text=(char **)malloc(sizeof(char)* curr_row_words_num);
        if (struct_array[i]._text == NULL)
        {
                printf("Error!, cannot allocat memory");
                exit(1);
        };


        for (j = 0; j < curr_row_words_num; j++)
        {
            struct_array[i]._text[j]=(char *)malloc(sizeof(char)* LEN_STR_MAX);
            if (struct_array[i]._text[j] == NULL)
            {
                printf("Error!, cannot allocat memory");
                exit(1);
            };

            fscanf(file,"%s",struct_array[i]._text[j]);
        }
            
    }
}