#include<iostream>
using namespace std;
const int N = 1e5+10;
int a[N], n, tmp[N];

inline void merge (int l, int r){
	int m = (l+r)>>1;
	for (int i=l, j=m, k=l; k<r; k++){
		if (i<m && (j>=r || a[i]<a[j])) tmp[k] = a[i++];
		else tmp[k] = a[j++];
	}
	for (int i=l; i<r; i++) a[i] = tmp[i];
}
inline void merge_sort (int l, int r) {
	if ( r-l<=1 ) return;
	int m = (l+r)>>1;
	merge_sort(l,m);
	merge_sort(m,r);
	merge(l,r);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    merge_sort(0, n);
    for(int i=0; i<n; i++) cout << a[i] << ' '; 
    cout << '\n';
}