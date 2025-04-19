#include <stdbool.h>
#include <stdlib.h>

#include "greatest/greatest.h"
#include "aligned/aligned.h"

#include "pointer_tag.h"

#define TAG 0x1

TEST test_pointer_tag(void) {
    uint32_t *ptr = (uint32_t *)aligned_malloc(64, 64);
    ASSERT_FALSE(pointer_is_tagged(ptr, TAG));
    uint32_t *tagged_ptr = pointer_tag(ptr, TAG);
    ASSERT_NEQ(ptr, tagged_ptr);
    ASSERT(pointer_is_tagged(tagged_ptr, TAG));
    uint32_t *untagged_ptr = pointer_untag(tagged_ptr, TAG);
    ASSERT_EQ(untagged_ptr, ptr);
    aligned_free(ptr);
    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    RUN_TEST(test_pointer_tag);
    GREATEST_MAIN_END();
}