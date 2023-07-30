#include "toolkit.h"
#include <stdlib.h>
#include <stdint.h>

Toolkit* toolkit_app_alloc() {
    Toolkit* app = malloc(sizeof(Toolkit));
    return app;
}

void toolkit_app_free(Toolkit* app) {
    furi_assert(app);
    free(app);
}

int32_t toolkit_app(void* p) {
    UNUSED(p);
    Toolkit* app = toolkit_app_alloc();
    FURI_LOG_I("Toolkit!", "Hello world!");
    toolkit_app_free(app);
    return 0;
}
