#include <map>
#include <vector>
#include <iostream>


/**
 * 维护区间最大值的线段树
*/


class SegTree {
    struct Node {
        int max;    // 最大值
        int tag;    // 懒标记
        int lc, rc; // left child, right child
    };
public:
    SegTree() {
        
    }
    void update(int start, int end, int val, int l = 0, int r = 1e9, int idx = 0) {
        // 将区间[start, end]的值 + val

        if(l > end || r < start)
            return;

        make_sure(idx);

        if(l >= start && r <= end) {
            tr_[idx].max += val;
            tr_[idx].tag += val;
            return;
        }

        int mid = l + r >> 1;
        push_down(idx, l, r);

        update(start, end, val, l, mid, tr_[idx].lc);
        update(start, end, val, mid + 1, r, tr_[idx].rc);

        // push_up
        push_up(idx);
    }

    int query(int start, int end, int l = 0, int r = 1e9, int idx = 0) {
        // 查询[start, end]的区间和

        if(l > end || r < start) {
            return 0;
        }
        if(l >= start && r <= end) {
            return tr_[idx].max;
        }

        int mid = l + r >> 1;
        make_sure(idx);
        push_down(idx, l, r);
        return std::max(query(start, end, l, mid, tr_[idx].lc), query(start, end, mid + 1, r, tr_[idx].rc));
    }

private:

    void make_sure(int idx) {
        while(idx >= tr_.size()) {
            tr_.emplace_back(0, 0, -1, -1);
        }
        if(tr_[idx].lc == -1) {
            tr_.emplace_back(0, 0, -1, -1);
            tr_[idx].lc = tr_.size() - 1;
        }
        if(tr_[idx].rc == -1) {
            tr_.emplace_back(0, 0, -1, -1);
            tr_[idx].rc = tr_.size() - 1;
        }
    }

    inline void push_up(int idx) {
        tr_[idx].max = std::max(tr_[tr_[idx].lc].max, tr_[tr_[idx].rc].max);
    }

    void push_down(int idx, int l, int r) {
        int mid = l + r >> 1;
        if(tr_[idx].tag) {
            int tag = tr_[idx].tag;

            Node& left = tr_[tr_[idx].lc];
            Node& right = tr_[tr_[idx].rc];
            
            left.tag += tag;
            right.tag += tag;

            left.max += tag;
            right.max += tag;

            tr_[idx].tag = 0;
        }
    }

private:
    std::vector<Node> tr_;
};





int main() {
    SegTree tree;

    tree.update(100, 200, 99);

    tree.update(200, 300, 1);

    std::cout << tree.query(200, 200) << std::endl;

    return 0;
}