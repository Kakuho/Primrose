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

    [[nodiscard]] constexpr T& operator[](std::size_t index) noexcept{
      return m_buffer[index];
    }

    [[nodiscard]] constexpr const T& operator[](std::size_t index) const noexcept{
      return m_buffer[index];
    }

    [[nodiscard]] constexpr T& Front() noexcept{
      return m_buffer[0];
    }

    [[nodiscard]] constexpr const T& Front() const noexcept{
      return m_buffer[0];
    }

    [[nodiscard]] constexpr T& Back() noexcept{
      return m_buffer[N-1];
    }

    [[nodiscard]] constexpr const T& Back() const noexcept{
      return m_buffer[N-1];
    }

    [[nodiscard]] constexpr T* Data() const noexcept { return m_buffer; }

    //---------------------------------------------------------------//
    //  Capacity
    //---------------------------------------------------------------//

    [[nodiscard]] constexpr std::size_t Size() const noexcept { return N; }

    // ------------------------------------------------------ //
    //  Operator Overloads
    // ------------------------------------------------------ //

    [[nodiscard]] constexpr bool operator==(const StaticArray<T,N>& rhs){
      for(std::size_t i = 0; i < N; i++){
        if(m_buffer[i] != rhs[i]){
          return false;
        }
      }
      return true;
    }
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
