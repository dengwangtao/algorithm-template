#include <iostream>
#include "segment_tree_max.hpp"
#include "segment_tree_sum.hpp"



int main() {
    SegTreeMax tree;

    tree.update(190, 200, 99);

    tree.update(200, 300, 1);

    std::cout << tree.query(200, 200) << std::endl;




    SegTreeSum tree2;

    tree2.update(190, 200, 99);

    tree2.update(200, 300, 1);

    std::cout << tree2.query(200, 200) << std::endl;

    return 0;
}