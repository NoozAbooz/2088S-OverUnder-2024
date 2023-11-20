#pragma once
#include "robodash/apix.hpp"

namespace rd {

class GifView : public rd::View {
  public:
    GifView();
    ~GifView();

    void initialize();
    void refresh();
};

}