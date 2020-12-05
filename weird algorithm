import java.io.*;
import java.util.*;
public class App {
    static class fr {
        BufferedReader br;
        StringTokenizer st;
 
        public fr() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
 
        int[] readArr(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = this.nextInt();
            }
            return a;
        }
    }
 
    static int sum(int[] a) {
        int s = 0;
        for (int i : a) s += i;
        return s;
    }
 
    static int min(int a[]) {
        int mn = 1000000000;
        for(int i : a) mn=Math.min(mn,i);
        return mn;
    }
    static int max(int a[]){
        int mx=-10000000;
        for(int i : a) mx=Math.max(mx,i);
        return mx;
    }
    static ArrayList<Integer> sieve(int n) {
        boolean primes[] = new boolean[n+1];
        ArrayList<Integer> s = new ArrayList<>();
        for(int i =0; i <= n; i++) primes[i] = true;
        for(int i =2; i <= n; i++) {
            if(primes[i]==true) {
                for(int j = i*i; j<=n; j+=i) {
                    primes[j] = false;
                }
            }
        }
        for(int i = 2; i<=n; i++) {
            if(primes[i]) s.add(i);
        }
        return s;
    }
    public static void main(String args[]) {
        fr s = new fr();
        long tt= s.nextLong();
        System.out.print(tt);
        while(tt!=1) {
            if(tt%2==0) tt/=2;
            else tt=3*tt+1;
            System.out.print(" "+ tt);
        }
    }
} 
