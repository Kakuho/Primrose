#ifndef STATICARRAY_HPP
#define STATICARRAY_HPP

// Static stack allocated array class

#include <concepts>
#include <cstdint>
#include <concepts>

namespace Prim{

// stack allocated array
template <typename T, std::size_t N>
  requires(N > 0 && std::copyable<T>)
struct StaticArray{
    T m_buffer[N];

    //---------------------------------------------------------------//
    //  Data Access
    //---------------------------------------------------------------//

    [[nodiscard]] T& operator[](std::size_t index) noexcept{
      return m_buffer[index];
    }

    [[nodiscard]] const T& operator[](std::size_t index) const noexcept{
      return m_buffer[index];
    }

    [[nodiscard]] T& Front() noexcept{
      return m_buffer[0];
    }

    [[nodiscard]] const T& Front() const noexcept{
      return m_buffer[0];
    }

    [[nodiscard]] T& Back() noexcept{
      return m_buffer[N-1];
    }

    [[nodiscard]] const T& Back() const noexcept{
      return m_buffer[N-1];
    }

    [[nodiscard]] T* Data() const noexcept { return m_buffer; }

    //---------------------------------------------------------------//
    //  Capacity
    //---------------------------------------------------------------//

    [[nodiscard]] std::size_t Size() const noexcept { return N; }

};

// helper functions

template<typename T, std::size_t N>
  requires std::copyable<T>
void Fill(StaticArray<T, N>& src, T value){
  for(auto& k: src){
    k = value;
  }
}

} // namespace Prim

#endif
