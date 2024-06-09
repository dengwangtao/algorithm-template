#pragma once

#include <map>
#include <vector>
#include <iostream>



// 区间修改, 单点查询

class SegTree2 {
    struct Node {
        int val;    // 区间值
        bool tag;   // 懒标记
        int lc, rc; // left child, right child
    };
public:
    SegTree2() {
        
    }
    void update(int start, int end, int val, int l = 0, int r = INT_MAX, int idx = 0) {
        // 将区间[start, end]的值 = val

        if(l > end || r < start)
            return;

        make_sure(idx);

        if(l >= start && r <= end) {
            tr_[idx].val = val;
            tr_[idx].tag = true;
            return;
        }

        int mid = l + (r - l) / 2;
        push_down(idx, l, r);

        update(start, end, val, l, mid, tr_[idx].lc);
        update(start, end, val, mid + 1, r, tr_[idx].rc);
    }

    int query(int pos, int l = 0, int r = INT_MAX, int idx = 0) {
        // 查询[start, end]的值

        if(l > pos || r < pos) {
            return 0;
        }
        if(l >= pos && r <= pos) {
            return tr_[idx].val;
        }

        int mid = l + (r - l) / 2;
        make_sure(idx);
        push_down(idx, l, r);
        if(pos <= mid) return query(pos, l, mid, tr_[idx].lc);
        else return query(pos, mid + 1, r, tr_[idx].rc);
    }

private:

    void make_sure(int idx) {
        while(idx >= tr_.size()) {
            tr_.emplace_back(Node{0, false, -1, -1});
        }
        if(tr_[idx].lc == -1) {
            tr_.emplace_back(Node{0, false, -1, -1});
            tr_[idx].lc = tr_.size() - 1;
        }
        if(tr_[idx].rc == -1) {
            tr_.emplace_back(Node{0, false, -1, -1});
            tr_[idx].rc = tr_.size() - 1;
        }
    }

    void push_down(int idx, int l, int r) {
        int mid = l + (r - l) / 2;
        if(tr_[idx].tag) {
            int val = tr_[idx].val;

            Node& left = tr_[tr_[idx].lc];
            Node& right = tr_[tr_[idx].rc];
            
            left.val = val;
            left.tag = true;
            
            right.val = val;
            right.tag = true;

            tr_[idx].tag = false;
        }
    }

private:
    std::vector<Node> tr_;
};