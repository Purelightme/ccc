#define MILL_USE_PREFIX
#include <libmill.h>

mill_coroutine void worker(void) {

}

int main() {
    mill_go(worker());
    return 0;
}