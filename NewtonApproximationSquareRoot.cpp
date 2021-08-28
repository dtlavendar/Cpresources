
double sqrtn(double n) {
	const double eps = 1e-15;
	double x = 1;
	// 3
	ll t = 0;	
	for(;;) {
		++t;
		double nx = (x + n / x) / 2;
		cout << nx << nl;
		if(abs(nx-x) < eps)
			break;
		x=nx;
	}
	cout << t << nl;
	return x;
}
