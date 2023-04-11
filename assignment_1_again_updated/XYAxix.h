#pragma once
#ifndef XYAXIX_H
#define XYAXIX_H


class XYaxis
{
public:

	XYaxis()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
		cluster = 0;
	}
	XYaxis(float x,float y)
	{
		this->x = x;
		this->y = y;
		this->cluster = 0;
		this->z = 0;
	}
	XYaxis(float x, float y,float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->cluster = 0;

	}

	float getx()

	{
		return x;
	}
	float gety()

	{
		return y;
	}
	float getz()

	{
		return z;
	}

	void setx(float x)

	{
		this->x=x;
	}
	void sety(float y)

	{
		this->y = y;
	}

	void setz(float z)

	{
		this->z = z;
	}

	void setcluster(int cluster)
	{
		this->cluster = cluster;
	}
	int getcluster()
	{
		return this->cluster;
	}


private:

	float x;
	float y;
	float z;
	int cluster;
	int git2;

};





#endif // !XYAXIX_H
