#ifndef FLOAT3_H
#define FLOAT3_H

class float3 {
	public:
		float x, y, z;
		float3() { x = 0; y = 0; z = 0; }
		float3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
		~float3() {}

		inline float3& operator= (const float3& V) {
			x = V.x;
			y = V.y;
			z = V.z;
			return (*this);
		}
		inline float3& operator+= (const float3 V) {
			x += V.x;
			y += V.y;
			z += V.z;
			return (*this);
		}
		inline float3 operator+ (const float3 V) const {
			float3 re;
			re.x = x + V.x;
			re.y = y + V.y;
			re.z = z + V.z;
			return re;
		}
		inline float3& operator-= (const float3 V) {
			x -= V.x;
			y -= V.y;
			z -= V.z;
			return (*this);
		}
		inline float3 operator- (const float3 V) const {
			float3 re;
			re.x = x - V.x;
			re.y = y - V.y;
			re.z = z - V.z;
			return re;
		}
		inline float3 operator- () {
			float3 re;
			re.x = -x;
			re.y = -y;
			re.z = -z;
			return re;
		}
		inline float3 operator* (float m) const {
			float3 re;
			re.x = x*m;
			re.y = y*m;
			re.z = z*m;
			return re;
		}
		inline float3 operator/ (float m) const {
			float3 re;
			re.x = x/m;
			re.y = y/m;
			re.z = z/m;
			return re;
		}
		inline bool operator == (const float3 &a) const {
			return (x == a.x && y == a.y && z == a.z);
		}
		inline bool operator != (const float3 &a) const {
			return (x != a.x || y != a.y || z != a.z);
		}
};


#endif