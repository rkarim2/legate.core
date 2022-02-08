/* Copyright 2021-2022 NVIDIA Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include "core/utilities/typedefs.h"

namespace legate {

template <int DIM>
struct inner_type_dispatch_fn {
  template <typename Functor, typename... Fnargs>
  constexpr decltype(auto) operator()(LegateTypeCode code, Functor f, Fnargs&&... args)
  {
    switch (code) {
      case LegateTypeCode::BOOL_LT: {
        return f.template operator()<LegateTypeCode::BOOL_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::INT8_LT: {
        return f.template operator()<LegateTypeCode::INT8_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::INT16_LT: {
        return f.template operator()<LegateTypeCode::INT16_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::INT32_LT: {
        return f.template operator()<LegateTypeCode::INT32_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::INT64_LT: {
        return f.template operator()<LegateTypeCode::INT64_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::UINT8_LT: {
        return f.template operator()<LegateTypeCode::UINT8_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::UINT16_LT: {
        return f.template operator()<LegateTypeCode::UINT16_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::UINT32_LT: {
        return f.template operator()<LegateTypeCode::UINT32_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::UINT64_LT: {
        return f.template operator()<LegateTypeCode::UINT64_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::HALF_LT: {
        return f.template operator()<LegateTypeCode::HALF_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::FLOAT_LT: {
        return f.template operator()<LegateTypeCode::FLOAT_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::DOUBLE_LT: {
        return f.template operator()<LegateTypeCode::DOUBLE_LT, DIM>(std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::COMPLEX64_LT: {
        return f.template operator()<LegateTypeCode::COMPLEX64_LT, DIM>(
          std::forward<Fnargs>(args)...);
      }
      case LegateTypeCode::COMPLEX128_LT: {
        return f.template operator()<LegateTypeCode::COMPLEX128_LT, DIM>(
          std::forward<Fnargs>(args)...);
      }
      default: break;
    }
    assert(false);
    return f.template operator()<LegateTypeCode::BOOL_LT, DIM>(std::forward<Fnargs>(args)...);
  }
};

template <int DIM>
struct inner_dim_dispatch_fn {
  template <typename Functor, typename... Fnargs>
  constexpr decltype(auto) operator()(int dim, Functor f, Fnargs&&... args)
  {
    switch (dim) {
      case 1: {
        return f.template operator()<DIM, 1>(std::forward<Fnargs>(args)...);
      }
#if LEGION_MAX_DIM >= 2
      case 2: {
        return f.template operator()<DIM, 2>(std::forward<Fnargs>(args)...);
      }
#endif
#if LEGION_MAX_DIM >= 3
      case 3: {
        return f.template operator()<DIM, 3>(std::forward<Fnargs>(args)...);
      }
#endif
#if LEGION_MAX_DIM >= 4
      case 4: {
        return f.template operator()<DIM, 4>(std::forward<Fnargs>(args)...);
      }
#endif
#if LEGION_MAX_DIM >= 5
      case 5: {
        return f.template operator()<DIM, 5>(std::forward<Fnargs>(args)...);
      }
#endif
#if LEGION_MAX_DIM >= 6
      case 6: {
        return f.template operator()<DIM, 6>(std::forward<Fnargs>(args)...);
      }
#endif
#if LEGION_MAX_DIM >= 7
      case 7: {
        return f.template operator()<DIM, 7>(std::forward<Fnargs>(args)...);
      }
#endif
#if LEGION_MAX_DIM >= 8
      case 8: {
        return f.template operator()<DIM, 8>(std::forward<Fnargs>(args)...);
      }
#endif
#if LEGION_MAX_DIM >= 9
      case 9: {
        return f.template operator()<DIM, 9>(std::forward<Fnargs>(args)...);
      }
#endif
    }
    assert(false);
    return f.template operator()<DIM, 1>(std::forward<Fnargs>(args)...);
  }
};

template <typename Functor, typename... Fnargs>
constexpr decltype(auto) double_dispatch(int dim, LegateTypeCode code, Functor f, Fnargs&&... args)
{
  switch (dim) {
#if LEGION_MAX_DIM >= 1
    case 1: {
      return inner_type_dispatch_fn<1>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 2
    case 2: {
      return inner_type_dispatch_fn<2>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 3
    case 3: {
      return inner_type_dispatch_fn<3>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 4
    case 4: {
      return inner_type_dispatch_fn<4>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 5
    case 5: {
      return inner_type_dispatch_fn<5>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 6
    case 6: {
      return inner_type_dispatch_fn<6>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 7
    case 7: {
      return inner_type_dispatch_fn<7>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 8
    case 8: {
      return inner_type_dispatch_fn<8>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 9
    case 9: {
      return inner_type_dispatch_fn<9>{}(code, f, std::forward<Fnargs>(args)...);
    }
#endif
  }
  assert(false);
  return inner_type_dispatch_fn<1>{}(code, f, std::forward<Fnargs>(args)...);
}

template <typename Functor, typename... Fnargs>
constexpr decltype(auto) double_dispatch(int dim1, int dim2, Functor f, Fnargs&&... args)
{
  switch (dim1) {
#if LEGION_MAX_DIM >= 1
    case 1: {
      return inner_dim_dispatch_fn<1>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 2
    case 2: {
      return inner_dim_dispatch_fn<2>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 3
    case 3: {
      return inner_dim_dispatch_fn<3>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 4
    case 4: {
      return inner_dim_dispatch_fn<4>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 5
    case 5: {
      return inner_dim_dispatch_fn<5>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 6
    case 6: {
      return inner_dim_dispatch_fn<6>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 7
    case 7: {
      return inner_dim_dispatch_fn<7>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 8
    case 8: {
      return inner_dim_dispatch_fn<8>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 9
    case 9: {
      return inner_dim_dispatch_fn<9>{}(dim2, f, std::forward<Fnargs>(args)...);
    }
#endif
  }
  assert(false);
  return inner_dim_dispatch_fn<1>{}(dim2, f, std::forward<Fnargs>(args)...);
}

template <typename Functor, typename... Fnargs>
constexpr decltype(auto) dim_dispatch(int dim, Functor f, Fnargs&&... args)
{
  switch (dim) {
#if LEGION_MAX_DIM >= 1
    case 1: {
      return f.template operator()<1>(std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 2
    case 2: {
      return f.template operator()<2>(std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 3
    case 3: {
      return f.template operator()<3>(std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 4
    case 4: {
      return f.template operator()<4>(std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 5
    case 5: {
      return f.template operator()<5>(std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 6
    case 6: {
      return f.template operator()<6>(std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 7
    case 7: {
      return f.template operator()<7>(std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 8
    case 8: {
      return f.template operator()<8>(std::forward<Fnargs>(args)...);
    }
#endif
#if LEGION_MAX_DIM >= 9
    case 9: {
      return f.template operator()<9>(std::forward<Fnargs>(args)...);
    }
#endif
  }
  assert(false);
  return f.template operator()<1>(std::forward<Fnargs>(args)...);
}

template <typename Functor, typename... Fnargs>
constexpr decltype(auto) type_dispatch(LegateTypeCode code, Functor f, Fnargs&&... args)
{
  switch (code) {
    case LegateTypeCode::BOOL_LT: {
      return f.template operator()<LegateTypeCode::BOOL_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::INT8_LT: {
      return f.template operator()<LegateTypeCode::INT8_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::INT16_LT: {
      return f.template operator()<LegateTypeCode::INT16_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::INT32_LT: {
      return f.template operator()<LegateTypeCode::INT32_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::INT64_LT: {
      return f.template operator()<LegateTypeCode::INT64_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::UINT8_LT: {
      return f.template operator()<LegateTypeCode::UINT8_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::UINT16_LT: {
      return f.template operator()<LegateTypeCode::UINT16_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::UINT32_LT: {
      return f.template operator()<LegateTypeCode::UINT32_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::UINT64_LT: {
      return f.template operator()<LegateTypeCode::UINT64_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::HALF_LT: {
      return f.template operator()<LegateTypeCode::HALF_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::FLOAT_LT: {
      return f.template operator()<LegateTypeCode::FLOAT_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::DOUBLE_LT: {
      return f.template operator()<LegateTypeCode::DOUBLE_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::COMPLEX64_LT: {
      return f.template operator()<LegateTypeCode::COMPLEX64_LT>(std::forward<Fnargs>(args)...);
    }
    case LegateTypeCode::COMPLEX128_LT: {
      return f.template operator()<LegateTypeCode::COMPLEX128_LT>(std::forward<Fnargs>(args)...);
    }
    default: break;
  }
  assert(false);
  return f.template operator()<LegateTypeCode::BOOL_LT>(std::forward<Fnargs>(args)...);
}

}  // namespace legate
