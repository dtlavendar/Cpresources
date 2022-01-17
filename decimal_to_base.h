const vector<char> representatives = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
string decimal_to_base(int number, int base) {
	ll a = 1;
	while(a <= 1e12) a *= base;
	string answer;
	bool go=0;
	while(a > 0) {
		if(number >= a) {
			go = 1;
		}
		if(go) {
			answer += representatives[number / a];
			number -= number / a * a;
		}
		a /= base;
	}
	
	
	// reverse(answer.begin(), answer.end());
	return answer;
}
