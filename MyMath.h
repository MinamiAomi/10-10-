#pragma once
#include <math.h>
#include <limits>

namespace Math
{

	constexpr float Pi = 3.14159265359f;
	constexpr float Two_Pi = 2.0f * Pi;
	constexpr float Pi_Over_2 = Pi / 2.0f;
	constexpr float INF = std::numeric_limits<float>::infinity();
	constexpr float NEG_INF = -std::numeric_limits<float>::infinity();

	/// <summary>
	/// 弧度法変換
	/// </summary>
	/// <param name="degrees">度数法</param>
	/// <returns>弧度法</returns>
	inline float ToRadians(float degrees) {
		return degrees * Pi / 180.0f;
	}
	/// <summary>
	/// 度数法変換
	/// </summary>
	/// <param name="radians">弧度法</param>
	/// <returns>度数法</returns>
	inline float ToDegrees(float radians) {
		return radians * 180.0f / Pi;
	}
	/// <summary>
	/// ほぼゼロ
	/// </summary>
	/// <param name="value">値</param>
	/// <param name="epsilon">誤差</param>
	/// <returns>true : false</returns>
	inline bool NearZero(float value, float epsilon = 0.001f) {
		return fabs(value) <= epsilon;
	}
	/// <summary>
	/// 大きいほうを求める
	/// </summary>
	/// <typeparam name="TYPE">型</typeparam>
	/// <param name="v1">値１</param>
	/// <param name="v2">値２</param>
	/// <returns>値１　or　値２</returns>
	template <typename TYPE>
	TYPE Max(const TYPE& v1, const TYPE& v2) {
		return v1 < v2 ? v2 : v1;
	}
	/// <summary>
	/// 小さいほうを求める
	/// </summary>
	/// <typeparam name="TYPE">型</typeparam>
	/// <param name="v1">値１</param>
	/// <param name="v2">値２</param>
	/// <returns>値１　or　値２</returns>
	template <typename TYPE>
	TYPE Min(const TYPE& v1, const TYPE& v2) {
		return v1 < v2 ? v1 : v2;
	}
	/// <summary>
	/// 値を収める
	/// </summary>
	/// <typeparam name="TYPE">型</typeparam>
	/// <param name="value">値</param>
	/// <param name="lower">下限</param>
	/// <param name="upper">上限</param>
	/// <returns></returns>
	template <typename TYPE>
	TYPE Clamp(const TYPE& value, const TYPE& lower, const TYPE& upper) {
		return Min(upper, Max(lower, value));
	}
	/// <summary>
	/// 絶対値
	/// </summary>
	/// <param name="value">値</param>
	/// <returns></returns>
	inline float Abs(float value) {
		return fabsf(value);
	}
	/// <summary>
	///	サイン
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Sin(float angle) {
		return sinf(angle);
	}
	/// <summary>
	/// コサイン
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Cos(float angle) {
		return cosf(angle);
	}
	/// <summary>
	/// タンジェント
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Tan(float angle) {
		return tanf(angle);
	}
	/// <summary>
	/// アークサイン
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Asin(float angle) {
		return asinf(angle);
	}
	/// <summary>
	/// アークコサイン
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Acos(float angle) {
		return acosf(angle);
	}
	/// <summary>
	/// アークタンジェント
	/// </summary>
	/// <param name="y">y成分</param>
	/// <param name="x">x成分</param>
	/// <returns>ラジアン</returns>
	inline float Atan2(float y, float x) {
		return atan2f(y, x);
	}
	/// <summary>
	/// 線形補間
	/// </summary>
	/// <param name="t">変化量</param>
	/// <param name="start">スタート</param>
	/// <param name="end">エンド</param>
	/// <returns></returns>
	inline float Lerp(float t, float start, float end) {
		return start + t * (end - start);
	}
	/// <summary>
	/// 平方根
	/// </summary>
	/// <param name="value">値</param>
	/// <returns></returns>
	inline float Sqrt(float value) {
		return sqrtf(value);
	}
	/// <summary>
	/// float剰余演算
	/// </summary>
	/// <param name="number">割られる数</param>
	/// <param name="denom">割る数</param>
	/// <returns>余り</returns>
	inline float Fmod(float number, float denom) {
		return fmodf(number, denom);
	}
	/// <summary>
	/// 冪乗
	/// </summary>
	/// <param name="base">底</param>
	/// <param name="exponent">指数</param>
	/// <returns></returns>
	inline float Pow(float base, float exponent) {
		return powf(base, exponent);
	}

}

