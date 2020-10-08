//
// Created by huxy on 13/11/2019.
//

#ifndef ASGE_PIXELBUFFER_H
#define ASGE_PIXELBUFFER_H

#include <array>
#include <atomic>

namespace ASGE {
  class PixelBuffer
  {
  public:
    PixelBuffer(unsigned int width, unsigned int height)
    : buffer_size{width, height} {};

    virtual ~PixelBuffer() = default;

    bool isBufferStale() const noexcept {return stale;}
    virtual const void* getPixelData() const noexcept = 0;
    virtual void* getPixelData() noexcept = 0;
    virtual void  upload(void *, int mip_level) noexcept = 0;
    virtual void  upload(unsigned int mip_level) noexcept = 0;
    virtual void  download(unsigned int mip_level) noexcept = 0;
    unsigned int  getWidth()  const noexcept {return buffer_size[0];}
    unsigned int  getHeight() const noexcept {return buffer_size[1];}

   protected:
    std::array<unsigned int, 2> buffer_size {0};
    mutable std::atomic<bool> stale{true};
  };
}

#endif // ASGE_PIXELBUFFER_H
