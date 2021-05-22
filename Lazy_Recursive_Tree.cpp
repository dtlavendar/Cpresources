template<class T>
struct segment_tree {
	struct segment_tree *lChild = NULL, *rChild = NULL;
	T sum = 0, lazy = 0;
	int leftmost, rightmost;


	segment_tree(int left, int right, vector<T> &v) {
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
	ll rangeQuery(int left, int right) {
		if(left > rightmost || right < leftmost)
			return 0;
		else if(left <= leftmost && right >= rightmost)
			return sum;
		push();
		return (lChild -> rangeQuery(left, right)) + (rChild -> rangeQuery(left, right));
	}
};
