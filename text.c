#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define FALSE 0
#define TRUE 1

int Mygetword(char w[])
{ // same logic of Mygetline()
    char *p_word = w;
    int counter = 0;
    char Cget = getchar();
    *p_word++ = Cget;
    while (counter < WORD && Cget != ' ' && Cget != '\t' && Cget != '\n')
    {
        Cget = getchar();
        *p_word++ = Cget;
        counter++;
    }
    *--p_word = '\0';
    return counter;
}

int similar(char *s, char *t, int n)
{
    if (strcmp(s,t)==0){
       return TRUE; 
    }
    if (strlen(s) != strlen(t) + 1) {
    return FALSE;
  }
  char *p_s = s;
  char *p_t = t;
  int counter = 0;
  int j = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (*(p_s+i) != *(p_t+j)) {
      i++;
      if (++counter > n) {
        return FALSE;  
      }
    }
    j++;
  }
  return TRUE;
}

void print_lines(char *str)
{
    char Buffer[LINE];
    while (!feof(stdin)) // If it's not the EOF keep reading promt from user.
    {
        if(fgets(Buffer, LINE, stdin) != NULL){
            if (strstr(Buffer,str) > 0){
            printf("%s",Buffer);
            }
        }
    }
}

void print_similar_words(char * str){
    while (!feof(stdin)) // If it's not the EOF keep reading promt from user.
    {
                char newWord[WORD];
                Mygetword(newWord);
                if(similar(newWord,str,1) == 1){
                    printf("%s\n",newWord);
                }
    }
}
int main()
{
   // ============ Gets the mission and the word. ======
    char Word[WORD];
    Mygetword(Word);
    char Mission = getchar();
    switch (Mission)
    {
    case 'a':
        print_lines(Word);
        break;

    case 'b':
        print_similar_words(Word);
        break;

    default:
        break;
    }
    return 0;
}