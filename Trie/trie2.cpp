#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define show(a) tr(a,it){ cout << *it << endl; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)

const int MAXN = 26;
 
struct Trie {
   Trie *child[MAXN];
   int prefixes;
   int words;
    
   Trie(){
      prefixes = 0;
      words = 0;
      for(int i = 0; i < MAXN; ++i)
         child[i] = NULL;
   }
    
   ~Trie() {
      for(int i = 0; i < MAXN; ++i)
         delete child[i];
   }
    
   void addWord(const char *s) {
        if(*s=='\0') {
           words++;
           return;
        }
        Trie *t = child[*s-'a'];
        if(child[*s-'a']==NULL) {
           t = child[*s-'a'] = new Trie();  
           t->prefixes = 1;
        } else {
           t->prefixes = t->prefixes + 1;
        }
        t->addWord(s+1);
   }
     
   int countPreffixes(const char *s) {
      if(*s=='\0')
        return prefixes;
      Trie *t = child[*s-'a'];
      if(t==NULL) 
         return 0;
      return t->countPreffixes(s+1);
   }
    
   int countWords(const char *s) {
      if(*s=='\0')
         return words;
      Trie *t = child[*s-'a'];
      if(t==NULL)
         return 0;
      return t->countWords(s+1);
   }
    
   bool find(const char *s) {
      return countWords(s) > 0;
   }
};
 
int main() {
   Trie *trie = new Trie();
   trie->addWord("pavel");
   trie->addWord("pavlok");
   trie->addWord("paval");
   trie->addWord("padk");
   trie->addWord("paq");
   trie->addWord("jose");
   trie->addWord("brenda");
 
   if(trie->find("brenda")) puts("found");
   if(trie->find("paq")) puts("found");
 
   return 0;
}