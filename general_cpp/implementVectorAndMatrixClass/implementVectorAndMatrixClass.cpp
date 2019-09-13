#include <iostream>
using namespace std;

template <typename T>
class Vector3D {
public:
	explicit Vector3D(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
	~Vector3D() {}

protected:
	friend ostream& operator<<(ostream &out, const Vector3D<T> &v);
private:
	T x;
	T y;
	T z;
};

template <typename T>
ostream& operator<<(ostream &out, const Vector3D<T> &v) {
	out << v.x << " " << v.y << " " << v.z << "\n";
	return out;
}

int main(int argc, char **argv) {
	Vector3D<float> vFloat(1.0, 1.1, 1.2);
	cout << vFloat;
	return 0;
}
