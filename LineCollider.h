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

    class Line* line() { return  mLine; }

private:
    static std::list<LineCollider*> sList;

public:
    static std::list<LineCollider*>& GroupPtr() { return sList; }

};

