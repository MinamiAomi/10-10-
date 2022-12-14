#pragma once
#include "GameObject.h"
#include "MyMath.h"
#include "LineCollider.h"

class Line :
    public GameObject
{

public:
    struct Data {
        Vector2D mStartPosition;
        Vector2D mEndPosition;
        float mTheta;
        float mWidth;
    };

private:
    Data mData;
    LineCollider mCollider;

public:
    Line(class Game* game);
    ~Line();

   void Create();
   void Draw();

   const Vector2D calcVector() { return mData.mEndPosition - mData.mStartPosition; }
};

