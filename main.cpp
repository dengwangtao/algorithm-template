#include <iostream>
#include "segment_tree_max.hpp"
#include "segment_tree_sum.hpp"
#include "segment_tree_trans.hpp"

#include "str_hash.h"
#include "heap_c.h"
#include "heap.hpp"

void test_SegTreeMax() {
    {
        SegTreeMax tree;

        tree.update(190, 200, 99);

        tree.update(200, 300, 1);

        std::cout << tree.query(200, 200) << std::endl;
    }
}

void test_SegTreeSum() {
    {
        SegTreeSum tree;

        tree.update(190, 200, 99);

        tree.update(200, 300, 1);

        std::cout << tree.query(200, 200) << std::endl;
    }
}

void test_SegTreeTrans() {
    {
        SegTreeTrans tree;
        tree.update_point(1, 100); // pos_1 += 100
        tree.update_point(9, 10);  // pos_9 += 10

        tree.zero(1, 8);            // 区间1-8 置零

        std::cout << tree.query_point(1) << " " << tree.query_point(9) << std::endl;
    }
}

void test_StringHash() {
    {
        StringHash sh("123456123");

        std::cout << "StringHash: " << (sh.get(0, 2) == sh.get(6, 8)) << std::endl;
    }

}

void test_heap_c() {
    // 按照second排序
    heap_push_val(2, 1);
    heap_push_val(2, 3);
    heap_push_val(2, 6);

    std::cout << heap_pop().second << std::endl;
    std::cout << heap_pop().second << std::endl;
}

void test_Heap() {
    Heap<int> hp([](auto a, auto b) {return a > b;});

    hp.push({9, 9});
    hp.push({2, 2});
    hp.push({3, 3});

    hp.update(3, 1);

    std::cout << hp.top().second << std::endl;
    hp.pop();
    hp.update(3, 1000);
    // hp.update(3, 1000); // 触发异常
    std::cout << hp.top().second << std::endl;
}

int main() {
    
    test_Heap();


    return 0;
}