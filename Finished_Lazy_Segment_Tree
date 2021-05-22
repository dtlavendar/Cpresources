template<class T>
struct segment_tree {
	// prevent pointer overflow
	struct segment_tree *lChild = NULL, *rChild = NULL;
	T sum = 0, lazy = 0;
	int leftmost, rightmost;
	using ll = long long;

	segment_tree(int left, int right, vector<T> &v) {
		// N log N
		leftmost = left;
		rightmost = right;
		if(leftmost == rightmost) {
			sum = v[leftmost];
		} else {
			int mid = (leftmost + rightmost) >> 1;
			lChild = new segment_tree(leftmost, mid, v);
			rChild = new segment_tree(mid + 1, rightmost, v);
			update();
		}
	}
	void push() {
		// O(1)
		lChild->lazy += lazy;
		rChild -> lazy += lazy;
		lChild->sum += lazy;
		rChild -> sum += lazy;
		lazy = 0;
	}
	void update() {
		sum = lChild->sum + rChild->sum;
	}

	void pointUpdate(int pos, long long val) {
		// log N
		if (leftmost == rightmost) {
			sum += val;
		} else {
			int r = lChild -> rightmost;
			if (pos <= r) {
				lChild->pointUpdate(pos, val);
			} else {
				rChild->pointUpdate(pos, val);
			}
			update();
			push();
		}
	}
	void updateRange(int left, int right, long long val) {
		// log N
		if(left > rightmost || right < leftmost)
			return;
		else if(left <= leftmost && right >= rightmost) {
			sum += val;
			lazy += val;
		} else {
			

			lChild -> updateRange(left, right, val);
			rChild -> updateRange(left, right, val);
			update();
			push();
		}
	}

	ll get(int pos) {
		// log N
		if(leftmost == rightmost) {
			return sum;
		} else {
			int r = lChild -> rightmost;
			if(pos <= r) {
				return lChild->get(pos);
			} else {
				return rChild->get(pos);
			}
		}
	}
	ll rangeQuery(int left, int right) {
		// log N
		if(left > rightmost || right < leftmost)
			return 0;
		else if(left <= leftmost && right >= rightmost)
			return sum;
		push();
		return (lChild -> rangeQuery(left, right)) + (rChild -> rangeQuery(left, right));
	}
};
