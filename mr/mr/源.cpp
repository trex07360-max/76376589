#include<iostream>
using namespace std;
#include <cmath>
#include <iomanip>

struct Rect
{
	double m_ID;        //此处因数据较多，为了可读性而选择分开定义，下处同理
	double m_color;
	double m_pointx;
	double m_pointy;
	double m_width;
	double m_height;
};

class Armor
{
public:

	Rect m_rect;

	Armor(Rect rect)
	{
		m_rect = rect;
	}

	void Armor_Color()
	{
		if (m_rect.m_color == 0)
		{
			cout << "颜色：蓝" << endl;
		}
		else if(m_rect.m_color == 1)
		{
			cout << "颜色：红" << endl;
		}
	}

	void Central_point()
	{
		double Central_point_x = m_rect.m_pointx + m_rect.m_width / 2;
		double Central_point_y = m_rect.m_pointy + m_rect.m_height / 2;
		cout << "(" << Central_point_x << "," << Central_point_y << ")"<<" ";
	}

    void Diagonal()
	{
		double l = sqrt(m_rect.m_width * m_rect.m_width + m_rect.m_height * m_rect.m_height);
		cout << "长度: " << fixed << setprecision(2) << l << endl;
		cout << defaultfloat;
	}

	void Armor_Point()
	{
		double zsx = m_rect.m_pointx;          //此处用拼音代替坐标名，例如：zsx=左上x=左上方点的x坐标
		double zsy = m_rect.m_pointy;
		double ysx = zsx + m_rect.m_width;
		double ysy = zsy;
		double yxx = ysx;
		double yxy = ysy + m_rect.m_height;
		double zxx = zsx;
		double zxy = zsy + m_rect.m_height;

		cout << "(" << zsx << "," << zsy << ")" << " " << "(" << ysx << "," << ysy << ")" << " " << "(" << yxx << "," << yxy << ")" << " " << "(" << zxx << "," << zxy << ")";
	}
};

void rect(Rect* r01)
{
	double ID;
	double color;
	double pointx;
	double pointy;
	double width;
	double height;

	cin >> ID >>color;
	cin >> pointx >> pointy >> width >> height;

	r01->m_ID = ID;
	r01->m_color = color;
	r01->m_pointx = pointx;
	r01->m_pointy = pointy;
	r01->m_width = width;
	r01->m_height = height;
}

void color(Rect r02)
{
	cout << "ID：" << r02.m_ID <<" ";
}

int main()
{
	Rect r01;
	rect( &r01);
	if (r01.m_ID > 6 || r01.m_ID < 0)
	{
		return 0;
	}
	Armor a01(r01);
	color(r01);
	a01.Armor_Color();
	a01.Central_point();
	a01.Diagonal();
	a01.Armor_Point();
	return 0;
}