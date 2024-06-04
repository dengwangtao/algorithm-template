#include <iostream>
#include "segment_tree_max.hpp"
#include "segment_tree_sum.hpp"
#include "segment_tree_trans.hpp"

#include "str_hash.h"

int main() {
    {
        SegTreeMax tree;

        tree.update(190, 200, 99);

        tree.update(200, 300, 1);

        std::cout << tree.query(200, 200) << std::endl;
    }




    {
        SegTreeSum tree;

        tree.update(190, 200, 99);

        tree.update(200, 300, 1);

        std::cout << tree.query(200, 200) << std::endl;
    }

    {
        SegTreeTrans tree;
        tree.update_point(1, 100); // pos_1 += 100
        tree.update_point(9, 10);  // pos_9 += 10

        tree.zero(1, 8);            // 区间1-8 置零

        std::cout << tree.query_point(1) << " " << tree.query_point(9) << std::endl;
    }

    {
        StringHash sh("123456123");

        std::cout << "StringHash: " << (sh.get(0, 2) == sh.get(6, 8)) << std::endl;
    }

    return 0;
}