#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v, pr, sz;
	Node *l, *r;
	Node(int vl=0){
		v=vl;
		l=r=nullptr;
		pr=rand();
		sz=1;
	}
	inline void up(){
		sz=1;
		if(l!=nullptr) sz+=l->sz;
		if(r!=nullptr) sz+=r->sz;
	}
}*root;
inline int get_size(Node* node){
	return node == nullptr ? 0 : node->sz;
}
void split(int k, Node *node, Node*& a, Node*& b){
	if(!node) a=b=nullptr;
	else if(k <= get_size(node->l)){ 
        b = node;
        split(k, node->l, a, b->l);
        b->up();
    } else { 						
        a = node;
        split(k-get_size(node->l), node->r, a->l, b);
        a->up();
    }
}

Node* merge(Node* a, Node* b){  
	if(a == nullptr) return b;
	if(b == nullptr) return a;
	if(a->pr < b->pr){
		a->r = merge(a->r, b);
		a->up();
		return a;
	} else {
		b->l = merge(a, b->l);
		b->up();
		return b;
	}
}

void insert(int p, int v){
	Node *a, *b, *nw=nullptr;
	split(p, root, a, b);
	nw=merge(nw, new Node(v));
	root=merge(merge(a, nw), b);
}

void erase(int p){
	Node *a, *b, *a2, *b2;
	split(p-1, root, a, b);
	split(p, b, a2, b2);// 
	root=merge(a, b2);
}



void print(Node *nd){
	if(nd!=nullptr){
		if(nd->l!=nullptr) print(nd->l);	
		printf("%d\n", nd->v);
		if(nd->r!=nullptr) print(nd->r);
	}
}

int n,m,v,p;
string od;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		insert(get_size(root), i);
	}
	print(root);
	while(m--){
		scanf("%s",&od);
		if(od[0]=='i'){
			scanf("%d", &v);
			insert(get_size(root), v);
		} else if(od[0]=='d'){
			scanf("%d", &p);
			erase(p);
		} else {
			print(root);
		}
	}
}

/*
ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
*/

