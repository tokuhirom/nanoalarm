#include <nanotap/nanotap.h>
#include "../nanoalarm.h"

int main() {
    nanoalarm::Alarm a(1);
    pause();

    ok(1, "passed");

    done_testing();
}
