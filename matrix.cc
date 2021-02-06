const long long mod = 1e9+7;
template<int n> struct matrix {
	long long arr[n][n];
	matrix() {
		memset(arr, 0, sizeof(arr));
	}
	
	matrix<n> multiply(matrix& mat) {
		matrix<n> result;
		
		for(int i=0; i < n; ++i) {
			for(int k=0; k < n; ++k) {
				for(int j=0; j < n; ++j) {
					result.arr[i][j] = (result.arr[i][j] + arr[i][k] * mat.arr[k][j]) % mod;
				}
			}
		}
		
		// multiplication is fine
		return result;
	}
	
	matrix<n> pow(matrix<n> &a, long long pwr) {
		matrix<n> res;
		for(int i=0; i < n; i++) res.arr[i][i]=1;
		
		while(pwr) {
			if(pwr&1) {
				res = res.multiply(a);
			}
			pwr /= 2;
			a = a.multiply(a);
		}
		return res;
	}
};