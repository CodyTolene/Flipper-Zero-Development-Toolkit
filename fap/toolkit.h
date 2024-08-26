#pragma once

#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <input/input.h>
#include <stdlib.h>
#include <notification/notification_messages.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>
#include <gui/scene_manager.h>
#include <gui/modules/variable_item_list.h>
#include <gui/modules/button_menu.h>

#define TAG "Toolkit"

// Screen size of Flipper Zero (width)
#define FRAME_WIDTH 128

// Screen size of Flipper Zero (height)
#define FRAME_HEIGTH 64

typedef struct {
    Gui* gui;
    FuriThread* worker_thread;
    ViewDispatcher* view_dispatcher;
} Toolkit;

Toolkit* toolkit_app_alloc();

void toolkit_app_free(Toolkit* app);

int32_t toolkit_app(void* p);
