// 10_복사생성자
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2
};

int main()
{
	Point p1;		
	Point p2(1, 2); 
	Point p3(p2);	
					
}




