#include "globals.hpp"

rd::GifView::GifView() : rd::View("Logo") {}
rd::GifView::~GifView() {}

void rd::GifView::initialize() {
	if (!pros::usd::is_installed()) return;

    lv_obj_t *obj = lv_obj_create(this->get_obj());
	lv_obj_set_size(obj, 540, 300);
	lv_obj_align(obj, LV_ALIGN_CENTER, 30, 30);
	static Gif gif("/usd/logo.gif", obj);
}

void rd::GifView::refresh() {}