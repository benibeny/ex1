#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_STR_MAX 100

struct STR_100{
    char name[LEN_STR_MAX];
};


struct Size_char{
    int _index;
    int _row_word_size;
    struct STR_100 *_strs;
};



void print_curr_array(const struct Size_char *struct_array,const int lines_lenth);
void swap(struct Size_char *struct_array,const int i,const  int j);
void sort_struct_array(struct Size_char *struct_array,const int n);
void sort_and_print_file(FILE *file);
void delete_struct_array(struct Size_char *struct_array,const int lines_length);



int main()

{
    char file_name[LEN_STR_MAX];
    scanf("%s",file_name);
    FILE *file;
    file=(fopen(file_name,"r"));
    if (file==NULL)
    {
        printf("Error!");
        exit(1);
    }

    sort_and_print_file(file);
}

//------------------------------------------------------------------------

void sort_and_print_file(FILE *file)
{
    int lines_lenth,i,j;
    fscanf(file, "%d", &lines_lenth);
    
    
    struct Size_char *struct_array=(struct Size_char *)malloc(sizeof(struct Size_char)* lines_lenth);
    if (struct_array == NULL)
    {
        printf("Error!, cannot allocat memory");
        fclose(file);
        exit(1);
    };
    

    
    for (i = 0; i < lines_lenth; i++)
    {
        fscanf(file,"%d" "%d",&struct_array[i]._index,&struct_array[i]._row_word_size);
        struct_array[i]._strs=(struct STR_100 *)malloc(sizeof(struct STR_100)* struct_array[i]._row_word_size);
        if (struct_array[i]._strs == NULL)
        {
            printf("Error!, cannot allocat memory");
            fclose(file);
            free(struct_array);
            exit(1);
        };

        for ( j = 0; j < struct_array[i]._row_word_size; j++)
        {
           fscanf(file,"%s",struct_array[i]._strs[j].name);
        } 
    }

    sort_struct_array(struct_array,lines_lenth);
    printf("%d\n",lines_lenth);
    print_curr_array(struct_array,lines_lenth);

    delete_struct_array(struct_array,lines_lenth);
    fclose(file);
}

//------------------------------------------------------------------------

void swap(struct Size_char *struct_array,const int i,const  int j) 
{
    struct Size_char temp=struct_array[i];
    struct_array[i]=struct_array[j];
    struct_array[j]=temp;
}

//---------------------------------------------------------------
void sort_struct_array(struct Size_char *struct_array,const int n) 
{
    
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (struct_array[j]._index > struct_array[j+1]._index)
            swap(struct_array, j, j + 1);
        }
    }
}

//-------------------------------------------------------------------
void print_curr_array(const struct Size_char *struct_array,const int lines_lenth)
{
    int i,j;
    
    for ( i = 0; i < lines_lenth; i++)
    {
        printf("%d %d ",struct_array[i]._index,struct_array[i]._row_word_size);
        for (j = 0; j < struct_array[i]._row_word_size; j++)
        {
            printf("%s ",struct_array[i]._strs[j]);
        } 
        printf("\n");
    }
    
}

//-------------------------------------------------------------------
void delete_struct_array(struct Size_char *struct_array,const int lines_length)
{
    for (int i = 0; i < lines_length; i++)
    {
        free(struct_array[i]._strs);  
    }
    free(struct_array);  
}