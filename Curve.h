#pragma once
#include "GameObject.h"
#include "MyMath.h"
#include <vector>

class Curve :
    public GameObject
{
public:
    struct Data {
        Vector2D mStartPosition;
        Vector2D mControlPosition1;
        Vector2D mControlPosition2;
        Vector2D mEndPosition;
        int mNumDivision;
        float mWidth;
        std::vector<Vector2D> mBezierPoints;
        std::vector<Vector2D> mUpperBezierPoints;
        std::vector<Vector2D> mLowerBezierPoints;

        std::vector<Vector2D> mBezierNormalVector;
    };

private:
    Data mData;

public:
    Curve(class Game* game);
    ~Curve();

    void Create();
    void Draw();
   
};

