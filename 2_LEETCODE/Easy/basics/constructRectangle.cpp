// 1. The area of the rectangular web page you designed must equal to the given target area.
// 2. The width W should not be larger than the length L, which means L >= W.
// 3. The difference between length L and width W should be as small as possible.

 vector<int> constructRectangle(int area) {
 	int w = (int) sqrt(area);
 	while (area%w!=0) w--;
 	vector<int> res = {area/w, w};
 	return res;        
 }