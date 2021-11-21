#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * sort(char user_string[]);
const char* set_string(char user_string[]);
const char * count_of_characters(char user_sentence1[], char Table_name[]);

int main(void) {

  int length;
  int length_2;
  char *user_sentence1 = malloc(201 * sizeof(char));
  char *user_sentence2 = malloc(201 * sizeof(char));
  printf("enter a sentence \n");
  scanf("%[^\n]%*c", user_sentence1);
  length = strlen(user_sentence1);
  if (length > 200){
    printf("too many words");
    return 0;
  }
  printf("enter a sentence \n");
  scanf("%[^\n]%*c", user_sentence2);
  length_2 = strlen(user_sentence2);
  if (length_2 > 200){
    printf("too many words");
    return 0;
  }
  count_of_characters(user_sentence1, "|SENTENCE1|"); 
  count_of_characters(user_sentence2, "|SENTENCE2|"); 
  return 0;
}


const char * sort(char user_string[]){
  
  int length = strlen(user_string);
  // printf("\nthis is the length %d\n", length);
  // char *user_cpy = malloc(length+1 * sizeof(char)); 

  char *user_cpy = malloc(length * sizeof(char));
  strcpy(user_cpy, user_string);
  char temp;

  for (int i = 0; i < length; i++ ){
    for (int j = i + 1; j < length; j++ ){
      if (user_cpy[i] > user_cpy[j]) {
          temp = user_cpy[i];
          user_cpy[i] = user_cpy[j];
          user_cpy[j] = temp;
    }
  }
  }

  char *user_cpy_pointer = user_cpy;
  return user_cpy_pointer;
}




// 
// 
const char* set_string(char user_string[]){
  // printf("%s", "flag");
  int length = strlen(user_string);
  
  char *sorted_user_string = malloc(length * sizeof(char));
  char *set_user_string = malloc(length * sizeof(char));
  int k = 0;
  strcpy(sorted_user_string, sort(user_string));

  for (int i =0 ; i <= length; i++){
    // printf("\nthis is user_string[%d] %c", i, user_string[i]);
    if (sorted_user_string[i] != sorted_user_string[i+1]){
      set_user_string[k] = sorted_user_string[i];
      k++;
    }
  }
  // printf("%s", set_user_string);

  // char *points_set = set_user_string;
  return set_user_string;
}

const char * count_of_characters(char user_sentence1[], char Table_name[]){
  int length = strlen(user_sentence1);
  // printf("\nlength %d\n", length);
  
  int counter = 0;
  char *set_of_characters = malloc(length * sizeof(char));
  strcpy(set_of_characters, set_string(user_sentence1)); 
  
  // printf("\n\nset_of characters = '%s'\n", set_of_characters);
  printf("\n\n%s", Table_name); 
  printf("\n%-5s %-5s %-12s", "char", "code", "occurances");
  for (int i = 0; i < strlen(set_of_characters); i++){
    for (int j= 0; j < length; j++ ){
    if (set_of_characters[i] ==user_sentence1[j]){
      counter++; 

    }
    }
    printf("\n'%-1c'%-3s%-5d% -12d", set_of_characters[i], " ",set_of_characters[i],counter);
    counter = 0;
  }
  return 0;
}