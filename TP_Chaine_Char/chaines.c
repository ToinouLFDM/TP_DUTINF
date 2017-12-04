#include <string.h>
#include <stdio.h>
#define MAXCHAR 100


void change_letter(char *tab,char to_change,char new);
int mylen(char *s);
void reverse(char*,char*);
char *last_char(char*);
int is_palindrome(char *s);
void change_maj(char *s);
void decal_char(char *s,int decal);
void decal_vignere(char *s, char*key);
void main()
{
  char tab[MAXCHAR]={"la marine ta tenir"};
  printf("%s\n",tab);
  change_letter(tab,'t','v');
  printf("%s\n",tab);
  char tab2[MAXCHAR];
  strcpy(tab2," à Malte");
  printf("%s\n",tab2);
  strcat(tab,tab2);
  printf("%s\n",tab);
  char *s3="abricot sec?";
  printf( "%s\n, longeur-> %d\n",s3,mylen(s3));
  char *s4;
  reverse("ta marine va tenir",s4);
  printf("%s\n",s4);
  printf("%s\n",last_char(s4));
  char s5[MAXCHAR]="unradarnu";
  if (is_palindrome(s5))
    printf("true\n");
  else
    printf("false\n");
  
  char s6[MAXCHAR]="CHihIRo!";
  printf("%s\n",s6 );
  change_maj(s6);
  printf("%s\n", s6);
  decal_char(s6,1);
  printf("%s\n",s6 );
  decal_char(s6,-1);
  printf("%s\n",s6 );
  decal_vignere(s6,"aaa");
  printf("%s\n",s6 );
  return;
}

void change_letter(char *tab, char to_change,char new)
{
  int i=0;
  for(;i<MAXCHAR;i++,tab+=1)
  {
    if(*tab==to_change)
      *tab=new;
  }
}
/*
void insert_space(char *str,char *word)
{
  i=0;
  count=0;
  char *temp;
  int len_temp;
  int a=0;
  for(;i<MAXCHAR;i++,str++)
  {

    if(*word=='\0' || a)
    {
      a=1;
      *temp=*str;
      *temp++;
    }
    if( *str==*word)
    {
      *word+=1;
      count+=1;
    }
    else
    {
      *word-=count;
      count=0;
    }  
  }

}
*/
void change_maj(char *s)
{
  int i=0;
  while(i<MAXCHAR && s[i]!='\0')
  {
    if( (s[i]>=97) && (s[i]<=122) )
        s[i]-=32;
      i++;
  }
}
void decal_char(char *s,int decal)
{

  int i=0;
  while(i<MAXCHAR && s[i]!='\0')
  {
    printf("%s\n",s );
    int x=0;
    if( (s[i]>=97) && (s[i]<=122) )
    {
      x+=decal%26;
    }
    if( (s[i]>=65) && (s[i]<=90) )
    {
      x+=decal%26;
    }
    if((s[i]+x<65 || (s[i]+x>90 && s[i]+x<122) )&& x!=0)
      x=26+x;
    //printf("char_decal ->%d : %c -> %c\n",x,s[i],s[i]+x);
    s[i]+=x;
    i++;

  }
}
void decal_vignere(char *s, char*key)
{
  int i=0;
  int n=mylen(key)-1;
  while(i<MAXCHAR && s[i]!='\0')
  {
    printf("%s\n",s );
    int x=0;
    if( (s[i]>=97) && (s[i]<=122) )
    {
      x+=key[i%n]%26;
    }
    if( (s[i]>=65) && (s[i]<=90) )
    {
      x+=key[i%n]%26;
    }
    printf("%c\n",key[i%n]);
    if((s[i]+x<65 || (s[i]+x>90 && s[i]+x<122) )&& x!=0)
      x=26+x;
    //printf("char_decal ->%d : %c -> %c\n",x,s[i],s[i]+x);
    s[i]+=x;
    i++;
  }
}
int is_palindrome(char *s)
{
  int i=0;
  int j=0;
  char stmp[MAXCHAR];
  strcpy(stmp,s);
  while(i<MAXCHAR && stmp[i]!='\0')
  {
    i++;
  }
  j=i-1;
  i=0;
  strcpy(stmp,s);
  while(j>0 && stmp[i]==stmp[j])
  {
    printf("%c,%c\n",stmp[i],stmp[j]);
    i++;
    j--;
  }
  printf("%c,%c\n",stmp[i],stmp[j]);
  return j==0;
}

void reverse(char *s,char *res)
{
  int count=0;
  int n=mylen(s)-1;
  char stmp[MAXCHAR];
  printf("salut\n");
  strcpy(stmp,s);
  printf("salut\n");
  while(count<=n)
  {
    
    *res=stmp[n-count];
    res+=1;
    count+=1;
  }
}

int mylen ( char *s )
{
  int compteur = 0 ;
  while (*s != '\0' )
  {
    s++ ;
    compteur++ ;
  }
  return compteur ;
}
char *last_char(char*s)
{
  while(*(s+1)!='\0')
    s++;
  return s;
}
