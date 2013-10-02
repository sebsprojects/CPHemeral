#include <algorithm>

#include "VertexImpl.h"
#include "RenderingComponentImpl.h"


using namespace cph;

VertexImpl::VertexImpl() :
	vecAttribs(), matAttribs(), primitiveIndices(), component(0)
{

}

VertexImpl::~VertexImpl() {

}

void VertexImpl::addAttributeVec(const char* name, Vecf* vec) {
	vecAttribs.insert(std::pair<std::string, Vecf*>(name, vec));
}

void VertexImpl::addAttributeMat(const char* name, Matf* mat) {
	matAttribs.insert(std::pair<std::string, Matf*>(name, mat));
}

void VertexImpl::removeAttribute(const char* name) {
	vecAttribs.erase(name);
	matAttribs.erase(name);
}

void VertexImpl::addPrimitiveIndex(int index) {
	if(std::find(primitiveIndices.begin(), primitiveIndices.end(), index) == primitiveIndices.end()) {
		primitiveIndices.push_back(index);
	}
}

void VertexImpl::removePrimitiveIndex(int index) {
	primitiveIndices.erase(std::remove(primitiveIndices.begin(), primitiveIndices.end(), index), primitiveIndices.end());
}

void VertexImpl::destroy() {
	component->removeVertex(this);
}

void VertexImpl::setComponent(RenderingComponentImpl* component) {
	this->component = component;
}
