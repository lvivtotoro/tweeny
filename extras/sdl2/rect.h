/*
 This file is part of the Tweeny library.

 Copyright (c) 2016-2018 Leonardo G. Lucena de Freitas
 Copyright (c) 2016 Guilherme R. Costa

 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef TWEENY_SDL2_RECT_H
#define TWEENY_SDL2_RECT_H

#include "color.h"

struct SDL_Renderer;

namespace tweeny {
  namespace extras {
    namespace sdl2 {

      class rect {
        public:
          rect(rect && other) noexcept;
          rect(const rect & other) = default;
          rect(SDL_Renderer * renderer, float x, float y, float w, float h, const sdl2::color & background, const sdl2::color & line);
          void fill(const sdl2::color & bg);
          void border(const sdl2::color & bg);
          void render();

        public:
          float x;
          float y;
          float w;
          float h;

        private:
          SDL_Renderer * renderer;
          sdl2::color fg;
          sdl2::color bg;
      };
    }
  }
}


#endif //TWEENY_SDL2_RECT_H
