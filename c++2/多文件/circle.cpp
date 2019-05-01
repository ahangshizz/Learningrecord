#include "circle.h"
void circle::set_r(double r) {
	m_r = r;
}
double circle::get_girth() {

	m_girth = m_r * 2 * 3.14;
	return m_girth;
}
double circle::get_acre() {
	m_acre = m_r*m_r*3.14;
	return m_acre;
}