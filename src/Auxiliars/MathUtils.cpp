#include "MathUtils.h"

const SDL_FPoint MathUtils::WORLD_UP = {
	0.0f,
	-1.0f
};

const SDL_FPoint MathUtils::WORLD_DOWN = {
	0.0f,
	1.0f
};

const SDL_FPoint MathUtils::WORLD_RIGHT = {
	1.0f,
	0.0f
};

const SDL_FPoint MathUtils::WORLD_LEFT = {
	-1.0f,
	0.0f
};


MathUtils::MathUtils() {}

MathUtils::~MathUtils() {}

SDL_FPoint MathUtils::CalculateCollision(float v1, float v2, float t1, float t2, float tContact) {
    float x = v2 * cosf(t2 - tContact) * cosf(tContact) + v1 * sinf(t1 - tContact) * cosf(tContact + M_PI / 2.0f);
    float y = v2 * cosf(t2 - tContact) * sinf(tContact) + v1 * sinf(t1 - tContact) * sinf(tContact + M_PI / 2.0f);

	SDL_FPoint res = {
        x,
        y
    };

	return res;
}

float MathUtils::GetAngle(int x1, int y1, int x2, int y2) {
	float angle = 90.0f + atan2f(y1 - y2, x1 - x2) * (180.0f / M_PI);
	return angle >= 0.0f ? angle : 360.0f + angle;
}

float MathUtils::GetDotProduct(SDL_FPoint x, SDL_FPoint y) {
    return x.x * y.x + x.y * y.y;
}

float MathUtils::GetMagnitude(float x, float y) {
	return sqrtf((x * x) + (y * y));
}

float MathUtils::GetMagnitude(const SDL_Point& point) {
	return sqrtf((point.x * point.x) + (point.y * point.y));
}

float MathUtils::GetMagnitudeSqr(const SDL_FPoint& point) {
	return (point.x * point.x) + (point.y * point.y);
}

SDL_FPoint MathUtils::GetNormalized(float x, float y) {
	float mag = GetMagnitude(x, y);
	
	SDL_FPoint res = {
		x / mag,
		y / mag
	};

	return res;
}

SDL_FPoint MathUtils::GetNormalized(const SDL_Point& point) {
	float mag = GetMagnitude(point.x, point.y);
	
	SDL_FPoint res = {
		(float)point.x / mag,
		(float)point.y / mag
	};

	return res;
}

SDL_FPoint MathUtils::GetNormalized(const SDL_FPoint& point) {
	float mag = GetMagnitude(point.x, point.y);

	SDL_FPoint res = {
		point.x / mag,
		point.y / mag
	};

	return res;
}


void MathUtils::Normalize(SDL_FPoint* point) {
	float mag = GetMagnitude(point->x, point->y);

	point->x = point->x / mag;
	point->y = point->y / mag;
}

SDL_FPoint MathUtils::VectorSubstract(const SDL_FPoint& a, const SDL_FPoint& b) {
	SDL_FPoint res = {
		a.x - b.x,
		a.y - b.y
	};
	return res;
}

SDL_FPoint MathUtils::VectorSubstract(const SDL_Point& a, const SDL_Point& b) {
	SDL_FPoint res = {
        static_cast<float>(a.x - b.x),
        static_cast<float>(a.y - b.y)
	};
	return res;
}

void MathUtils::VectorSubstract(SDL_Point* a, const SDL_Point& b) {
	a->x -= b.x;
	a->y -= b.y;
}

SDL_FPoint MathUtils::VectorAdd(const SDL_FPoint& a, const SDL_FPoint& b) {
	return {
		a.x + b.x,
		a.y + b.y
	};
}

float MathUtils::DistanceSqr(const SDL_FPoint& a, const SDL_FPoint& b) {
	//Sub the vectors and then get the magnitude of that sqr (that should be the distance sqr)
	SDL_FPoint difference = VectorSubstract(a, b);
	return GetMagnitudeSqr(difference);
}

SDL_FPoint MathUtils::ToSDL_FPoint(const SDL_Point& point) {
	SDL_FPoint res = {
		(float)point.x,
		(float)point.y
	};
	return res;
}

float MathUtils::Clamp(float n, float lower, float upper) {
	return std::max(lower, std::min(n, upper));
}

int MathUtils::Random(int min, int max) {
	return min + rand() % ((max + 1) - min);
}

int MathUtils::RoundToClosestInteger(float n) {
	//First off, we get the difference between the int part and the total part
	int wholePart = (int)n;
	float diff = n - wholePart;
	return diff < 0.5f ? (int)floor(n) : (int)ceil(n);
}

bool MathUtils::Between(int value, int lower, int upper) {
	return value <= upper && value >= lower;
}