// 2次元ベクトル
class Vector2D
{

public:

	float x; // x成分
	float y; // y成分


public:

	//コンストラクタ

	Vector2D() : x(0.0f), y(0.0f) {}
	Vector2D(float x, float y) : x(x), y(y) {}
	Vector2D(const Vector2D& vector) : Vector2D(vector.x, vector.y) {}
	~Vector2D() {}


	// セット関数
	/// <summary>
	/// セット
	/// </summary>
	inline void Set(float x, float y);
	/// <summary>
	/// ゼロベクトルにする
	/// </summary>
	inline void SetZero();
	/// <summary>
	/// 正規化ベクトルにする
	/// </summary>
	inline void SetNormalize();
	/// <summary>
	/// 大きさを変える
	/// </summary>
	/// <param name="length">大きさ</param>
	inline void SetMagnitude(float length);
	/// <summary>
	/// 回転させる
	/// </summary>
	/// <param name="theta">回転角度</param>
	inline void SetRotate(float theta);

	// const関数 
	/// <summary>
	/// 長さ
	/// </summary>
	/// <returns>float型</returns>
	inline float Length() const;
	/// <summary>
	/// 長さの二乗
	/// </summary>
	/// <returns>float型</returns>
	inline float LengthSquare() const;
	/// <summary>
	/// ベクトルとの距離
	/// </summary>
	/// <param name="other">ベクトル</param>
	/// <returns>float型</returns>
	inline float DistanceFrom(const Vector2D& other) const;
	/// <summary>
	/// 内積
	/// </summary>
	/// <param name="other">ベクトル</param>
	/// <returns>float型</returns>
	inline float Dot(const Vector2D& other) const;
	/// <summary>
	/// 外積
	/// </summary>
	/// <param name="other">ベクトル</param>
	/// <returns>float型</returns>
	inline float Cross(const Vector2D& other) const;
	/// <summary>
	/// なす角
	/// </summary>
	/// <returns></returns>
	inline float Angle() const;
	/// <summary>
	/// 正規化
	/// </summary>
	/// <returns>Vector2D型</returns>
	inline Vector2D Normalized() const;
	/// <summary>
	/// 法線ベクトル
	/// </summary>
	/// <returns>Vector2D型</returns>
	inline Vector2D Normal() const;
	/// <summary>
	/// 回転したベクトル
	/// </summary>
	/// <param name="theta">回転角度</param>
	/// <returns>Vector2D型</returns>
	inline Vector2D Rotated(float theta) const;
	/// <summary>
	/// 大きさを変えたベクトル
	/// </summary>
	/// <param name="length">大きさ</param>
	/// <returns>Vector2D型</returns>
	inline Vector2D Magnituded(float length) const;
	/// <summary>
	/// 反射ベクトル
	/// </summary>
	/// <param name="normal">正規化した壁の法線ベクトル</param>
	/// <returns>Vector2D型</returns>
	inline Vector2D Reflected(const Vector2D& normal) const;
	/// <summary>
	/// 壁ずりベクトル
	/// </summary>
	/// <param name="normal">正規化した壁の法線ベクトル</param>
	/// <returns>Vector2D型</returns>
	inline Vector2D AlongWall(const Vector2D& normal) const;

	// 比較関数

	/// <summary>
	/// ゼロベクトルであるか
	/// </summary>
	/// <returns>bool型</returns>
	inline bool IsZero() const;

	// 演算子のオーバーロード

	inline Vector2D operator+() const;
	inline Vector2D operator-() const;
	inline Vector2D operator+(const Vector2D& other) const;
	inline Vector2D operator-(const Vector2D& other) const;
	inline Vector2D operator*(float s) const;
	inline Vector2D operator/(float s) const;
	inline Vector2D operator*(const Vector2D& other) const;
	inline Vector2D operator/(const Vector2D& other) const;
	inline const Vector2D& operator=(const Vector2D& other);
	inline const Vector2D& operator+=(const Vector2D& other);
	inline const Vector2D& operator-=(const Vector2D& other);
	inline const Vector2D& operator*=(float s);
	inline const Vector2D& operator/=(float s);
	inline bool operator==(const Vector2D& other) const;
	inline bool operator!=(const Vector2D& other) const;

	// 後にくる乗算
	friend inline Vector2D operator*(float s, const Vector2D& vector) {
		return { s * vector.x,s * vector.y };
	}

};

