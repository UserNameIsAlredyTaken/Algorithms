#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h> 
#include <cstdlib>

using namespace std;

struct type {
	int num;
	int x;
	int y;
};

int sortT(const void* lhs,const void* rhs){
	if ((*(type*)lhs).x == (*(type*)rhs).x) return (*(type*)lhs).y - (*(type*)rhs).y;
	return (*(type*)lhs).x - (*(type*)rhs).x;
} 

int sortT2(const void* lhs,const void* rhs){
	if ((*(type*)lhs).y == (*(type*)rhs).y) return (*(type*)lhs).x - (*(type*)rhs).x;
	return (*(type*)lhs).y - (*(type*)rhs).y;
} 

int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	
	int cX;
	int cY;
	int points;
	cin >> cX;
	cin >> cY;
	cin >> points;
	
	int right = 0;
	int top = 0;
	type* cot = new type[points];
	for (int i = 0; i<points; i++){
		scanf("%d", &cot[i].x);
		scanf("%d", &cot[i].y);
	}
	
	if(points==0 && cX!=1 && cY !=1){
		cout << cX + cY;
		return 0;
	}
	
	if(points==0 && (cX==1 || cY ==1)){
		cout << 1;
		return 0;
	}
	
	if(points==cX*cY){
		cout << 0;
		return 0;
	}
	
	qsort(cot, points, sizeof(type), sortT2);
	
	map <int, int> map1;
	int stY = 0;
	for(int i=1; i<=cY; i++){
		if(cot[stY].y!=i) {;
			if(cX!=1)
			right++;
	 	}
		else{
			bool l=true;
			for(int j=stY;;j++){
				if(j>points) break;
				if(cot[j].y!=i || (j==points && cot[j-1].y==i)){
					stY = j;
					if(cX - cot[j-1].x >= 1 ) {
						if(cX - cot[j-1].x == 1 ) {
							map1.insert(pair<int,int>(cot[j-1].x + 1 + cX*(i-1), 0));
						}
						else right++;
					}
					if(l==true){
						if(cot[j-1].x >= 2 ){
							if(cot[j-1].x == 2 ){
								map1.insert(pair<int,int>(cX*(i-1) + cot[j-1].x - 1, 0));
							}
							else right++;
						}
					} 
					break;
				}
				if(l==true && j!=points){
					if(cot[j].x >= 2 ){
						if(cot[j].x == 2 ){
							map1.insert(pair<int,int>(cX*(i-1) + cot[j].x - 1, 0));
						}
						else right++;
					}
					l=false;
				} 
				else {
					if(cot[j].x - cot[j-1].x >= 2 ) {
						if(cot[j].x - cot[j-1].x == 2 ) {
							map1.insert(pair<int,int>(cX*(i-1) + cot[j].x - 1, 0));
						}
						else right++;
					}
				}
			}
		}
	}
	
	if(cY == 1) {
		cout << right + map1.size();
		return 0;
	}
	
	qsort(cot, points, sizeof(type), sortT);
	
	int stY2 = 0;
	for(int i=1; i<=cX; i++){
		if(cot[stY2].x!=i) {
			if(cY!=1)
			top++;
		}
		else{
			bool l=true;
			for(int j=stY2;;j++){
				if(j>points ) break;
				if(cot[j].x!=i || (j==points && cot[j-1].x==i)){
					stY2 = j;
					if(cY - cot[j-1].y >= 1 ) {
						if(cY - cot[j-1].y == 1 ) {
							if(map1.count(cot[j-1].x + (cot[j-1].y)*cX)==true) right++;
						} 
						else top++;
					}
					if(l==true){
						if(cot[j-1].y >= 2 ){
							if(cot[j-1].y == 2 ){
								if(map1.count(cot[j-1].x)==true) right++;
							}
							else top++;
						}
					} 
					break;
				}
				if(l==true && j!=points){
					if(cot[j].y >= 2 ){
						if(cot[j].y == 2 ){
							if(map1.count(cot[j].x)==true) right++;
						} 
						else top++;
					}
					l=false;
				} 
				else {
					if(cot[j].y - cot[j-1].y >= 2 ) {
						if(cot[j].y - cot[j-1].y == 2 ) {
							if(map1.count(cot[j].x + (cot[j-1].y)*cX)==true) right++;
						} 
						else top++;
					}
				}
			}
		}
	}
	long long answer = top + right;

	cout <<answer;
	
	return 0;
}
