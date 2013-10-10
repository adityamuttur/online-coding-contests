#include <cstdio>
#include <cmath>

using namespace std;

int main() {

	int N, x1, x2, x3, y1, y2, y3;
	int smallest_index, largest_index, current_area, smallest_area, largest_area;
	double a, b, c, s;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

		current_area = (int)( fabs( (x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2)) ) );

		if (i == 1) {
			smallest_area = largest_area = current_area;
			smallest_index = largest_index  = 1;
		}
		if (current_area <= smallest_area) {
			smallest_area = current_area;
			smallest_index = i;
		}
		if (current_area >= largest_area) {
			largest_area = current_area;
			largest_index = i;
		}
	}
	printf("%d %d", smallest_index, largest_index);

	return 0;
}