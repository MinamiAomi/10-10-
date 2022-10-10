#include "LineCollider.h"
#include "Line.h"

LineCollider::LineCollider(class Line* line) :
	mLine(line)
{
	sList.push_back(this);
}
LineCollider::~LineCollider(){}