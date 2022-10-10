#include "LineCollider.h"
#include "Line.h"

std::list<LineCollider*> LineCollider::sList;

LineCollider::LineCollider(class Line* line) :
	mLine(line)
{
	sList.push_back(this);
}
LineCollider::~LineCollider(){}