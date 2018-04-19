#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
using namespace std;



struct point 
{
  float x,y;
   
};

int compareX(const void* a, const void* b)
{
    point *p1 = (point *)a,  *p2 = (point *)b;
    return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    point *p1 = (point *)a,   *p2 = (point *)b;
    return (p1->y - p2->y);
}

float diff_X(point p1, point p2){
	return(p1.x - p2.x);
}

float diff_Y(point p1, point p2){
	return(p1.y - p2.y);
}

float distance(point p1,point p2){
	float X=diff_X(p1,p2);
	float Y=diff_Y(p1,p2);
	return sqrt(X*X + Y*Y);
}

float bruteForce(point p[],int n){
	float min=FLT_MAX;
	float k;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			k=distance(p[i],p[j]);
			if(k < min)
				min=k;

		}
	}
	return min;
}

float minimum(float x, float y)
{
    return (x < y)? x : y;
}
void print_points(point p[],int n){
	for(int i=0;i<n;i++){
		cout<<p[i].x<<" "<<p[i].y<<"\n";
	}

}
int main(){
	point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    qsort(P, n, sizeof(point), compareX);
    print_points(P,n);
	return 0;
}