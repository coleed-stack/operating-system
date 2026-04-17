#include "types.h"
#include "stat.h"
#include "user.h"

#define ARENA_SIZE 1024

typedef struct {
   uchar memory[ARENA_SIZE];
   uint offset;
} Arena;

// Initialize the arena
void arena_init(Arena* a) {
   a->offset = 0;
}

void* arena_alloc(Arena* a, uint size) {
   // 1. Check if there is enough space left in the arena (ARENA_SIZE - current offset).
	if (a->offset + size > ARENA_SIZE) {
   // 2. If not, return NULL.
		return 0;
	}
   // 3. If there is, calculate the pointer to the current free memory.
	void* ptr = &a->memory[a->offset];
   // 4. Increment the offset by 'size'.
	a->offset += size;
   // 5. Return the pointer.
	return ptr;
}

int main(int argc, char *argv[]) {
   Arena my_arena;
   arena_init(&my_arena);

   int* num = (int*)arena_alloc(&my_arena, sizeof(int));
   if (num) {
       *num = 42;
       printf(1, "Allocated number: %d\n", *num);
   } else {
       printf(1, "Allocation failed!\n");
   }

   // Try allocating more than the remaining space to test your error handling
   char* big_string = (char*)arena_alloc(&my_arena, 2048);
   if (!big_string) {
	 printf(1, "Successfully caught out-of-memory error!\n");
   }
   exit();
}
