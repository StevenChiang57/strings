//
//  strings.c
//  strings
//
//  Created by William McCarthy on 052//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>


char dest2[BUFSIZ];
char dest[BUFSIZ];
char src[BUFSIZ] = "Ask not what you can do for your country";


char* strcpy_(char* s, const char* t) {
  char* p = s;
  while ((*s++ = *t++) != '\0') { }

  return p;
}

char* strncpy_(char* s, const char* t, size_t n) {
  char* p = s;

  while (n-- > 0 && *t != '\0') {
    *s++ = *t++;
  }

  while ((int)n-- > 0) {
    *s++ = '\0';
  }

  *s = '\0';
  return p;
}

char* strcat_(char* s, const char* t) {
  char* p = s;

  while (*s != '\0') { ++s; }
  while ((*s++ = *t++) != '\0') { }

  return p;
}


char* strncat_(char* s, const char* t, size_t n) {
  char* p = s;

  while (*s != '\0') { ++s; }
  while (n-- > 0 && *t != '\0') {
    *s++ = *t++;
  }

  *s = '\0';  // in case n goes to 0 while still characters in t
  return p;
}

int strcmp_(const char* s, const char* t) {
  while (*s != '\0' && *t != '\0' && *s == *t) {
    ++s;
    ++t;
  }
  return *s - *t;
}

int strncmp_(const char* s, const char* t, size_t n) {
  while (n-- > 1 && *s != '\0' && *t != '\0' && *s == *t) {
    ++s;
    ++t;
  }
  return *s - *t;
}

const char* strchr_(const char* s, char c) {
  while (*s != '\0' && *s != c) {
    ++s;
  }
  return (*s == c ? s : NULL);
}
const char* strrchr_(const char* s, char c) {
  const char* t = s + strlen(s) - 1;

  while (t >= s && *t != c) {
    --t;
  }
  return (*t == c ? t : NULL);
}

size_t strspn_(const char *s, const char *t){
  size_t inprefix = 0;
  while (strchr_(t, *s){
    ++s;
    ++inprefix;
  }
  return inprefix;
}

size_t strcspn_(const char *s, const char *t){
  size_t outprefix = 0;
  while (!strchr_(t, *s){
    ++s;
    ++outprefix;
  }
  return outprefix;
}

char * strpbrk_(const char *cs, const char *ct){
  while (ct != '\0'){
    if (strchr_(ct, *cs))
      return cs;
    ++cs;
  }
}

void test_strcpy() {
  strcpy(src, "Ask not what you can do for your country");
  memset(dest2, 0, sizeof(dest2));
  memset(dest, 0, sizeof(dest));

  printf("asserting that strcpy(dest, \"%s\") is correct", src);
  assert(strcmp(strcpy_(dest2, src), strcpy(dest, src)) == 0);
  printf("\n");
}

void test_strncpy(const char* s, size_t n) {
  strcpy(src, s);
  memset(dest2, 0, sizeof(dest2));
  memset(dest, 0, sizeof(dest));
  printf("\nasserting that strncpy(dest, \"%s\", %zu) is correct", src, n);
  assert(strcmp(strncpy_(dest2, src, n), strncpy(dest, src, n)) == 0);
}

void test_strcat(const char* s, const char* t) {
  memset(dest2, 0, sizeof(dest2));
  memset(dest, 0, sizeof(dest));

  strcpy(dest, s);
  strcpy(dest2, s);
  printf("\nasserting that strcat(\"%s\", \"%s\") is correct", s, t);
  assert(strcmp(strcat_(dest2, t), strcat(dest, t)) == 0);
}

void test_strncat(const char* s, const char* t, size_t n) {
  memset(dest2, 0, sizeof(dest2));
  memset(dest, 0, sizeof(dest));

  strcpy(dest, s);
  strcpy(dest2, s);
  printf("\nasserting that strncat_(\"%s\", \"%s\", %zu) is correct", s, t, n);
  assert(strcmp(strncat_(dest2, t, n), strncat(dest, t, n)) == 0);
}

void test_strcmp(const char* s, const char* t) {
  printf("\nasserting that strcmp_(\"%s\", \"%s\") is correct", s, t);
  assert(strcmp_(s, t) == strcmp(s, t));
}

void test_strncmp(const char* s, const char* t, size_t n) {
  printf("\nasserting that strncmp_(\"%s\", \"%s\", %zu) is correct", s, t, n);
  assert(strncmp_(s, t, n) == strncmp(s, t, n));
}

void test_strchr(const char* s, char c) {
  printf("\nasserting that strchr_(\"%s\", \'%c\') is correct", s, c);
  assert(strchr_(s, c) == strchr(s, c));
}

void test_strrchr(const char* s, char c) {
  printf("\nasserting that strrchr_(\"%s\", \'%c\') is correct", s, c);
  assert(strrchr_(s, c) == strrchr(s, c));
}

void test_strspn(const char *s, const char *t){
  printf("\nasserting that strspn(\"%s\", \'%s\') is correct", s, t);
  assert(strspn_(s, t) == strspn(s, t));
}

void test_strspn(const char *s, const char *t){
  printf("\nasserting that strcspn(\"%s\", \'%s\') is correct", s, t);
  assert(strcspn_(s, t) == strcspn(s, t));
}

void tests_strncpy() {
  test_strncpy("Ask not", 3);
  test_strncpy("Ask not", 20);
  printf("\n");
}

void tests_strcat() {
  test_strcat("cats", " and dogs");
  test_strcat("what we have here", " is a failure to communicate");
  printf("\n");
}

void tests_strncat() {
  test_strncat("cats", " and dogs", 4);
  test_strncat("cats", " and dogs", 20);
  printf("\n");
}

void tests_strcmp() {
  test_strcmp("cats", "catharsis");
  test_strcmp("catharsis", "cats");
  test_strcmp("catharsis", "catharsis");
  printf("\n");
}

void tests_strncmp() {
  test_strncmp("cats", "catharsis", 20);
  test_strncmp("cats", "catharsis", 3);
  test_strncmp("catharsis", "cats", 20);
  test_strncmp("catharsis", "cats", 3);
  test_strncmp("catharsis", "catharsis", 20);
  test_strncmp("catharsis", "catharsis", 3);
  printf("\n");
}

void test_strchar_helper(void (*helper)(const char*, char)) {
  helper("function", 'c');
  helper("function", 'n');
  helper("function", 'f');
  helper("function", 'z');
  printf("\n");
}
void tests_strchr()  { test_strchar_helper(test_strchr); }
void tests_strrchr() { test_strchar_helper(test_strrchr); }

void test_strspn(){

}


void tests_strspn(){
  test_strspn();
  test_strspn();
}

void tests_strcspn(){
  test_strcspn();
  test_strcspn();
}

void tests_strpbrk(){
  test_strpbrk();
  test_strpbrk();
}

void tests_strstr(){
  test_strstr();
  test_strstr();
}

void tests_strlen(){
  test_strlen();
  test_strlen();
}

void tests_strtok(){
  test_strtok();
  test_strtok();
}


int main(int argc, const char * argv[]) {
  tests_strcpy();
  tests_strncpy();

  tests_strcat();
  tests_strncat();

  tests_strcmp();
  tests_strncmp();

  tests_strchr();
  tests_strrchr();

  // tests_strspn();
  // tests_strcspn();
  // tests_strpbrk();
  // tests_strstr();
  // tests_strlen();
  // tests_strtok();

  printf("\n\tAll assertions passed...\n");
  return 0;
}
