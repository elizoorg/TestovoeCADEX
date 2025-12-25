#include "Vector3.h"
#include <sstream>
#include <iomanip>


std::string formatDouble(double value, int precision)
{
	
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(precision) << value;
		return oss.str();
	
}

std::ostream& operator << (std::ostream& out, const Vector3& v) { out << v.x << " " << v.y << " " << v.z; return out; }

std::string Vector3::toString(int precision) const
{
	return "(" + formatDouble(x, precision) + ", "
		+ formatDouble(y, precision) + ", "
		+ formatDouble(z, precision) + ")";

}

