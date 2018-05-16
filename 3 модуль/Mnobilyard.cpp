#include <iostream>
#include <stack> 

using namespace std;

void add_ghost_balls(int current, int last_popped, stack<int> &balls) {
	for (int i = last_popped + 1; i < current; i++) {
		balls.push(i);
	}
}

int main() {
	int n;
	cin >> n;

	stack<int> balls;
	balls.push(0);
	
	int current;
	int last_popped = 0;
	for (int i = 0; i < n; i++) {
		cin >> current;
		if (balls.top() > current) {
			cout << "Cheater";
			return 0;
		}
		if (balls.top() == current) {
			balls.pop();
		} else {
			add_ghost_balls(current, last_popped, balls);
			last_popped = current;
		}
	}	
	cout << "Not a proof"; 
	return 0;
}