/// <summary>
/// 3次ベジェ曲線
/// </summary>
/// <param name="t">媒介変数</param>
/// <param name="start">始点</param>
/// <param name="control1">制御点１</param>
/// <param name="control2">制御点２</param>
/// <param name="end">終点</param>
/// <returns></returns>
inline Vector2D CalcCubicBezierCurve(float t, const Vector2D& start, const Vector2D& control1, const Vector2D& control2, const Vector2D& end) {
	float s = 1.0f - t;
	return (Math::Pow(s, 3) * start) + (3 * Math::Pow(s, 2) * t * control1) + (3 * s * Math::Pow(t, 2) * control2) + Math::Pow(t, 3) * end;
}

/// <summary>
/// 微分3次ベジェ曲線
/// </summary>
/// <param name="t"></param>
/// <param name="start"></param>
/// <param name="control1"></param>
/// <param name="control2"></param>
/// <param name="end"></param>
/// <returns></returns>
inline Vector2D DiffCubicBezierCurve(float t, const Vector2D& start, const Vector2D& control1, const Vector2D& control2, const Vector2D& end) {
	return 3 * (-start + 3 * control1 - 3 * control2 + end) * Math::Pow(t, 2.0f) + 6 * (start - 2 * control1 + control2) * t + 3 * (-start + control1);
}

class Matrix33 {

private:
	float ele[3][3];

public:
	Matrix33(
		float _00 = 1, float _01 = 0, float _02 = 0,
		float _10 = 0, float _11 = 1, float _12 = 0,
		float _20 = 0, float _21 = 0, float _22 = 1) {
		ele[0][0] = _00, ele[0][1] = _01, ele[0][2] = _02;
		ele[1][0] = _10, ele[1][1] = _11, ele[1][2] = _12;
		ele[2][0] = _20, ele[2][1] = _21, ele[2][2] = _22;
	}
	Matrix33(float e[3][3]) {
		memcpy(ele, e, 9 * sizeof(float));
	}


	inline void setIdentity();
	inline Vector2D operator*(const Vector2D& vec) const;
	inline Matrix33 operator*(const Matrix33& mat) const;
	inline Matrix33& operator*=(const Matrix33& mat);

	inline static Matrix33 CreateScaling(float x, float y);
	inline static Matrix33 CreateScaling(const Vector2D& vec);
	inline static Matrix33 CreateScaling(float s);

	inline static Matrix33 CreateRotation(float t);

	inline static Matrix33 CreateTranslation(float x, float y);
	inline static Matrix33 CreateTranslation(const Vector2D& vec);
};

#pragma region Vector2D関数定義

// セット関数

inline void Vector2D::Set(float x, float y) {
	x = x;
	y = y;
}

inline void Vector2D::SetZero() {
	x = 0;
	y = 0;
}
inline void Vector2D::SetNormalize() {
	*this = Normalized();
}
inline void Vector2D::SetMagnitude(float length) {
	*this = Magnituded(length);
}
inline void Vector2D::SetRotate(float theta) {
	*this = Rotated(theta);
}

// const関数 
inline float Vector2D::Length() const {
	return Math::Sqrt(LengthSquare());
}
inline float Vector2D::LengthSquare() const {
	return Dot(*this);
}
inline float Vector2D::DistanceFrom(const Vector2D& other) const {
	return (other - *this).Length();
}
inline float Vector2D::Dot(const Vector2D& other) const {
	return x * other.x + y * other.y;
}
inline float Vector2D::Cross(const Vector2D& other) const {
	return x * other.y - y * other.x;
}
inline float Vector2D::Angle() const {
	return Math::Atan2(y, x);
}
inline Vector2D Vector2D::Normalized() const {
	return Length() != 0 ? *this / Length() : *this;
}
inline Vector2D Vector2D::Normal() const {
	return { -y,x };
}
inline Vector2D Vector2D::Rotated(float theta) const {
	float c = Math::Cos(theta);
	float s = Math::Sin(theta);
	return{ x * c - y * s ,y * c + x * s };
}
inline Vector2D Vector2D::Magnituded(float length) const {
	return Normalized() * length;
}
inline Vector2D Vector2D::Reflected(const Vector2D& normal) const {
	return normal.Dot(-*this) * 2 * normal + *this;
}
inline Vector2D Vector2D::AlongWall(const Vector2D& normal) const {
	return normal.Dot(-*this) * normal + *this;
}

// 比較関数

inline bool Vector2D::IsZero() const {
	return x == 0.0 && y == 0.0;
}

// 演算子のオーバーロード

