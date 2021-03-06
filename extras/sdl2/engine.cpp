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

#include "SDL.h"
#include "engine.h"
#include "sprite.h"

tweeny::extras::sdl2::sprite tweeny::extras::sdl2::engine::sprite(const unsigned char * data, unsigned int len, int framesx, int framesy) {
  return tweeny::extras::sdl2::sprite{renderer, data, len, framesx, framesy};
}

tweeny::extras::sdl2::sprite tweeny::extras::sdl2::engine::sprite(const char * file, int framesx, int framesy) {
  return tweeny::extras::sdl2::sprite{renderer, file, framesx, framesy};
}

tweeny::extras::sdl2::engine::engine(int w, int h) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

tweeny::extras::sdl2::engine::~engine() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void tweeny::extras::sdl2::engine::clear() {
  clear(clearcolor.r, clearcolor.g, clearcolor.b, clearcolor.a);
}

void tweeny::extras::sdl2::engine::clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  start = SDL_GetTicks();
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, clearcolor.r, clearcolor.g, clearcolor.b, clearcolor.a);
}

void tweeny::extras::sdl2::engine::flip() {
  SDL_RenderPresent(renderer);
  dt = SDL_GetTicks() - start;
}

bool tweeny::extras::sdl2::engine::quit() {
  return SDL_QuitRequested();
}

void tweeny::extras::sdl2::engine::delay(uint32_t ms) {
  SDL_Delay(ms);
}

tweeny::extras::sdl2::rect tweeny::extras::sdl2::engine::rect(float x, float y, float w, float h, const tweeny::extras::sdl2::color & fill, tweeny::extras::sdl2::color & background) {
  return {renderer, x, y, w, h, fill, background};
}




