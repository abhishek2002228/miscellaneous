#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s){
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++){
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

unsigned hashval;
struct nlist *np;

struct nlist *lookup(char *s){
    hashval = hash(s);
    for (np = hashtab[hashval]; np != NULL; np = np->next)
    {
        if(strcmp(s, np->name) == 0){
            return np;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *defn){
    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np)); // allocate size for the structure np is pointing to
        if(np == NULL || (np->name = strdup(name)) == NULL){
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval]; // make np-> next point to the first structure in hastab[hashval]
        hashtab[hashval] = np; // make np as the first structure in hashtab[hashval], effectively inserting np in the beginning
    }
    else{
        free((void *)np->defn);
    }
    if((np->defn = strdup(defn)) == NULL){ // add definition to the name
        return NULL;
    }
    return np;
}

int undef(char *name){
    struct nlist *p;
    if ((np = lookup(name)) == NULL)
    {
        return 0;
    }
    // hashval assigned in lookup
    for (p = hashtab[hashval]; p->next != np; p=p->next){
        ;
    }
    p->next = np->next;
    free((void *)np->defn);
    free((void *)np->name);
    free((void *)np);
    return 1;
}