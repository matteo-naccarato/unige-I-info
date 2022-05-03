#include <iostream>
#include <cmath>

using namespace std;

class Punto2d {

public:

	// Costruttori
	Punto2d();
	Punto2d(double x, double y);
	Punto2d(const Punto2d& p);

	// Distruttore
	~Punto2d();

	// Selettori
	double getX() const;
	double getY() const;

	// Modificatori
	void setX(double x);
	void setY(double x);

	// Operatori sovraccaricati
	Punto2d operator-() const;
	Punto2d& operator++();
	Punto2d operator++(int);
    Punto2d& operator--();
	Punto2d operator--(int);
	Punto2d operator+(Punto2d p) const;
	Punto2d operator-(Punto2d p) const;
	Punto2d operator*(double s) const;
	const Punto2d& operator=(const Punto2d& p);

	bool operator==(Punto2d p) const;

	// AMICHE 
	friend ostream& operator<<(ostream& os, const Punto2d& p);
	friend istream& operator>>(istream& is, Punto2d& p);

private:
	double _x;
	double _y;
};

/////////////////////////////////////////////////////////////////////
// Costruttori della classe Punto2d
/////////////////////////////////////////////////////////////////////

Punto2d::Punto2d()
	: _x(0.0), _y(0.0)
{
}

Punto2d::Punto2d(double x, double y)
	: _x(x), _y(y)
{
}

Punto2d::Punto2d(const Punto2d& p)
	: _x(p._x), _y(p._y)
{
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe Punto2d
/////////////////////////////////////////////////////////////////////

Punto2d::~Punto2d()
{
}

/////////////////////////////////////////////////////////////////////
// Selettori della classe Punto2d
/////////////////////////////////////////////////////////////////////

double Punto2d::getX() const
{
	return _x;
}

double Punto2d::getY() const
{
	return _y;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe Punto2d
/////////////////////////////////////////////////////////////////////

void Punto2d::setX(double x)
{
	_x = x;
}

void Punto2d::setY(double y)
{
	_y = y;
}

/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati della classe Punto2d
/////////////////////////////////////////////////////////////////////

Punto2d Punto2d::operator-() const
{
	return Punto2d(-getX(), -getY());
}

Punto2d& Punto2d::operator++()
{
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return *this;
}

Punto2d Punto2d::operator++(int)
{
	Punto2d temp(*this);
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return temp;
}

Punto2d& Punto2d::operator--()
{
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return *this;
}

Punto2d Punto2d::operator--(int)
{
	Punto2d temp(*this);
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return temp;
}

Punto2d Punto2d::operator+(Punto2d p) const
{
	return Punto2d(getX() + p.getX(), getY() + p.getY());
}

Punto2d Punto2d::operator-(Punto2d p) const
{
	return Punto2d(getX() - p.getX(), getY() - p.getY());
}

Punto2d Punto2d::operator*(double s) const
{
	return Punto2d(s * getX(), s * getY());
}

const Punto2d& Punto2d::operator=(const Punto2d& p)
{
	if (&p != this) {
		setX(p.getX());
		setY(p.getY());
	}
	return *this;
}

bool Punto2d::operator==(Punto2d p) const {
	return (_x == p.getX() && _y == p.getY());
}



/////////////////////////////////////////////////////////////////////
// Funzioni FUORI CLASSE e FRIENDS
/////////////////////////////////////////////////////////////////////

float distanza(Punto2d p1, Punto2d p2) {
	return sqrt((p1.getX() - p2.getX())*(p1.getX() - p2.getX()) + (p1.getY() - p2.getY())*(p1.getY() - p2.getY()));
} 

ostream& operator<<(ostream& os, const Punto2d& p) {
	os << "( " << p.getX() << "," << p.getY() << " )" << endl;
	return os;
}

istream& operator>>(istream& is, Punto2d& p) {
	is >> p._x >> p._y;
	return is;
}


/////////////////////////////////////////////////////////////////////
// Funzione main
/////////////////////////////////////////////////////////////////////

int main()
{
	Punto2d p, q;
	cout << "Inserire le coordinate del primo punto: ";
	cin >> p;
	cout << "\t" << p << endl;
	cout << "Interire le coordinate del secondo punto: ";
	cin >> q;
	cout << "\t" << q << endl;

	cout << "\nDistanza tra i due punti inseriti: " << distanza(p, q) << endl;
	cout << "I due punti " << ((p == q)?"":"non ") << "sono uguali" << endl;

	return 0;
}
