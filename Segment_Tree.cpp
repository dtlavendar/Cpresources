#include <bits/stdc++.h>
using namespace std;


struct segment_tree_queries {
	using T = long long;
	vector<T> tree;
	vector<T> a;
	int N;
	segment_tree_queries(vector<T> &arr) {
		N = arr.size();
		assert(N <= 2e7);
		// you're pushing it close with a segment tree anyways
		tree.resize(4 * N);
		a = vector<T>(arr.begin(), arr.end());
		init(1, 0, N - 1);
	}
	void comb(int vertex) {
		// change to whatever function (TODO: make sure to change query function)
		tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
	}
	void init(int vertex, int leftBound, int rightBound) {
		if(leftBound== rightBound) {
			tree[vertex] = a[leftBound];
		} else {
			int middle = (leftBound + rightBound) >> 1;
			init(2 * vertex, leftBound, middle);
			init(2 * vertex + 1, middle + 1, rightBound);
			comb(vertex);
		}
	}
	void update(int vertex, int leftBound, int rightBound, int position, T value) {
		assert(position >= leftBound && position <= rightBound);
		if(leftBound == rightBound) {
			tree[leftBound] = value;
		} else {
			int mid = (leftBound + rightBound) / 2;
			if(position <= mid)
				update(2 * vertex, leftBound, mid, position, value);
			else
				update(2 * vertex + 1, mid + 1, rightBound, position, value);
			comb(vertex);
		}
	}
	T query(int vertex, int leftBound, int rightBound, int leftQuery, int rightQuery) {
		if(leftBound > rightQuery || rightBound < leftQuery)
			return 0;
		else if(leftQuery <= leftBound && rightQuery >= rightBound)
			return tree[vertex];
		int middle = (leftBound + rightBound) >> 1;
		// remember to change if you're changing comb
		return query(vertex * 2, leftBound, middle, leftQuery, rightQuery) + query(vertex * 2 + 1, middle + 1, rightBound, leftQuery, rightQuery);
	}
	void update(int pos, int val) {
		update(1, 0, N -1, pos, val);
	}
	T query(int left, int right) {
		return query(1, 0, N - 1, left, right);
	}
};