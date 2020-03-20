#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 100020

int segment_tree[4*MAX];
int values[MAX];


void build(int node, int start, int end){
    if(start == end){
        segment_tree[node] = values[start];
    }else{
        int mid = (start + end) / 2;

        //Make the left part
        build(node * 2, start, mid);

        //Make the right part
        build(node * 2 + 1, mid + 1, end);

        // Update the node
        segment_tree[node] = min(segment_tree[node*2], segment_tree[node*2+1]);
    }
}

void Update(int node, int start, int end, int idx, int val){
    if(start == end){
        values[idx] = val;
        segment_tree[node] = val; 
    }else{
        int mid = (start + end) / 2;

        if(idx >= start && idx <= mid){
            // Left child
            Update(node * 2, start, mid, idx, val);
        }else{
            Update(node * 2 + 1, mid + 1, end, idx, val);
        }
        segment_tree[node] = min(segment_tree[node*2], segment_tree[node*2+1]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l)
    {
        // range represented by a node is completely outside the given range
        return INT_MAX;
    }
    if(l <= start && end <= r)
    {
        // range represented by a node is completely inside the given range
        return segment_tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1, p2);
}

void clear(){
    for(int i = 0; i < 4*MAX; i++){
        values[i] = INT_MAX;
    }
}

int main(){
    int n, q;
    clear();
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> values[i];
    }
    
    build(1,1,n);
    char type;
    int a, b;
    for(int i = 0; i < q; i++){
        cin >> type >> a >> b;
        if(type == 'q'){
            cout << query(1,1,n,a,b) << endl;
        }else{
            Update(1,1,n,a,b);
        }
    }
    return 0;
}