#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DICT_LEN 1000
#define WORD_LEN 16
#define N_CHARS 24

char *dict[DICT_LEN];
char word[WORD_LEN+1];
char revcipher[N_CHARS];
char tmpcipher[N_CHARS];

int wordlen(char *word){
  int i = 0;
  while(word[i++] != '\0');
  return i - 1;
}

char *decode_word(char *word, char *dict, char *newcipher){
  /* Check whether there is a word in `dict` that is compatible
     with `newcipher` and `word`. If so, update `newcipher` accordingly. */
  int j;
  char letter;
  int len = wordlen(word);

  if (len != wordlen(dict)) return 0;   /* word too long */

  /* Refill reverse cipher. */
  for (j = 0; j < N_CHARS; j++){
    tmpcipher[j] = newcipher[j];
    if (newcipher[j] != 0)
      revcipher[newcipher[j] - 'a'] = j;
  }

  for (j = 0; j < len; j++){
    /* word[j] in cipher */
    if ((letter = tmpcipher[word[j] - 'a'])){
      /* cipher incompatibility */
      if (dict[j] != letter) break;
    }
    else{
      /* word[j] not in cipher */
      if (revcipher[dict[j] - 'a'] &&
	  revcipher[dict[j] - 'a'] != word[j]){
	/* word and dict[i] incompatible */
	break;
      }
      tmpcipher[word[j] - 'a'] = dict[j];
      revcipher[dict[j] - 'a'] = word[j];
    }
  }

  if (j == len){
    char *returncipher = calloc(N_CHARS, sizeof(char));
    memcpy(returncipher, tmpcipher, N_CHARS);
    return returncipher;
  }
  return NULL;
}

char *decipher(char *cipher, char *line){
  /* If `line` end is reached, return complete `cipher`.
     Else, fetch a `word` from line, and try to update the current
         `cipher` using `dict` and `word`. */
  int i = 0;
  char *newcipher;
  /* Get next word; if reached end, return successful cipher. */
  if (sscanf(line, "%s", word) < 1) return cipher;
  printf("%s\n", word);

  /* If any dict word compatible with current cipher and word, branch. */
  while (dict[i] != NULL){
    printf("--%s\n", dict[i]);
    if ((newcipher = decode_word(word, dict[i], cipher)) != NULL &&
	(newcipher = decipher(newcipher, line + wordlen(word) + 1)) != NULL)
      return newcipher;
    i++;
  }
  return NULL;
}

void test_word(){
  int i;
  char *newcipher = (char *) calloc(N_CHARS, sizeof(char));
  char *res = (char *) calloc(N_CHARS, sizeof(char));
  char word[] = "abba";
  dict[0] = "dddd";
  dict[1] = "bbbbbbb";
  dict[2] = "baab";
  dict[3] = "zyyz";
  dict[4] = "bkcb";
  dict[5] = "hijklmnabcd";
  res = decode_word(word, dict[0], newcipher);
  if (res != NULL)
    printf("ERROR");
  res = decode_word(word, dict[2], newcipher);
  for (i = 0; i < N_CHARS; i++)
    printf("%c\n", (char) res[i]);
}

void test_decipher(){
  int i;
  char *newcipher = (char *) calloc(N_CHARS, sizeof(char));
  char word[] = "abba kkkk uuuu ssss\n";
  dict[0] = "baab";
  dict[1] = "yyyy";
  newcipher = decipher(newcipher, word);
  if (newcipher == NULL)
    printf("No solutions");
  else
    for (i = 0; i < N_CHARS; i++)
      printf("%c|", (char) newcipher[i]);
}

int main(void){
  test_decipher();
  
  /* int nwords, word_id, len; */
  /* size_t dummy; */
  /* char *line; */

  /* while (scanf("%d", &nwords) > 0){ */
  /*   getchar(); /\* remove newline *\/ */

  /*   /\* Read the dictionary. *\/ */
  /*   for (word_id = 0; word_id < nwords; word_id++){ */
  /*     len = getline(&dict[word_id], &dummy, stdin); */
  /*     dict[word_id][len-1] = '\0'; /\* remove newline *\/ */
  /*   } */

  /*   /\* Process line-by-line. *\/ */
  /*   while((len = getline(&line, &dummy, stdin)) != -1){ */
  /*     while (sscanf(line, "%s", word) >= 1){ */
  /* 	len = wordlen(word); */
  /* 	printf("%s len %d\n", word, len); */
  /* 	line += len + 1; */
  /*     } */
  /*   } */
  /* } */
  return 0;
}
