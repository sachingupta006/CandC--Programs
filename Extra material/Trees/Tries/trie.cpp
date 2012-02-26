#include<iostream>
#include<stdio.h>
#include<string.h>
#define NOT_FOUND 0
#define FOUND 1
using namespace std;

struct trie_node
{
       int words;
       int prefixes;
       trie_node* child[26];
}*root=NULL;
typedef struct trie_node tn;            // typedef so that the name becomes short

void initializeRoot(tn *root)            //initialize the trie 
{
    tn* node=new tn;
    root=node;                          //initializing the trie root node
    for(int i=0;i<26;i++)
             root->child[i]=NULL;
    root->words=0;
    root->prefixes=0;
}
  
     
void addNode(tn *node, char c)          //add a child at character 'c' to a node 'node'
{
     tn* childNode =new tn;
     for(int i=0;i<26;i++)
             childNode->child[i]=NULL;
     childNode->words=0;
     childNode->prefixes=0;
     
     int index=(int)c-97;
     node->child[index]=childNode;
}
int findWord(tn *root, char *word)
{
     tn* curr;
     curr=root;
     int len=strlen(word);            //find length of the word
     int i;
     for(i=0;i<len;i++)
     {
         int index = (int)word[i] - 97;         // find the child of the current node depending on the next character
         curr=curr->child[index];
         if(curr==NULL)                         // if node exists then the word might exist
           return NOT_FOUND;
     }
     if(i==len)
        return FOUND;
     else
         return NOT_FOUND;
}
void addWord(tn *root, char *word)
{
     int len=strlen(word);
     tn* curr=root;
     tn* parent=root;
     int i;
     for(i=0;i<len;i++)
     {
         curr->prefixes++;                        // increment the number of prfix with the word till word[i]
         if(i==len-1)
            curr->words++;                        // word is finished increment the numbre of words
         int index= (int)word[i] - 97;            
         parent=curr;              
         curr=curr->child[i];
         if(curr==NULL)
            addNode(parent,word[i]);              // no child exists for word[i] -- create one
     }
}
int countPrefix(tn *root, char *prefix)
{
     tn* curr;
     curr=root;
     int len=strlen(prefix);            //find length of the word
     int i;
     for(i=0;i<len;i++)
     {
         int index = (int)prefix[i] - 97;         // find the child of the current node depending on the next character
         curr=curr->child[index];
         if(curr==NULL)                         // if node exists then the word might exist
           return NOT_FOUND;
     }
     if(i==len)
        return curr->prefixes;
     else
         return NOT_FOUND;
}      
     
int main()
{
    initializeRoot(root);
    system("pause");
    return 0;
}
