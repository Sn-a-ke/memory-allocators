#ifndef STACKALLOCATOR_H
#define STACKALLOCATOR_H

#include "Allocator.h"

class StackAllocator : public Allocator {
protected:
	void* m_start_ptr;
	std::size_t m_offset;
public:
	StackAllocator(const std::size_t totalSize);

	virtual ~StackAllocator();

	virtual void* Allocate(const std::size_t size, const short alignment = 0);

	virtual void Free(const std::size_t size);

	virtual void Init() override;

private:
	StackAllocator(StackAllocator &stackAllocator);

	struct AllocationHeader {
		char padding;
	};

};

#endif /* STACKALLOCATOR_H */