inline Vector2D Vector2D::operator+() const {
	return *this;
}
inline Vector2D Vector2D::operator-() const {
	return { -x,-y };
}
inline Vector2D Vector2D::operator+(const Vector2D& other) const {
	return { x + other.x, y + other.y };
}
inline Vector2D Vector2D::operator-(const Vector2D& other) const {
	return { x - other.x, y - other.y };
}
inline Vector2D Vector2D::operator*(float s) const {
	return { x * s, y * s };
}
inline Vector2D Vector2D::operator/(float s) const {
	return { x * (1.0f / s), y * (1.0f / s) };
}
inline Vector2D Vector2D::operator*(const Vector2D& other) const {
	return { x * other.x, y * other.y };
}
inline Vector2D Vector2D::operator/(const Vector2D& other) const {
	return { x * (1.0f / other.x), y * (1.0f / other.y) };
}
inline const Vector2D& Vector2D::operator=(const Vector2D& other) {
	x = other.x;
	y = other.y;
	return *this;
}
inline const Vector2D& Vector2D::operator+=(const Vector2D& other) {
	x += other.x;
	y += other.y;
	return *this;
}
inline const Vector2D& Vector2D::operator-=(const Vector2D& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}
inline const Vector2D& Vector2D::operator*=(float s) {
	x *= s;
	y *= s;
	return *this;
}
inline const Vector2D& Vector2D::operator/=(float s) {
	x /= s;
	y /= s;
	return *this;
}
inline bool Vector2D::operator==(const Vector2D& other) const {
	return x == other.x && y == other.y;
}
inline bool Vector2D::operator!=(const Vector2D& other) const {
	return x != other.x && y != other.y;
}

#pragma endregion


#pragma region Matrix33関数定義
inline void Matrix33::setIdentity() {
	float iden[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	memcpy(ele, iden, 9 * sizeof(float));
}
inline Vector2D Matrix33::operator*(const Vector2D& vec) const{
	return Vector2D(
		ele[0][0] * vec.x + ele[0][1] * vec.y + ele[0][2],
		ele[1][0] * vec.x + ele[1][1] * vec.y + ele[1][2]);
}
inline Matrix33 Matrix33::operator*(const Matrix33& mat) const {
	return Matrix33(
			ele[0][0] * mat.ele[0][0] + ele[0][1] * mat.ele[1][0] + ele[0][2] * mat.ele[2][0],
			ele[0][0] * mat.ele[0][1] + ele[0][1] * mat.ele[1][1] + ele[0][2] * mat.ele[2][1],
			ele[0][0] * mat.ele[0][2] + ele[0][1] * mat.ele[1][2] + ele[0][2] * mat.ele[2][2],

			ele[1][0] * mat.ele[0][0] + ele[1][1] * mat.ele[1][0] + ele[1][2] * mat.ele[2][0],
			ele[1][0] * mat.ele[0][1] + ele[1][1] * mat.ele[1][1] + ele[1][2] * mat.ele[2][1],
			ele[1][0] * mat.ele[0][2] + ele[1][1] * mat.ele[1][2] + ele[1][2] * mat.ele[2][2], 

			ele[2][0] * mat.ele[0][0] + ele[2][1] * mat.ele[1][0] + ele[2][2] * mat.ele[2][0],
			ele[2][0] * mat.ele[0][1] + ele[2][1] * mat.ele[1][1] + ele[2][2] * mat.ele[2][1],
			ele[2][0] * mat.ele[0][2] + ele[2][1] * mat.ele[1][2] + ele[2][2] * mat.ele[2][2]);
}
inline Matrix33& Matrix33::operator*=(const Matrix33& mat) {
	*this = *this * mat;
	return *this;
}
inline Matrix33 Matrix33::CreateScaling(float x, float y) {
	return Matrix33(
		x, 0, 0,
		0, y, 0,
		0, 0, 1
	);
}
inline Matrix33 Matrix33::CreateScaling(const Vector2D& vec) {
	return CreateScaling(vec.x, vec.y);
}
inline Matrix33 Matrix33::CreateScaling(float s){
	return CreateScaling(s, s);
}
inline Matrix33 Matrix33::CreateRotation(float t) {
	float s = Math::Sin(t);
	float c = Math::Cos(t);
	return Matrix33(
		c, -s,  0,
		s, c,  0,
		0,  0,  1
	);
}
inline Matrix33 Matrix33::CreateTranslation(float x, float y) {
	return Matrix33(
		1, 0, x,
		0, 1, y,
		0, 0, 1
	);
}
inline Matrix33 Matrix33::CreateTranslation(const Vector2D& vec) {
	return CreateTranslation(vec.x, vec.y);
}
#pragma endregion