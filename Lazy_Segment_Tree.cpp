#include<iostream>
#include<vector>
using ll = long long;

class SegmentTree{
    private:
    int n;
    std::vector<ll> arr;
    std::vector<ll> tree;
    std::vector<ll> lazy;

    public:
    SegmentTree(int n, std::vector<ll>& arr) : n(n), arr(arr), tree(n * 4), lazy(n * 4){
        build(1, n, 1);
    }

    void build(int l, int r, int idx){
        if(l == r){
            tree[idx] = arr[l];
            return ;
        }
        int mid = (l + r) / 2;
        build(l, mid, idx * 2);
        build(mid + 1, r, idx * 2 + 1);
        tree[idx] = std::max(tree[idx * 2], tree[idx * 2 + 1]);
        lazy[idx] = 0;
    }

    ll query(int l, int r, int curr_l, int curr_r, int idx){
        if(curr_r < l || r < curr_l) return INT32_MIN;
        if(idx * 2 <= n * 2) lazy[idx * 2] += lazy[idx];
        if(idx * 2 + 1 <= n * 2) lazy[idx * 2 + 1] += lazy[idx];
        tree[idx] += lazy[idx];
        lazy[idx] = 0;
        if(curr_l >= l && curr_r <= r) return tree[idx];
        int mid = (curr_l + curr_r) / 2;
        return std::max(query(l, r, curr_l, mid, idx * 2), query(l, r, mid + 1, curr_r, idx * 2 + 1));
    }

    void update(int l, int r, int curr_l, int curr_r, int idx, ll val){
        if(curr_r < l || r < curr_l) return;
        if(curr_l != curr_r){
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        tree[idx] += lazy[idx];
        lazy[idx] = 0;
        if(l <= curr_l && curr_r <= r){
            tree[idx] += val;
            if(curr_l != curr_r){
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }
            return;
        }
        int mid = (curr_l + curr_r) / 2;
        update(l, r, curr_l, mid, idx * 2, val);
        update(l, r, mid + 1, curr_r, idx * 2 + 1, val);
        tree[idx] = std::max(tree[idx * 2], tree[idx * 2 + 1]);
    }

    int getN(){
        return n;
    }

    void printTree(){
        for(int i = 1; i <= n; i++){
            std::cout << tree[i] << ' ';
        }
        std::cout << '\n';
    }

    void printLazy(){
        for(int i = 1; i <= n; i++){
            std::cout << lazy[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main(){
    int n;
    std::cin >> n;
    std::vector<ll> arr(n + 1);
    for(int i = 1; i <= n; i++){
        std::cin >> arr[i];
    }
    SegmentTree tree(n, arr);
    tree.printTree();

    int q;
    std::cin >> q;
    for(int i = 0; i < q; i++){
        int cmd;
        std::cin >> cmd;
        switch (cmd)
        {
        case 0:{
            int l, r;
            std::cin >> l >> r;
            std::cout << tree.query(l, r, 1, n, 1) << '\n';
            break;
        }
        case 1:{
            int l, r;
            ll val;
            std::cin >> l >> r >> val;
            tree.update(l, r, 1, n, 1, val);
            break;
        }
        default:
            break;
        }
    }

    return 0;
}