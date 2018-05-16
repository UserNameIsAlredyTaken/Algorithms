#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

struct point {
	int x;
	int y;
};


int main() {
	int m, n, k;
	cin >> m >> n >> k;

	vector<struct point> p;

	struct point current_point;
	for (int i = 0; i < k; i++) {				
		cin >> current_point.x >> current_point.y;
		p.push_back(current_point);
	}
	
	set<int> short_stripes;
	int ver_stripes_c = 0;
	int hor_stripes_c = 0;


	//проходимся по столбцам
	sort(p.begin(), p.end(), [](const struct point& p1, const struct point& p2) {//сортируем массив точек (прежде всего по иксам)		
		return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
	});
	
	int j = 0;	
	for (int i = 1; i <= m; i++) {
		set<int> cur_col_dots;

		cur_col_dots.insert(0);//добавляем в точки текущего столба гранцу снизу
		for (; (j < k) && (p[j].x == i); j++) {
			cur_col_dots.insert(p[j].y);
		}
		cur_col_dots.insert(n + 1);//добавляем в точки текущего столба гранцу сверху

		int length_of_stripe;
		int prev = *cur_col_dots.begin();
		for (auto it = ++cur_col_dots.begin(); it != cur_col_dots.end(); it++) {
			int next = *it;

			length_of_stripe = next - prev - 1;

			if (length_of_stripe != 0) {
				ver_stripes_c++;
				if (length_of_stripe == 1) {
					short_stripes.insert((i - 1) * n + *it - 1);//записываем номер очередной короткой полоски
				}
			}

			prev = next;			
		}
	}


	//проходимся по стокам
	sort(p.begin(), p.end(), [](const struct point& p1, const struct point& p2) {//сортируем массив точек (прежде всего по игрекам)		
		return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
	});

	j = 0;
	for (int i = 1; i <= n; i++) {
		set<int> cur_str_dots;

		cur_str_dots.insert(0);//добавляем в точки текущей строки гранцу слева
		for (; (j < k) && (p[j].y == i); j++) {
			cur_str_dots.insert(p[j].x);
		}
		cur_str_dots.insert(m + 1);//добавляем в точки текущей строки гранцу справа

		int length_of_stripe;
		int prev = *cur_str_dots.begin();
		for (auto it = ++cur_str_dots.begin(); it != cur_str_dots.end(); it++) {
			int next = *it;

			length_of_stripe = next - prev - 1;
			
			if (length_of_stripe != 0) {
				hor_stripes_c++;
				if (length_of_stripe == 1) {
					short_stripes.insert((*it - 2) * n + i);//записываем номер очередной короткой полоски
				}
			}

			prev = next;
		}
	}

	cout << ver_stripes_c + hor_stripes_c - short_stripes.size();
}