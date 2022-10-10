#pragma once
#include "QuadCollider.h"
#include <list>

class LineCollider :
    public QuadCollider
{

private:
    class Line* mLine;

public:
    LineCollider(class Line* line);
    ~LineCollider();


private:
    static std::list<LineCollider*> sList;

public:
    static const std::list<LineCollider*>& GroupPtr() { return sList; }

};

