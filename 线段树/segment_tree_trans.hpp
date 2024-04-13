#include <map>
#include <vector>
#include <iostream>


/**
 * 区间赋值(0)
 * 单点增减
 * 单点查询
*/
class SegTreeTrans {
    struct Node {
        bool istag; // 是否下传
        int val;    // 区间赋值
        int lc, rc; // left child, right child
    };

public:
    SegTreeTrans() {}
    
    // 区间置零
    void zero(int start, int end, int l = 0, int r = 1e9, int idx = 0) {
        if (l > end || r < start)
            return;
        
        make_sure(idx);
        if (l >= start && r <= end) {
            tr_[idx].istag = true;
            tr_[idx].val = 0;
            return;
        }

        int mid = l + r >> 1;
        push_down(idx, l, r);

        zero(start, end, l, mid, tr_[idx].lc);
        zero(start, end, mid + 1, r, tr_[idx].rc);

    }

    // 单点更新
    void update_point(int pos, int val, int l = 0, int r = 1e9, int idx = 0) {
        if (l > pos || r < pos)
            return;

        if (l == r && l == pos) {
            tr_[idx].val += val;
            return;
        }
        make_sure(idx);

        int mid = l + r >> 1;
        push_down(idx, l, r);

        if (pos <= mid)
            update_point(pos, val, l, mid, tr_[idx].lc);
        else
            update_point(pos, val, mid + 1, r, tr_[idx].rc);

    }

    // 单点查询
    int query_point(int pos, int l = 0, int r = 1e9, int idx = 0) {
        if (l == r && l == pos)
            return tr_[idx].val;
        
        make_sure(idx);
        int mid = l + r >> 1;
        push_down(idx, l, r);

        if (pos <= mid)
            return query_point(pos, l, mid, tr_[idx].lc);
        else
            return query_point(pos, mid + 1, r, tr_[idx].rc);
    }

private:
    std::vector<Node> tr_;

    void make_sure(int idx) {
        while (idx >= tr_.size()) {
            tr_.emplace_back(Node{false, 0, -1, -1});
        }
        if (tr_[idx].lc == -1) {
            tr_.emplace_back(Node{false, 0, -1, -1});
            tr_[idx].lc = tr_.size() - 1;
        }
        if (tr_[idx].rc == -1) {
            tr_.emplace_back(Node{false, 0, -1, -1});
            tr_[idx].rc = tr_.size() - 1;
        }
    }

    void push_down(int idx, int l, int r) {
        if(tr_[idx].istag) {
            Node& left = tr_[tr_[idx].lc];
            Node& right = tr_[tr_[idx].rc];
            
            left.istag = true;
            right.istag = true;
            
            left.val = tr_[idx].val;
            right.val = tr_[idx].val;
            tr_[idx].istag = false;
        }
        
    }
};