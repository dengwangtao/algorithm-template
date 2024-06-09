#ifndef __HEAP_C
#define __HEAP_C

#define MAXN 1005

/*小根堆 === START ===*/

/*堆中节点类型*/
struct Pair {
	int first;
	int second;
};

void swapPair(struct Pair *a, struct Pair *b) {
	int t = -1;
	t = a->first;
	a->first = b->first;
	b->first = t;

	t = a->second;
	a->second = b->second;
	b->second = t;
}

struct Pair heap[MAXN * 4];
static int heap_size = 0;

void heap_push_up(int index) {
	int fa = -1;
	while (index > 0) {
		fa = (index - 1) / 2; /*父节点*/
		if (heap[index].second < heap[fa].second) { /*子节点更小, 和父节点交换*/
			swapPair(&heap[index], &heap[fa]);
			index = fa;
		} else {
			break;
		}
	}
}

void heap_push_down(int index) {
	int lc = -1, rc = -1; /*left child, right child*/
	int cur = -1;
	while (index < heap_size) {
		cur = index;
		lc = index * 2 + 1;
		rc = index * 2 + 2;

		if (lc < heap_size && heap[lc].second < heap[cur].second) {
			cur = lc;
		}
		if (rc < heap_size && heap[rc].second < heap[cur].second) {
			cur = rc;
		}

		if (cur == index) {
			break;
		}

		swapPair(&heap[index], &heap[cur]);
		index = cur;
	}
}

void heap_push(struct Pair p) {
	/*往堆中添加元素*/
	heap[heap_size ++] = p;
	heap_push_up(heap_size - 1);
}

void heap_push_val(int first, int second) {
	/*往堆中添加元素*/
	struct Pair p;
	p.first = first;
	p.second = second;
	heap_push(p);
}

struct Pair heap_pop() {
	/*删除并返回堆顶元素*/
	struct Pair res;
	if (heap_size > 0) {
		res = heap[0];
		swapPair(&heap[0], &heap[-- heap_size]);	/*将堆顶和最后的元素交换, 然后down一下*/
		heap_push_down(0);
	}
	return res;
}

/*小根堆 === END ===*/



#endif