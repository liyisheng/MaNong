#include <iostream>

class Line
{
	private:
		class Point
		{
			public:
				Point (int xp = 0, int yp = 0) : ix_(xp), iy_(yp) {}

				void printpoint() const; 
			private:
				int ix_;
				int iy_;
		};

	public:
		Line(int x1, int y1, int x2, int y2) : pt1(x1, y1), pt2(x2, y2){}

		void printline() const
		{
			pt1.printpoint();
			std::cout << " ----->";
			pt2.printpoint();
			std::cout << std::endl;
		}

		void getPoint(int x, int y)
		{
			Point *pt = new Point(x, y);
			pt->printpoint();
		}

	private:
		Point pt1;
		Point pt2;
};

void Line::Point::printpoint() const
{
	std::cout << "(" << ix_ << ", " << iy_ << ")" << std::endl;
}


int main()
{
	Line line1(1, 2, 3, 4);
	line1.printline();

	//Line::Point pt1(5,6);
	//pt1.printpoint();
	line1.getPoint(5, 6);  

//	pImpl

}
