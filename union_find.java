package cf;
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.lang.Math;
//import cf.A.FastScanner;

public class B {
	public static void main(String args[]) {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt();
		int q = fs.nextInt();
		
		union_find nodes = new union_find(n);
		while(q-- > 0) {
			int type = fs.nextInt();
			if(type == 1) {
				int u = fs.nextInt(), v= fs.nextInt();
				System.out.println(nodes.connected(u,v) ? "1" : "0");
			} else if(type == 0) {
				int u = fs.nextInt(), v = fs.nextInt();
				nodes.merge(u, v);
			}
		}
		
	}
	
	static class union_find {
		int par[];
		int size[];
		int nodes;
		public union_find(int n) {
			nodes = n;
			par = new int[n];
			size = new int[n];
			for(int i=0; i < n; i++)
				par[i] = i;
		}
		public int find(int n) {
			if(par[n] == n)
				return par[n];
			return par[n] = find(par[n]);
		}
		public void merge(int x, int y) {
			int u = find(x);
			int v = find(y);
			if(u != v) {
				if(size[u] < size[v]) {
					int temp=u;
					u=v;
					v=temp;
				}
				par[v]=u;
				if(size[v] == size[u])
					size[u]++;
			}
		}
		public boolean connected(int x, int y) {
			return find(x) == find(y);
		}
	}
	
	
	
	
	
	
    static class FastScanner 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastScanner() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        }
        public int[] nextArray(int n) {
            int a[] = new int[n];
            for(int i =0; i < n; i++) a[i]=this.nextInt();
            return a;
        }
        public int max(int a[]) {
        	int mx = Integer.MIN_VALUE;
        	for(int i : a)
        		mx = Math.max(i, mx);
        	return mx;
        }
        public int count(int a[], int val) {
        	int ans =0;
        	for(int i : a)
        		ans += val == i ? 1 : 0;
        	return ans;
        }
        public int min(int a[]) {
        	int mn = Integer.MAX_VALUE;
        	for(int i : a)
        		mn = Math.min(i, mn);
        	return mn;
        }
        public void randomShuffleSort(int []a) {
            for(int i =0; i < (a.length)/2; i++) {
                int temp=a[i];
                a[i]=a[(a.length)-1-i];
                a[(a.length)-1-i]=temp;
            }
            this.fine_sort(a);
        }
        public void fine_sort(int a[]) {
            ArrayList<Integer> A = new ArrayList<>();
            for(int i : a) A.add(i);
            Collections.sort(A);
            for(int i=0; i < a.length; i++) {
                a[i]=A.get(i);
            }
        } 
    }
}
