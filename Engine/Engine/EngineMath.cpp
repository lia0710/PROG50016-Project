#include "EngineCore.h"
#include "EngineMath.h"

Vec2 Vec2::Zero = Vec2();
Vec2 Vec2::UnitX = Vec2(1, 0);
Vec2 Vec2::UnitY = Vec2(0, 1);

Vec2::Vec2() {
	x = 0;
	y = 0;
}

Vec2::Vec2(const float value) {
	x = value;
	y = value;
}

Vec2::Vec2(float _x, float _y) : x(_x), y(_y) {}

Vec2::Vec2(IVec2 value)
{
	x = static_cast<float>(value.x);
	y = static_cast<float>(value.y);
}

Vec2 Vec2::operator-() const {
	return { -this->x, -this->y };
}

bool Vec2::operator==(const Vec2& rhs) const
{
	return std::abs(this->x - rhs.x) <= SDL_FLT_EPSILON && std::abs(this->y - rhs.y) <= SDL_FLT_EPSILON;
}

bool Vec2::operator!=(const Vec2& rhs) const
{
	return !(*this == rhs);
}

Vec2& Vec2::operator+=(const Vec2& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;

	return *this;
}

Vec2& Vec2::operator-=(const Vec2& rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
}

Vec2& Vec2::operator*=(const Vec2& rhs) {
	this->x *= rhs.x;
	this->y *= rhs.y;

	return *this;
}

Vec2& Vec2::operator/=(const Vec2& rhs) {
	this->x /= rhs.x;
	this->y /= rhs.y;

	return *this;
}

Vec2& Vec2::operator*=(const float& f) {
	this->x *= f;
	this->y *= f;

	return *this;
}

Vec2& Vec2::operator/=(const float& f) {
	const float inv_f = 1.0f / f;
	this->x *= inv_f;
	this->y *= inv_f;

	return *this;
}

Vec2 Vec2::operator+(const Vec2& rhs) const {
	return { this->x + rhs.x, this->y + rhs.y };
}

Vec2 Vec2::operator-(const Vec2& rhs) const {
	return { this->x - rhs.x, this->y - rhs.y };
}

Vec2 Vec2::operator*(const Vec2& rhs) const {
	return { this->x * rhs.x, this->y * rhs.y };
}

Vec2 Vec2::operator/(const Vec2& rhs) const {
	return { this->x / rhs.x, this->y / rhs.y };
}

Vec2 Vec2::operator*(const float& f) const {
	return { this->x * f, this->y * f };
}

Vec2 Vec2::operator/(const float& f) const {
	const float inv_f = 1.0f / f;
	return { this->x * inv_f, this->y * inv_f };
}

void Vec2::Normalize() {
	// TODO: Maybe rework this check?
	if (this->x == 0 || this->y == 0) {
		return;
	}
	*this /= this->Magnitude();
}

float Vec2::Magnitude() const {
	return SDL_sqrtf(this->MagnitudeSquared());
}

float Vec2::Dot(const Vec2& rhs) const {
	return this->x * rhs.x + this->y * rhs.y;
}

float Vec2::Dot(const Vec2& lhs, const Vec2& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

float Vec2::MagnitudeSquared() const {
	return this->x * this->x + this->y * this->y;
}

float Vec2::Distance(const Vec2& rhs) const {
	return (*this - rhs).Magnitude();
}

float Vec2::Distance(const Vec2& lhs, const Vec2& rhs) {
	return (lhs - rhs).Magnitude();
}

IVec2 IVec2::Zero = IVec2();
IVec2 IVec2::UnitX = IVec2(1, 0);
IVec2 IVec2::UnitY = IVec2(0, 1);

IVec2::IVec2() {
	x = 0;
	y = 0;
}

IVec2::IVec2(const int value) {
	x = value;
	y = value;
}

IVec2::IVec2(int _x, int _y) : x(_x), y(_y) {}

IVec2::IVec2(Vec2 value)
{
	x = static_cast<int>(value.x);
	y = static_cast<int>(value.y);
}

IVec2 IVec2::operator-() const {
	return { -this->x, -this->y };
}

bool IVec2::operator==(const IVec2& rhs) const
{
	return this->x == rhs.x && this->y == rhs.y;
}

bool IVec2::operator!=(const IVec2& rhs) const
{
	return !(*this == rhs);
}

IVec2& IVec2::operator+=(const IVec2& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;

	return *this;
}

IVec2& IVec2::operator-=(const IVec2& rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
}

IVec2& IVec2::operator*=(const IVec2& rhs) {
	this->x *= rhs.x;
	this->y *= rhs.y;

	return *this;
}

IVec2& IVec2::operator/=(const IVec2& rhs) {
	this->x /= rhs.x;
	this->y /= rhs.y;

	return *this;
}

IVec2& IVec2::operator*=(const int& f) {
	this->x *= f;
	this->y *= f;

	return *this;
}

IVec2& IVec2::operator/=(const int& f) {
	this->x /= f;
	this->y /= f;

	return *this;
}

IVec2 IVec2::operator+(const IVec2& rhs) const {
	return { this->x + rhs.x, this->y + rhs.y };
}

IVec2 IVec2::operator-(const IVec2& rhs) const {
	return { this->x - rhs.x, this->y - rhs.y };
}

IVec2 IVec2::operator*(const IVec2& rhs) const {
	return { this->x * rhs.x, this->y * rhs.y };
}

IVec2 IVec2::operator/(const IVec2& rhs) const {
	return { this->x / rhs.x, this->y / rhs.y };
}

IVec2 IVec2::operator*(const int& f) const {
	return { this->x * f, this->y * f };
}

IVec2 IVec2::operator/(const int& f) const {
	return { this->x / f, this->y / f };
}
