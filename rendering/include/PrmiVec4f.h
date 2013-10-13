#ifndef PRMI_VEC4F_H_
#define PRMI_VEC4F_H_

#include <cstdint>
#include "Vec4f.h"
#include "Primitive.h"


namespace cph {

struct PrmiVec4f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;
	virtual const char* getName() const = 0;
	virtual void setName(const char* name) = 0;

	virtual Vec4f* get() = 0;

};

}

#endif