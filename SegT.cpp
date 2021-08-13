
// usage: 
// change op -> min, gcd, xor, addition
// qry -> (node, left, right)
// upd -> (pos, val)

typedef int T;
T op(T x, T y) {
	return x+y;
}

struct node {
	
	struct node *lChild, *rChild;
	int cnt;
	T val;
	int leftmost, rightmost;
	node(int left, int right) {
		cnt=1;
		leftmost=left;
		rightmost=right;
		if(leftmost==rightmost)
			val=0,lChild=nullptr, rChild=nullptr;
		else {
			int mid=(leftmost+rightmost)/2;
			lChild=new node(left,mid);
			rChild=new node(mid+1,right);
			recalc();
			cnt+=lChild->cnt+rChild->cnt;
		}
	}

	void recalc() {
		val=op(lChild->val,rChild->val);
	}
};	

void upd(node *root, int pos, T val) {
	if(root->leftmost==root->rightmost) {
		root->val=val;
	} else {
		if(root->lChild->rightmost >= pos)
			upd(root->lChild, pos, val);
		else
			upd(root->rChild, pos, val);
		root->recalc();
	}
}

T qry(node *root, int l, int r) {
	if(l > root->rightmost || r < root->leftmost)
		return 0;
	
	else if(l <= root->leftmost && r >= root->rightmost)
		return root->val;

	return op(qry(root->lChild, l, r), qry(root->rChild, l, r));
}
