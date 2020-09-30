// ----------------------------------------------------
// Vec3 class    -----------
// ----------------------------------------------------

#ifndef __VEC3_H__
#define __VEC3_H__

#include <math.h>

template<class TYPE>
class vec3
{
public:

	TYPE x, y, z;

	vec3()
	{}

	vec3(const vec3<TYPE>& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}

	vec3(const TYPE& x, const TYPE& y, const TYPE& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& create(const TYPE& x, const TYPE& y, const TYPE& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;

		return(*this);
	}

	// Math ------------------------------------------------
	vec3 operator -(const vec3& v) const
	{
		vec3 r;

		r.x = x - v.x;
		r.y = y - v.y;
		r.z = z - v.z;

		return(r);
	}

	vec3 operator + (const vec3& v) const
	{
		vec3 r;

		r.x = x + v.x;
		r.y = y + v.y;
		r.z = z + v.z;

		return(r);
	}

	const vec3& operator -=(const vec3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return(*this);
	}

	const vec3& operator +=(const vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return(*this);
	}

	bool operator ==(const vec3& v) const
	{
		return (x == v.x && y == v.y && z == v.z);
	}

	bool operator !=(const vec3& v) const
	{
		return (x != v.x || y != v.y || z != v.z);
	}

	// Utils ------------------------------------------------

	vec3& Normalize()
	{
		vec3 f;
		f.x = x / sqrtf((x * x) + (y * y) + (z * z));
		f.y = y / sqrtf((x * x) + (y * y) + (z * z));
		f.z = z / sqrtf((x * x) + (y * y) + (z * z));
		return f;
	}

	vec3& Zero()
	{
		x = y = z = 0;
		return(*this);
	}

	bool IsZero() const
	{
		return (x == 0 && y == 0 && z == 0);
	}

	// Distances ---------------------------------------------
	TYPE DistanceTo(const vec3& v) const
	{
		TYPE fx = x - v.x;
		TYPE fy = y - v.y;

		return sqrtf((fx * fx) + (fy * fy));
	}
};

#endif // __VEC3_H__