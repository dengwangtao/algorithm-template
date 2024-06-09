#pragma once

#include <vector>
#include <unordered_map>
#include <functional>

template<typename T>
class Heap {

public:
    using Cmp = std::function<bool(const T&, const T&)>;    // 比较函数
    using Node = std::pair<int, T>;                         // 堆中节点类型

    // 构造函数
    Heap() {
        // 设置默认比较函数
        m_cmp = [](const T& a, const T& b) -> bool {
            return a < b;
        };
    }

    Heap(Cmp cmp): m_cmp(cmp) {}


    void push(const Node& node) {
        m_heap.push_back(node);
        m_map[node.first] = m_heap.size() - 1;

        // push_up
        push_up(m_heap.size() - 1);
    }

    void pop() {
        size_t n = m_heap.size();
        if(n > 1) {
            std::swap(m_heap[0], m_heap[n - 1]);
        }
        m_map.erase(m_heap[n - 1].first);       // 删除映射关系
        m_heap.pop_back();                      // 删除节点

        // push_down
        push_down(0);
    }

    const Node& top() const {
        return m_heap.at(0);
    }

    void update(int idx, const T& val) {
        size_t index = m_map.at(idx);
        m_heap[index].second = val;
        push_down(push_up(index));
    }


private:

    size_t push_up(size_t idx) {
        while(idx > 0) {
            size_t fa = (idx - 1) / 2;
            if(m_cmp(m_heap[idx].second, m_heap[fa].second)) {
                std::swap(m_heap[fa], m_heap[idx]);
                idx = fa;
                m_map[m_heap[idx].first] = idx;
                m_map[m_heap[fa].first] = fa;
            } else return idx;
        }
        return idx;
    }

    size_t push_down(size_t idx) {
        size_t n = m_heap.size();
        while(idx < n) {
            size_t lc = idx * 2 + 1;
            size_t rc = idx * 2 + 2;
            size_t cur = idx;
            if(lc < n && m_cmp(m_heap[lc].second, m_heap[cur].second)) cur = lc;
            if(rc < n && m_cmp(m_heap[rc].second, m_heap[cur].second)) cur = rc;
            if(cur == idx) return idx;
            std::swap(m_heap[cur], m_heap[idx]);
            idx = cur;
            m_map[m_heap[idx].first] = idx;
            m_map[m_heap[cur].first] = cur;
        }
        return idx;
    }


    Cmp m_cmp;

    std::unordered_map<int, size_t> m_map; // 根据 pair 的 first 找到堆中的索引
    std::vector<Node> m_heap;


};