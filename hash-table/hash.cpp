#include<iostream>
#include<string.h>
using namespace std;

int hashcalc(char array[5][50], char* str , int tam){
    int key=0;
    for(int i=0; str[i]!='\0'; i++){
        key+=(int) str[i];
    }
    int i=0;
    while(array[key%tam][0] != '0'){
        key+=i;
        if(i++ >= 6) break;
    }
    return key%tam;
}

int hashsearch(char array[5][50], char* str , int tam){
    int key = hashcalc(array, str,tam);
    int i=0;
    while(strcmp( str, array[key])!=0){
        key+=(++i);
        if(i >= tam){
            return -1;
        }
    }
    return key%tam;
}

int main (){
    int tam = 5;

    char str1[50] = "hello";
    char str2[50] = "world";
    char str3[50] = "everybody";
    char str4[50] = "now";
    char str5[50] = "bang";

    char array[5][50] = {"0\0","0\0","0\0","0\0","0\0"};
        
    
    
    strcpy( array[ hashcalc(array,str1, tam) ],str1);
    strcpy( array[ hashcalc(array,str2, tam) ],str2);
    strcpy( array[ hashcalc(array,str3, tam) ],str3);
    strcpy( array[ hashcalc(array,str4, tam) ],str4);
    strcpy( array[ hashcalc(array,str5, tam) ],str5);
    
    for(int i=0; i < tam ; i++){
        printf("(%d) - %s\n",i, array[i]);
    }
    
    strcpy( array[0],str1);
    strcpy( array[1],str2);
    strcpy( array[2],str3);
    strcpy( array[3],str4);
    strcpy( array[4],str5);
    
    
    
    printf("\n");

    for(int i=0; i < 5 ; i++)
        printf("(%d) - %s\n",i, array[i]);

    printf("\n\n(%d)\n",hashsearch(array,"worldss\0", tam));
    

    return 0;
}