//<------------------------------------------------------------------------------------------------------------------------->
//q1 intersection between two lines
class Line{
public:
	double slope,yintercept;
	Line(Point start, Point end){
		double deltay = end.y-start.y;
		double deltax = end.x - start.x;
		slope = deltay/deltax;
		yintercept = end.y - slope*end.x;
	}
}

class Point{
public:
	double x,y;
	Point(double x, double y){
		this->X = x;
		this->y = y;
	}

	void setLocation(double x, double y){
		this->X = x;
		this->y = y;
	}
}

Point intersection(Point start1,Point end1, Point start2, Point end2){
	if(start1.x>end1.x) swap(start1,end1);
	if(start2.x>end2.x) swap(start2,end2);
	if(start1.x>start2.x){swap(start1,start2);swap(end1,end2);}

	Line l1 = new Line(start1,end1);
	Line l2 = new Line(start2,end2);

	if(l1.slope == l2.slope){
		if(l1.yintercept == l2.yintercept && isBetween(start1,start2,end1)){return start2;}		
	}

	double x = line2.yintercept - line1.yintercept/ (line1.slope-line2.slope);
	double y = x*line1.slope + line1.yintercept;
	Point intersection = new Point(x,y);

	if(isBetween(start1,intersection,end1) && isBetween(star2,intersection,end2)){return intersection;}
	return NULL;
}

bool isBetween(Point start, Point middle, Point end){
	return isBetween(start.x,middle.x,end.y) && isBetween(start.y,middle.y,end.y);
}

bool isBetween(double start, double middle, double end){
	return start>end? end<=middle && middle<=start: start<=middle && middle<=end; 
}
//<------------------------------------------------------------------------------------------------------------------------->
//q2  there will be always more number of 2s in a number than 5s so counting 5 is enough
int countFactZeroes(int n){
	int count = 0;
	for(int i=2;i<n;i++){
		count+= factorsof5(i);
	}
	return count;
}

int countFactZeroes(int num){
	int count=0;
	if(num<0){return -1;}
	for(int i=5;num/i>0;i*=5){
		count+=num/i;
	}
	return count;
}

//<----------------------------------------------------------------------------------------------------------------------->
//q3)
int findSmallestDifference(vector<int> a,vector<int> b){
	sort(a.begin(),a.end());sort(b.begin(),b.end());
	int f=0,s=0;
	int diff = INT_MAX:
	while(f<a.size()&&s<b.size()){
		if(abs(a[f]-b[s])<diff){
			diff= abs(a[f]-b[s]);			
		}
		if(a[f]<b[s]){
			f++;
		}else{
			s++;
		}
	}
	return diff;
}
//<------------------------------------------------------------------------------------------------------------------------->
//q4)
int negate(int a){
	int sign = a<0?1:-1;
	int neg = 0;
	while(a!=0){
		neg += sign;
		a += sign;
	}
	return neg;
}
//<------------------------------------------------------------------------------------------------------------------------->
//q5)
int divide(int a,int b){
	//a<b always and b is not 0
	int x=0,product=0;
	while(product+a<=b){
		product+=a;
		x++;
	}
	return (a>0 && b>0 || a<0 && b<0) x:negate(x);
}

//<------------------------------------------------------------------------------------------------------------------------->
//q6) All possible lengths for a diving board where we can use max upto k boards of length sh and lo
set<int> allLenghts(int k, int sh, int lo){
	set<int> result;
	getAllLenghts(k,0,sh,lo,result);
	return result;
}

 0(2^k) time
void getAllLenghts(int k, int cur, int sh, int lo, set<int> &result){
	if(k==0){
		result.insert(cur);
	}else{
		getAllLenghts(k-1,cur+sh,sh,lo,result);
		getAllLenghts(k-1,cur+lo,sh,lo,result);
	}
}
//<----------------------------------------------------------------------------------------------------------------------->
//memo;
set<int> allLenghts(int k, int sh, int lo){
	set<int> result;
	set<int> memo;
	getAllLenghts(k,0,sh,lo,result,memo);
	return result;
}

 O(k^2) time;
void getAllLenghts(int k, int cur, int sh, int lo, set<int> &result, set<int> &memo){
	if(k==0){
		result.insert(cur);
	}else{
		string key = k+" "+cur;
		if(memo.find(key)!=memo.end()){
			return;
		}
		getAllLenghts(k-1,cur+sh,sh,lo,result);
		getAllLenghts(k-1,cur+lo,sh,lo,result);
		memo.insert(key);
	}
}
//<----------------------------------------------------------------------------------------------------------------------->
// most optimal solutions

set<int> allLenghts(int k, int sh, int lo){
	set<int> lengths;
	for(int ns=0;ns<=k;ns++){// there are only 2 options which means if we choose sh -> 1 lo -> n-1;
		int nl = k-ns;
		int l = ns*sh + nl*lo;
		lengths.insert(l);
	}
	return lengths;
}

//<---------------------------------------------------------------------------------------------------------------------->
// calculator without * and / but with ( and )
int calculate(string s){
	stack<int> nums,ops;
	int num=0,rst=0,sign=1;
	for(char c:s){
		if(isdigit(c)){
			num=num*10+(c-'0');
		}else{
			rst+=sign*num;
			num=0;
			if(c=='+') sign = 1;
			if(c=='-') sign = -1;
			if(c=='('){
				nums.push(rst);
				ops.push(sign);
				rst=0;
				sign=1;
			}
			if(c==')' && ops.size()){
				rst = ops.top()*rst+nums.top();
				ops.pop();nums.pop();
			}
		}
	}
	rst += sign*num;
	return rst;
}

//<------------------------------------------------------------------------------------------------------------------------->
int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op; //(if + it will be 1 else -1)
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

